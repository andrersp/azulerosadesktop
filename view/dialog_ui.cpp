#include "view/dialog_ui.h"

// Mask Widget
MaskWidget::MaskWidget(QWidget *parent) : QWidget(parent) {
  setWindowFlag(Qt::FramelessWindowHint, true);
  setAttribute(Qt::WA_StyledBackground);
  setStyleSheet("background:rgba(0,0,0,99);");
  setAttribute(Qt::WA_DeleteOnClose);
}
void MaskWidget::show() {
  if (!parentWidget()) {
    return;
  }
  setGeometry(0, 0, parentWidget()->geometry().width(),
              parentWidget()->geometry().height());
  QWidget::show();
}

MaskWidget::~MaskWidget() {}

DialogMsg::DialogMsg(QWidget *frame, const int status, const QString msg)
    : QDialog() {
  mask = new MaskWidget(frame);

  QFile css(":Style/Style/dialog.qss");
  css.open(QFile::ReadOnly);
  setStyleSheet(QLatin1String(css.readAll()));

  QString titulo;

  switch (status) {
  case 0:
    titulo = "Erro!";
    icon_dialog = new QPixmap(":Images/Images/error.svgz");
    break;
  case 1:
    titulo = "Sucesso!";
    icon_dialog = new QPixmap(":Images/Images/success.svgz");
    break;
  case 2:
    titulo = "Atenção!";
    icon_dialog = new QPixmap(":Images/Images/attention.svgz");
    break;
  }
  setWindowTitle(titulo);
  setObjectName("dialog_confirm");
  resize(400, 300);

  setWindowFlags(Qt::FramelessWindowHint);
  setAttribute(Qt::WA_DeleteOnClose);
  QPainterPath path;
  path.addRoundedRect(QRect(this->rect()), 10, 10);
  QRegion mask = QRegion(path.toFillPolygon().toPolygon());
  setMask(mask);

  grid_dialog = new QVBoxLayout(this);
  grid_dialog->setMargin(10);

  label_titulo = new QLabel(this);
  label_titulo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label_titulo->setFixedHeight(25);
  label_titulo->setTextFormat(Qt::AutoText);
  label_titulo->setText(titulo);
  label_titulo->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  label_titulo->setObjectName("titulo_dialog");
  grid_dialog->addWidget(label_titulo);

  grid_titulo = new QHBoxLayout(label_titulo);
  grid_titulo->setSpacing(0);
  grid_titulo->setMargin(0);
  grid_titulo->setAlignment(Qt::AlignVCenter);

  bt_close = new QPushButton(label_titulo);
  bt_close->setIcon(QIcon(":Images/Images/bt_close.svgz"));
  bt_close->setIconSize(QSize(15, 15));
  bt_close->setCursor(Qt::PointingHandCursor);
  bt_close->setFocusPolicy(Qt::NoFocus);
  bt_close->setFlat(true);
  grid_titulo->addWidget(bt_close, 0, Qt::AlignRight);

  grid_dialog->addSpacing(5);

  lb_icon = new QLabel(this);
  lb_icon->setFixedSize(QSize(50, 50));
  lb_icon->setPixmap(icon_dialog->scaled(lb_icon->size(), Qt::KeepAspectRatio,
                                         Qt::SmoothTransformation));
  lb_icon->setScaledContents(true);
  grid_dialog->addWidget(lb_icon, 0, Qt::AlignHCenter);

  grid_dialog->addSpacing(5);

  lb_msg = new QLabel(this);
  lb_msg->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  lb_msg->setFixedHeight(110);
  lb_msg->setTextFormat(Qt::AutoText);
  lb_msg->setText(msg);
  lb_msg->setWordWrap(true);
  lb_msg->setObjectName("lb_dialog_msg");
  lb_msg->setAlignment(Qt::AlignCenter);

  grid_dialog->addWidget(lb_msg);

  lb_dica = new QLabel(this);
  lb_dica->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  lb_dica->setFixedHeight(20);
  lb_dica->setTextFormat(Qt::AutoText);
  lb_dica->setText("Pressione OK para sair ou Cancelar para continuar");
  lb_dica->setAlignment(Qt::AlignCenter);
  lb_dica->setObjectName("lb_dialog_dica");
  grid_dialog->addWidget(lb_dica, 0, Qt::AlignHCenter);

  button_box = new QDialogButtonBox(Qt::Horizontal);
  button_box->setMaximumSize(QSize(300, 30));
  button_box->setCenterButtons(true);

  bt_confirm = new QPushButton(this);
  bt_confirm->setFixedSize(QSize(80, 30));
  bt_confirm->setText("OK");
  bt_confirm->setObjectName("bt_confirm");
  bt_confirm->setCursor(Qt::PointingHandCursor);
  button_box->addButton(bt_confirm, button_box->AcceptRole);

  bt_cancel = new QPushButton(this);
  bt_cancel->setFixedSize(QSize(100, 30));
  bt_cancel->setText("CANCELAR");
  bt_cancel->setObjectName("bt_cancel");
  bt_cancel->setCursor(Qt::PointingHandCursor);
  button_box->addButton(bt_cancel, button_box->RejectRole);

  grid_dialog->addWidget(button_box, 0, Qt::AlignCenter);

  connect(bt_close, &QAbstractButton::clicked, this, &QDialog::accept);
  connect(bt_cancel, &QAbstractButton::clicked, this, &QDialog::close);
  connect(bt_confirm, &QAbstractButton::clicked, this, &QDialog::accept);

  // status ? setWindowTitle("ok") : setWindowTitle("Não");
}
int DialogMsg::show() {

  mask->show();
  int result = this->exec();
  mask->close();
  return result;
}

