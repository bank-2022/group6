const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const kortti = {
  getById: function(id, callback) {
    return db.query('SELECT * from kortti where idKortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT * from kortti', callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.Pin, saltRounds, function(err,
    hash) {
      return db.query(
        'INSERT into kortti (Kortinnumero,Pin,idAsiakas,idTili) values(?,?,?,?)',
        [kortti.Kortinnumero, hash, kortti.idAsiakas, kortti.idTili],
        callback
      ) ;
    })
  },

  delete: function(id, callback) {
    return db.query('DELETE from kortti where idKortti=?', [id], callback);
  },

  update: function(id,kortti, callback) {
    bcrypt.hash(kortti.Pin, saltRounds, function(err,
    hash) {
      return db.query(
        'UPDATE kortti set Kortinnumero=?,Pin=?,idAsiakas=?,idTili=? where idKortti=?',
        [kortti.Kortinnumero, hash, kortti.idAsiakas, kortti.idTili ,id],
        callback
      ) ;
    })
  },
  
};
module.exports = kortti;