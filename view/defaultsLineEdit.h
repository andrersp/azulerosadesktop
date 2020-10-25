#ifndef DEFAULTSLINEEDIT_H
#define DEFAULTSLINEEDIT_H

#include <QLineEdit>

class DefaultLineEdit : public QLineEdit {
public:
	explicit DefaultLineEdit(const QString &placeholder, QWidget *parent = nullptr);
	virtual ~DefaultLineEdit();

};
#endif