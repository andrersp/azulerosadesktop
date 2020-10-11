#include "view/toolbar_view.h"

ToolBarView::ToolBarView(const QString &title, QWidget *parent) : QToolBar(parent){

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setFixedWidth(120);
	setToolButtonStyle(Qt::ToolButtonTextBesideIcon);	
	addAction("Teste 1");
	addAction("teste21");

	QIcon icon_home(":Images/Images/home.svgz");




	setOrientation(Qt::Vertical);
	setMovable(false);
	bt_home = new BtMenu(this);
	bt_home->setText("Home");
	bt_home->setIcon(icon_home);

	addWidget(bt_home);
	

	// addAction(action_home);

	// insertWidget(action_home, bt_home);

	

}

ToolBarView::~ToolBarView(){
	qDebug() << "Delete Toolbar";


}