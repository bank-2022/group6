const db = require('../database');

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where id_kortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    return db.query(
      'insert into kortti (idKortti,Kortinnumero,Pin) values(?,?,?)',
      [kortti.idKortti, kortti.Kortinnumero, kortti.Pin],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where id_kortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    return db.query(
      'update kortti set idKortti=?,Kortinnumero=?, Pin=? where id_kortti=?',
      [kortti.idKortti, kortti.Kortinnumero, kortti.Pin, id],
      callback
    );
  }
};
module.exports = kortti;