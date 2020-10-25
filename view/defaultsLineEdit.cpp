#include "view/defaultsLineEdit.h"

DefaultLineEdit::DefaultLineEdit(const QString &placeholder, QWidget *parent)
    : QLineEdit(parent) {
  setObjectName("default_line_edit");
  setMinimumHeight(30);
  setMaximumHeight(35);
  setMinimumWidth(100);
  setTextMargins(4, 0, 0, 0);
  setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  setPlaceholderText(placeholder);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
DefaultLineEdit::~DefaultLineEdit() {}

// Default Line Edit Float
DefaultLineEditFloat::DefaultLineEditFloat(const QString &placeholder,
                                           QWidget *parent)
    : QLineEdit(parent) {

  QRegExp regex("^(\\d{0,9})(?:\\.|\\,|\\d+)(\\d{1,2})?$");
  QRegExpValidator *valida_float = new QRegExpValidator(regex, this);
  setValidator(valida_float);
  setObjectName("default_line_edit");
  setMinimumHeight(30);
  setMaximumHeight(35);
  setMinimumWidth(100);
  setTextMargins(4, 0, 0, 0);
  setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  setPlaceholderText(placeholder);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  connect(this, &DefaultLineEditFloat::editingFinished, this, &DefaultLineEditFloat::format_number);
}
void DefaultLineEditFloat::format_number(){
	if (!text().isEmpty()){
		setText(QString::number(text().replace(",", ".").toFloat(), 'f', 2));
	}
}

DefaultLineEditFloat::~DefaultLineEditFloat() {}

// Default Text Edit
DefaultTextEdit::DefaultTextEdit(const QString &placeholder, QWidget *parent)
    : QTextEdit(parent) {

  setObjectName("default_text_edit");
  setAlignment(Qt::AlignLeft | Qt::AlignTop);
  setPlaceholderText(placeholder);
  setContentsMargins(4, 0, 0, 0);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

DefaultTextEdit::~DefaultTextEdit() {}