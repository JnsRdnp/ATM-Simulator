const express = require('express');
const router = express.Router();
const user = require('../models/user_model');

router.get('/user/',
    function (request, response) {
        user.getAll(function (error, dbResult) {
            if (error) {
                response.json(error);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        })
    });

router.get('/user/:id',
    function (request, response) {
        user.getById(request.params.id, function (error, dbResult) {
            if (error) {
                response.json(error);
            } else {
                response.json(dbResult);
            }
        })
    });


router.post('/user/', 
function(request, response) {
  user.add(request.body, function(error, dbResult) {
    if (error) {
      response.json(error);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/user/:id', 
function(request, response) {
  user.delete(request.params.id, function(error, dbResult) {
    if (error) {
      response.json(error);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/user/:id', 
function(request, response) {
  user.update(request.params.id, request.body, function(error, dbResult) {
    if (error) {
      response.json(error);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;