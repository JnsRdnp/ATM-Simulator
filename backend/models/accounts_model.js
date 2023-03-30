const db=require('../database');

const accounts={
    getAll:function(callback) {
        return db.query('select * from accounts;', callback);
    },
    getById:function(id, callback) {
        return db.query('select * from accounts where idaccounts=?', [id], callback);
    },
    add:function(accounts, callback) {
        return db.query('insert into accounts (balance,creditLimit,card_idcard,idowner)\
        values(?,?,?,?)',
        [accounts.balance, accounts.creditLimit,
            accounts.card_idcard,accounts.idowner],callback);
    },
    delete:function(id, callback) {
        return db.query('delete from accounts where idaccounts=?', [id], callback);
    },
    update:function(id, accounts, callback) {
        return db.query(
          'update accounts set balance=?,creditLimit=?,card_idcard=?,idowner=? where idaccounts=?',
          [accounts.balance, accounts.creditLimit,
            accounts.card_idcard, accounts.idowner,id],callback);
      }
    
};

module.exports=accounts;