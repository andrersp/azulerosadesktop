#include "view/frame_side_menu.h"

FrameMenu::FrameMenu(QWidget *parent) : QFrame(parent) {
  setFixedWidth(180);
  setObjectName("fr_menu");

  grid = new QVBoxLayout(this);
  grid->setAlignment(Qt::AlignTop);
  grid->setMargin(0);
  grid->setSpacing(2);


  QIcon icon_home(":Images/Images/dashboard.svgz");
  bt_home = new ButtonMenu("Dashboard", icon_home, this);
  grid->addWidget(bt_home);


  // Stock Session
  label = new QLabel(this);
  label->setText("Estoque");
  label->setObjectName("label_menu");
  label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label->setFixedHeight(25);
  grid->addWidget(label);

  bt_product = new ButtonMenu("Produtos", QIcon(":Images/Images/products.svgz"), this);
  grid->addWidget(bt_product);


  QIcon icon_tag(":Images/Images/tag.svgz");
  bt_product = new ButtonMenu("Categorias", icon_tag, this);
  grid->addWidget(bt_product);
  // end Stock Session

  label = new QLabel(this);
  label->setText("Cadastros");
  label->setObjectName("label_menu");
  label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  label->setFixedHeight(25);
  grid->addWidget(label);

  bt_product = new ButtonMenu("Clientes", QIcon(":Images/Images/clients.svgz"), this);
  grid->addWidget(bt_product);

  bt_product = new ButtonMenu("Fornecedores", QIcon(":Images/Images/providers.svgz"), this);
  grid->addWidget(bt_product);

  button_group = new QButtonGroup(this);

  foreach (auto &iten, findChildren<QPushButton *>()) {
    button_group->addButton(iten);
  }
}



FrameMenu::~FrameMenu() {}