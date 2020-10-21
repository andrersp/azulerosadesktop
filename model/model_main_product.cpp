#include "model/model_main_product.h"

#include <QDebug>
#include <QFont>
#include <QJsonArray>
#include <QJsonObject>

ModelMainProduct::ModelMainProduct(QObject *parent) : QObject(parent) {}

void ModelMainProduct::get_products() {
  ModelRequest request = ModelRequest(this);
  auto [status, response] = request.GET("/product");

  if (status) {
    QJsonArray data_array = response.value("data").toArray();

    QVector<QStringList> products = {};

    foreach (const QJsonValue &value, data_array) {
      QJsonObject obj = value.toObject();

      QStringList data = {
          QString::number(obj.value("id").toInt()),
          obj.value("name").toString(),
          obj.value("category").toString(),
          QString::number(obj.value("available_stock").toDouble(), 'f', 2),
          QString::number(obj.value("sale_price").toDouble(), 'f', 2),          
          obj.value("cover").toString(),
          "Editar"};
      products.append(data);
    }

    emit signal_products(products);
  }

  if (response.value("message").isObject()) {
    QString msg = "";
    foreach (const QString &key, response.keys()) {
      // qDebug() << response.value(key);
      QJsonObject value = response.value(key).toObject();
      foreach (const QString &key2, value.keys()) {
        QJsonArray data_array = value.value(key2).toArray();

        QString error;

        for (int i = 0; i < data_array.count(); i++) {

          error = error + data_array[i].toString();
        }

        msg = msg + key2 + " - " + error + "\n";
      }
    }

    emit signal_err(status, msg);
    return;
    // qDebug() << msg;
  }

  emit signal_err(status, response.value("message").toString());



}

// Table Model Product
ModelMainProduct::~ModelMainProduct() {}

ModelTableProduct::ModelTableProduct(QObject *parent)
    : QAbstractTableModel(parent) {}

int ModelTableProduct::rowCount(const QModelIndex &parent) const {
  return itens.count();
}

int ModelTableProduct::columnCount(const QModelIndex &parent) const {
  return header.count();
}

QVariant ModelTableProduct::data(const QModelIndex &index, int role) const {

  // Alignment
  if (role == Qt::TextAlignmentRole) {
    if (index.column() == 1 || index.column() == 2) {
      return Qt::AlignLeft + Qt::AlignVCenter;
    }

    return Qt::AlignCenter;
  }

  if (role == Qt::FontRole) {
    if (index.column() == 0 || index.column() == 5) {
      QFont bold;
      bold.setBold(true);
      return bold;
    }
  }

  if (role == Qt::DisplayRole || role == Qt::EditRole) {
    return itens.at(index.row()).at(index.column());
  }
  return QVariant();
}

Qt::ItemFlags ModelTableProduct::flags(const QModelIndex &index) const {
  return QAbstractTableModel::flags(index) | Qt::ItemIsEnabled |
         Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

QVariant ModelTableProduct::headerData(int section, Qt::Orientation orientation,
                                       int role) const {
  if (role == Qt::TextAlignmentRole) {
    if (section == 1) {
      return Qt::AlignLeft + Qt::AlignVCenter;
    }

    return Qt::AlignCenter;
  }

  if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {

    return header.at(section);
  }

  return QVariant();
}

void ModelTableProduct::set_data(const QVector<QStringList> &itens) {
  beginResetModel();
  this->itens = itens;
  endResetModel();
}

ModelTableProduct::~ModelTableProduct() {}