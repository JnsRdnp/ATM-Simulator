const express = require('express');
const router = express.Router();
const user = require('../models/user_model');

router.get('/',
    function (request, response) {
        users.getAll(function (error, dbResult) {
            if (error) {
                response.json(error);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        })
    });

router.get('/:id',
    function (request, response) {
        users.getById(request.params.id, function (error, dbResult) {
            if (error) {
                response.json(error);
            } else {
                response.json(dbResult);
            }
        })
    });


router.post('/', 
function(request, response) {
  users.add(request.body, function(error, dbResult) {
    if (error) {
      response.json(error);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  users.delete(request.params.id, function(error, dbResult) {
    if (error) {
      response.json(error);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  users.update(request.params.id, request.body, function(error, dbResult) {
    if (error) {
      response.json(error);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;