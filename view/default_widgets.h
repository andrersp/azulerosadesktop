#ifndef DEFAULT_WIDGETS_H
#define DEFAULT_WIDGETS_H

#include <view/customshadow.h>
#include <QDebug>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QToolButton>

class ButtonMenu : public QPushButton {
 public:
  explicit ButtonMenu(const QString &text, const QIcon &icon,
                      QWidget *parent = nullptr);
  virtual ~ButtonMenu();

  virtual QSize sizeHint() const override;

 protected:
  virtual void paintEvent(QPaintEvent *e) override;

 private:
  QPixmap m_pixmap;
  QIcon *m_active;
};

// Custom Buttom Add
class ButtonAdd : public QPushButton {
 public:
  explicit ButtonAdd(const QString &text,
                      QWidget *parent = nullptr);
  virtual ~ButtonAdd();

  virtual QSize sizeHint() const override;

 protected:
  virtual void paintEvent(QPaintEvent *e) override;
  virtual bool event(QEvent *event) override;


 private:
  QPixmap *m_pixmap;
  QPixmap *m_active;
  bool is_focus = false;
};

// End Custom Buttom Add

// Custom Buttom Edit
class ButtonEditTable : public QPushButton {
 public:
  explicit ButtonEditTable(const QString &text,
                      QWidget *parent = nullptr);
  virtual ~ButtonEditTable();

  virtual QSize sizeHint() const override;

 protected:
  virtual void paintEvent(QPaintEvent *e) override;
  virtual bool event(QEvent *event) override;


 private:
  QPixmap *m_pixmap;
  QPixmap *m_active;
  bool is_focus = false;
};

// End Custom Buttom Edit

// Line Edit With Left Icon
class LineEditIconLeft : public QLineEdit {
 public:
  explicit LineEditIconLeft(const QIcon &icon, QWidget *parent = nullptr);
  virtual ~LineEditIconLeft();
  void setIcon(QIcon icon);

 protected:
  virtual void paintEvent(QPaintEvent *e);

 private:
  QIcon _icon;
};

class FrameSearch : public QFrame {
 public:
  explicit FrameSearch(const QString &title, QWidget *parent = nullptr);
  virtual ~FrameSearch();
  ButtonAdd *button;

 private:
  QLabel *title;
  QHBoxLayout *grid;
};

class LineEditSearch : public QLineEdit {
  Q_OBJECT
 public:
  explicit LineEditSearch(const QString &text, QWidget *parent = nullptr);
  virtual ~LineEditSearch();

 protected:
  void paintEvent(QPaintEvent *e);

 private:
  QIcon m_icon;
};


// Default Frame Title
class FrameTitle : public QFrame {
public:
  explicit FrameTitle(const QString &title, QWidget *parent = nullptr);
  virtual ~FrameTitle();
private:
  QLabel *lb_title;
  QHBoxLayout *grid;
};



// Default Frame Form
class FrameForm : public QWidget {
  Q_OBJECT
public:
  explicit FrameForm(const QString &title, QWidget *parent = nullptr);
  virtual ~FrameForm();
public slots:
  void addWidget(QWidget *widget, int row, int col, int rowSpan, int colSpan, Qt::Alignment alignment = Qt::Alignment());



private:
  QVBoxLayout *grid;
  QGridLayout *form_grid;
  FrameTitle *fr_title;
  QFrame *form_frame;
};

#endif