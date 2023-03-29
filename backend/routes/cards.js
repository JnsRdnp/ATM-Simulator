const express = require('express');
const router = express.Router();
const cards = require("../models/cards_model");

router.get('/cards/',
function(request, response) {
  cards.getAll(function (error, dbResult) {
    if (error) {
        response.json(error);
    } else {
        console.log(dbResult);
        response.json(dbResult);
    }
  });
});

router.get('/cards/:id',
function(request, response) {
    cards.getById(request.params.id, function (error, dbResult) {
        if (error) {
            response.json(error);
        } else {
            console.log(dbResult);
            response.json(dbResult);
        }
    });
});

router.put('/cards/:id',
function(request, response) {
    cards.update(request.params.id, request.body, function(error, dbResult){
        if (error){
            response.json(error);
        } else {
            response.json(dbResult);
        }
    });
});

router.delete('/cards/:id',
function(request, response) {
    cards.delete(request.params.id, function(error, dbResult) {
        if (error){
            response.json(error);
        } else {
            response.json(dbResult);
        }
    });
});

router.post('/cards',
function(request, response) {
    cards.add(request.body, function(error, dbResult){
        if (error){
            response.json(error);
        } else {
            response.json(dbResult);
        }
    });
});

module.exports = router;
