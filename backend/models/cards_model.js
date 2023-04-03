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

    //the following tables use b? to signify conversion to bit datatype.
    add: function(cards, callback) {
        bcrypt.hash(cards.PINcode, saltRounds, function(error, hash){
            return db.query("insert into cards (idcard, PINcode, user_iduser, credit, debit) values (?,?,?,b?,b?)",
            [cards.id, hash, cards.idUser, cards.credit, cards.debit], callback);
        });
    },

    update: function(id, cards, callback) {
        bcrypt.hash(cards.PINcode, saltRounds, function(error, hash){
            return db.query("update cards set PINcode = ?, user_iduser = ?, credit = b?, debit = b? where idcard = ?",
            [hash, cards.idUser, cards.credit, cards.debit, id], callback);
        });
    },

    checkPin: function(cardID, callback) {
        return db.query("select PINcode from cards where idcard = ?", [cardID], callback);
    }
}

module.exports=cards;