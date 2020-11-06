#include "model/model_completer.h"

int ModelCompleter::rowCount(const QModelIndex &index) const {
  return itens.count();
}

int ModelCompleter::columnCount(const QModelIndex &index) const { return 2; }

Qt::ItemFlags ModelCompleter::flags(const QModelIndex &index) const {
  return QAbstractTableModel::flags(index) | Qt::ItemIsSelectable |
         Qt::ItemIsEnabled;
}

QVariant ModelCompleter::data(const QModelIndex &index, int role) const {
  if (role == Qt::DisplayRole || role == Qt::EditRole) {
    return itens.at(index.row()).at(index.column());
  }

  return QVariant();
}

bool ModelCompleter::setData(const QModelIndex &index, const QStringList &value,
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

bool ModelCompleter::insertRows(int position, int rows,
                                const QModelIndex &index) {
  Q_UNUSED(index);
  beginInsertRows(QModelIndex(), position, position + rows - 1);

  for (int row = 0; row < rows; row++) {
    itens.insert(position, {QString(), QString()});
  }
  endInsertRows();

  return true;
}

void ModelCompleter::set_data(const QVector<QStringList> &itens) {
  beginResetModel();
  this->itens = itens;
  endResetModel();
}

ModelCompleter::~ModelCompleter() {}