#ifndef MODEL_MAIN_PRODUCT_H
#define MODEL_MAIN_PRODUCT_H

#include <QAbstractTableModel>
#include <QJsonArray>
#include <QJsonObject>
#include <QObject>
#include <QPainter>
#include <QStyledItemDelegate>

#include "model/request.h"

// Default Model
class ModelMainProduct : public QObject {
  Q_OBJECT
 public:
  explicit ModelMainProduct(QObject *parent = nullptr);
  virtual ~ModelMainProduct();
 public slots:
  void get_products();
 signals:
  void signal_product(QVector<QStringList> &data);
  void signal_err(int status, QString msg);
};

// Table Model Product
class ModelTableProduct : public QAbstractTableModel {
  Q_OBJECT
 public:
  explicit ModelTableProduct(QObject *parent = nullptr);
  virtual ~ModelTableProduct();

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

  Qt::ItemFlags flags(const QModelIndex &index) const override;

  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;

  QStringList header = {"#",         "",           "Produto", "Descrição",
                        "Categoria", "Disponível", "Valor",   "Editar"};

  QVector<QStringList> itens = {};

  void set_data(const QVector<QStringList> &itens);
};

// Delegetate

class DelegateProduct : public QStyledItemDelegate {
  Q_OBJECT
 public:
  DelegateProduct(QObject *parent = nullptr);

  // virtual void paint(QPainter *painter, const QStyleOptionViewItem &option,
  //                    const QModelIndex &index) const override;
  // QSize sizeHint(const
  // QStyleOptionViewItem &option, const QModelIndex &index) const override;
  virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const override;
  virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;
  virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                            const QModelIndex &index) const override;
};

#endif