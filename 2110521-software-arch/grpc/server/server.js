const PROTO_PATH="./restaurant.proto";
require("dotenv").config();

//var grpc = require("grpc");
var grpc = require("@grpc/grpc-js");

var protoLoader = require("@grpc/proto-loader");
const mongoose = require("mongoose");
const Menu = require("../models/Menu");

var packageDefinition = protoLoader.loadSync(PROTO_PATH,{
    keepCase: true,
    longs: String,
    enums: String,
    arrays: true
});

var restaurantProto =grpc.loadPackageDefinition(packageDefinition);

const server = new grpc.Server();

const toMenuItem = item => ({
    id: item._id.toString(),
    name: item.name,
    price: item.price
});

server.addService(restaurantProto.RestaurantService.service,{
    getAllMenu: async (_, callback)=>{
        try {
            const menu = await Menu.find();
            callback(null, {menu: menu.map(toMenuItem)});
        } catch (error) {
            callback({code: grpc.status.INTERNAL, details: error.message});
        }
    },
    get: async (call, callback)=>{
        try {
            const menuItem = await Menu.findById(call.request.id);
            if (!menuItem) return callback({code: grpc.status.NOT_FOUND, details: "Not found"});
            callback(null, toMenuItem(menuItem));
        } catch (error) {
            callback({code: grpc.status.NOT_FOUND, details: "Not found"});
        }
    },
    insert: async (call, callback)=>{
        try {
            const menuItem = await Menu.create({name: call.request.name, price: call.request.price});
            callback(null, toMenuItem(menuItem));
        } catch (error) {
            callback({code: grpc.status.INTERNAL, details: error.message});
        }
    },
    update: async (call, callback)=>{
        try {
            const menuItem = await Menu.findByIdAndUpdate(call.request.id,
                {name: call.request.name, price: call.request.price}, {new: true, runValidators: true});
            if (!menuItem) return callback({code: grpc.status.NOT_FOUND, details: "Not Found"});
            callback(null, toMenuItem(menuItem));
        } catch (error) {
            callback({code: grpc.status.NOT_FOUND, details: "Not Found"});
        }
    },
    remove: async (call, callback) => {
        try {
            const menuItem = await Menu.findByIdAndDelete(call.request.id);
            if (menuItem) {
            callback(null,{});
            } else callback({code: grpc.status.NOT_FOUND, details: "NOT Found"});
        } catch (error) {
            callback({code: grpc.status.NOT_FOUND, details: "NOT Found"});
        }
    }
});

const port = "127.0.0.1:30043";
const databaseUri = process.env.MONGODB_URI;

if (!databaseUri) throw new Error("MONGODB_URI environment variable is required");

mongoose.connect(databaseUri)
    .then(() => server.bindAsync(port, grpc.ServerCredentials.createInsecure(), () => {
        server.start();
        console.log(`Server running at http://${port}`);
    }))
    .catch(error => {
        console.error("MongoDB connection failed:", error.message);
        process.exitCode = 1;
    });
