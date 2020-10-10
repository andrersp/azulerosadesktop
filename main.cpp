#include <QApplication>
#include <QMainWindow>
#include "control/mainwindow_control.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindowControl main;
	
	// mainwindow->show()
	main.show();

	return  app.exec();
	
}