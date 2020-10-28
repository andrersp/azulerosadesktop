#include "view/defaultsLineEdit.h"

DefaultLineEdit::DefaultLineEdit(const QString &placeholder, QWidget *parent)
    : QLineEdit(parent) {
  setObjectName("default_line_edit");
  setMinimumHeight(25);
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
  setMinimumHeight(25);
  setMaximumHeight(35);
  setMinimumWidth(100);
  setTextMargins(4, 0, 0, 0);
  setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  setPlaceholderText(placeholder);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  connect(this, &DefaultLineEditFloat::editingFinished, this,
          &DefaultLineEditFloat::format_number);
}
void DefaultLineEditFloat::format_number() {
  if (!text().isEmpty()) {
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
  setTabChangesFocus(true);
}

DefaultTextEdit::~DefaultTextEdit() {}

// Custom COmpleter

DefaultCompleter::DefaultCompleter(const QString &placeholder, QWidget *parent)
    : QLineEdit(parent) {
  setObjectName("default_line_edit");
  setMinimumHeight(25);
  setMaximumHeight(35);
  setMinimumWidth(100);
  setTextMargins(4, 0, 0, 0);
  setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  setPlaceholderText(placeholder);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  completation = new QCompleter(this);
  completation->setCompletionColumn(1);
  completation->setCaseSensitivity(Qt::CaseInsensitive);
  completation->setMaxVisibleItems(20);
  setCompleter(completation);

  cp_layout = new QHBoxLayout(this);
  cp_layout->setMargin(0);
  cp_layout->setContentsMargins(0, 2, 5, 2);

  bt_popup = new QToolButton(this);
  bt_popup->setToolButtonStyle(Qt::ToolButtonIconOnly);
  bt_popup->setIconSize(QSize(25, 25));
  bt_popup->setIcon(QIcon(":Images/Images/icon_down.svg"));
  bt_popup->setCursor(Qt::PointingHandCursor);
  bt_popup->setObjectName("bt_popup");

  cp_layout->addWidget(bt_popup, 0, Qt::AlignRight);
  
  // Connect
  connect(bt_popup, &QToolButton::clicked, this, &DefaultCompleter::show_popup);


}

void DefaultCompleter::show_popup() {
  completation->setCompletionPrefix("");
  completation->complete();
}

DefaultCompleter::~DefaultCompleter() {}