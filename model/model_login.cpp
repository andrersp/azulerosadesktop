#include "model/data_user.h"
#include "model/model_login.h"
#include "model/request.h"

#include <QJsonArray>
#include <QJsonObject>

void ModelLogin::set_user(QString &user, QString &password) {
  this->user = user;
  this->password = password;
}

void ModelLogin::login() {

  ModelRequest request(this);
  QJsonObject data{{"username", user}, {"password", password}

  };

  auto [status, response] = request.post("login/", data);

  if (status) {
    QJsonObject data{response.value("data").toObject()};
    token = data.value("token").toString();
    emit success();
    return;
  }
  if (response.value("message").isObject()) {
    QString msg = "";
    foreach (const QString &key, response.keys()) {
      QJsonObject value = response.value(key).toObject();
      foreach (const QString &key2, value.keys()) {
        QJsonArray data_array = value.value(key2).toArray();

        QString error;

        for (int i = 0; i < data_array.count(); i++) {

          error = error + data_array[i].toString();
        }

        msg = msg + key2 + " - " + error + "\n";
      }
    }

    emit err(status, msg);
    return;
    
  }

  emit err(status, response.value("message").toString());

  
}

void ModelLogin::logout(){
  ModelRequest request(this);

  QJsonObject data{};

  request.post("logout/", data);
}

ModelLogin::~ModelLogin() {}
