#include "view/default_widgets.h"

#include <QPainter>
ButtonMenu::ButtonMenu(const QString &text, const QIcon &icon, QWidget *parent) : QPushButton(text, parent){
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	setFixedHeight(35);
	// setFlat(true);
	setFocusPolicy(Qt::NoFocus);
	setCursor(Qt::PointingHandCursor);
	setObjectName("button_menu");
	setCheckable(true);


	m_pixmap = icon.pixmap(QSize(20, 20));


	qDebug() << m_pixmap;
}
ButtonMenu::~ButtonMenu(){}

QSize ButtonMenu::sizeHint() const {
	const auto parentHint = QPushButton::sizeHint();
	return  QSize(parentHint.width() + m_pixmap.width(), std::max(parentHint.height(), m_pixmap.height()));

}

void ButtonMenu::paintEvent(QPaintEvent *e){

	QPushButton::paintEvent(e);

	if (!m_pixmap.isNull()){
		const int y = (height() - m_pixmap.height()) / 2;
		QPainter painter(this);
		painter.drawPixmap(10, y, m_pixmap);
	}

}