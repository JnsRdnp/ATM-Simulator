const db = require('../database');
const bcrypt = require('bcryptijs');

const saltrounds=20;
const cards={
    getAll: function(callback) {
        return db.query('select * from user_table' callback);
    }
}