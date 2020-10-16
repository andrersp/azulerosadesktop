#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include <QFontDatabase>
#include "control/mainwindow_control.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QFontDatabase *db_font = new QFontDatabase();
	db_font->addApplicationFont(":Fonts/Fonts/OpenSans-Regular.ttf");
	db_font->addApplicationFont(":Fonts/Fonts/Poppins-Bold.ttf");
	db_font->addApplicationFont(":Fonts/Fonts/Poppins-Medium.ttf");
	db_font->addApplicationFont(":Fonts/Fonts/Montserrat-Bold.ttf");
	
	

	QFile layout_qss(":Style/Style/layout.qss");
	QFile labels_qss(":Style/Style/labels.qss");
	layout_qss.open(QFile::ReadOnly);
	labels_qss.open(QFile::ReadOnly);
	app.setStyleSheet(QLatin1String(
		layout_qss.readAll() + 
		labels_qss.readAll()
		));

	MainWindowControl main;
	
	// mainwindow->show()
	main.show();

	return  app.exec();
	
}