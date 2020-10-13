#include "view/login_view.h"

void LoginView::setup_ui(){
	
	setObjectName("window_login");
	grid_qw_login = new QVBoxLayout(this);
	grid_qw_login->setSpacing(0);
	grid_qw_login->setMargin(0);

	fr_login = new QFrame(this);
	fr_login->setFixedSize(QSize(350, 500));
	fr_login->setStyleSheet("background-color: blue");

	grid_fr_login = new QVBoxLayout(fr_login);
	bt_login = new QPushButton(fr_login);
	bt_login->setText("Login");

	grid_fr_login->addWidget(bt_login);

	grid_qw_login->addWidget(fr_login, 0, Qt::AlignCenter);




	qDebug() << "Testando";
}

LoginView::~LoginView(){
	qDebug() << "Saindo";
}