const express = require('express');
const history = require('../models/history_model');
const router = express.Router();

router.get('/',
    function(request, response){
        history.getAll(function(error, dbResult) {
            if (error) {
                response.json(error);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        });
    });



module.exports=router;