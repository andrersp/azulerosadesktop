#include "view/defaultComboBox.h"

DefaultComboBox::DefaultComboBox(QWidget *parent) : QComboBox(parent){
	setObjectName("default_combobox");
	setMinimumHeight(30);
	setMaximumHeight(35);
	setMinimumWidth(120);
	setContentsMargins(4, 0, 0, 0);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}
DefaultComboBox::~DefaultComboBox(){}