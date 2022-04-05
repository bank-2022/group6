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
      'insert into tilitapahtumat (paiva_ja_aika,tapahtuma,summa,kortti_idkortti) values(?,?,?,?)',
      [tilitapahtumat.paiva_ja_aika, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.kortti_idkortti],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where id_tilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set paiva_ja_aika=?,tapahtuma=?, summa=?, kortti_idkortti=? where id_tilitapahtumat=?',
      [tilitapahtumat.paiva_ja_aika, tilitapahtumat.tapahtuma, tilitapahtumat.summa, tilitapahtumat.kortti_idkortti, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;