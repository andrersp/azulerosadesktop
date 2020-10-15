#include "model/model_login.h"
#include "model/request.h"
#include "model/data_user.h"

#include <QJsonObject>


void ModelLogin::set_user(QString &user, QString &password) {
	this->user = user;
	this->password = password;
}

void ModelLogin::login(){
	qDebug() << user << password;

	ModelRequest request(this);

	QJsonObject data{
		{"username", user},
		{"password", password}

	};

	auto [status, response] = request.post("user/login", data);

	if (status)
	{
		QJsonObject data{response.value("data").toObject()};
		token = data.value("token").toString();
		emit success();


	}

	
}

ModelLogin::~ModelLogin(){
	qDebug() << "Delete Login";
}

