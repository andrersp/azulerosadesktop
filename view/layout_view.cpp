
#include "view/layout_view.h"

#include <QPushButton>
#include <QToolBar>

MainWindowView::MainWindowView(QObject *parent) {
  setMinimumSize(QSize(1268, 684));
  setObjectName("layout_window");

  central_grid = new QGridLayout(this);
  central_grid->setSpacing(0);
  central_grid->setMargin(0);
  central_grid->setAlignment(Qt::AlignTop);

  // Top Frame Menu
  fr_top = new QFrame(this);
  fr_top->setFixedHeight(55);
  fr_top->setFrameShadow(QFrame::Plain);
  fr_top->setFrameShape(QFrame::NoFrame);
  fr_top->setObjectName("fr_top");

  grid_top = new QHBoxLayout(fr_top);
  grid_top->setContentsMargins(0, 30, 0, 30);

  central_grid->addWidget(fr_top, 0, 0, 1, 2);
  // End Top Frame Menu

  // Side Menu
  fr_menu = new FrameMenu(this);

  central_grid->addWidget(fr_menu, 1, 0, 1, 1);
  // End SIde Menu

  // Stack WIdget Container
  container = new QStackedWidget(this);
  container->setObjectName("container");

  central_grid->addWidget(container, 1, 1, 1, 1);  

  status_bar = new QStatusBar(this);
  status_bar->setMaximumHeight(20);
  status_bar->setMinimumHeight(20);
  status_bar->setObjectName("status_bar");
  status_bar->setSizeGripEnabled(false);
  status_bar->setContentsMargins(2, 0, 2, 0);
  status_bar->showMessage(tr("Testando"));

  // mainwindow->setStatusBar(status_bar);
  central_grid->addWidget(status_bar, 2, 0, 1, 2);

  QMetaObject::connectSlotsByName(parent);
}

MainWindowView::~MainWindowView() { qDebug() << "delete View"; }