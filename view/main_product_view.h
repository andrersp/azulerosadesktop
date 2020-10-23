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
#include "view/default_widgets.h"
#include "view/default_table.h"


class FrameProduct : public QFrame {
  Q_OBJECT
public:
  explicit FrameProduct(QWidget *parent = nullptr);
  virtual ~FrameProduct();

  QString name;
  QPushButton *bt_add;
  int product_id;

private:
  QGridLayout *grid;
  QLabel *lb_name, *lb_value, *lb_id, *lb_cover, *lb_category, *lb_qtde, *label;
  QString product_name, product_category, product_value, qtde_available,
      url_image;


 private slots:
  void set_cover(QString &url);
public slots:
  void set_data(QJsonObject &obj);
signals:
  void send_product_id(int &produc_id);
};


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
  

private:
  QScrollArea *scroll;
};

#endif