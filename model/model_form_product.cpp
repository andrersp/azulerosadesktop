#include "model/model_form_product.h"

void ModelFormProduct::get_selects() {
  ModelRequest request = ModelRequest(this);
  auto [status, response] = request.GET("/product/selects");

  if (status) {
    QJsonObject data = response.value("data").toObject();

    QJsonArray array_categories = data.value("categories").toArray();
    QJsonArray array_providers = data.value("providers").toArray();
    QJsonArray array_brands = data.value("brands").toArray();
    QJsonArray array_units = data.value("units").toArray();

    // Categories
    emit signal_category(0, "Categoria");
    foreach (const QJsonValue &value, array_categories) {
      QJsonObject obj = value.toObject();
      emit signal_category(obj.value("id").toInt(),
                           obj.value("name").toString());
    }

    // Brands
    emit signal_brands(0, "Marca");

    foreach (const QJsonValue &value, array_brands) {
      QJsonObject obj = value.toObject();

      emit signal_brands(obj.value("id").toInt(), obj.value("name").toString());
    }

    // Units
    emit signal_units(0, "Unidade");

    foreach (const QJsonValue &value, array_units) {
      QJsonObject obj = value.toObject();

      emit signal_units(obj.value("id").toInt(), obj.value("name").toString());
    }

    // Model Completer Provider
    QVector<QStringList> v_providers = {};
    QStringList l_provider = {"", "Fornecedor"};
    v_providers.append(l_provider);

    foreach (const QJsonValue &value, array_providers) {
      QJsonObject obj = value.toObject();

      QStringList data;
      data << QString::number(obj.value("id").toInt())
           << obj.value("fancy_name").toString();
      v_providers.append(data);
    }

    emit signal_providers(v_providers);

    // Send Signal check id
    emit signal_check_id();
  }
}

// Get Product By id
void ModelFormProduct::get_product(const int &id){

	if (!id) {
		return;
	}

	ModelRequest request = ModelRequest(this);

	auto [status, response] = request.GET(QString("/product/%1").arg(id));

	if (status) {
		QJsonObject data = response.value("data").toObject();
		emit signal_product(data);
	}

}

// Action delete image
void ModelFormProduct::delete_image(const QString &id_image) {

  ModelRequest request = ModelRequest(this);

  auto [status, response] = request.DEL("/product/image/" + id_image );

  if (status) {
    return;
  }
  emit signal_msg(status, response.value("message").toString());
}

// Save Product
void ModelFormProduct::save_product(const QJsonObject &data) {

  ModelRequest request = ModelRequest(this);

  auto [status, response] = request.post("/product", data);

  if (status) {
    emit signal_msg(status, response.value("message").toString());
    return;
  }
  // qDebug() << response;
  if (response.value("message").isObject()) {
    QString msg = "";
    foreach (const QString &key, response.keys()) {
      QJsonObject value = response.value(key).toObject();
      foreach (const QString &key2, value.keys()) {

        QString msg_data = "";
        QJsonArray array_msg = value.value(key2).toArray();

        foreach (const QJsonValue &msg2, array_msg) {
          msg_data = msg2.toString() + "," ;
        }
        msg = msg + key2 + " - " +  msg_data + "\n";
        // msg = msg + key2 + " - " + value.value(key2).toString() + "\n";
      }
    }

    emit signal_msg(status, msg);
    return;
    
  }
  emit signal_msg(status, response.value("message").toString());




}

ModelFormProduct::~ModelFormProduct() {}