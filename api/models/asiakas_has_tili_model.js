const db = require('../database');

const Asiakas_has_Tili = {
  getById: function(id, callback) {
    return db.query('select * from Asiakas_has_Tili where idAsiakas_has_Tili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from Asiakas_has_Tili', callback);
  },
  add: function(Asiakas_has_Tili, callback) {
    return db.query(
      'insert into Asiakas_has_Tili (idAsiakas,idTili) values(?,?)',
      [Asiakas_has_Tili.idAsiakas, Asiakas_has_Tili.idTili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Asiakas_has_Tili where idAsiakas_has_Tili=?', [id], callback);
  },
  update: function(id, Asiakas_has_Tili, callback) {
    return db.query(
      'update Asiakas_has_Tili set idAsiakas=?,idTili=? where id_Asiakas_has_Tili=?',
      [Asiakas_has_Tili.idAsiakas, Asiakas_has_Tili.idTili, id],
      callback
    );
  }
};
module.exports = Asiakas_has_Tili;