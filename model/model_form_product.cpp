#include "model/model_form_product.h"

void ModelFormProduct::get_selects() {
  ModelRequest request = ModelRequest(this);
  auto [status, response] = request.GET("products/selects/");

  if (status) {
    QJsonObject data = response.value("data").toObject();

    QJsonArray array_categories = data.value("categories").toArray();
    QJsonArray array_providers = data.value("providers").toArray();
    QJsonArray array_brands = data.value("brands").toArray();
    QJsonArray array_units = data.value("units").toArray();

    // Categories

    QVector<QStringList> v_categories;
    QStringList l_category = {"", "Categoria"};
    v_categories.append(l_category);

    foreach (const QJsonValue &value, array_categories) {
      QJsonObject obj = value.toObject();
      QStringList v = {QString::number(obj.value("id").toInt()),
                       obj.value("name").toString()};
      v_categories.append(v);
    }
    emit signal_category(v_categories);

    // Brands
    QVector<QStringList> v_brands;
    QStringList l_brand = {"", "Marca"};
    v_brands.append(l_brand);

    // emit signal_brands(0, "Marca");

    foreach (const QJsonValue &value, array_brands) {
      QJsonObject obj = value.toObject();

      QStringList v = {QString::number(obj.value("id").toInt()),
                       obj.value("name").toString()};
      v_brands.append(v);
    }

    emit signal_brands(v_brands);

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
    return;
  }

  // Array response error
  if (response.value("message").isObject()) {
    QString msg = "";
    foreach (const QString &key, response.keys()) {
      QJsonObject value = response.value(key).toObject();
      foreach (const QString &key2, value.keys()) {
        QString msg_data = "";
        QJsonArray array_msg = value.value(key2).toArray();

        foreach (const QJsonValue &msg2, array_msg) {
          msg_data = msg2.toString() + ",";
        }
        msg = msg + key2 + " - " + msg_data + "\n";
        // msg = msg + key2 + " - " + value.value(key2).toString() + "\n";
      }
    }

    emit signal_msg(status, msg);
    return;
  }
  emit signal_msg(status, response.value("message").toString());
}

// Get Product By id
void ModelFormProduct::get_product(const int &id) {
  if (!id) {
    return;
  }

  ModelRequest request = ModelRequest(this);

  auto [status, response] = request.GET(QString("products/%1").arg(id));

  if (status) {
    QJsonObject data = response.value("data").toObject();
    emit signal_product(data);
  }
}

// Action delete image
void ModelFormProduct::delete_image(const QString &id_image) {
  ModelRequest request = ModelRequest(this);

  auto [status, response] = request.DEL("products/image/" + id_image);

  if (status) {
    return;
  }
  emit signal_msg(status, response.value("message").toString());
}

// Save Product
void ModelFormProduct::save_product(const QJsonObject &data, const int &product_id) {
  ModelRequest request = ModelRequest(this);
  

  auto [status, response] = product_id ?  request.put(QString("products/%1").arg(product_id), data) :  request.post(QString("products/"), data);

  if (status) {
    QJsonObject resp = response.value("data").toObject();
    int product_id = resp.value("id").toInt();

    emit signal_msg_sucess(status, response.value("message").toString(),
                           product_id);
    return;
  }

  // Array response error
  if (response.value("message").isObject()) {
    QString msg = "";
    foreach (const QString &key, response.keys()) {
      QJsonObject value = response.value(key).toObject();
      foreach (const QString &key2, value.keys()) {
        QString msg_data = "";
        QJsonArray array_msg = value.value(key2).toArray();

        foreach (const QJsonValue &msg2, array_msg) {
          msg_data = msg2.toString() + ",";
        }
        msg = msg + key2 + " - " + msg_data + "\n";
        // msg = msg + key2 + " - " + value.value(key2).toString() + "\n";
      }
    }

    emit signal_msg(status, msg);
    return;
  }
  emit signal_msg(status, response.value("message").toString());
}

void ModelFormProduct::save_category(const QJsonObject &data) {
  ModelRequest request;

  auto [status, response] = request.post("products/categories/", data);

  if (status) {
    QJsonObject obj = response.value("data").toObject();

    int id_category = obj.value("id").toInt();
    QString name_category = obj.value("name").toString();

    emit signal_new_category(id_category, name_category);
    return;
  }
  // Array response error
  if (response.value("message").isObject()) {
    QString msg = "";
    foreach (const QString &key, response.keys()) {
      QJsonObject value = response.value(key).toObject();
      foreach (const QString &key2, value.keys()) {
        QString msg_data = "";
        QJsonArray array_msg = value.value(key2).toArray();

        foreach (const QJsonValue &msg2, array_msg) {
          msg_data = msg2.toString() + ",";
        }
        msg = msg + key2 + " - " + msg_data + "\n";
        // msg = msg + key2 + " - " + value.value(key2).toString() + "\n";
      }
    }

    emit signal_msg(status, msg);
    return;
  }
  emit signal_msg(status, response.value("message").toString());
}

// Save New Brand
void ModelFormProduct::save_brand(const QJsonObject &data) {
  ModelRequest request;

  auto [status, response] = request.post("products/brands/", data);

  if (status) {
    QJsonObject obj = response.value("data").toObject();

    int id_category = obj.value("id").toInt();
    QString name_category = obj.value("name").toString();

    emit signal_new_brand(id_category, name_category);
    return;
  }
  // Array response error
  if (response.value("message").isObject()) {
    QString msg = "";
    foreach (const QString &key, response.keys()) {
      QJsonObject value = response.value(key).toObject();
      foreach (const QString &key2, value.keys()) {
        QString msg_data = "";
        QJsonArray array_msg = value.value(key2).toArray();

        foreach (const QJsonValue &msg2, array_msg) {
          msg_data = msg2.toString() + ",";
        }
        msg = msg + key2 + " - " + msg_data + "\n";
        // msg = msg + key2 + " - " + value.value(key2).toString() + "\n";
      }
    }

    emit signal_msg(status, msg);
    return;
  }
  emit signal_msg(status, response.value("message").toString());
}

ModelFormProduct::~ModelFormProduct() {}