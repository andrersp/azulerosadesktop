#include "control/mainwindow_control.h"

#include <QDebug>
#include <QPushButton>


MainWindowControl::MainWindowControl(QWidget *parent): QMainWindow(parent){

	// view = new MainWindowView(this);
	resize(1268, 684);
	setMinimumSize(QSize(1268, 684));
	setUnifiedTitleAndToolBarOnMac(true);
	// takeCentralWidget();
	window_layout();	

	
	// connect(quit2, &QAction::triggered, this, &MainWindowControl::window_layout);
	// connect(login, &QAction::triggered, this, &MainWindowControl::window_login);

}

void MainWindowControl::window_login(){
	ui_login = new LoginView(this);
	ui_login->setup_ui();
	// view->central_grid->addWidget(ui_login->qw_login);
	// removeToolBar(view->toolbar);

	setCentralWidget(ui_login);
	qDebug() << centralWidget();
	connect(ui_login->bt_login, &QPushButton::clicked, this, &MainWindowControl::window_layout);
}

void MainWindowControl::window_layout(){

	view = new LayoutControl(this);	
	
	setCentralWidget(view);

	// connect(view->bt, &QPushButton::clicked, this, &MainWindowControl::window_login);
}


void MainWindowControl::clear_widget(){
	qDebug() << "Clear widgets";
}
