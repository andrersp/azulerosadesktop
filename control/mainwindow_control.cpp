#include "control/mainwindow_control.h"

#include <QDebug>
#include <QPushButton>

#include "model/data_user.h"
#include "model/model_login.h"

QString token="";


MainWindowControl::MainWindowControl(QWidget *parent): QMainWindow(parent){

	// view = new MainWindowView(this);
	resize(1268, 684);
	setMinimumSize(QSize(1268, 684));
	setUnifiedTitleAndToolBarOnMac(true);
	// takeCentralWidget();
	window_login();	

	
	// connect(quit2, &QAction::triggered, this, &MainWindowControl::window_layout);
	// connect(login, &QAction::triggered, this, &MainWindowControl::window_login);

}

void MainWindowControl::window_login(){
	ui_login = new LoginView(this);
	ui_login->setup_ui();
	setCentralWidget(ui_login);

	

	qDebug() << centralWidget();
	connect(ui_login->bt_login, &QPushButton::clicked, this, &MainWindowControl::login);

}

void MainWindowControl::login(){

	if (ui_login->tx_user->text().isEmpty()){
		qDebug() << "Sem USuario";
		return;
	}

	if (ui_login->tx_password->text().isEmpty()){
		qDebug() << "sem senha";
		return;
	}

	QString user{ui_login->tx_user->text()};
	QString password{ui_login->tx_password->text()};

	ModelLogin model_login(this);
	connect(&model_login, &ModelLogin::success, this, &MainWindowControl::window_layout);

	model_login.set_user(user, password);
	model_login.login();

}

void MainWindowControl::window_layout(){

	view = new LayoutControl(this);	
	
	setCentralWidget(view);

	// connect(view->bt, &QPushButton::clicked, this, &MainWindowControl::window_login);
}


void MainWindowControl::clear_widget(){
	qDebug() << "Clear widgets";
}
