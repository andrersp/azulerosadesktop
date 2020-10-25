#include "view/defaultsLineEdit.h"

DefaultLineEdit::DefaultLineEdit(const QString &placeholder, QWidget *parent)
    : QLineEdit(parent) {
    	setObjectName("default_line_edit");
    	setMinimumHeight(25);
    	setMaximumHeight(35);
    	setTextMargins(4, 0, 0, 0);
    	setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    	setPlaceholderText(placeholder);

    }
DefaultLineEdit::~DefaultLineEdit() {}