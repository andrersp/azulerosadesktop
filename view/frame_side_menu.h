#ifndef TOOLBAR_VIEW_H
#define TOOLBAR_VIEW_H

#include <QDebug>
#include <QButtonGroup>
#include <QFrame>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

#include "view/default_widgets.h"

class FrameMenu : public QFrame {

public:
	FrameMenu(QWidget *parent = nullptr);
	~FrameMenu();
	QVBoxLayout *grid;
	ButtonMenu *bt_home, *bt_product;

	QLabel *label;

private:
	QButtonGroup *button_group;	

};




#endif