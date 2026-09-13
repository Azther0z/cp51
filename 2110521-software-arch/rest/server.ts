import { PrismaPg } from "@prisma/adapter-pg";
import express from "express";
import type { NextFunction, Request, Response } from "express";
import { Prisma, PrismaClient } from "./generated/prisma/client.js";

const databaseUrl = process.env.DATABASE_URL;

if (!databaseUrl) {
  throw new Error("DATABASE_URL is required");
}

const prisma = new PrismaClient({
  adapter: new PrismaPg({ connectionString: databaseUrl }),
});
const app = express();

app.use(express.json());

// GETALL
app.get("/users", async (_req: Request, res: Response) => {
  const users = await prisma.user.findMany({ orderBy: { id: "asc" } });
  res.json(users);
});

// GETONE
app.get("/users/:id", async (req: Request, res: Response) => {
  const id = Number(req.params.id);

  if (!Number.isInteger(id)) {
    res.status(400).json({ error: "User ID must be an integer" });
    return;
  }

  const user = await prisma.user.findUnique({ where: { id } });

  if (!user) {
    res.status(404).json({ error: "User not found" });
    return;
  }

  res.json(user);
});

// POST
app.post("/users", async (req: Request, res: Response) => {
  const { name, email } = req.body;

  if (typeof name !== "string" || typeof email !== "string" || !name || !email) {
    res.status(400).json({ error: "name and email are required" });
    return;
  }

  const user = await prisma.user.create({ data: { name, email } });
  res.status(201).json(user);
});

// PUT
app.put("/users/:id", async (req: Request, res: Response) => {
  const id = Number(req.params.id);
  const { name, email } = req.body;

  if (!Number.isInteger(id)) {
    res.status(400).json({ error: "User ID must be an integer" });
    return;
  }

  if (typeof name !== "string" || typeof email !== "string" || !name || !email) {
    res.status(400).json({ error: "name and email are required" });
    return;
  }

  const user = await prisma.user.update({ where: { id }, data: { name, email } });
  res.json(user);
});

// DELETE
app.delete("/users/:id", async (req: Request, res: Response) => {
  const id = Number(req.params.id);

  if (!Number.isInteger(id)) {
    res.status(400).json({ error: "User ID must be an integer" });
    return;
  }

  await prisma.user.delete({ where: { id } });
  res.status(204).send();
});

app.use((error: unknown, _req: Request, res: Response, _next: NextFunction) => {
  if (error instanceof Prisma.PrismaClientKnownRequestError) {
    if (error.code === "P2025") {
      res.status(404).json({ error: "User not found" });
      return;
    }

    if (error.code === "P2002") {
      res.status(409).json({ error: "Email already exists" });
      return;
    }
  }

  console.error(error);
  res.status(500).json({ error: "Internal server error" });
});

const port = Number(process.env.PORT ?? 8000);

app.listen(port, () => {
  console.log(`User API listening on port ${port}`);
});

async function shutdown() {
  await prisma.$disconnect();
  process.exit(0);
}

process.on("SIGINT", shutdown);
process.on("SIGTERM", shutdown);
