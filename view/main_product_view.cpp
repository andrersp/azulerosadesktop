#include "view/main_product_view.h"

MainProductView::MainProductView(QWidget *parent): QFrame(parent){

	grid = new QGridLayout(this);
	grid->setMargin(20);

	table_product = new DefaultTable(this);
	grid->QLayout::addWidget(table_product);

}

MainProductView::~MainProductView(){}