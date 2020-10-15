#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <QDebug>
#include <QFrame>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "view/default_widgets.h"

class LoginView : public QWidget{
	
public:
	LoginView(QObject *parent = nullptr){};
	~LoginView();

	QWidget *qw_login;
	QFrame  *fr_login, *container_login;

	QPushButton *bt_login;

	QLabel *lb_logo;

	QHBoxLayout *grid_qw_login, *grid_container_login;



	QVBoxLayout *grid_fr_login;

	LineEditIconLeft *tx_user, *tx_password;

	void setup_ui();

};

#endif