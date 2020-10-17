#include "view/default_table.h"
#include <QFile>

DefaultTable::DefaultTable(QWidget *parent) : QTableView(parent){
	QFile table_qss(":Style/Style/table.qss");
	table_qss.open(QFile::ReadOnly);
	setStyleSheet(QLatin1String(table_qss.readAll()));

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	horizontalHeader()->setDefaultSectionSize(100);
	horizontalHeader()->setHighlightSections(false);
	horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	verticalHeader()->hide();
	verticalHeader()->setDefaultSectionSize(35);
	setShowGrid(false);
	setFrameShape(QFrame::NoFrame);
	setFrameShadow(QFrame::Plain);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	setFocusPolicy(Qt::NoFocus);
	setIconSize(QSize(25, 20));
	setObjectName("default_table");
	setSortingEnabled(true);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setCursor(Qt::PointingHandCursor);
	setAlternatingRowColors(true);

}

DefaultTable::~DefaultTable(){}