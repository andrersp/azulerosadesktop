#include "control/main_product_control.h"
#include <QMainWindow>
MainProductControl::MainProductControl(QWidget *parent)
  : MainProductView(parent) {

    

  // table_model = new ModelTableProduct(this);
  // table_product->setModel(table_model);

  // // Stretch Table Model Columns
  // QHeaderView *header = table_product->horizontalHeader();
  // header->setSectionResizeMode(1, QHeaderView::Stretch);
  // table_product->setColumnWidth(0, 70);

  connect(this, &MainProductControl::signal_set_product, this, &MainProductView::set_frame_product);
}

// Get Products
void MainProductControl::get_products() {

  QList<QWidget *> list = this->fr_product->findChildren<QWidget *>(
                            QString(), Qt::FindDirectChildrenOnly);

  foreach (QWidget *w, list) {
    w->disconnect();
    w->setParent(NULL);
    w->deleteLater();
  }

  ModelMainProduct model;
  connect(&model, &ModelMainProduct::signal_products, this,
          &MainProductControl::set_products);
  connect(&model, &ModelMainProduct::signal_product, this, &MainProductControl::set_product);
  model.get_products();
}

void MainProductControl::set_product(const QJsonObject &obj){
  qDebug() << obj.value("name").toString();
}

void MainProductControl::set_products(const QVector<QStringList> &itens) {

  int x = 0;
  int y = 0;

  for (int i = 0; i < itens.count(); i++) {

    QString url(itens[i][5]);
    QString nome(itens[i][1]);
    QString valor(itens[i][4]);

    frame_product = new FrameProduct(url, nome, valor, 1, fr_product);

    connect(frame_product->bt_add, &QPushButton::clicked, this, &MainProductControl::tamanho);
    emit signal_set_product(frame_product, y, x++);

    if (x == 5) {
      x = 0;
      y++;
    }

    if (i == 19)
      break;
  }
}

void MainProductControl::tamanho() {
  qDebug() << frame_product->size();
  qDebug() << fr_product->parentWidget()->parentWidget()->size();
  qDebug() << fr_product->parentWidget()->objectName();
}

MainProductControl::~MainProductControl() {}