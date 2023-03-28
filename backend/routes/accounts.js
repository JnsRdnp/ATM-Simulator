const express = require('express');
const accounts = require('../models/accounts_model');
const router = express.Router();

router.get('/',
    function(request, response){
        accounts.getAll(function(error, dbResult) {
            if (error) {
                response.json(error);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        });
    });

module.exports=router;
