#include "control/mainwindow_control.h"
#include <QToolBar>



MainWindowControl::MainWindowControl(QWidget *parent): QMainWindow(parent){

	view = new MainWindowView(this);	

	// QToolBar *toolbar = addToolBar("main tollbar");
	// toolbar->setOrientation(Qt::Vertical);
	// toolbar->addAction("New File");
	// toolbar->addAction("TEste File");

	// view->central_grid->addWidget(toolbar, 0, 0, 1, 1);

	// QAction *quit2 = new QAction("Quit");
	// quit2->setCheckable(true);
	// toolbar->addAction(quit2);
	// connect(quit2, &QAction::triggered, this, &MainWindowControl::close);

}