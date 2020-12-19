#include "control/main_product_control.h"
#include "control/layout_control.h"

MainProductControl::MainProductControl(QWidget *parent)
    : MainProductView(parent) {
  // Model
  table_model = new ModelTableProduct(this);
  // Filter
  filter = new FilterProduct(this);
  filter->setDynamicSortFilter(true);
  filter->setSourceModel(table_model);
  table_products->setModel(filter);

  delegate_product = new DelegateProduct(table_products);
  table_products->setItemDelegate(delegate_product);

  // Resize Coluns
  QHeaderView *header = table_products->horizontalHeader();
  header->setSectionResizeMode(2, QHeaderView::Stretch);
  header->setSectionResizeMode(3, QHeaderView::Stretch);
  header->setSectionResizeMode(4, QHeaderView::ResizeToContents);
  table_products->setColumnWidth(0, 70);
  table_products->setColumnWidth(7, 140);

  // Connect Filter
  connect(fr_search->tx_search, &LineEditSearch::textChanged, this,
          &MainProductControl::filter_product);

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
  connect(&model, &ModelMainProduct::signal_err, this,
          &MainProductControl::dialog_err);

  // Call Model get produtos
  model.get_products();
}

// Receive signal with Array of products
void MainProductControl::set_product_grid(const QVector<QStringList> &data) {
  // Objectcast to layout control
  table_model->set_data(data);
  // QTimer::singleShot(1, this, &MainProductControl::set_persistent);

  // set_persistent();
}

void MainProductControl::select_product(const QModelIndex &index) {
  int col = index.column();

  if (col == 7) {
    int id_product;
    id_product = index.sibling(index.row(), 0).data().toInt();

    emit signal_get_product(id_product);
  }
  fr_search->tx_search->clear();
}

void MainProductControl::filter_product(const QString &index) {
  filter->setFilterRegExp(QRegExp(index, Qt::CaseInsensitive));
  // set_persistent();
}

void MainProductControl::set_persistent() {
  for (int i = 0; i < filter->rowCount(); i++) {
    // table_products->openPersistentEditor(filter->index(i, 1));
    table_products->openPersistentEditor(filter->index(i, 7));
  }
}

void MainProductControl::dialog_err(int status, QString msg) {
  DialogMsg *dialog = new DialogMsg(this, status, msg);
  int resp = dialog->show();
}

MainProductControl::~MainProductControl() {}