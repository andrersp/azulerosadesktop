#ifndef DEFAULTSLABEL_H
#define DEFAULTSLABEL_H

#include <QLabel>

class DefaultLabel : public QLabel {
public:
	explicit DefaultLabel(const QString &text, QWidget *parent = nullptr);
	virtual ~DefaultLabel();

};

#endif