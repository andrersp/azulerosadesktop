#ifndef DEFAULTSLINEEDIT_H
#define DEFAULTSLINEEDIT_H

#include <QLineEdit>
#include <QTextEdit>
#include <QRegExp>
#include <QRegExpValidator>
#include <QCompleter>
#include <QToolButton>
#include <QHBoxLayout>


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

// Custom Completer

class DefaultCompleter : public QLineEdit {
	Q_OBJECT
public:
	explicit DefaultCompleter(const QString &placeholder, QWidget *parent = nullptr);
	virtual ~DefaultCompleter();

	QCompleter *completation;
private slots:
	void show_popup();

private:
	QToolButton *bt_popup;
	QHBoxLayout *cp_layout;

};

#endif