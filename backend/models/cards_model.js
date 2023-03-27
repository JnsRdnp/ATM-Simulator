const db = require('../database');
const bcrypt = require('bcryptijs');

const saltRounds=20;
const cards={
    getAll: function(callback) {
        return db.query('select * from cards', callback);
    },

    getById: function(id, callback) {
        return db.query('select * from cards where idcard=?', [id], callback);
    },

    add: function(user, callback) {
        bcrypt.hash(cards.PINcode, saltRounds, function(error, hash){
            return db.query('insert into cards (idcard, PINcode) values (?,?)',
            [cards.idCard, hash], callback);
        });
    },
}