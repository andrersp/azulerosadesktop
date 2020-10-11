#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include "control/mainwindow_control.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QFile layout_qss(":Style/Style/layout.qss");
	layout_qss.open(QFile::ReadOnly);
	app.setStyleSheet(QLatin1String(layout_qss.readAll()));

	MainWindowControl main;
	
	// mainwindow->show()
	main.show();

	return  app.exec();
	
}