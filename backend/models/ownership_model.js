const db=require('../database');

const ownership={
    getAll:function(callback) {
        return db.query('select * from ownership;'
        , callback);
    },
    getOwnership:function(id, callback) {
        return db.query('select idownership, user_iduser, account_idaccount from ownership where user_iduser=?'
        , [id], callback);
    },
    addOwnership:function(id, callback) {
        return db.query('INSERT INTO ownership (idownership, user_iduser, account_idaccount) VALUES(?,?,?',
        [id.idownership, id.user_iduser, id.account_idaccount], callback);
    }
}

module.exports=ownership;