DialogMsg::~DialogMsg() {}

DialogImg::DialogImg(const QPixmap &img) : QDialog() {
  QFile css(":Style/Style/dialog.qss");
  css.open(QFile::ReadOnly);
  setStyleSheet(QLatin1String(css.readAll()));

  setWindowTitle("Visualizar de Imagem");
  setObjectName("dialog_confirm");
  resize(800, 600);

  setWindowFlags(Qt::FramelessWindowHint);
  setAttribute(Qt::WA_DeleteOnClose);
  QPainterPath path;
  path.addRoundedRect(QRect(this->rect()), 10, 10);
  QRegion mask = QRegion(path.toFillPolygon().toPolygon());
  setMask(mask);

  grid_dialog = new QVBoxLayout(this);
  grid_dialog->setMargin(10);

  label_titulo = new QLabel(this);
  label_titulo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label_titulo->setFixedHeight(30);
  label_titulo->setTextFormat(Qt::AutoText);
  label_titulo->setText("Visualizar de Imagem");
  label_titulo->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  label_titulo->setObjectName("titulo_dialog");
  grid_dialog->addWidget(label_titulo);

  grid_titulo = new QHBoxLayout(label_titulo);
  grid_titulo->setSpacing(0);
  grid_titulo->setMargin(0);
  grid_titulo->setAlignment(Qt::AlignVCenter);

  bt_close = new QPushButton(label_titulo);
  bt_close->setIcon(QIcon(":Images/Images/bt_close.svgz"));
  bt_close->setIconSize(QSize(15, 15));
  bt_close->setCursor(Qt::PointingHandCursor);
  bt_close->setFocusPolicy(Qt::NoFocus);
  bt_close->setFlat(true);
  grid_titulo->addWidget(bt_close, 0, Qt::AlignRight);

  grid_dialog->addSpacing(10);

  lb_imagem = new QLabel(this);
  lb_imagem->setMaximumSize(QSize(780, 440));
  // lb_imagem->setScaledContents(true);
  lb_imagem->setAlignment(Qt::AlignCenter);
  grid_dialog->addWidget(lb_imagem);

  lb_imagem->setPixmap(img.scaledToHeight(440, Qt::SmoothTransformation));
  

  connect(bt_close, &QAbstractButton::clicked, this, &DialogImg::close);
}
DialogImg::~DialogImg() {}



