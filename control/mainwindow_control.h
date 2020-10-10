#ifndef MAINWINDOW_CONTROL_H
#define MAINWINDOW_CONTROL_H

#include "view/mainwindow_view.h"


class MainWindowControl : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindowControl(QWidget *parent = nullptr);

private:
	MainWindowView *view;

};

#endif