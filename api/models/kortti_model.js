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
      'INSERT into kortti (Kortinnumero,Pin) values(?,?)',
      [kortti.Kortinnumero, kortti.Pin],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('DELETE from kortti where idKortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    return db.query(
      'UPDATE kortti set Kortinnumero=?, Pin=? where idKortti=?',
      [kortti.Kortinnumero, kortti.Pin, id],
      callback
    );
  }
};
module.exports = kortti;