// Dailog Input
DialogInput::DialogInput(const QString &title, QWidget *frame)
    : QDialog() {
  
  QFile css(":Style/Style/dialog.qss");
  css.open(QFile::ReadOnly);
  setStyleSheet(QLatin1String(css.readAll()));

  setWindowTitle(title);
  setObjectName("dialog_confirm");
  resize(400, 150);

  setWindowFlags(Qt::FramelessWindowHint);
  // setAttribute(Qt::WA_DeleteOnClose);
  QPainterPath path;
  path.addRoundedRect(QRect(this->rect()), 10, 10);
  QRegion mask = QRegion(path.toFillPolygon().toPolygon());
  setMask(mask);

  grid_dialog = new QVBoxLayout(this);
  grid_dialog->setMargin(10);

  label_titulo = new QLabel(this);
  label_titulo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label_titulo->setFixedHeight(25);
  label_titulo->setTextFormat(Qt::AutoText);
  label_titulo->setText(title);
  label_titulo->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  label_titulo->setObjectName("titulo_dialog");
  grid_dialog->addWidget(label_titulo);

  grid_titulo = new QHBoxLayout(label_titulo);
  grid_titulo->setSpacing(0);
  grid_titulo->setMargin(0);
  grid_titulo->setAlignment(Qt::AlignVCenter);

  bt_close = new QPushButton(label_titulo);
  bt_close->setIcon(QIcon(":Images/Images/bt_close.svgz"));
  bt_close->setIconSize(QSize(15, 15));
  bt_close->setCursor(Qt::PointingHandCursor);
  bt_close->setFocusPolicy(Qt::NoFocus);
  bt_close->setFlat(true);
  grid_titulo->addWidget(bt_close, 0, Qt::AlignRight);

  grid_dialog->addSpacing(5);

  grid_dialog->addSpacing(5);

  tx_name = new DefaultLineEdit(title, this);

  grid_dialog->addWidget(tx_name);

  lb_dica = new QLabel(this);
  lb_dica->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  lb_dica->setFixedHeight(20);
  lb_dica->setTextFormat(Qt::AutoText);
  lb_dica->setText("Para sair pressione Cancelar");
  lb_dica->setAlignment(Qt::AlignCenter);
  lb_dica->setObjectName("lb_dialog_dica");
  grid_dialog->addWidget(lb_dica, 0, Qt::AlignHCenter);

  button_box = new QDialogButtonBox(Qt::Horizontal);
  button_box->setMaximumSize(QSize(300, 30));
  button_box->setCenterButtons(true);

  bt_confirm = new QPushButton(this);
  bt_confirm->setFixedSize(QSize(100, 30));
  bt_confirm->setText("SALVAR");
  bt_confirm->setObjectName("bt_save");
  bt_confirm->setCursor(Qt::PointingHandCursor);
  button_box->addButton(bt_confirm, button_box->AcceptRole);

  bt_cancel = new QPushButton(this);
  bt_cancel->setFixedSize(QSize(100, 30));
  bt_cancel->setText("CANCELAR");
  bt_cancel->setObjectName("bt_cancel_input");
  bt_cancel->setCursor(Qt::PointingHandCursor);
  button_box->addButton(bt_cancel, button_box->RejectRole);

  grid_dialog->addWidget(button_box, 0, Qt::AlignCenter);

  connect(bt_close, &QAbstractButton::clicked, this, &QDialog::accept);
  connect(bt_cancel, &QAbstractButton::clicked, this, &QDialog::close);
  connect(bt_confirm, &QAbstractButton::clicked, this, &QDialog::accept);

  // status ? setWindowTitle("ok") : setWindowTitle("Não");
}

DialogInput::~DialogInput() {}