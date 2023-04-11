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

router.get('/getPage/:accountID/:amount/:page',
    function(request, response) {
      history.getPage(request.params.accountID, request.params.amount, request.params.page, function(error, dbResult) {
        if(error){
          response.json(error);
        } else {
          //response.json(dbResult[0]);

          const formattedResults = dbResult[0].map(function(result) {
          const date = new Date(result.date);
          
          //with toLocaleString js does not automatically change the timezone
          const formattedDate = date.toLocaleString();
          return Object.assign({}, result, { date: formattedDate });
          });
          response.json(formattedResults);
      }
    });
  });

router.delete('/:id', 
    function(request, response) {
      history.delete(request.params.id, function(error, dbResult) {
        if (error) {
          response.json(error);
        } else {
          response.json(dbResult);
        }
      });
    });
    
module.exports=router;