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
	db_font->addApplicationFont(":Fonts/Fonts/Amble-Regular.ttf");
	qDebug() << QT_VERSION_STR;
	
	

	QFile layout_qss(":Style/Style/layout.qss");
	QFile labels_qss(":Style/Style/labels.qss");
	QFile buttons_qss(":Style/Style/buttons.qss");
	QFile text_edit_qss(":Style/Style/text_edit.qss");
	QFile cbox_qss(":Style/Style/combobox.qss");
	layout_qss.open(QFile::ReadOnly);
	labels_qss.open(QFile::ReadOnly);
	buttons_qss.open(QFile::ReadOnly);
	text_edit_qss.open(QFile::ReadOnly);
	cbox_qss.open(QFile::ReadOnly);
	app.setStyleSheet(QLatin1String(
		layout_qss.readAll() + 
		labels_qss.readAll() +
		buttons_qss.readAll() +
		text_edit_qss.readAll() + 
		cbox_qss.readAll()
		));

	MainWindowControl main;
	// main.showMaximized();	
	
	// mainwindow->show()
	main.show();

	return  app.exec();
	
}