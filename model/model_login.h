#ifndef MODEL_LOGIN_H
#define MODEL_LOGIN_H

#include <QObject>
#include <QDebug>
class ModelLogin : public QObject {
	Q_OBJECT
public:

	explicit ModelLogin(QObject *parent =nullptr) : QObject(parent){};
	virtual ~ModelLogin();
	void set_user(QString &user, QString &password);

	void login();
private:
	QString user, password;

signals:
	void success();
	void err(bool &status, QString &msg);


};


#endif