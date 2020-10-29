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
		qDebug() << "Not Id";		
	}

	ModelRequest request = ModelRequest(this);

	auto [status, response] = request.GET(QString("/product/%1").arg(id));

	if (status) {
		QJsonObject data = response.value("data").toObject();
		emit signal_product(data);
	}

}

ModelFormProduct::~ModelFormProduct() {}