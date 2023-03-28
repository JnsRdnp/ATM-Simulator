const db=require('../database');

const accounts={
    getAll:function(callback) {
        return db.query('select * from accounts;'
        , callback);
    }
};

module.exports=accounts;