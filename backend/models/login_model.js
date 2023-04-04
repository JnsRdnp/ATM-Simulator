const db = require('../database');

const login = {
    checkPin: function(cardID, callback) {
        return db.query("select PINcode from cards where idcard = ?", [cardID], callback);
    }
}

module.exports=login;