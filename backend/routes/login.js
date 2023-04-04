const express = require('express');
const router = express.Router();
const jtw = require('jsonwebtoken');
const dotenv = require('dotenv');
const bcrypt = require('bcryptjs');
const login = require("../models/login_model");

//Original source: https://peatutor.com/express/Examples/webtoken.php, refactored by Saku Roininen
router.post('/login',
function(request, response) {
    if(!(request.body.cardID && request.body.PINcode)){
        console.log("username or password missing");
        response.send(false);
    }
    const user = request.body.cardID;
    const pass = request.body.PINcode;
        
    login.checkPin(user, function(dbError, dbResult) {
        if(dbError){
            response.json(dbError);
        }
        if (!(dbResult.length > 0)) {
            console.log("user does not exists");
            response.send(false);
        }
        bcrypt.compare(pass,dbResult[0].PINcode, function(error,compareResult) {
            if(!compareResult) {
                console.log("wrong password");
                response.send(false);
            }
            console.log("succes");
            const token = generateAccessToken({ cardID: user });
            response.send(token);			
        });
    });
});

function generateAccessToken(id) {
    dotenv.config();
    return jtw.sign(id, process.env.MY_TOKEN, { expiresIn: '200s'});
}

module.exports = router;