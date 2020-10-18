#ifndef MAIN_PRODUCT_VIEW_H
#define MAIN_PRODUCT_VIEW_H

#include <QFrame>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include "view/default_table.h"


class FrameProduct : public QFrame {
	Q_OBJECT
public:
	explicit FrameProduct(QString &url_image, QString &name, QString &value, int id, QWidget *parent=nullptr);
	virtual ~FrameProduct();

private:
	QGridLayout *grid;
	QLabel *lb_name, *lb_value, *lb_id, *lb_cover;

private slots:
void set_cover(QString &url);




};


class MainProductView : public QScrollArea{
public:
	explicit MainProductView(QWidget *parent = nullptr);
	virtual ~MainProductView();

	QFrame *fr_product;

	FrameProduct *frame_product;

protected:
	DefaultTable *table_product;
	QGridLayout *grid;

private:

	QScrollArea *scroll;
	

};



#endif