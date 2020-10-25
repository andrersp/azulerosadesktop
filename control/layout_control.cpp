#include "control/layout_control.h"
#include "control/mainwindow_control.h"
#include "view/defaultsLabel.h"
#include "view/defaultsLineEdit.h"

LayoutControl::LayoutControl(QObject *parent) : MainWindowView(parent) {
  MainWindowControl *window = qobject_cast<MainWindowControl *>(parent);

  dashboard_frame = new DashBoardControl(this);
  DefaultLabel *label = new DefaultLabel("Teste", this->fr_top);
  DefaultLineEdit *editline = new DefaultLineEdit("Nome", this->fr_top);

  //  main Window Product
  main_product = new MainProductControl(this);
  // Connect Button new to this set_form_product_window
  connect(main_product->fr_search->button, &QPushButton::clicked,
          [=] { set_form_product_window(0); });

  // Connect signal to select product into set_form_product_window
  connect(main_product, &MainProductControl::signal_get_product, this,
          &LayoutControl::set_form_product_window);

  // Product Form

  product_form = new ProductForm(this);




  // Add Widgets into container
  container->addWidget(dashboard_frame);
  container->addWidget(main_product);
  container->addWidget(product_form);

  // Current widget container
  container->setCurrentWidget(dashboard_frame);

  // Set Checked Menu
  fr_menu->bt_home->setChecked(true);
  connect(this, &LayoutControl::dialog_msg, window,
          &MainWindowControl::dialog_err);

  connect(fr_menu->bt_home, &QPushButton::clicked, this,
          &LayoutControl::tamanho);
  connect(fr_menu->bt_product, &QPushButton::clicked, this,
          &LayoutControl::set_window_produto);
}

LayoutControl::~LayoutControl() {}

void LayoutControl::tamanho() { container->setCurrentWidget(dashboard_frame); }

// set  Main Window Product current
void LayoutControl::set_window_produto() {
  container->setCurrentWidget(main_product);
  main_product->get_products();
}

void LayoutControl::set_form_product_window(const int &product_id = 0) {
  qDebug() << product_id;
  container->setCurrentWidget(product_form);
}