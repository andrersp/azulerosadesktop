#pragma once

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkDiskCache>
#include <QTimer>

class ModelRequest : public QObject
{
	Q_OBJECT
public:
	explicit ModelRequest(QObject *parent = nullptr);
	~ModelRequest();

	QNetworkAccessManager *manager;
	QTimer *timer;
	QEventLoop *loop;
	// QNetworkReply *reply;
	//   QJsonObject resp;

	QString url_base{"http://azulerosapersonalizados.com.br/api/v1/admin/"};
		// QString url_base{"http://127.0.0.1:5000/api/v1/admin/"};

	std::tuple<bool, QJsonObject> post(const QString &endpoint, const QJsonObject &dados);
	std::tuple<bool, QJsonObject> put(const QString &endpoint, const QJsonObject &dados);
	std::tuple<bool, QJsonObject> GET(const QString endpoint);
	std::tuple<bool, QJsonObject> gets(const QString &url);
	std::tuple<bool, QJsonObject> DEL(const QString &endpoint);

	QByteArray get_image(const QString &url_image);

signals:
	void requestFinished(QNetworkReply *reply);

private:
	QByteArray image_data;
  QNetworkDiskCache *cache_dir;
};
