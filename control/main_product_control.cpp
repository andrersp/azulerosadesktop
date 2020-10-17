#include "control/main_product_control.h"


MainProductControl::MainProductControl(QWidget *parent) : MainProductView(parent){

	table_model = new ModelTableProduct(this);
	table_product->setModel(table_model);

	// Stretch Table Model Columns
	QHeaderView *header = table_product->horizontalHeader();
	header->setSectionResizeMode(1, QHeaderView::Stretch);

}

void MainProductControl::get_products(){

	ModelMainProduct model;
	connect(&model, &ModelMainProduct::signal_products, table_model, &ModelTableProduct::set_data);

	model.get_products();

	

}

void MainProductControl::tst_data(const QVector<QStringList> &itens){
	qDebug() << "teste";
	qDebug() << itens;
}

MainProductControl::~MainProductControl(){}