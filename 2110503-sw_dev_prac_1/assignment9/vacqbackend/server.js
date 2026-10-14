const express = require('express');
const cors = require('cors');
const dotenv = require('dotenv');
const cookieParser = require('cookie-parser');
const connectDB = require('./config/db');

dotenv.config({ path: './config/config.env' });

connectDB();

const app = express();
app.use(cors());
app.use(express.json());

app.use(cookieParser());

app.set('query parser', 'extended');

app.get('/', (req, res) => {
  // res.send('<h1>Hello from express</h1>');
  // res.send({ name: 'Brad' });
  // res.json({ name: 'Bard' });
  // res.sendStatus(400);
  // res.status(400);
  // res.status(400).json({ success: false });
  res.status(200).json({ success: true, data: { id: 1 } });
})

const hospitals = require(`./routes/hospitals`);
app.use(`/api/v1/hospitals`, hospitals);

const appointments = require('./routes/appointments');
app.use('/api/v1/appointments', appointments);

const auth = require('./routes/auth');
app.use('/api/v1/auth', auth);

const PORT = process.env.PORT || 5000;
const server = app.listen(PORT, console.log('Server running in ', process.env.NODE_ENV, ' mode on port ', PORT));

process.on('unhandledRejection', (err, promise) => {
  console.log(`Error: ${err.message}`);
  server.close(() => process.exit(1));
});
