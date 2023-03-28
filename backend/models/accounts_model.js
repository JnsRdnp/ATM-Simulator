const db=require('../database');

const accounts={
    getAll:function(callback) {
        return db.query('select * from accounts;', callback);
    },
    getById:function(id, callback) {
        return db.query('select * from accounts where idaccounts=?', [id], callback);
    }

    
};

module.exports=accounts;