#include "widgets/defaultsLabel.h"

DefaultLabel::DefaultLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent) {

    	setObjectName("default_label");
    	setFrameShape(QFrame::NoFrame);
    	setFrameShadow(QFrame::Plain);
    	setFixedHeight(25);
    	// setMaximumWidth(120);
    	setAlignment(Qt::AlignLeft);
    	setContentsMargins(4, 5, 0, 3);
    }

DefaultLabel::~DefaultLabel() {}


// upload Image
LabelUploadImage::LabelUploadImage(QWidget *parent) : QLabel(parent)
{

	setAlignment(Qt::AlignCenter);
	setCursor(Qt::PointingHandCursor);
	// setScaledContents(true);
	setMinimumSize(QSize(100, 65));
	setMaximumSize(QSize(200, 112));
	setContentsMargins(5, 5, 5, 5);
	setObjectName("lb_imagem");
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	layout = new QVBoxLayout(this);
	layout->setSpacing(3);
	layout->setMargin(0);
	layout->setAlignment(Qt::AlignTop);

	bt_add = new QToolButton(this);
	bt_add->setCursor(Qt::PointingHandCursor);
	bt_add->setFixedSize(QSize(20, 20));
	bt_add->setIconSize(QSize(15, 15));
	bt_add->setFocusPolicy(Qt::NoFocus);
	bt_add->setToolTip("Adicionar Imagem");
	bt_add->setIcon(QIcon(":Images/Images/icon_add_image.svgz"));
	bt_add->setObjectName("bt_add_image");
	layout->addWidget(bt_add, 0, Qt::AlignRight | Qt::AlignTop);

	bt_show = new QToolButton(this);
	bt_show->setCursor(Qt::PointingHandCursor);
	bt_show->setFixedSize(QSize(20, 20));
	bt_show->setIconSize(QSize(15, 15));
	bt_show->setFocusPolicy(Qt::NoFocus);
	bt_show->setToolTip("Ampliar Imagem");
	bt_show->setIcon(QIcon(":Images/Images/icon_show_image.svgz"));
	bt_show->setObjectName("bt_ver_image");
	bt_show->setDisabled(true);
	layout->addWidget(bt_show, 0, Qt::AlignRight | Qt::AlignTop);

	bt_remove = new QToolButton(this);
	bt_remove->setCursor(Qt::PointingHandCursor);
	bt_remove->setFixedSize(QSize(20, 20));
	bt_remove->setIconSize(QSize(15, 15));
	bt_remove->setFocusPolicy(Qt::NoFocus);
	bt_remove->setToolTip("Remover Imagem");
	bt_remove->setIcon(QIcon(":Images/Images/icon_remove_image.svgz"));
	bt_remove->setObjectName("bt_remove_image");
	bt_remove->setDisabled(true);
	layout->addWidget(bt_remove, 0, Qt::AlignRight | Qt::AlignTop);

	tx_id = new QLineEdit(this);
	tx_id->setHidden(true);

	connect(bt_remove, &QToolButton::clicked, this, &LabelUploadImage::remove_image);
	connect(bt_show, &QToolButton::clicked, this, &LabelUploadImage::show_image);
	connect(bt_add, &QToolButton::clicked, this, &LabelUploadImage::upload_image);
}
void LabelUploadImage::set_image_url(const QByteArray &img, const QString &id_img)
{

	img_data.loadFromData(img);
	setPixmap(img_data.scaledToHeight(this->height(), Qt::SmoothTransformation));
	tx_id->setText(id_img);
	// bt_add->setDisabled(true);
	bt_show->setEnabled(true);
	bt_remove->setEnabled(true);
}

void LabelUploadImage::remove_image()
{

	DialogMsg *dialog = new  DialogMsg(parentWidget(), 2, "Deseja remover a imagem?\nEssa ação não poderá ser desfeita.\nContinuar?");
	bool result = dialog->exec();

	if (!result) {
		return;
	}
	if (!tx_id->text().isEmpty()) {
		emit signal_remove_image(tx_id->text());
		tx_id->clear();
		clear();
		bt_remove->setDisabled(true);
		bt_show->setDisabled(true);

	}
	else {
		clear();
		bt_remove->setDisabled(true);
		bt_show->setDisabled(true);

	}
}

void LabelUploadImage::show_image()
{

	DialogImg *dialog = new DialogImg(img_data);
	MaskWidget *mask = new MaskWidget(parentWidget()->parentWidget()->parentWidget()->parentWidget()->parentWidget());
	mask->show();
	dialog->exec();
	mask->close();
}

void LabelUploadImage::upload_image() {
	QFileDialog dialog(this);
	dialog.setOption(QFileDialog::DontUseNativeDialog, true);

	QString fname = dialog.getOpenFileName(this, tr("Selecionar Imagem"), "", tr("Image Files (*.png *.jpg *.jpeg)"));

	if (!fname.isEmpty()) {

		

		if (!this->pixmap(Qt::ReturnByValue).isNull()) {
			DialogMsg *dialog = new  DialogMsg(parentWidget(), 2, "A Imagem Anterior será removida.\nEssa ação não poderá ser desfeita.\nContinuar?");
			bool result = dialog->exec();

			if (!result) {
				return;
			}
			if (!tx_id->text().isEmpty()) {
				emit signal_remove_image(tx_id->text());
				tx_id->clear();
			}
		}
		img_data.load(fname);
		this->setPixmap(img_data.scaledToHeight(this->height(), Qt::SmoothTransformation));
		bt_show->setEnabled(true);
		bt_remove->setEnabled(true);
	}
}

void LabelUploadImage::clearContent(){
	tx_id->clear();
	bt_remove->setDisabled(true);
	bt_show->setDisabled(true);
	clear();
}


LabelUploadImage::~LabelUploadImage(){}