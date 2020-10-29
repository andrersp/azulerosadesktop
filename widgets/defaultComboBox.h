#ifndef DEFAULTCOMBOBOX_H
#define DEFAULTCOMBOBOX_H
#include <QComboBox>


class DefaultComboBox : public QComboBox {
public:
	explicit DefaultComboBox(QWidget *parent = nullptr);
	virtual ~DefaultComboBox();

};

#endif