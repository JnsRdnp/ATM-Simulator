const express = require('express');
const router = express.Router();
const jtw = require('jsonwebtoken');
const dotenv = require('dotenv');
const bcrypt = require('bcryptjs');
const cards = require("../models/cards_model");

router.get('/',
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

router.get('/:id',
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

router.put('/:id',
function(request, response) {
    cards.update(request.params.id, request.body, function(error, dbResult){
        if (error){
            response.json(error);
        } else {
            response.json(dbResult);
        }
    });
});

router.delete('/:id',
function(request, response) {
    cards.delete(request.params.id, function(error, dbResult) {
        if (error){
            response.json(error);
        } else {
            response.json(dbResult);
        }
    });
});

router.post('/',
function(request, response) {
    cards.add(request.body, function(error, dbResult){
        if (error){
            response.json(error);
        } else {
            response.json(dbResult);
        }
    });
});

function generateAccessToken(id) {
    dotenv.config();
    return jtw.sign(id, process.env.MY_TOKEN, { expiresIn: '200s'});
}

module.exports = router;
