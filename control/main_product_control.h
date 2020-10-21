#ifndef MAIN_PRODUCT_CONTROL_H
#define MAIN_PRODUCT_CONTROL_H
#include "view/main_product_view.h"
#include "model/model_main_product.h"

class MainProductControl : public MainProductView {
  Q_OBJECT
public:
  explicit MainProductControl(QWidget *parent = nullptr);
  virtual ~MainProductControl();
public slots:
  void get_products();
  void set_products(const QVector<QStringList> &itens) ;
  void set_product(const QJsonObject &obj);
  void tamanho();
private:
	ModelTableProduct *table_model;

signals:
	void signal_set_product(QWidget *frame, int x, int y);

};

#endif