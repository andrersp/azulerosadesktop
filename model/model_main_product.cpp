#include "model/model_main_product.h"
#include "model/request.h"
#include "view/default_widgets.h"

#include <QDebug>
#include <QFont>
#include <QPixmap>

#include <QJsonObject>

ModelMainProduct::ModelMainProduct(QObject *parent) : QObject(parent) {}

void ModelMainProduct::get_products() {
  ModelRequest request = ModelRequest(this);
  auto [status, response] = request.GET("/product");

  if (status) {

    QJsonArray data_array = response.value("data").toArray();
    QVector<QStringList> products = {};
    // emit signal_product(data_array);

    foreach (const QJsonValue &value, data_array) {
      QJsonObject obj = value.toObject();
      qDebug() << obj;

      QStringList data = {
          QString::number(obj.value("id").toInt()),
          obj.value("cover").toString(),
          obj.value("name").toString(),
          obj.value("category").toString(),
          QString::number(obj.value("available_stock").toDouble(), 'f', 2),
          QString::number(obj.value("sale_price").toDouble(), 'f', 2),
          "Editar"};

      products.append(data);
    }

    emit signal_product(products);
  }

  if (response.value("message").isObject()) {
    QString msg = "";

    foreach (const QString &key, response.keys()) {
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
    if (index.column() == 0 || index.column() == 6) {
      QFont bold;
      bold.setBold(true);
      return bold;
    }
  }

  // if (index.column() == 2) {

  //   if (role == Qt::DisplayRole || role == Qt::EditRole) {
  //     return QVariant();
  //   }

  //   if (role == Qt::DecorationRole) {
  //     ModelRequest request = ModelRequest();

  //     QByteArray img = request.get_image(index.data().toString());

  //     QPixmap cover;
  //     cover.loadFromData(img);
  //     qDebug() << "image";
  //     return cover;

  //   }
  // }

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

// Start Delegate
DelegateProduct::DelegateProduct(QObject *parent) : QStyledItemDelegate(parent){}

QWidget *DelegateProduct::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &option,
                                       const QModelIndex &index) const {
  ButtonAdd *editor = new ButtonAdd("EDITAR", parent);
  qDebug() << "button";

    return editor;
}

// QSize DelegateProduct::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const{
//   return QSize(32, 32);
//   Q_UNUSED(option);
//   Q_UNUSED(index);
// }

// void DelegateProduct::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {

//   if (index.column() == 10) {

//     ModelRequest request = ModelRequest();

//     QByteArray img = request.get_image(index.model()->data(index).toString());
//     QPixmap cover;
//     cover.loadFromData(img);

//     cover = cover.scaledToHeight(32);

//     painter->drawPixmap(option.rect.x(),option.rect.y(),cover);    
    
//   }

//   QStyledItemDelegate::paint(painter, option, index);


// }

void DelegateProduct::setEditorData(QWidget *editor, const QModelIndex &index ) const {

  if (index.column() == 6 ){
     QString value("teste");
     ButtonAdd *button = static_cast<ButtonAdd *>(editor);
     button->setText("Editar");
  }
}

void DelegateProduct::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

