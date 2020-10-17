#ifndef MAIN_PRODUCT_VIEW_H
#define MAIN_PRODUCT_VIEW_H

#include <QFrame>
#include <QGridLayout>
#include "view/default_table.h"

class MainProductView : public QFrame{
public:
	explicit MainProductView(QWidget *parent = nullptr);
	virtual ~MainProductView();

protected:
	DefaultTable *table_product;

private:
	QGridLayout *grid;

};



#endif