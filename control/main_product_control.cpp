#include "control/main_product_control.h"
#include "control/layout_control.h"

MainProductControl::MainProductControl(QWidget *parent)
    : MainProductView(parent) {
  table_model = new ModelTableProduct(this);
  table_products->setModel(table_model);

  delegate_product = new DelegateProduct(table_products);
  table_products->setItemDelegate(delegate_product);

  // Resize Coluns
  QHeaderView *header = table_products->horizontalHeader();
  header->setSectionResizeMode(2, QHeaderView::Stretch);
  header->setSectionResizeMode(3, QHeaderView::Stretch);
  header->setSectionResizeMode(4, QHeaderView::ResizeToContents);
  table_products->setColumnWidth(0, 70);
  table_products->setColumnWidth(7, 140);

  // Connect Table into select product
  connect(table_products, &DefaultTable::clicked, this,
          &MainProductControl::select_product);
}

// Get Products
void MainProductControl::get_products() {
  ModelMainProduct model;

  // Connect Model signal product with this set product grid
  connect(&model, &ModelMainProduct::signal_product, this,
          &MainProductControl::set_product_grid);

  // Call Model get produtos
  model.get_products();
}

// Receive signal with Array of products
void MainProductControl::set_product_grid(const QVector<QStringList> &data) {
  // Objectcast to layout control
  table_model->set_data(data);

  for (int i = 0; i < table_model->rowCount(); i++) {
    table_products->openPersistentEditor(table_model->index(i, 1));
    table_products->openPersistentEditor(table_model->index(i, 7));
  }
}

void MainProductControl::select_product(const QModelIndex &index) {

  int col = index.column();

  if (col == 7) {
  	int id_product;
  	id_product = index.sibling(index.row(), 0).data().toInt();

  	emit signal_get_product(id_product);
  }

}

MainProductControl::~MainProductControl() {}