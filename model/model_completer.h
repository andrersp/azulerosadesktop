#ifndef MODEL_COMPLETER_H
#define MODEL_COMPLETER_H
#include <QAbstractTableModel>

class ModelCompleter : public QAbstractTableModel {
	Q_OBJECT
public:
	explicit ModelCompleter(QObject *parent = nullptr) : QAbstractTableModel(parent){};
	virtual ~ModelCompleter();

	int rowCount(const QModelIndex &index = QModelIndex()) const override;
	int columnCount(const QModelIndex &index = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVector<QStringList> itens = {};
	bool setData(const QModelIndex &index, const QStringList &value, int role = Qt::EditRole);
	bool insertRows(int position, int rows, const QModelIndex &index) override;

	void set_data(const QVector<QStringList> &itens);

};

#endif