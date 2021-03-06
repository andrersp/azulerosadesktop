#ifndef LAYOUT_CONTROL_H
#define LAYOUT_CONTROL_H
#include <QList>
#include <QComboBox>
#include "view/layout_view.h"
#include "control/dashboard_control.h"
#include "control/main_product_control.h"
#include "control/form_product_control.h"




class LayoutControl : public MainWindowView {
	Q_OBJECT
public:
	LayoutControl(){};
	LayoutControl(QObject *parent);
	~LayoutControl();

	DashBoardControl *dashboard_frame;
	MainProductControl *main_product;
	ProductFormControl *product_form;

public slots:
	void set_dashboard_widow();
	void set_window_produto();
	void set_form_product_window(const int &product_id);
signals:
	void dialog_msg(int status, QString msg);

private slots:
	void erase_form(QWidget *widget);




};


#endif