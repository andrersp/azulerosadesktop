#include "view/default_widgets.h"

#include <QPainter>
#include <QPainterPath>
ButtonMenu::ButtonMenu(const QString &text, const QIcon &icon, QWidget *parent)
    : QPushButton(text, parent) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  setFixedHeight(35);
  // setFlat(true);
  setFocusPolicy(Qt::NoFocus);
  setCursor(Qt::PointingHandCursor);
  setObjectName("button_menu");
  setCheckable(true);

  m_pixmap = icon.pixmap(QSize(20, 20));
  
}

QSize ButtonMenu::sizeHint() const {
  const auto parentHint = QPushButton::sizeHint();
  return QSize(parentHint.width() + m_pixmap.width(),
               std::max(parentHint.height(), m_pixmap.height()));
}

void ButtonMenu::paintEvent(QPaintEvent *e) {

  QPushButton::paintEvent(e);

  if (!m_pixmap.isNull()) {
    const int y = (height() - m_pixmap.height()) / 2;
    QPainter painter(this);
    painter.drawPixmap(10, y, m_pixmap);
  }
}

ButtonMenu::~ButtonMenu() {}

// End Button Menu

// start Line Edit Icon Left

LineEditIconLeft::LineEditIconLeft(const QIcon &icon, QWidget *parent)
    : QLineEdit(parent) {

  setIcon(icon);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void LineEditIconLeft::setIcon(QIcon icon) {
  _icon = icon;

  if (_icon.isNull()) {
    setTextMargins(1, 1, 1, 1);
    return;
  }

  setTextMargins(1, 1, 1, 1);
}

void LineEditIconLeft::paintEvent(QPaintEvent *e) {
	QLineEdit::paintEvent(e);

	if (!_icon.isNull()){
		QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    

		

		QPixmap pxm = _icon.pixmap(height() - 16, height() - 16);
		int x = 12;
		
		painter.drawPixmap(x, 6, pxm);
    // painter.drawLine(40, 3, 40, height() - 4);
	
	}
}

LineEditIconLeft::~LineEditIconLeft() {}
