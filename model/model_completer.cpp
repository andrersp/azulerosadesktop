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

void ModelCompleter::set_data(const QVector<QStringList> &itens) {
	beginResetModel();
	this->itens = itens;
	endResetModel();

}

ModelCompleter::~ModelCompleter(){}