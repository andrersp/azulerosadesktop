#include "control/layout_control.h"
#include "control/mainwindow_control.h"

LayoutControl::LayoutControl(QObject *parent) : MainWindowView(parent) {
  MainWindowControl *window = qobject_cast<MainWindowControl *>(parent);

  dashboard_frame = new DashBoardControl(this); 

  //  main Window Product
  main_product = new MainProductControl(this);
  // Connect Button new to this set_form_product_window
  connect(main_product->fr_search->button, &QPushButton::clicked,
          [=] { set_form_product_window(0); });

  // Connect signal to select product into set_form_product_window
  connect(main_product, &MainProductControl::signal_get_product, this,
          &LayoutControl::set_form_product_window);

  
  // ** Product Form
  product_form = new ProductFormControl(this);
  connect(product_form->bt_cancel, &QPushButton::clicked, this, &LayoutControl::set_window_produto);




  // Add Widgets into container
  container->addWidget(dashboard_frame);
  container->addWidget(main_product);
  container->addWidget(product_form);

  // Current widget container
  // container->setCurrentWidget(dashboard_frame);
  set_dashboard_widow();

  // Set Checked Menu current dashboard
  fr_menu->bt_home->setChecked(true);



  // Layout Connects
  connect(this, &LayoutControl::dialog_msg, window,
          &MainWindowControl::dialog_err);

  connect(fr_menu->bt_home, &QPushButton::clicked, this,
          &LayoutControl::set_dashboard_widow);
  connect(fr_menu->bt_product, &QPushButton::clicked, this,
          &LayoutControl::set_window_produto);
}



// Set DhashBoard Window
void LayoutControl::set_dashboard_widow() { 
  container->setCurrentWidget(dashboard_frame); 
}

// set  Main Window Product current
void LayoutControl::set_window_produto() {
  container->setCurrentWidget(main_product);
  main_product->get_products();
}


// Set Form Product Current or Select Product to edit
void LayoutControl::set_form_product_window(const int &product_id = 0) {

  erase_form(product_form);  // Erase line edit
  if (product_id)
    product_form->tx_id->setText(QString::number(product_id));
  product_form->get_selects();
  container->setCurrentWidget(product_form);
}

void LayoutControl::erase_form(QWidget *widget) {

  QList<QLineEdit *>  lineedits = widget->findChildren<QLineEdit *>();
  foreach(const auto &wid, lineedits) {
    wid->clear();
  }
}



LayoutControl::~LayoutControl() {}