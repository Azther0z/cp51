const Appointment = require('../models/Appointment')
const Hospital = require('../models/Hospital')

exports.getAppointments = async (req, res, next) => {
  let query;
  if (req.user.role !== 'admin') {
    query = Appointment.find({ user: req.user.id })
  } else {
    if (req.params.hospitalId) {
      query = Appointment.find({ hospital: req.params.hospitalId });
    } else {
      query = Appointment.find();
    }
  }
  query = query.populate({
    path: 'hospital',
    select: 'name province tel'
  });
  try {
    const appointments = await query;
    return res.status(200).json({
      success: true,
      count: appointments.length,
      data: appointments
    });
  }
  catch (error) {
    console.log(error);
    return res.status(500).json({
      success: false,
      message: "Cannot find appointment"
    });
  }
}

exports.getAppointment = async (req, res, next) => {
  try {
    const appointment = await Appointment.findById(req.params.id).populate({
      path: 'hospital',
      select: 'name description tel'
    });
    if (!appointment) {
      return res.status(404).json({
        success: false,
        message: `No appointment with the id of ${req.params.id}`
      });
    }
    return res.status(200).json({
      success: true,
      data: appointment
    });
  }
  catch (error) {
    console.log(error);
    return res.status(500).json({
      sucess: false,
      message: "Cannot find appointment"
    });
  }
}

exports.addAppointment = async (req, res, next) => {
  try {
    req.body.hospital = req.params.hospitalId;
    req.body.user = req.user.id;

    // If the user is not admin, they can only create at most 3 appointments
    const existedAppointments = await Appointment.find({ user: req.user.id });
    if (existedAppointments.length >= 3 && req.user.role !== 'admin') {
      return res.status(400).json({
        success: false,
        message: `The user with ID ${req.user.id} already made 3 appointments`
      });
    }

    const hospital = await Hospital.findById(req.params.hospitalId);
    if (!hospital) {
      return res.status(404).json({
        success: false,
        message: `No hospital with the id of ${req.params.hospitalId}`
      });
    }
    const appointment = await Appointment.create(req.body);
    return res.status(201).json({
      success: true,
      data: appointment
    });
  }
  catch (error) {
    console.log(error);
    return res.status(500).json({
      success: false,
      message: "Cannot create Appointment"
    });
  }
}

exports.updateAppointment = async (req, res, next) => {
  try {
    let appointment = await Appointment.findById(req.params.id);
    if (!appointment) {
      return res.status(404).json({
        success: false,
        message: `No appointment with id of ${req.params.id}`
      });
    }

    // Only owner or admin can update
    if (appointment.user.toString() !== req.user.id && req.user.role !== 'admin') {
      return res.status(401).json({
        success: false,
        message: `User ${req.user.id} is not authorized to update this appointment`
      });
    }

    appointment = await Appointment.findByIdAndUpdate(req.params.id, req.body, {
      new: true,
      runValidators: true
    });
    res.status(200).json({
      success: true,
      data: appointment
    });
  } catch (error) {
    console.log(error);
    res.status(500).json({
      success: false,
      message: `Cannot update to Appointment`
    });
  }
};
exports.deleteAppointment = async (req, res, next) => {
  try {
    const appointment = await Appointment.findById(req.params.id);
    if (!appointment) {
      return res.status(404).json({
        success: false,
        message: `Appointment not found with id of ${req.params.id}`
      });
    }

    // Only owner or admin can delete
    if (appointment.user.toString() !== req.user.id && req.user.role !== 'admin') {
      return res.status(401).json({
        success: false,
        message: `User ${req.user.id} is not authorized to delete this appointment`
      });
    }

    await appointment.deleteOne();
    res.status(200).json({ success: true, data: {} });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      success: false,
      message: "Cannot delete appointment"
    });
  }
};
