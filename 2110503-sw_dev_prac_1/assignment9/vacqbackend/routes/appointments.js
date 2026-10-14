const express = require('express');
const { getAppointments, getAppointment, addAppointment, updateAppointment, deleteAppointment } = require('../controllers/appointment');
const { protect, authorize } = require('../middleware/auth');

const router = express.Router({ mergeParams: true });

router.get('/', protect, getAppointments);
router.get('/:id', protect, getAppointment);
router.post('/', protect, authorize('admin', 'user'), addAppointment);
router.put('/:id', protect, authorize('admin', 'user'), updateAppointment);
router.delete('/:id', protect, authorize('admin', 'user'), deleteAppointment);

module.exports = router;
