const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');
const jwt = require('jsonwebtoken');

const dotenv=require('dotenv');
dotenv.config();

const indexRouter = require('./routes/index');
const usersRouter = require('./routes/user');
const accountsRouter = require('./routes/accounts');
const historyRouter = require('./routes/history');
const cardsRouter = require('./routes/cards');
const { constants } = require('fs/promises');
const ownershipRouter = require('./routes/ownership');

const app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/user', usersRouter);
app.use('/cards',cardsRouter);
app.use('/accounts',accountsRouter);
app.use('/history',historyRouter);
app.use('/ownership', ownershipRouter);

app.listen(process.env.port, function(){
    console.log("Application listens to port " + process.env.port);
});

module.exports = app;
