#ifndef MAIN_PRODUCT_CONTROL_H
#define MAIN_PRODUCT_CONTROL_H
#include <QJsonObject>
#include "model/model_main_product.h"
#include "view/main_product_view.h"

class MainProductControl : public MainProductView {
  Q_OBJECT
 public:
  MainProductControl(QWidget *parent = nullptr);
  virtual ~MainProductControl();
 public slots:
  void get_products();
  void set_product_grid(const QVector<QStringList> &data);
  
private:
	ModelTableProduct *table_model;
	DelegateProduct *delegate_product;
	FilterProduct *filter;
	void select_product(const QModelIndex &index);
	void filter_product(const QString &index);
	void set_persistent();

signals:
	void signal_get_product(int &id);
};

#endif