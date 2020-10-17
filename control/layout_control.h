#ifndef LAYOUT_CONTROL_H
#define LAYOUT_CONTROL_H
#include "view/layout_view.h"
#include "control/dashboard_control.h"
#include "control/main_product_control.h"



class LayoutControl : public MainWindowView {
	Q_OBJECT
public:
	LayoutControl(QObject *parent);
	~LayoutControl();

	DashBoardControl *dashboard_frame;
	MainProductControl *main_product;

public slots:
	void tamanho();
	void set_window_produto();

};


#endif