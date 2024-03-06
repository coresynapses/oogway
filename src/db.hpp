#include <bits/stdc++.h>

#include <QObject>
#include <QQuickItem>

#include <sqlite3.h>
#include <sodium.h>
#include <cryptopp/rsa.h>

#include <boost/asio.hpp>
#include <boost/beast.hpp>

using namespace std;

// class Db : public QQuickItem {
class Db : public QObject {

  Q_OBJECT
  QML_ELEMENT
  QML_SINGLETON

public:
  Db(string path);
  ~Db();

  Q_INVOKABLE bool CheckLogin(string username, string password, string two_fa_code);

private:
  sqlite3* db;
  int rc;
};
