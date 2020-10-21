#ifndef MAIN_PRODUCT_VIEW_H
#define MAIN_PRODUCT_VIEW_H

#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include "view/default_widgets.h"


class FrameProduct : public QFrame {
  Q_OBJECT
public:
  explicit FrameProduct(QString &url_image, QString &name, QString &value,
                        int id, QWidget *parent = nullptr);
  virtual ~FrameProduct();

  QString name;
  QPushButton *bt_add;

private:
  QGridLayout *grid;
  QLabel *lb_name, *lb_value, *lb_id, *lb_cover, *lb_category, *lb_qtde, *label;


private slots:
  void set_cover(QString &url);
};

class MainProductView : public QWidget {
public:
  explicit MainProductView(QWidget *parent = nullptr);
  virtual ~MainProductView();

  QFrame *fr_product;
  FrameSearch *fr_search;

  FrameProduct *frame_product;
  void set_frame_product(QWidget *frame, int x, int y);

protected:
  QGridLayout *grid;
  QHBoxLayout *grid_search;
  QVBoxLayout *grid_main_product;
  

private:
  QScrollArea *scroll;
};

#endif