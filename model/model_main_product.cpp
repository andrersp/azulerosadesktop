#include "model/model_main_product.h"
#include "model/request.h"
#include "widgets/default_widgets.h"
#include <QFont>
#include <QJsonObject>
#include <QLabel>
#include <QPixmap>
#include <QAbstractItemView>
#include <QTableView>
#include <QDebug>
ModelMainProduct::ModelMainProduct(QObject *parent) : QObject(parent) {}

void ModelMainProduct::get_products() {
  ModelRequest request = ModelRequest(this);
  auto [status, response] = request.GET("products/");

  if (status) {
    QJsonArray data_array = response.value("data").toArray();
    QVector<QStringList> products = {};
    // emit signal_product(data_array);

    foreach (const QJsonValue &value, data_array) {
      QJsonObject obj = value.toObject();

      QStringList data = {
          QString::number(obj.value("id").toInt()),
          obj.value("cover").toString(),
          obj.value("name").toString(),
          obj.value("short_description").toString(),
          obj.value("category").toString(),
          QString::number(obj.value("available_stock").toDouble(), 'f', 2),
          QString::number(obj.value("sale_price").toDouble(), 'f', 2),
          "Editar"};

      products.append(data);
    }

    emit signal_product(products);
    return;
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
    if (index.column() == 2 ||  index.column() == 3) {
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

  if (role == Qt::ForegroundRole && index.column() == 1) {
    return QColor(Qt::white);
  }

  if (role == Qt::DisplayRole || role == Qt::EditRole) {

    if (index.column() == 7) {
      return "";
    }

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
    if (section == 2 || section == 3) {
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

/* Start Delegeate Produtc */
DelegateProduct::DelegateProduct(QObject *parent)
    : QStyledItemDelegate(parent) {}

QWidget *DelegateProduct::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &option,
                                       const QModelIndex &index) const {

  if (index.column() == 1) {
    QLabel *editor = new QLabel(parent);
    editor->setContentsMargins(2, 2, 2, 2);
    editor->setAttribute(Qt::WA_TransparentForMouseEvents);
    return editor;
  }
  else if (index.column() == 7) {
    ButtonEditTable *editor = new ButtonEditTable("Editar", parent);
    // editor->setAttribute(Qt::WA_TransparentForMouseEvents);
    return editor;
  }
   else {
    return QStyledItemDelegate::createEditor(parent, option, index);
  }
}

void DelegateProduct::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const {
  if (index.column() == 1) {
    QString value{index.model()->data(index, Qt::EditRole).toString()};

    QPixmap pixmap;

    QLabel *label = static_cast<QLabel *>(editor);
    label->setContentsMargins(2, 2, 2, 2);
    pixmap.load(":Images/Images/products.svgz");
    label->setPixmap(pixmap.scaledToHeight(50, Qt::SmoothTransformation));

  }
}


void DelegateProduct::updateEditorGeometry(
    QWidget *editor, const QStyleOptionViewItem &option,
    const QModelIndex &index /* index */) const {

  QRect rect = option.rect;

  if  (index.column() == 7) {
    rect.setX(rect.x() + 10);
    rect.setY(rect.y() + 20);
  }

  editor->setGeometry(rect);
}

void DelegateProduct::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (QAbstractItemView* tableView = qobject_cast<QAbstractItemView*>(this->parent()))
    {   
        QModelIndex hover = tableView->indexAt(tableView->viewport()->mapFromGlobal(QCursor::pos()));
        if (hover.row() == index.row())
        {            
            QRect position(option.rect.x(), option.rect.y() + 78, option.rect.width(), 1);
            painter->fillRect(position ,QColor("#069"));
            position = QRect(option.rect.x(), option.rect.y(), option.rect.width(), 1);
            painter->fillRect(position ,QColor("#069"));
        }        
    }

    QTableView *table = qobject_cast<QTableView*>(this->parent());
    if (index.column() == 7) {
        table->openPersistentEditor(index);     
      
    }
 
    QStyledItemDelegate::paint(painter, option, index);
}


// Filter Product
FilterProduct::FilterProduct(QObject *parent) : QSortFilterProxyModel(parent){}

bool FilterProduct::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const {

  QModelIndex index = sourceModel()->index(sourceRow, 2, sourceParent);
  QModelIndex index1 = sourceModel()->index(sourceRow, 0, sourceParent);

  return (
    sourceModel()->data(index).toString().contains(filterRegExp()) or  
    sourceModel()->data(index1).toString().contains(filterRegExp())
    );

}

FilterProduct::~FilterProduct(){} 