#ifndef DASHBOARD_CONTROL_H
#define DASHBOARD_CONTROL_H

#include "view/dashboard_view.h"

class DashBoardControl : public DashBoardView {
	Q_OBJECT

public:
	explicit DashBoardControl(QWidget *parent=nullptr);
	virtual ~DashBoardControl();

};

#endif