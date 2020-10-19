#ifndef DEFAULT_WIDGETS_H
#define DEFAULT_WIDGETS_H

#include <QDebug>
#include <QFrame>
#include <QHBoxLayout>
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
};

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
	explicit FrameSearch(QWidget *parent = nullptr);
	virtual ~FrameSearch();

	QHBoxLayout *grid;

};

#endif