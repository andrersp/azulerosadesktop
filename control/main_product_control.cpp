#include "control/main_product_control.h"

MainProductControl::MainProductControl(QWidget *parent) : MainProductView(parent){

	// table_model = new ModelTableProduct(this);
	// table_product->setModel(table_model);

	// // Stretch Table Model Columns
	// QHeaderView *header = table_product->horizontalHeader();
	// header->setSectionResizeMode(1, QHeaderView::Stretch);
	// table_product->setColumnWidth(0, 70);
	

}

void MainProductControl::get_products(){

	// qDebug() << this->fr_product->findChildren<QFrame *>();
	QList<QFrame *> list = this->fr_product->findChildren<QFrame *>();

	foreach(QFrame *w, list) {
		w->disconnect();
		w->setParent(NULL);
		w->deleteLater();
	}


	// int x = 0;
	// int y = 0;
	// for (int i=0; i < 7; i++ ){	
		
	// 	// qDebug() << i;
	// 	QString url("URL");
	// 	QString nome("Caneca Branca");
	// 	QString valor("25.00");
	// 	frame_product = new FrameProduct(url, nome, valor, 1, this);
	// 	grid->addWidget(frame_product, y, x++, 1, 1);
		
	// 	if (x == 5) {
	// 		x = 0;
	// 		y++;
	// 	}
	// }

	ModelMainProduct model;
	connect(&model, &ModelMainProduct::signal_products, this, &MainProductControl::set_products);
	model.get_products();

	

}

void MainProductControl::set_products(const QVector<QStringList> &itens){

	int x = 0;
	int y = 0;

	for (int i =0; i < itens.count(); i++){

			QString url(itens[i][5]);
			QString nome(itens[i][1]);
			QString valor(itens[i][4]);

		frame_product = new FrameProduct(url, nome, valor, 1, this);
		grid->addWidget(frame_product, y, x++, 1, 1);
		
		if (x == 5) {
			x = 0;
			y++;
		}

		if (i == 1000)
			break;

	}
}

MainProductControl::~MainProductControl(){}