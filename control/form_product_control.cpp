#include "control/form_product_control.h"
#include <QDebug>
ProductFormControl::ProductFormControl(QWidget *parent) : ProductForm(parent) {
  model_provider = new ModelCompleter(this);
  tb_providers->setModel(model_provider);

  complete_provider = new ModelCompleter(this);
  tx_provider->completation->setModel(complete_provider);

  connect(bt_save, &QPushButton::clicked, this,
          &ProductFormControl::save_product);
}

void ProductFormControl::get_selects() {
  ModelFormProduct model = ModelFormProduct(this);
  connect(&model, &ModelFormProduct::signal_category, this,
          &ProductFormControl::set_categories);
  connect(&model, &ModelFormProduct::signal_providers, complete_provider,
          &ModelCompleter::set_data);
  model.get_selects();
}

void ProductFormControl::set_categories(const int &id,
                                        const QString &category) {
  cb_category->addItem(category, id);
}

void ProductFormControl::save_product() { qDebug() << cb_category->font(); }

ProductFormControl::~ProductFormControl() {}