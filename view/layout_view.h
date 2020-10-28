#ifndef MAINWINDOW_VIEW_H
#define MAINWINDOW_VIEW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QPushButton>

#include "view/frame_side_menu.h"
class MainWindowView : public QWidget{
	
public:
	explicit MainWindowView(QObject *parent = nullptr);
	~MainWindowView();

	QGridLayout *central_grid;

	QFrame *fr_top;

	FrameMenu *fr_menu;
	QVBoxLayout *grid_menu;
	QHBoxLayout *grid_top;

	QStackedWidget *container;

	QStatusBar *status_bar;	

	QWidget *wd1, *wd2;	

};


#endif