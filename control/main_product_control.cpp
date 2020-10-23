#include "control/main_product_control.h"
#include "control/layout_control.h"

MainProductControl::MainProductControl(QWidget *parent)
  : MainProductView(parent) {

    table_model = new ModelTableProduct(this);
    table_products->setModel(table_model);

    delegate_product = new DelegateProduct();
    table_products->setItemDelegate(delegate_product);

    // Resize Coluns
    QHeaderView *header = table_products->horizontalHeader();
    header->setSectionResizeMode(2, QHeaderView::Stretch);
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    table_products->setColumnWidth(0, 70);


  }

// Get Products
void MainProductControl::get_products() {
  // Clear fr_product on reload
  // QList<QWidget *> list = this->fr_product->findChildren<QWidget *>(
  //                           QString(), Qt::FindDirectChildrenOnly);

  // foreach (QWidget *w, list) {
  //   w->disconnect();
  //   w->setParent(NULL);
  //   w->deleteLater();
  // }

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
  LayoutControl *layout_control = new LayoutControl();
  LayoutControl *control = qobject_cast<LayoutControl *>(layout_control);

  table_model->set_data(data);


}


void MainProductControl::tamanho() {

}

MainProductControl::~MainProductControl() {}