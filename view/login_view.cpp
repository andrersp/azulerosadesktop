#include "view/login_view.h"

void LoginView::setup_ui() {

  setObjectName("window_login");
  grid_qw_login = new QHBoxLayout(this);
  grid_qw_login->setSpacing(0);
  grid_qw_login->setMargin(10);

  container_login = new QFrame(this);
  container_login->setFixedSize(QSize(700, 400));
  container_login->setObjectName("container_login");

  grid_container_login = new QHBoxLayout(container_login);
  grid_container_login->setSpacing(40);
  grid_container_login->setMargin(20);
  grid_container_login->setAlignment(Qt::AlignCenter);

  lb_logo = new QLabel(this);
  lb_logo->setFixedSize(QSize(200, 200));
  lb_logo->setPixmap(QPixmap(":Images/Images/logo.svgz")
                         .scaled(lb_logo->size(), Qt::KeepAspectRatio,
                                 Qt::SmoothTransformation));

  grid_container_login->addWidget(lb_logo);

  fr_login = new QFrame(container_login);
  fr_login->setFixedSize(QSize(300, 300));

  grid_fr_login = new QVBoxLayout(fr_login);

  tx_user =
      new LineEditIconLeft(QIcon(":Images/Images/icon_user.svgz"), fr_login);
  tx_user->setFixedHeight(40);
  tx_user->setPlaceholderText("Usuário");
  tx_user->setObjectName("tx_login");

  grid_fr_login->addWidget(tx_user);

  tx_password = new LineEditIconLeft(QIcon(":Images/Images/icon_password.svgz"),
                                     fr_login);
  tx_password->setFixedHeight(40);
  tx_password->setEchoMode(QLineEdit::Password);
  tx_password->setPlaceholderText("Senha");
  tx_password->setObjectName("tx_login");

  grid_fr_login->addWidget(tx_password);

  bt_login = new QPushButton(fr_login);
  bt_login->setText("LOGIN");
  bt_login->setFixedHeight(40);
  bt_login->setCursor(Qt::PointingHandCursor);
  bt_login->setFocusPolicy(Qt::NoFocus);
  bt_login->setObjectName("bt_login");

  grid_fr_login->addWidget(bt_login);

  grid_container_login->addWidget(fr_login);

  grid_qw_login->addWidget(container_login, 0, Qt::AlignCenter);

  qDebug() << "Testando";
}

LoginView::~LoginView() { qDebug() << "Saindo"; }