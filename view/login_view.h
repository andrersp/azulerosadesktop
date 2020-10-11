#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <QDebug>
#include <QFrame>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class LoginView : public QWidget{
	
public:
	LoginView(QObject *parent = nullptr){};
	~LoginView();

	QWidget *qw_login;
	QFrame  *fr_login;

	QPushButton *bt_login;

	QVBoxLayout *grid_qw_login, *grid_fr_login;

	void setup_ui();

};

#endif