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
        return db.query('insert into ownership (idownership, user_iduser, account_idaccount) values (?,?,?);', [id.idownership, id.user_iduser, id.account_idaccount], callback);
    },

    deleteOwnership:function(id, callback) {
        return db.query('delete from ownership where idownership=?',
        [id], callback);
    },
    updateOwnership:function(id, idownership,callback) {
        return db.query('UPDATE idownership SET idownership=?, user_iduser=?, account_idaccount=? WHERE idownership=?'
        , [idownership.idownership, idownership.user_iduser, idownership.account_idaccount, id], callback);
    }
};

module.exports=ownership;