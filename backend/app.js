const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');

const dotenv=require('dotenv');
dotenv.config();

const indexRouter = require('./routes/index');
const usersRouter = require('./routes/user');
const accountsRouter = require('./routes/accounts');
const { constants } = require('fs/promises');

const app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/cards',cardsRouter);
app.use('/users', usersRouter);
app.use('/accounts',accountsRouter);

app.listen(process.env.port, function(){
    console.log("Application listens to port " + process.env.port);
});

module.exports = app;
