#include "control/layout_control.h"
#include "control/mainwindow_control.h"


LayoutControl::LayoutControl(QObject *parent) : MainWindowView(parent){

	MainWindowControl *window = qobject_cast<MainWindowControl *>(parent);
	
	dashboard_frame = new DashBoardControl(this); 

	main_product = new MainProductControl(this);



	// Add Widgets into container
	container->addWidget(dashboard_frame);
	container->addWidget(main_product);

	// Current widget container
	container->setCurrentWidget(dashboard_frame);

	// Set Checked Menu
	fr_menu->bt_home->setChecked(true);

	// window->clear_widget();

	// connect(bt, &QPushButton::clicked, window, &MainWindowControl::clear_widget);
	// connect(bt, SIGNAL(clicked()), parent, SLOT(clear_widget()));
	connect(this, &LayoutControl::dialog_msg, window, &MainWindowControl::dialog_err);
	// connect(bt, &QPushButton::clicked, this, &LayoutControl::tamanho);
	// connect(bt2, &QPushButton::clicked, this, &LayoutControl::set_window_produto);
	// connect(toolbar->bt_home, &QToolButton::clicked, this, &LayoutControl::set_window_produto);
	connect(fr_menu->bt_home, &QPushButton::clicked, this, &LayoutControl::tamanho);
	connect(fr_menu->bt_product, &QPushButton::clicked, this, &LayoutControl::set_window_produto);

}

LayoutControl::~LayoutControl(){}

void LayoutControl::tamanho(){
	container->setCurrentWidget(dashboard_frame);
	


}


// set  Main Window Product current 
void LayoutControl::set_window_produto(){
	container->setCurrentWidget(main_product);
	main_product->get_products();
}