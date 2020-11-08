#ifndef MODEL_LOGIN_H
#define MODEL_LOGIN_H

#include <QObject>

class ModelLogin : public QObject {
	Q_OBJECT
public:

	explicit ModelLogin(QObject *parent =nullptr) : QObject(parent){};
	virtual ~ModelLogin();
	void set_user(QString &user, QString &password);
public slots:
	void login();
	void logout();
private:
	QString user, password;

signals:
	void success();
	void err(int status, QString msg);


};


#endif