const db=require('../database');


history={

    getAll:function(callback) {
        return db.query('select * from history;', callback);
    },
    delete:function(id, callback) {
        return db.query('delete from history where idhistory=?', [id], callback);
    }
};


module.exports=history;