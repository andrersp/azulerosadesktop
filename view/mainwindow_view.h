#ifndef MAINWINDOW_VIEW_H
#define MAINWINDOW_VIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QStatusBar>

class MainWindowView{
	
public:
	explicit MainWindowView(QMainWindow *mainwindow = nullptr);

	QWidget *central_widget;
	QGridLayout *central_grid;
	QStatusBar *status_bar;

};


#endif