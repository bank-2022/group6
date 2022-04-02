const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'pankkiuser',
  password: 'pankkipass',
  database: 'pankki'
});
module.exports = connection;