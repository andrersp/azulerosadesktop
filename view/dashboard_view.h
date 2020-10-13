#ifndef DASHBOARD_VIEW_H
#define DASHBOARD_VIEW_H

#include <QFrame>
#include <QGridLayout>



class DashBoardView : public QFrame {
public:
	explicit DashBoardView(QWidget *parent=nullptr);
	virtual ~DashBoardView();

	QGridLayout *grid;

	

};

#endif