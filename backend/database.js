const dotenv = require('dotenv');
const mysql=require('mysql2');

dotenv.config();

const connection = mysql.createPool(process.env.mysqlString);

module.exports=connection;