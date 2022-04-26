const db = require('../database');

const login={
  checkPassword: function(Kortinnumero, callback) {
      return db.query('SELECT Pin FROM kortti WHERE Kortinnumero = ?',[Kortinnumero], callback); 
    }
};
          
module.exports = login;