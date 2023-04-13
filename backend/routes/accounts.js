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

router.get('/:id',
function (request, response) {
    accounts.getById(request.params.id, function (err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(dbResult);
        }
    })
});

router.get('/card/:id',
function (request, response) {
    accounts.getById(request.params.id, function (err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(dbResult);
        }
    })
});

router.post('/', 
function(request, response) {
    accounts.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.delete('/:id', 
function(request, response) {
  accounts.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put('/update/:id', 
function(request, response) {
  accounts.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put('/debitWithdraw', function(request, response) {
  accounts.depitWithdraw(request.body.accountID,request.body.amount, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put('/creditWithdraw', function(request, response) {
  accounts.creditWithdraw(request.body.accountID,request.body.amount, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.get('/getBalance/:id',
function (request, response) {
    accounts.getBalance(request.params.id, function (err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(dbResult);
        }
    })
});


module.exports=router;
