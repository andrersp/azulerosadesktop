#ifndef DEFAULTSLABEL_H
#define DEFAULTSLABEL_H

#include <QLabel>
#include <QVBoxLayout>
#include <QToolButton>
#include <QLineEdit>
#include <QFileDialog>
#include "view/dialog_ui.h"

class DefaultLabel : public QLabel {
public:
	explicit DefaultLabel(const QString &text, QWidget *parent = nullptr);
	virtual ~DefaultLabel();

};

// Label Upload Image

// Label Image
class LabelUploadImage : public QLabel
{
	Q_OBJECT

public:
	LabelUploadImage(QWidget *parent = nullptr);
	~LabelUploadImage();
	QPixmap img_data;
	QLineEdit *tx_id;

private:
	QVBoxLayout *layout;
	QToolButton *bt_add, *bt_remove, *bt_show;
public slots:
	void set_image_url(const QByteArray &img, const QString &id_img);
	void clearContent();
	

	//	void remove_image();
private slots:
	void remove_image();
	void show_image();
	void upload_image();


signals:

void signal_remove_image(const QString &id_image);

};

#endif