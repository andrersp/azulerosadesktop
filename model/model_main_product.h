#ifndef MODEL_MAIN_PRODUCT_H
#define MODEL_MAIN_PRODUCT_H

#include <QObject>
#include <QAbstractTableModel>
#include <QJsonArray>

#include "model/request.h"



class ModelMainProduct : public QObject{
	Q_OBJECT
public:
	explicit ModelMainProduct(QObject *parent = nullptr);
	virtual ~ModelMainProduct();
public slots:
	void get_products();
signals:
void signal_product(QJsonArray &array);
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

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	Qt::ItemFlags flags(const QModelIndex &index) const override;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	QStringList header = {"#", "Produto", "Categoria", "Disponível", "Valor", "Editar"};

	QVector<QStringList> itens = {};

	void set_data(const QVector<QStringList> &itens);

};

#endif