#include "control/form_product_control.h"
#include <QAbstractProxyModel>
#include <QBuffer>
#include <QDebug>
ProductFormControl::ProductFormControl(QWidget *parent) : ProductForm(parent) {
  model_provider = new ModelCompleter(this);
  tb_providers->setModel(model_provider);

  // Model Category
  model_category = new ModelCompleter(this);
  tx_category->completation->setModel(model_category);

  // Tb Provider
  tb_providers->setColumnHidden(0, true);
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
  connect(tx_category->bt_add, &QPushButton::clicked, this, &ProductFormControl::dialog_add_category);

  // Connect Dialog
  // connect(this, SIGNAL(signal_dialog(int status, QString msg)),
  // this->parent(), SLOT(dialog_err(int status, QString msg)));
}

void ProductFormControl::get_selects() {
  // cb_category->clear();
  cb_brand->clear();
  cb_unit->clear();
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
  // cb_category->addItem(category, id);
  qDebug() << id;
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
                   index.sibling(index.row(), 1).data().toString()};

  int row = model_provider->rowCount();
  int col = model_provider->columnCount();
  model_provider->setData(model_provider->index(row, col), data, Qt::EditRole);
}

// Set product selected
void ProductFormControl::set_product(const QJsonObject &product) {
  tx_internal_code->setText(product.value("internal_code").toString());
  cb_enable->setCurrentIndex(
      cb_enable->findData(product.value("available").toBool()));
  tx_product_name->setText(product.value("name").toString());

  int id_category {product.value("category").toInt()};

  for (int i = 0; i < model_category->rowCount(); i ++) {
      if (model_category->index(i, 0).data().toInt() == id_category){
        tx_category->completation->setCurrentRow(i);
        tx_category->setText(tx_category->completation->currentCompletion());
      }
  }
  // cb_category->setCurrentIndex(
  //     cb_category->findData(product.value("category").toInt()));
  cb_brand->setCurrentIndex(cb_brand->findData(product.value("brand").toInt()));
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
                             obj.value("fancy_name").toString()}));
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

  QJsonObject data;
  data.insert("id", tx_id->text().toInt());
  data.insert("internal_code", tx_internal_code->text());
  data.insert("name", tx_product_name->text());
  data.insert("category", id_category);
  data.insert("brand", cb_brand->currentData().toInt());
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
  connect(&model, &ModelFormProduct::signal_msg, this,
          &ProductFormControl::dialog_err);
  model.save_product(data);
}

void ProductFormControl::remove_image(const QString &id_image) {
  ModelFormProduct model = ModelFormProduct(this);
  model.delete_image(id_image);
}

void ProductFormControl::dialog_err(int status, QString msg) {
  DialogMsg *dialog = new DialogMsg(this, status, msg);
  int resp = dialog->show();
  
  if (status != 1) return;

  if (resp) emit bt_cancel->clicked();
}


void ProductFormControl::dialog_add_category(){
  DialogInput *dialog = new DialogInput("Nova Categoria", this);
  MaskWidget *mask = new MaskWidget(this);
  mask->show();
  int resp = dialog->exec();
  mask->close();
}

void ProductFormControl::add_category(const QString &category) {
  qDebug() << category;
}

ProductFormControl::~ProductFormControl() {}