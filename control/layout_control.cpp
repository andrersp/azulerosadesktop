#include "control/layout_control.h"
#include "control/mainwindow_control.h"


LayoutControl::LayoutControl(QObject *parent) : MainWindowView(parent){

	MainWindowControl *window = qobject_cast<MainWindowControl *>(parent);

	// window->clear_widget();

	// connect(bt, &QPushButton::clicked, window, &MainWindowControl::clear_widget);
	// connect(bt, SIGNAL(clicked()), parent, SLOT(clear_widget()));
	connect(bt, &QPushButton::clicked, this, &LayoutControl::tamanho);
	connect(bt2, &QPushButton::clicked, this, &LayoutControl::set_window_produto);
	connect(toolbar->bt_home, &QToolButton::clicked, this, &LayoutControl::set_window_produto);

}

LayoutControl::~LayoutControl(){
	qDebug() << "Delete Layout Control";
}

void LayoutControl::tamanho(){

	// qDebug() << status_bar->size();

	container->setCurrentWidget(wd2);

}

void LayoutControl::set_window_produto(){
	container->setCurrentWidget(wd1);

}