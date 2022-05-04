const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where id_tilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT * FROM tilitapahtumat ORDER BY idTilitapahtumat DESC', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (Tapahtuma,Summa,idTili,idKortti) values(?,?,?,?)',
      [tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, tilitapahtumat.idTili, tilitapahtumat.idKortti],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('DELETE from tilitapahtumat where id_tilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set Tapahtuma=?, Summa=?, idTili, idKortti=? where id_tilitapahtumat=?',
      [tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, tilitapahtumat.idTili, tilitapahtumat.idKortti, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;