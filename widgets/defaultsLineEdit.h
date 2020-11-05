#ifndef DEFAULTSLINEEDIT_H
#define DEFAULTSLINEEDIT_H

#include <QCompleter>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>
#include <QTextEdit>
#include <QToolButton>
#include <QDebug>

// Default Line Edit
class DefaultLineEdit : public QLineEdit {
 public:
  explicit DefaultLineEdit(const QString &placeholder,
                           QWidget *parent = nullptr);
  virtual ~DefaultLineEdit();
};

// Default Line Edit Float
class DefaultLineEditFloat : public QLineEdit {
 public:
  explicit DefaultLineEditFloat(const QString &placeholder,
                                QWidget *parent = nullptr);
  virtual ~DefaultLineEditFloat();

 private:
  void format_number();
};

// Default Text Edit
class DefaultTextEdit : public QTextEdit {
 public:
  explicit DefaultTextEdit(const QString &placeholder,
                           QWidget *parent = nullptr);
  virtual ~DefaultTextEdit();
};

// Custom Completer
class DefaultCompleter : public QLineEdit {
  Q_OBJECT
 public:
  explicit DefaultCompleter(const QString &placeholder,
                            QWidget *parent = nullptr);
  virtual ~DefaultCompleter();

  QCompleter *completation;
 public slots:
  void show_popup();
private slots:
  void set_current_row(const QModelIndex &index);


 private:
  QToolButton *bt_popup;
  QHBoxLayout *cp_layout;
};


// Custom Ccompleter with add Button
class DefaultLineEditSearchAdd : public QLineEdit {
  Q_OBJECT
 public:
  explicit DefaultLineEditSearchAdd(const QString &placeholder,  QWidget *parent = nullptr);
  virtual ~DefaultLineEditSearchAdd();
  QCompleter *completation;
  QToolButton *bt_add;

 private:
  QToolButton *bt_popup;
  QHBoxLayout *grid;
private slots:
  void set_current_index(const QModelIndex &index);
 public slots:
  void show_popup();
};

#endif