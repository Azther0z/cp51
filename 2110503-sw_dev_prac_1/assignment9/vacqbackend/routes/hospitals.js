const express = require('express');
const dotenv = require('dotenv');
const { getHospitals, getHospital, createHospital, updateHospital, deleteHospital } = require('../controllers/hospitals');
const { protect, authorize } = require('../middleware/auth');
const appointmentRouter = require('./appointments');

const router = express.Router();

router.route('/').get(getHospitals).post(protect, authorize('admin'), createHospital);
router.route('/:id').get(getHospital).put(protect, authorize('admin'), updateHospital).delete(protect, authorize('admin'), deleteHospital);

router.use('/:hospitalId/appointments', appointmentRouter);

module.exports = router;
