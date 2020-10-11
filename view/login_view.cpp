#include "view/login_view.h"

void LoginView::setup_ui(){
	this->setStyleSheet("background: pink");
	grid_qw_login = new QVBoxLayout(this);
	grid_qw_login->setSpacing(0);
	grid_qw_login->setMargin(0);

	fr_login = new QFrame(this);
	fr_login->setStyleSheet("background-color: blue");

	grid_fr_login = new QVBoxLayout(fr_login);
	bt_login = new QPushButton(fr_login);
	bt_login->setText("Login");

	grid_fr_login->addWidget(bt_login);

	grid_qw_login->addWidget(fr_login);




	qDebug() << "Testando";
}

LoginView::~LoginView(){
	qDebug() << "Saindo";
}