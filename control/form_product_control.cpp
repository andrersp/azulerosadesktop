#include "control/form_product_control.h"
#include <QDebug>
ProductFormControl::ProductFormControl(QWidget *parent) : ProductForm(parent) {

  model_provider = new ModelCompleter(this);
  tb_providers->setModel(model_provider);
  // Tb Provider
  tb_providers->setColumnHidden(0, true);
  tb_providers->setFocusPolicy(Qt::NoFocus);
  QHeaderView *header = tb_providers->horizontalHeader();
  header->setSectionResizeMode(1, header->Stretch);

  complete_provider = new ModelCompleter(this);
  tx_provider->completation->setModel(complete_provider);

  connect(bt_save, &QPushButton::clicked, this,
          &ProductFormControl::save_product);
}

void ProductFormControl::get_selects() {
  cb_category->clear();
  cb_brand->clear();
  cb_unit->clear();
  tx_long_description->clear();

  ModelFormProduct model = ModelFormProduct(this);
  connect(&model, &ModelFormProduct::signal_category, this,
          &ProductFormControl::set_categories);
  connect(&model, &ModelFormProduct::signal_brands, this,
          &ProductFormControl::set_brands);
  connect(&model, &ModelFormProduct::signal_units, this,
          &ProductFormControl::set_units);
  connect(&model, &ModelFormProduct::signal_providers, complete_provider,
          &ModelCompleter::set_data);
  connect(&model, &ModelFormProduct::signal_check_id, this,
          &ProductFormControl::check_id);
  model.get_selects();
}

// Set categories data into cb_category
void ProductFormControl::set_categories(const int &id,
                                        const QString &category) {
  cb_category->addItem(category, id);
}

// set units data into cb_unit
void ProductFormControl::set_units(const int &id, const QString &unit) {
  cb_unit->addItem(unit, id);
}

// set brands into cb_brand
void ProductFormControl::set_brands(const int &id, const QString &brand) {
  cb_brand->addItem(brand, id);
}

// get product if id is not empyt

void ProductFormControl::check_id() {
  if (!tx_id->text().isEmpty()) {
    ModelFormProduct model;
    int id_product = tx_id->text().toInt();
    connect(&model, &ModelFormProduct::signal_product, this,
            &ProductFormControl::set_product);

    model.get_product(id_product);
  }
}

// Set product selected
void ProductFormControl::set_product(const QJsonObject &product) {

  tx_internal_code->setText(product.value("internal_code").toString());
  cb_enable->setCurrentIndex(cb_enable->findData(product.value("available").toBool()));
  tx_product_name->setText(product.value("name").toString());
  cb_category->setCurrentIndex(cb_category->findData(product.value("category").toInt()));
  cb_brand->setCurrentIndex(cb_brand->findData(product.value("brand").toInt()));
  tx_description->setPlainText(product.value("short_description").toString());
  tx_weight->setText(QString::number(product.value("weight").toDouble(), 'f', 2));
  tx_height->setText(QString::number(product.value("height").toDouble(), 'f', 2));
  tx_width->setText(QString::number(product.value("width").toDouble(), 'f', 2));
  tx_length->setText(QString::number(product.value("length").toDouble(), 'f', 2));
  tx_sale_price->setText(QString::number(product.value("sale_price").toDouble(), 'f', 2));
  tx_maximum_discount->setText(QString::number(product.value("maximum_discount").toDouble(), 'f', 2));
  tx_minimum_sale->setText(QString::number(product.value("minimum_sale").toDouble(), 'f', 2));
  cb_unit->setCurrentIndex(cb_unit->findData(product.value("unit").toInt()));
  tx_minimum_stock->setText(QString::number(product.value("minimum_stock").toDouble(), 'f', 2));
  tx_maximum_stock->setText(QString::number(product.value("maximum_stock").toDouble(), 'f', 2));
  cb_subtract->setCurrentIndex(cb_subtract->findData(product.value("subtract").toBool()));
  tx_long_description->setText(product.value("long_description").toString());


  
  QJsonArray array_providers = product.value("providers").toArray();
  QVector<QStringList> data = {};

  foreach (const QJsonValue &value, array_providers) {
    QJsonObject obj = value.toObject();    
    data.append(QStringList({QString::number(obj.value("id").toInt()), obj.value("fancy_name").toString()}));
  }

  model_provider->set_data(data);




  QJsonObject stock = product.value("stock").toObject();
  tx_purchase_price->setText(QString::number(stock.value("purchase_price").toDouble(), 'f', 2));
  tx_available_stock->setText(QString::number(stock.value("available_stock").toDouble(), 'f', 2));





}

void ProductFormControl::save_product() { qDebug() << cb_category->font(); }

ProductFormControl::~ProductFormControl() {}