const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const cards={
    getAll:function(callback) {
        return db.query('select * from cards;', callback);
    },

    getById: function(id, callback) {
        return db.query('select * from cards where idcard=?', [id], callback);
    },

    delete: function(id, callback){
        return db.query('delete from cards where idcard = ?', [id], callback);
    },

    add: function(cards, callback) {
        bcrypt.hash(cards.PINcode, saltRounds, function(error, hash){
            //look into making a check on the credit and debit values to make sure they are either 1 or 0, making mySQL table into bit
            //does not work.
            return db.query("insert into cards (idcard, PINcode, user_iduser, credit, debit) values (?,?,?,?,?)",
            [cards.id, hash, cards.idUser, cards.credit, cards.debit], callback);
        });
    },

    update: function(id, cards, callback) {
        bcrypt.hash(cards.PINcode, saltRounds, function(error, hash){
            return db.query("update cards set PINcode = ?, user_iduser = ?, credit = ?, debit = ? where idcard = ?",
            [hash, cards.idUser, cards.credit, cards.debit, id], callback);
        });
    }
}

module.exports=cards;