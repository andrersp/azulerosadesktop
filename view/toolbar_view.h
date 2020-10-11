#ifndef TOOLBAR_VIEW_H
#define TOOLBAR_VIEW_H
#include <QToolBar>
#include <QMenu>
#include <QAction>
#include <QDebug>

#include "view/default_widgets.h"
class ToolBarView :  public QToolBar{
	Q_OBJECT
public:
	explicit ToolBarView(const QString &title, QWidget *parent);
	~ToolBarView();

	BtMenu *bt_home;	

	

	

};

#endif