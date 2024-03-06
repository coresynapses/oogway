#include "db.hpp"

Db::Db(string path) {
  rc = sqlite3_open(path.c_str(), &db);

  if (rc)
    cout << "Not found: " << sqlite3_errmsg(db) << endl;
  else
    cout << "Database opened\n";
}

Db::~Db() {
  sqlite3_close(db);
}

bool Db::CheckLogin(string username, string password, string two_fa_code) {
  cout << "Username: " << username << endl;
  cout << "Password: " << password << endl;
  cout << "2FA Code: " << two_fa_code << endl;
  return true;
}
