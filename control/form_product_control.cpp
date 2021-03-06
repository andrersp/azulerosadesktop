#include "control/form_product_control.h"
#include <QAbstractProxyModel>
#include <QBuffer>

ProductFormControl::ProductFormControl(QWidget *parent) : ProductForm(parent) {
  // Model Category
  model_category = new ModelCompleter(this);
  tx_category->completation->setModel(model_category);

  completer_brand = new ModelCompleter(this);
  tx_brand->completation->setModel(completer_brand);

  // Tb Provider
  model_provider = new ModelMiniTable(this);
  tb_providers->setModel(model_provider);
  tb_providers->setColumnHidden(0, true);
  tb_providers->setColumnWidth(2, 35);
  tb_providers->setFocusPolicy(Qt::NoFocus);
  QHeaderView *header = tb_providers->horizontalHeader();
  header->setSectionResizeMode(1, header->Stretch);


  complete_provider = new ModelCompleter(this);
  tx_provider->completation->setModel(complete_provider);

  connect(bt_save, &QPushButton::clicked, this,
          &ProductFormControl::save_product);

  // Connect Provider completer
  connect(tx_provider->completation,
          QOverload<const QModelIndex &>::of(&QCompleter::activated), this,
          &ProductFormControl::select_provider);
  // Connect Remove Provider
  connect(tb_providers, QOverload<const QModelIndex &>::of(&DefaultTable::clicked), this, &ProductFormControl::remove_provider);

  // Coonect LabelUpload remove Image
  connect(img1, &LabelUploadImage::signal_remove_image, this,
          &ProductFormControl::remove_image);
  connect(img2, &LabelUploadImage::signal_remove_image, this,
          &ProductFormControl::remove_image);
  connect(img3, &LabelUploadImage::signal_remove_image, this,
          &ProductFormControl::remove_image);
  connect(img4, &LabelUploadImage::signal_remove_image, this,
          &ProductFormControl::remove_image);
  connect(img5, &LabelUploadImage::signal_remove_image, this,
          &ProductFormControl::remove_image);

  // Connect Add Category dialog
  connect(tx_category->bt_add, &QPushButton::clicked, this,
          &ProductFormControl::dialog_add_category);

  // Connect Add brand Dialog
  connect(tx_brand->bt_add, &QPushButton::clicked, this, &ProductFormControl::dialog_add_brand);

  // Connect Dialog
  // connect(this, SIGNAL(signal_dialog(int status, QString msg)),
  // this->parent(), SLOT(dialog_err(int status, QString msg)));
}

void ProductFormControl::get_selects() {

  tx_description->clear();
  cb_unit->clear();
  cb_subtract->setCurrentIndex(1);
  model_provider->itens.clear();
  QList<LabelUploadImage *> lb_images = {img_cover, img1, img2,
                                         img3,      img4, img5};

  // Clear Images
  for (int i = 0; i < lb_images.count(); i++) {
    lb_images[i]->clearContent();
  }

  // Clear long_description
  tx_long_description->clearSource();

  ModelFormProduct model = ModelFormProduct(this);
  connect(&model, &ModelFormProduct::signal_category, model_category,
          &ModelCompleter::set_data);
  connect(&model, &ModelFormProduct::signal_brands, completer_brand,
          &ModelCompleter::set_data);
  connect(&model, &ModelFormProduct::signal_units, this,
          &ProductFormControl::set_units);
  connect(&model, &ModelFormProduct::signal_providers, complete_provider,
          &ModelCompleter::set_data);
  connect(&model, &ModelFormProduct::signal_check_id, this,
          &ProductFormControl::check_id);
  connect(&model, &ModelFormProduct::signal_msg, this,
          &ProductFormControl::dialog_err);
  model.get_selects();
}

