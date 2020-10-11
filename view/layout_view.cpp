
#include "view/layout_view.h"

#include <QPushButton>
#include <QToolBar>
#include "view/toolbar_view.h"

MainWindowView::MainWindowView(QObject *parent){

    setMinimumSize(QSize(1268, 684));
    setObjectName("layout_window");

    central_grid = new QGridLayout(this);
    central_grid->setSpacing(0);
    central_grid->setMargin(0);
    central_grid->setAlignment(Qt::AlignTop);


    // Top Frame Menu
    fr_top = new QFrame(this);
    fr_top->setFixedHeight(50);
    fr_top->setFrameShadow(QFrame::Plain);
    fr_top->setFrameShape(QFrame::NoFrame);
    fr_top->setObjectName("fr_top");

    grid_top = new QHBoxLayout(fr_top);
    grid_top->setMargin(0);

    central_grid->addWidget(fr_top, 0, 0, 1, 2);
    // End Top Frame Menu

    // Side Menu
    fr_menu = new QFrame(this);
    fr_menu->setFixedWidth(120);
    fr_menu->setFrameShape(QFrame::NoFrame);
    fr_menu->setFrameShadow(QFrame::Plain);
    fr_menu->setObjectName("fr_menu");

    grid_menu = new QVBoxLayout(fr_menu);
    grid_menu->setMargin(0);
    grid_menu->setAlignment(Qt::AlignTop);

    toolbar = new ToolBarView("Teste", fr_menu);
    grid_menu->addWidget(toolbar);

    central_grid->addWidget(fr_menu, 1, 0, 1, 1);
    // End SIde Menu

    // Stack WIdget Container
    container = new QStackedWidget(this);
    container->setObjectName("container");

    central_grid->addWidget(container, 1, 1, 1, 1);

    wd1 = new QWidget(this);
    wd1->setObjectName("wd1");

    wd2 = new QWidget(this);
    wd2->setObjectName("wd2");


    container->addWidget(wd1);
    container->addWidget(wd2);








    bt = new QPushButton(fr_menu);
    bt->setText("Primeiro");
    bt->setObjectName("bt_teste");
    grid_menu->addWidget(bt);

    bt2 = new QPushButton(fr_menu);
    bt2->setText("Segundo");
    bt2->setObjectName("bt2_teste");
    grid_menu->addWidget(bt2);

    // toolbar = mainwindow->addToolBar("main tollbar");
    // toolbar->setOrientation(Qt::Vertical);
    // toolbar->setMovable(false);
    // toolbar->addAction("New File");
    // toolbar->addAction("TEste File");

    // QAction *login = new QAction("Login");
    // toolbar->addAction(login);

    // // view->central_grid->addWidget(toolbar, 0, 0, 1, 1);

    // QAction *quit2 = new QAction("Quit");
    // // quit2->setCheckable(true);
    // toolbar->addAction(quit2);

    // ToolBarView *toolbar = new ToolBarView("teste", this);
    // mainwindow->addTo

    // central_grid->addWidget(toolbar);


    // mainwindow->setCentralWidget(this);

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

MainWindowView::~MainWindowView(){
    qDebug() << "delete View";
}