#ifndef DEFAULT_WIDGETS_H
#define DEFAULT_WIDGETS_H

#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>


class ButtonMenu : public QPushButton {
public:
	explicit ButtonMenu(const QString &text, const QIcon &icon, QWidget *parent = nullptr);
	virtual ~ButtonMenu();

	virtual QSize sizeHint() const override;
protected:
	virtual void paintEvent(QPaintEvent *e) override;

private:
	QPixmap m_pixmap;


};





#endif		