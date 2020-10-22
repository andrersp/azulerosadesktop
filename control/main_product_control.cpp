#include "control/main_product_control.h"
#include "control/layout_control.h"

MainProductControl::MainProductControl(QWidget *parent)
  : MainProductView(parent) {}

// Get Products
void MainProductControl::get_products() {
  // Clear fr_product on reload
  QList<QWidget *> list = this->fr_product->findChildren<QWidget *>(
                            QString(), Qt::FindDirectChildrenOnly);

  foreach (QWidget *w, list) {
    w->disconnect();
    w->setParent(NULL);
    w->deleteLater();
  }

  ModelMainProduct model;

  // Connect Model signal product with this set product grid
  connect(&model, &ModelMainProduct::signal_product, this,
          &MainProductControl::set_product_grid);

  // Call Model get produtos
  model.get_products();
}

// Receive signal with Array of products
void MainProductControl::set_product_grid(const QJsonArray &data_array) {

  // Objectcast to layout control
  LayoutControl *layout_control = new LayoutControl();
  LayoutControl *control = qobject_cast<LayoutControl *>(layout_control);

  // value for grid in fr_product
  int x = 0, y = 0;

  

  foreach (const QJsonValue &value, data_array) {
    QJsonObject obj = value.toObject();

    frame_product = new FrameProduct(fr_product);
    frame_product->set_data(obj);
    // Connect send_id_product frame_product to control set_form_product
    connect(frame_product, &FrameProduct::send_product_id, control, &LayoutControl::set_form_product_window);

    // Send signal to insert product into grid
    set_frame_product(frame_product, y, x++);

    if (x == 5) {
      x = 0;
      y++;
    }
  }
}


void MainProductControl::tamanho() {
  qDebug() << frame_product->size();
  qDebug() << fr_product->parentWidget()->parentWidget()->size();
  qDebug() << fr_product->parentWidget()->objectName();
}

MainProductControl::~MainProductControl() {}