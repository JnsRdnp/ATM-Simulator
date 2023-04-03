const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=20;
const cards={
    getAll:function(callback) {
        return db.query('select * from cards;', callback);
    },

    getById: function(id, callback) {
        return db.query('select * from cards where idcard=?', [id], callback);
    },

    add: function(callback) {
        bcrypt.hash(cards.PINcode, saltRounds, function(error, hash){
            return db.query('insert into cards (idcard, PINcode, user_iduser, credit, debit) values (?,?,?,?,?)',
            [id, hash, cards.idUser, cards.credit, cards.debit], callback);
        });
    },

    delete: function(id, callback){
        return db.query('delete from cards where idcard = ?', [id], callback);
    },

    update: function(id, user, callback) {
        bcrypt.hash(cards.PINcode, saltRounds, function(error, hash){
            return db.query('update cards set PINcode = ?, user_iduser = ?, credit = ?, debit = ? where idcard = ?) values (?,?,?,?,?)',
            [hash, cards.idUser, cards.credit, cards.debit, id], callback);
        });
    }
}

module.exports=cards;