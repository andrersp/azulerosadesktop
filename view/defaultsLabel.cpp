#include "view/defaultsLabel.h"

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