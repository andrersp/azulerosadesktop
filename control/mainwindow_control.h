#ifndef MAINWINDOW_CONTROL_H
#define MAINWINDOW_CONTROL_H

#include "control/layout_control.h"
#include "view/login_view.h"


class MainWindowControl : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindowControl(QWidget *parent = nullptr);

	void window_login();
	void window_layout();
	QToolBar *toolbar;

public slots:
void clear_widget();

private:
	LayoutControl *view;
	LoginView *ui_login;


};

#endif