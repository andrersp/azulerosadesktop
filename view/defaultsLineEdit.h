#ifndef DEFAULTSLINEEDIT_H
#define DEFAULTSLINEEDIT_H

#include <QLineEdit>
#include <QTextEdit>
#include <QRegExp>
#include <QRegExpValidator>


// Default Line Edit
class DefaultLineEdit : public QLineEdit {
public:
	explicit DefaultLineEdit(const QString &placeholder, QWidget *parent = nullptr);
	virtual ~DefaultLineEdit();

};

// Default Line Edit Float
class DefaultLineEditFloat : public QLineEdit {
public:
	explicit DefaultLineEditFloat(const QString &placeholder, QWidget *parent = nullptr);
	virtual ~DefaultLineEditFloat();
private:
	void format_number();

};

// Default Text Edit
class DefaultTextEdit : public QTextEdit {
public:
	explicit DefaultTextEdit(const QString &placeholder, QWidget *parent = nullptr);
	virtual ~DefaultTextEdit();
};
#endif