const db=require('../database');

const ownership={
    getAll:function(callback) {
        return db.query('select * from ownership;'
        , callback);
    },
    getOwnership:function(id, callback) {
        return db.query('select idownership from ownership where user_iduser=?'
        , [id], callback);
    }
}

module.exports=ownership;