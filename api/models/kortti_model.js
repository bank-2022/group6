const db = require('../database');

const kortti = {
  getById: function(id, callback) {
    return db.query('SELECT * from kortti where idKortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT * from kortti', callback);
  },
  add: function(kortti, callback) {
    return db.query(
      'INSERT into kortti (Kortinnumero,Pin, idAsiakas, idTili) values(?,?,?,?)',
      [kortti.Kortinnumero, kortti.Pin, kortti.idAsiakas, kortti.idTili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('DELETE from kortti where idKortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    return db.query(
      'UPDATE kortti set Kortinnumero=?, Pin=?, idAsiakas=?, idTili=? where idKortti=?',
      [kortti.Kortinnumero, kortti.Pin, kortti.idAsiakas, kortti.idTili, id],
      callback
    );
  }
};
module.exports = kortti;