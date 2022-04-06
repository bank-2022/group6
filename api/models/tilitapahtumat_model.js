const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where id_tilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (PaivajaAika,Tapahtuma,Summa) values(?,?,?)',
      [tilitapahtumat.PaivajaAika, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('DELETE from tilitapahtumat where id_tilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set Paiva_ja_Aika=?,Tapahtuma=?, Summa=? where id_tilitapahtumat=?',
      [tilitapahtumat.PaivajaAika, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;