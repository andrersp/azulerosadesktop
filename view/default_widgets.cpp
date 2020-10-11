#include "view/default_widgets.h"

BtMenu::BtMenu(QWidget *parent) : QToolButton(parent)
{
	// QSizePolicy::setHeightForWidth(this->sizePolicy().hasHeightForWidth());

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	setFixedHeight(40);
	setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	setCursor(Qt::PointingHandCursor);
	setObjectName("bt_menu");
	setIconSize(QSize(30, 30));
}
BtMenu::~BtMenu() {}