#ifndef DASHBOARD_VIEW_H
#define DASHBOARD_VIEW_H

#include <QFrame>
#include <QGridLayout>
#include <QLabel>


class FrameInfo : public QFrame {
public:
	explicit FrameInfo(QString text, QPixmap *img, QWidget *parent = nullptr);
	virtual ~FrameInfo();

	

	QLabel *lb_img, *lb_title, *lb_value;
public slots:
	void set_value(QString value);
private:	
	QGridLayout *grid;


};


class DashBoardView : public QFrame {
public:
	explicit DashBoardView(QWidget *parent=nullptr);
	virtual ~DashBoardView();

	QGridLayout *grid;

protected:
	FrameInfo *info_client, *info_product, *info_sale, *info_revenue;	

};

#endif