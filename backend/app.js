const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');

const dotenv=require('dotenv');
dotenv.config();

const ownershipRouter = require('./routes/ownership');
const indexRouter = require('./routes/index');
const usersRouter = require('./routes/user');
const { constants } = require('fs/promises');

const app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);

app.use('/ownership', ownershipRouter);

app.listen(process.env.port, function(){
    console.log("Application listens to port " + process.env.port);
});

module.exports = app;
