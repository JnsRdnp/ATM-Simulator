const mysql=require('mysql2');

const connection = mysql.createPool(process.env.mysqlString);

module.exports=connection;