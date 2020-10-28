#include "view/main_product_view.h"
#include <QDebug>
#include "model/request.h"
#include "view/customshadow.h"



MainProductView::MainProductView(QWidget *parent) : QWidget(parent) {
  grid_main_product = new QVBoxLayout(this);
  grid_main_product->setSpacing(20);
  grid_main_product->setMargin(20);

  fr_search = new FrameSearch("Produtos", this);

  grid_main_product->addWidget(fr_search);

  table_products = new DefaultTable(this);
  table_products->verticalHeader()->setDefaultSectionSize(80);
  table_products->setSelectionMode(QAbstractItemView::NoSelection);
  grid_main_product->addWidget(table_products);

  
  // grid->setAlignment(Qt::AlignTop);

  
}


MainProductView::~MainProductView() {}