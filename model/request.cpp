#include "model/request.h"
#include "model/data_user.h"
#include <QJsonDocument>
#include <QJsonObject>

ModelRequest::ModelRequest(QObject *parent) : QObject(parent) {
  manager = new QNetworkAccessManager(this);

  cache_dir = new QNetworkDiskCache(this);
  cache_dir->setCacheDirectory("cache");
  manager->setCache(cache_dir);
  //	manager->setNetworkAccessible(QNetworkAccessManager::Accessible);

  timer = new QTimer();
  timer->setSingleShot(true);
  loop = new QEventLoop();

  QObject::connect(timer, SIGNAL(timeout()), loop, SLOT(quit()));
  QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), loop,
                   SLOT(quit()));
}

std::tuple<bool, QJsonObject> ModelRequest::post(const QString &endpoint,
                                                 const QJsonObject &dados) {
  QString url = url_base + endpoint;
  QNetworkRequest request;
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QByteArray jsonString = "Bearer " + token.toLocal8Bit();
  request.setRawHeader("Authorization", jsonString);
  request.setUrl(QUrl(url));
  QNetworkReply *reply =
      this->manager->post(request, QJsonDocument(dados).toJson());

  timer->start(5000);
  loop->exec();
  QJsonObject data;
  bool status;
  if (timer->isActive()) {
    timer->stop();

    //		emit requestFinished(reply);
    if (reply->error() == QNetworkReply::NoError) {
      status = true;
      data = QJsonDocument::fromJson(reply->readAll()).object();
    } else {
      int status_code =
          reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

      if (status_code) {
        status = false;
        data = QJsonDocument::fromJson(reply->readAll()).object();
      } else {
        QJsonObject resp;
        resp.insert("message", reply->errorString());
        status = false;
        data = QJsonDocument(resp).object();
      }
    }
  } else {
    QJsonObject resp;
    resp.insert("message", reply->errorString());
    status = false;
    data = QJsonDocument(resp).object();
  }

  //	return
  reply->deleteLater();
  return {status, data};
}

// Get
std::tuple<bool, QJsonObject> ModelRequest::GET(const QString endpoint) {
  QString url = url_base + endpoint;
  QNetworkRequest request;
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QByteArray jsonString = "Bearer " + token.toLocal8Bit();

  request.setRawHeader("Authorization", jsonString);
  request.setUrl(QUrl(url));
  QNetworkReply *reply = this->manager->get(request);

  timer->start(5000);
  loop->exec();

  QJsonObject data;
  bool status;

  if (timer->isActive()) {
    timer->stop();

    //		emit requestFinished(reply);
    if (reply->error() == QNetworkReply::NoError) {
      status = true;
      data = QJsonDocument::fromJson(reply->readAll()).object();
    } else {
      int status_code =
          reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

      if (status_code) {
        status = false;
        data = QJsonDocument::fromJson(reply->readAll()).object();
      } else {
        QJsonObject resp;
        resp.insert("message", reply->errorString());
        status = false;
        data = QJsonDocument(resp).object();
      }
    }
  } else {
    QJsonObject resp;
    resp.insert("message", reply->errorString());
    status = false;
    data = QJsonDocument(resp).object();
  }

  //	return
  reply->deleteLater();
  return {status, data};
}

// Get
std::tuple<bool, QJsonObject> ModelRequest::gets(const QString &url) {
  QNetworkRequest request;
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  request.setUrl(QUrl(url));
  QNetworkReply *reply = this->manager->get(request);

  timer->start(5000);
  loop->exec();

  QJsonObject data;
  bool status;

  if (timer->isActive()) {
    timer->stop();

    //		emit requestFinished(reply);
    if (reply->error() == QNetworkReply::NoError) {
      status = true;
      data = QJsonDocument::fromJson(reply->readAll()).object();
    } else {
      int status_code =
          reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

      if (status_code) {
        status = false;
        data = QJsonDocument::fromJson(reply->readAll()).object();
      } else {
        QJsonObject resp;
        resp.insert("message", reply->errorString());
        status = false;
        data = QJsonDocument(resp).object();
      }
    }
  } else {
    QJsonObject resp;
    resp.insert("message", reply->errorString());
    status = false;
    data = QJsonDocument(resp).object();
  }

  //	return
  reply->deleteLater();
  return {status, data};
}

QByteArray ModelRequest::get_image(const QString &url_image) {

  QNetworkRequest request;
  request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);

  request.setUrl(QUrl(url_image));

  QNetworkReply *reply = this->manager->get(request);
  timer->start(5000);
  loop->exec();

  if (timer->isActive()) {
    timer->stop();
    if (reply->error() == QNetworkReply::NoError) {
    //   QVariant fromCache = reply->attribute(QNetworkRequest::SourceIsFromCacheAttribute);
    // qDebug() << "page from cache?" << fromCache.toBool();
      image_data = reply->readAll();
    }
  }

  return image_data;
}

std::tuple<bool, QJsonObject> ModelRequest::DEL(const QString &endpoint) {
  QString url = url_base + endpoint;
  QNetworkRequest request;
  // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QByteArray jsonString = "Bearer " + token.toLocal8Bit();

  request.setRawHeader("Authorization", jsonString);
  request.setUrl(QUrl(url));
  QNetworkReply *reply = this->manager->deleteResource(request);

  timer->start(5000);
  loop->exec();

  QJsonObject data;
  bool status;

  if (timer->isActive()) {
    timer->stop();

    //		emit requestFinished(reply);
    if (reply->error() == QNetworkReply::NoError) {
      status = true;
      data = QJsonDocument::fromJson(reply->readAll()).object();
    } else {
      int status_code =
          reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

      if (status_code) {
        status = false;
        data = QJsonDocument::fromJson(reply->readAll()).object();
      } else {
        QJsonObject resp;
        resp.insert("message", reply->errorString());
        status = false;
        data = QJsonDocument(resp).object();
      }
    }
  } else {
    QJsonObject resp;
    resp.insert("message", reply->errorString());
    status = false;
    data = QJsonDocument(resp).object();
  }

  //	return
  reply->deleteLater();
  return {status, data};
}

ModelRequest::~ModelRequest() { }
