#ifndef MAIN_PRODUCT_VIEW_H
#define MAIN_PRODUCT_VIEW_H

#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QJsonObject>
#include "widgets/default_widgets.h"
#include "widgets/default_table.h"



// Main Product View
class MainProductView : public QWidget {
public:
  explicit MainProductView(QWidget *parent = nullptr);
  virtual ~MainProductView();

  QFrame *fr_product;
  FrameSearch *fr_search;
  DefaultTable *table_products;

  

protected:
  QHBoxLayout *grid_search;
  QVBoxLayout *grid_main_product;
};

#endif