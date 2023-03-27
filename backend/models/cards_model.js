const db = require('../database');
const bcrypt = require('bcryptijs');

const saltrounds=20;
const cards={
    getAll: function(callback) {
        return db.query('select * from cards' callback);
    },

    getById: function(id, callback) {
        return db.query('select * from cards where idcard=?', [id], callback)
    },
}