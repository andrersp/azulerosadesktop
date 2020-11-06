#ifndef MODELMINITABLE_H
#define MODELMINITABLE_H

#include <QAbstractTableModel>
#include <QIcon>

class ModelMiniTable : public QAbstractTableModel {
	Q_OBJECT
public:
	explicit ModelMiniTable(QObject *parent = nullptr) : QAbstractTableModel(parent){};
	virtual ~ModelMiniTable();

	int rowCount(const QModelIndex &index = QModelIndex()) const override;
	int columnCount(const QModelIndex &index = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVector<QStringList> itens = {};
	bool setData(const QModelIndex &index, const QStringList &value, int role = Qt::EditRole);
	bool insertRows(int position, int rows, const QModelIndex &index) override;
	bool removeRows(int position, int rows, const QModelIndex &index) override;

	void set_data(const QVector<QStringList> &itens);

};

#endif