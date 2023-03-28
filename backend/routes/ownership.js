const express = require('express');
const router = express.Router();
const onwership=require('../models/ownership_model');

router.get('/', functions(req, res, next){
res.send('message to website'+process.env.SQlserver);
});

module.exports = router;