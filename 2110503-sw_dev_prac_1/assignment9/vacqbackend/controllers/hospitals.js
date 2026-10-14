const Hospital = require('../models/Hospital')
const Appointment = require('../models/Appointment')

exports.getHospitals = async (req, res, next) => {
  // Exclude some fields
  console.log(req.query);
  const reqQuery = { ...req.query };
  const removeFields = ['select', 'sort'];
  removeFields.forEach(param => { delete reqQuery[param] });
  console.log(reqQuery);

  // Query operators
  let queryStr = JSON.stringify(reqQuery).replace(/\b(gt|gte|lt|lte|in)\b/g, match => `$${match}`);

  let query = Hospital.find(JSON.parse(queryStr)).populate('appointments');

  // Select fields
  if (req.query.select) {
    query = query.select(req.query.select.split(',').join(' '));
  }

  // Sort
  const sortBy = req.query.sort ? req.query.sort.split(',').join(' ') : '-createdAt';
  query = query.sort(sortBy);

  // Pagination
  const page = parseInt(req.query.page, 10) || 1;
  const limit = parseInt(req.query.limit, 10) || 25;
  const startIndex = (page - 1) * limit;
  const endIndex = page * limit;
  const total = await Hospital.countDocuments();
  query = query.skip(startIndex).limit(limit);
  const pagination = {};
  if (endIndex < total) {
    pagination.next = {
      page: page + 1,
      limit
    }
  }
  if (startIndex > 0) {
    pagination.prev = {
      page: page - 1,
      limit
    }
  }

  try {
    const hospitals = await query;
    res.status(200).json({ success: true, count: hospitals.length, pagination, data: hospitals });
  } catch (err) {
    console.log(err);
    res.status(400).json({ success: false });
  }
};
exports.getHospital = async (req, res, next) => {
  try {
    const hospital = await Hospital.findById(req.params.id).populate('appointments');
    if (!hospital) {
      res.status(400).json({ success: false });
    }
    res.status(200).json({ success: true, data: hospital });
  } catch (err) {
    res.status(400).json({ success: false });
  }
};
exports.createHospital = async (req, res, next) => {
  console.log(req.body);
  const hospital = await Hospital.create(req.body);
  res.status(201).json({ success: true, data: hospital });
};
exports.updateHospital = async (req, res, next) => {
  try {
    const hospital = await Hospital.findByIdAndUpdate(req.params.id, req.body, { new: true, runValidators: true });
    if (!hospital) {
      res.status(400).json({ success: false });
    }
    res.status(200).json({ success: true, data: hospital });
  } catch (err) {
    res.status(400).json({ success: false });
  }
};
exports.deleteHospital = async (req, res, next) => {
  try {
    const hospital = await Hospital.findById(req.params.id);
    if (!hospital) {
      res.status(404).json({
        success: false,
        message: `Hospital not found with id of ${req.params.id}`
      });
    }
    await Appointment.deleteMany({ hospital: req.params.id });
    await Hospital.deleteOne({ _id: req.params.id });
    res.status(200).json({ success: true, data: {} });
  } catch (err) {
    console.log(err);
    res.status(400).json({ success: false });
  }
};