// set units data into cb_unit
void ProductFormControl::set_units(const int &id, const QString &unit) {
  cb_unit->addItem(unit, id);
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

void ProductFormControl::select_provider(const QModelIndex &index) {
  if (index.row() == 0) {
    dialog_err(2, "Selecione um fornecedor");
    tx_provider->setFocus();
    tx_provider->show_popup();
    return;
  }
  int id_provider = index.sibling(index.row(), 0).data().toInt();

  for (int i = 0; i < model_provider->rowCount(); i++) {
    if (model_provider->index(i, 0).data().toInt() == id_provider) {
      dialog_err(2, "Fornecedor ja cadastrado");
      return;
    }
  }

  QStringList data{index.sibling(index.row(), 0).data().toString(),
                   index.sibling(index.row(), 1).data().toString(), ""};

  int row = model_provider->rowCount();
  int col = model_provider->columnCount();
  model_provider->setData(model_provider->index(row, col), data, Qt::EditRole);
}

// remove Provider of table

void ProductFormControl::remove_provider(const QModelIndex &index) {

  int col = index.column();

  if (col == 2) {
    model_provider->removeRows(index.row(), 1, QModelIndex());
  }

}

// Set product selected
void ProductFormControl::set_product(const QJsonObject &product) {
  tx_internal_code->setText(product.value("internal_code").toString());
  cb_enable->setCurrentIndex(
      cb_enable->findData(product.value("available").toBool()));
  tx_product_name->setText(product.value("name").toString());

  int id_category{product.value("category").toInt()};

  for (int i = 0; i < model_category->rowCount(); i++) {
    if (model_category->index(i, 0).data().toInt() == id_category) {
      tx_category->completation->setCurrentRow(i);
      tx_category->setText(tx_category->completation->currentCompletion());
    }
  }

  int id_brand{product.value("brand").toInt()};  

  for (int i = 0; i < completer_brand->rowCount(); i++) {
    if (completer_brand->index(i, 0).data().toInt() == id_brand) {
      tx_brand->completation->setCurrentRow(i);
      tx_brand->setText(tx_brand->completation->currentCompletion());
    }
  }

  // cb_brand->setCurrentIndex(cb_brand->findData(product.value("brand").toInt()));
  tx_description->setPlainText(product.value("short_description").toString());
  tx_weight->setText(
      QString::number(product.value("weight").toDouble(), 'f', 2));
  tx_height->setText(
      QString::number(product.value("height").toDouble(), 'f', 2));
  tx_width->setText(QString::number(product.value("width").toDouble(), 'f', 2));
  tx_length->setText(
      QString::number(product.value("length").toDouble(), 'f', 2));
  tx_sale_price->setText(
      QString::number(product.value("sale_price").toDouble(), 'f', 2));
  tx_maximum_discount->setText(
      QString::number(product.value("maximum_discount").toDouble(), 'f', 2));
  tx_minimum_sale->setText(
      QString::number(product.value("minimum_sale").toDouble(), 'f', 2));
  cb_unit->setCurrentIndex(cb_unit->findData(product.value("unit").toInt()));
  tx_minimum_stock->setText(
      QString::number(product.value("minimum_stock").toDouble(), 'f', 2));
  tx_maximum_stock->setText(
      QString::number(product.value("maximum_stock").toDouble(), 'f', 2));
  cb_subtract->setCurrentIndex(
      cb_subtract->findData(product.value("subtract").toBool()));
  tx_long_description->setText(product.value("long_description").toString());

  // Provider
  QJsonArray array_providers = product.value("providers").toArray();
  QVector<QStringList> data = {};

  foreach (const QJsonValue &value, array_providers) {
    QJsonObject obj = value.toObject();
    data.append(QStringList({QString::number(obj.value("id").toInt()),
                             obj.value("fancy_name").toString(), ""}));
  }


  model_provider->set_data(data);

  // cover
  ModelRequest request = ModelRequest(this);

  QString cover(request.get_image(product.value("cover").toString()));

  if (!cover.isEmpty()) img_cover->set_image_url(request.get_image(cover), "");

  // Images
  QList<LabelUploadImage *> lb_images = {img1, img2, img3, img4, img5};
  QJsonArray array_images = product.value("images").toArray();

  int i = 0;
  foreach (const QJsonValue &value, array_images) {
    QJsonObject obj = value.toObject();
    lb_images[i]->set_image_url(request.get_image(obj.value("url").toString()),
                                QString::number(obj.value("id").toInt()));

    i++;
    if (i == 5) break;
  }

  // Stock
  QJsonObject stock = product.value("stock").toObject();
  tx_purchase_price->setText(
      QString::number(stock.value("purchase_price").toDouble(), 'f', 2));
  tx_available_stock->setText(
      QString::number(stock.value("available_stock").toDouble(), 'f', 2));
}

// Save Product
void ProductFormControl::save_product() {
  if (tx_internal_code->text().isEmpty()) {
    dialog_err(2, "Código interno não digitado");
    tx_internal_code->setFocus();
    return;
  }

  if (tx_product_name->text().isEmpty()) {
    dialog_err(2, "Nome do produto não digitado");
    tx_product_name->setFocus();
    return;
  }

  QAbstractProxyModel *proxy_category = qobject_cast<QAbstractProxyModel *>(
      tx_category->completation->completionModel());
  QModelIndex index_category =
      proxy_category->mapToSource(tx_category->completation->currentIndex());

  int id_category{
      index_category.sibling(index_category.row(), 0).data().toInt()};

  if (!id_category) {
    dialog_err(2, "Nenhuma categoria selecionada");
    tx_category->setFocus();
    tx_category->show_popup();
    return;
  }

  if (tx_description->toPlainText().isEmpty()) {
    dialog_err(2, "Digite uma descrição para o produto");
    tx_description->setFocus();
    return;
  }

  if (tx_minimum_sale->text().isEmpty()) {
    dialog_err(2, "Digite a quantidade mínima permitida por venda");
    tx_minimum_sale->setFocus();
    return;
  }

  if (cb_unit->currentIndex() == 0) {
    dialog_err(2, "Selecione a unidade de medida do produto");
    cb_unit->setFocus();
    cb_unit->showPopup();
    return;
  }

  if (tx_minimum_stock->text().isEmpty()) {
    dialog_err(2, "Digite a quantidade mínima para estoque");
    tx_minimum_stock->setFocus();
    return;
  }

  if (tx_maximum_stock->text().isEmpty()) {
    dialog_err(2, "Digite a quantidade máxima para estoque");
    tx_maximum_stock->setFocus();
    return;
  }


  QAbstractProxyModel *proxy_brand = qobject_cast<QAbstractProxyModel *>(
      tx_brand->completation->completionModel());
  QModelIndex index_brand =
      proxy_brand->mapToSource(tx_brand->completation->currentIndex());

  int id_brand{
      index_brand.sibling(index_brand.row(), 0).data().toInt()};

  QJsonObject data;
  data.insert("internal_code", tx_internal_code->text());
  data.insert("name", tx_product_name->text());
  data.insert("category", id_category);
  data.insert("brand", id_brand);
  data.insert("unit", cb_unit->currentData().toInt());
  data.insert("minimum_stock", tx_minimum_stock->text().toDouble());
  data.insert("maximum_stock", tx_maximum_stock->text().toDouble());
  data.insert("subtract", cb_subtract->currentData().toBool());
  data.insert("short_description", tx_description->toPlainText());
  data.insert("long_description", tx_long_description->toHtml());

  // Image cover to base 64
  if (!img_cover->pixmap(Qt::ReturnByValue).isNull()) {
    QByteArray bytearray;
    QBuffer buffer(&bytearray);
    img_cover->img_data.save(&buffer, "PNG");
    data.insert("cover", QString::fromLatin1(bytearray.toBase64().data()));
  } else {
    data.insert("cover", "");
  }

  data.insert("height", tx_height->text().toDouble());
  data.insert("width", tx_width->text().toDouble());
  data.insert("length", tx_length->text().toDouble());
  data.insert("weight", tx_weight->text().toDouble());
  data.insert("minimum_sale", tx_minimum_sale->text().toDouble());
  data.insert("sale_price", tx_sale_price->text().toDouble());
  data.insert("maximum_discount", tx_maximum_discount->text().toDouble());
  data.insert("available", cb_enable->currentData().toBool());

  // Array to insert Provider id

  QJsonArray providers;

  for (int i = 0; i < model_provider->rowCount(); i++) {
    providers.append(model_provider->index(i, 0).data().toInt());
  }
  data.insert("provider", providers);

  // Array to insert Images

  QJsonArray data_images;
  QList<LabelUploadImage *> lb_images = {img1, img2, img3, img4, img5};
  for (int i = 0; i < 5; i++) {
    if (lb_images[i]->tx_id->text().isEmpty()) {
      if (!lb_images[i]->pixmap(Qt::ReturnByValue).isNull()) {
        QByteArray bytearray;
        QBuffer buffer(&bytearray);
        lb_images[i]->img_data.save(&buffer, "PNG");
        data_images.append(QString::fromLatin1(bytearray.toBase64().data()));
      }
    }
  }

  data.insert("images", data_images);

  ModelFormProduct model = ModelFormProduct(this);
  connect(&model, &ModelFormProduct::signal_msg_sucess, this,
          &ProductFormControl::dialog_sucess);
  connect(&model, &ModelFormProduct::signal_msg, this,
          &ProductFormControl::dialog_err);
  model.save_product(data, tx_id->text().toInt());
}

void ProductFormControl::remove_image(const QString &id_image) {
  ModelFormProduct model = ModelFormProduct(this);
  model.delete_image(id_image);
}

void ProductFormControl::dialog_add_category() {
  DialogInput dialog = DialogInput("Nova Categoria", this);
  MaskWidget mask = MaskWidget(this);
  mask.show();
  int resp = dialog.exec();
  mask.close();

  if (resp) {
    QString category_name = dialog.tx_name->text();
    QString description = dialog.tx_description->toPlainText();

    if (category_name.isEmpty()) {
      dialog_err(2, "Nome não informado. \nTente Novamente");
      dialog_add_category();
      return;
    }

    QJsonObject data;
    data.insert("name", category_name);
    data.insert("description", description);

    ModelFormProduct model;

    // Connect Signal
    connect(&model, &ModelFormProduct::signal_msg, this,
            &ProductFormControl::dialog_err);
    connect(&model, &ModelFormProduct::signal_new_category, this,
            &ProductFormControl::select_new_categorry);
    model.save_category(data);
  }
}

void ProductFormControl::select_new_categorry(const int &id_category,
                                              const QString &name_category) {
  tx_category->completation->setCompletionPrefix("");
  int row = model_category->rowCount();
  int col = model_category->columnCount();

  QStringList data{QString::number(id_category), name_category};
  model_category->setData(model_category->index(row, col), data, Qt::EditRole);

  for (int i = 0; i < model_category->rowCount(); i++) {
    
    if (id_category == model_category->index(i, 0).data().toInt()) {
      tx_category->completation->setCurrentRow(i);
      tx_category->setText(tx_category->completation->currentCompletion());
    }
  }
}


void ProductFormControl::dialog_add_brand() {
  DialogInput dialog = DialogInput("Nova Marca", this);
  MaskWidget mask = MaskWidget(this);
  mask.show();
  int resp = dialog.exec();
  mask.close();

  if (resp) {
    QString category_name = dialog.tx_name->text();
    QString description = dialog.tx_description->toPlainText();

    if (category_name.isEmpty()) {
      dialog_err(2, "Nome não informado. \nTente Novamente");
      dialog_add_brand();
      return;
    }

    QJsonObject data;
    data.insert("name", category_name);
    data.insert("description", description);

    ModelFormProduct model;

    // Connect Signal
    connect(&model, &ModelFormProduct::signal_msg, this,
            &ProductFormControl::dialog_err);
    connect(&model, &ModelFormProduct::signal_new_brand, this,
            &ProductFormControl::select_new_brand);
    model.save_brand(data);
  }
}

void ProductFormControl::select_new_brand(const int &id_category,
                                              const QString &name_brand) {
  tx_brand->completation->setCompletionPrefix("");
  int row = completer_brand->rowCount();
  int col = completer_brand->columnCount();

  QStringList data{QString::number(id_category), name_brand};
  completer_brand->setData(completer_brand->index(row, col), data, Qt::EditRole);

  for (int i = 0; i < completer_brand->rowCount(); i++) {
    
    if (id_category == completer_brand->index(i, 0).data().toInt()) {
      tx_brand->completation->setCurrentRow(i);
      tx_brand->setText(tx_brand->completation->currentCompletion());
    }
  }
}


void ProductFormControl::dialog_err(int status, QString msg) {
  DialogMsg *dialog = new DialogMsg(this, status, msg);
  int resp = dialog->show();

  if (status != 1) return;

  if (resp) emit bt_cancel->clicked();
}

void ProductFormControl::dialog_sucess(int status, QString msg, int product_id) {
  DialogMsg *dialog = new DialogMsg(this, status, msg);
  int resp = dialog->show();

  if (status != 1) return;

  tx_id->setText(QString::number(product_id));

  if (resp) emit bt_cancel->clicked();
}

ProductFormControl::~ProductFormControl() {}