const dotenv = require('dotenv');
const mysql=require('mysql2');
dotenv.config();
const connection = mysql.createPool(process.env.SQL_SERVER);

module.exports=connection;