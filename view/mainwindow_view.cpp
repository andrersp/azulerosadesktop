
#include "view/mainwindow_view.h"

MainWindowView::MainWindowView(QMainWindow *mainwindow) {
	mainwindow->resize(1268, 684);
	mainwindow->setMinimumSize(QSize(1268, 684));
	

	central_widget = new QWidget();
    // central_widget->set
    central_widget->setMaximumSize(QSize(3840, 2160));

    central_grid = new QGridLayout(central_widget);
    central_grid->setSpacing(0);
    central_grid->setMargin(0);

    mainwindow->setCentralWidget(central_widget);

    status_bar = new QStatusBar(central_widget);
    status_bar->setMaximumHeight(20);
    status_bar->setMinimumHeight(20);
    status_bar->setObjectName("status_bar");
    status_bar->setSizeGripEnabled(false);
    status_bar->setContentsMargins(2, 0, 2, 0);

    mainwindow->setStatusBar(status_bar);

    QMetaObject::connectSlotsByName(mainwindow);

}
