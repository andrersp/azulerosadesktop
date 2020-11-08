#include "model/modelMiniTable.h"


// Model For Mini Tables
int ModelMiniTable::rowCount(const QModelIndex &index) const {
  return itens.count();
}

int ModelMiniTable::columnCount(const QModelIndex &index) const { return 3; }

Qt::ItemFlags ModelMiniTable::flags(const QModelIndex &index) const {
  return QAbstractTableModel::flags(index) | Qt::ItemIsSelectable |
         Qt::ItemIsEnabled;
}

QVariant ModelMiniTable::data(const QModelIndex &index, int role) const {

  if (index.column() == 2) {
    if (role == Qt::DecorationRole && index.column() == 2) {
      return QIcon(":Images/Images/icon_remove_image.svgz");
    }
  }

  if (role == Qt::DisplayRole || role == Qt::EditRole) {
    return itens.at(index.row()).at(index.column());
  }

  return QVariant();
}

bool ModelMiniTable::setData(const QModelIndex &index, const QStringList &value,
                             int role) {
  if (role == Qt::EditRole) {
    if (!checkIndex(index)) {
      return false;
    }
    beginResetModel();
    // this->itens[index.row()][index.column()] = value.toString();
    this->itens.append(value);
    endResetModel();
    emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
    return true;
  }

  return false;
}

bool ModelMiniTable::insertRows(int position, int rows,
                                const QModelIndex &index) {
  Q_UNUSED(index);
  beginInsertRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; row++) {
    itens.insert(position, {QString(), QString()});
  }
  endInsertRows();

  return true;
}

bool ModelMiniTable::removeRows(int position, int rows,
                                const QModelIndex &index) {
  Q_UNUSED(index);
  beginRemoveRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; ++row) {
    itens.remove(position);
  }
  endRemoveRows();

  return true;
}

void ModelMiniTable::set_data(const QVector<QStringList> &itens) {
  beginResetModel();
  
  this->itens = itens;
  endResetModel();
}

ModelMiniTable::~ModelMiniTable() {}