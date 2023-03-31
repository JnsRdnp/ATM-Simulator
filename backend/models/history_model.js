const db=require('../database');


history={

    getAll:function(callback) {
        return db.query('select * from history;', callback);
    }

};


module.exports=history;