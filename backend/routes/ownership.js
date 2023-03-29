const express = require('express');
const router = express.Router();
const onwership=require('../models/ownership_model');

router.get('/',function(request,response){
    user.getAll(function(error, dbresult){
        if (error){
            response.json(error);
        }
        else{
            response.json(dbresult);
        }
    })
});
module.exports = router;