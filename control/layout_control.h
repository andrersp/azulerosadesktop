#ifndef LAYOUT_CONTROL_H
#define LAYOUT_CONTROL_H
#include "view/layout_view.h"



class LayoutControl : public MainWindowView {
	Q_OBJECT
public:
	LayoutControl(QObject *parent);
	~LayoutControl();

private slots:
	void tamanho();
	void set_window_produto();

};


#endif