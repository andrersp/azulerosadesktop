#ifndef DEFAULT_TABLE_H
#define DEFAULT_TABLE_H

#include <QTableView>
#include <QHeaderView>

class DefaultTable : public QTableView{
	Q_OBJECT
public:
	explicit DefaultTable(QWidget *parent = nullptr);
	virtual ~DefaultTable();
	void makePersistent();

};


#endif