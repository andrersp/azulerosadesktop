#include "widgets/default_widgets.h"
#include <QEvent>
#include <QPainter>
#include <QPainterPath>

// Default Button Left Menu
ButtonMenu::ButtonMenu(const QString &text, const QIcon &icon, QWidget *parent)
    : QPushButton(text, parent) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  setFixedHeight(35);
  // setFlat(true);
  setFocusPolicy(Qt::NoFocus);
  setCursor(Qt::PointingHandCursor);
  setObjectName("button_menu");
  setCheckable(true);

  m_pixmap = icon.pixmap(QSize(20, 20));
  m_active = new QIcon(":Images/Images/active_menu.svgz");
}

QSize ButtonMenu::sizeHint() const {
  const auto parentHint = QPushButton::sizeHint();
  return QSize(parentHint.width() + m_pixmap.width(),
               std::max(parentHint.height(), m_pixmap.height()));
}

void ButtonMenu::paintEvent(QPaintEvent *e) {
  QPushButton::paintEvent(e);
  QPainter painter(this);
  if (!m_pixmap.isNull()) {
    const int y = (height() - m_pixmap.height()) / 2;
    painter.drawPixmap(10, y, m_pixmap);
  }

  if (this->isChecked()) {
    QPixmap pxm = m_active->pixmap(height() - 20, height() - 20);

    painter.drawPixmap(width() - 15, 10, pxm);
  }
}

ButtonMenu::~ButtonMenu() {}

// end Default Button Left Menu

// Custom Button Add
ButtonAdd::ButtonAdd(const QString &text, QWidget *parent)
    : QPushButton(text, parent) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  setFixedHeight(40);
  setFixedWidth(120);
  // setFlat(true);
  setFocusPolicy(Qt::NoFocus);
  setCursor(Qt::PointingHandCursor);
  setObjectName("bt_new");
  setCheckable(true);

  m_pixmap = new QPixmap(QIcon(":Images/Images/icon_add.svgz").pixmap(20, 25));
  m_active =
      new QPixmap(QIcon(":Images/Images/icon_add_active.svgz").pixmap(20, 25));
}

QSize ButtonAdd::sizeHint() const {
  const auto parentHint = QPushButton::sizeHint();
  return QSize(parentHint.width() + m_pixmap->width(),
               std::max(parentHint.height(), m_pixmap->height()));
}

void ButtonAdd::paintEvent(QPaintEvent *e) {
  QPushButton::paintEvent(e);
  QPainter painter(this);

  if (is_focus) {
    painter.drawPixmap(10, 7, *m_active);
  } else {
    painter.drawPixmap(10, 7, *m_pixmap);
  }
}

bool ButtonAdd::event(QEvent *event) {
  switch (event->type()) {
  case QEvent::HoverEnter:
    is_focus = true;
    break;
  case QEvent::HoverLeave:
    is_focus = false;

    break;
  default:
    break;
  }

  return QWidget::event(event);
}

ButtonAdd::~ButtonAdd() {}
// End Custom Button Add

// Custom Button Edit
ButtonEditTable::ButtonEditTable(const QString &text, QWidget *parent)
    : QPushButton(text, parent) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  setFixedHeight(40);
  setFixedWidth(120);
  // setFlat(true);
  setFocusPolicy(Qt::NoFocus);
  setCursor(Qt::PointingHandCursor);
  setObjectName("bt_edit");
  setCheckable(true);

  m_pixmap = new QPixmap(QIcon(":Images/Images/icon_edit_active.svgz").pixmap(20, 25));
  m_active =
      new QPixmap(QIcon(":Images/Images/icon_edit.svgz").pixmap(20, 25));
}

QSize ButtonEditTable::sizeHint() const {
  const auto parentHint = QPushButton::sizeHint();
  return QSize(parentHint.width() + m_pixmap->width(),
               std::max(parentHint.height(), m_pixmap->height()));
}

void ButtonEditTable::paintEvent(QPaintEvent *e) {
  QPushButton::paintEvent(e);
  QPainter painter(this);

  if (is_focus) {
    painter.drawPixmap(10, 10, *m_active);
  } else {
    painter.drawPixmap(10, 10, *m_pixmap);
  }
}

bool ButtonEditTable::event(QEvent *event) {
  switch (event->type()) {
  case QEvent::HoverEnter:
    is_focus = true;
    break;
  case QEvent::HoverLeave:
    is_focus = false;
    break;
  case QEvent::MouseButtonPress:  
      return false;      
  default:
    break;
  }

  return QWidget::event(event);
}

ButtonEditTable::~ButtonEditTable() {}
// End Custom Button Edit


// start Line Edit Icon Left
LineEditIconLeft::LineEditIconLeft(const QIcon &icon, QWidget *parent)
    : QLineEdit(parent) {
  setIcon(icon);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void LineEditIconLeft::setIcon(QIcon icon) {
  _icon = icon;

  if (_icon.isNull()) {
    setTextMargins(1, 1, 1, 1);
    return;
  }

  setTextMargins(1, 1, 1, 1);
}

void LineEditIconLeft::paintEvent(QPaintEvent *e) {
  QLineEdit::paintEvent(e);

  if (!_icon.isNull()) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPixmap pxm = _icon.pixmap(height() - 16, height() - 16);
    int x = 12;

    painter.drawPixmap(x, 6, pxm);
    // painter.drawLine(40, 3, 40, height() - 4);
  }
}

LineEditIconLeft::~LineEditIconLeft() {}
// end Line Edit Icon Left



// Default Frame Search
FrameSearch::FrameSearch(const QString &title, QWidget *parent)
    : QFrame(parent) {
  // Shadow Effect
  CustomShadow *shadow = new CustomShadow();
  shadow->setBlurRadius(10.0);
  shadow->setDistance(3.0);
  shadow->setColor(QColor(0, 0, 0, 80));
  setAutoFillBackground(true);
  setGraphicsEffect(shadow);

  setObjectName("fr_search");
  setFixedHeight(50);
  setFrameShadow(Plain);
  setFrameShape(NoFrame);

  grid = new QHBoxLayout(this);
  grid->setContentsMargins(10, 5, 10, 5);
  grid->setSpacing(10);
  grid->setDirection(QHBoxLayout::LeftToRight);
  // grid->setAlignment(Qt::AlignLeft);

  // Title
  this->title = new QLabel(this);
  this->title->setText(title);
  this->title->setObjectName("label_menu");
  this->title->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->title->setFixedHeight(30);
  this->title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  this->grid->addWidget(this->title);

  // Button To Add
  button = new ButtonAdd("Novo", this);
  grid->addWidget(button);

  tx_search = new LineEditSearch("Buscar", this);
  grid->addWidget(tx_search, 0, Qt::AlignRight);
}

FrameSearch::~FrameSearch() {}
// End Default Frame Search


// Custon Line Edit Search
LineEditSearch::LineEditSearch(const QString &text, QWidget *parent)
    : QLineEdit(parent) {
  setObjectName("line_edit_search");
  setPlaceholderText(text);
  setFixedHeight(30);
  setFixedWidth(300);

  m_icon = QIcon(":Images/Images/lupa.svgz");
  setTextMargins(2, 1, 1, 1);
}

void LineEditSearch::paintEvent(QPaintEvent *e) {
  QLineEdit::paintEvent(e);

  if (!m_icon.isNull()) {
    QPainter painter(this);
    QPixmap pxm = m_icon.pixmap(height() - 10, height() - 10);
    int x = 2, cx = pxm.width();

    painter.drawPixmap(width() - 25, 5, pxm);
    painter.setPen(QColor("lightgrey"));    
  }
}

LineEditSearch::~LineEditSearch() {}
// End Custon Line Edit Search


//Default Frame title
FrameTitle::FrameTitle(const QString &title, QWidget *parent): QFrame(parent) {

  setFrameShape(QFrame::NoFrame);
  setFrameShadow(QFrame::Plain);
  setFixedHeight(40);
  setObjectName("frame_title");

  grid = new QHBoxLayout(this);
  grid->setMargin(0);
  grid->setSpacing(0);
  grid->setDirection(QHBoxLayout::LeftToRight);
  


  lb_title = new QLabel(this);
  lb_title->setText(title);
  lb_title->setObjectName("label_title");
  lb_title->setContentsMargins(5, 0, 0, 0);
  lb_title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

  grid->addWidget(lb_title);
}

FrameTitle::~FrameTitle(){}


// Default Frame Forms
FrameForm::FrameForm(const QString  &title, QWidget *parent) : QWidget(parent) {
  setObjectName("default_frame");

  grid = new QVBoxLayout(this);
  grid->setMargin(20);
  grid->setSpacing(0);

  fr_title = new FrameTitle(title, this);
  grid->addWidget(fr_title);

  form_frame = new QFrame(this);
  form_frame->setFrameShape(QFrame::NoFrame);
  form_frame->setFrameShadow(QFrame::Plain);
  form_frame->setObjectName("form_frame");

  form_grid = new QGridLayout(form_frame);
  form_grid->setVerticalSpacing(0);
  form_grid->setHorizontalSpacing(10);
  form_grid->setMargin(5);
  form_grid->setAlignment(Qt::AlignTop);

  grid->addWidget(form_frame);

  fr_buttons = new QFrame(this);
  fr_buttons->setObjectName("fr_buttons");
  fr_buttons->setFixedHeight(50);

  grid_buttons = new QHBoxLayout(fr_buttons);
  grid_buttons->setMargin(5);

  bt_cancel = new QPushButton(fr_buttons);
  bt_cancel->setFixedHeight(35);
  bt_cancel->setFixedWidth(140);
  bt_cancel->setCursor(Qt::PointingHandCursor);
  bt_cancel->setText("Cancelar");
  bt_cancel->setObjectName("bt_cancel");

  grid_buttons->addWidget(bt_cancel);

  grid_buttons->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Fixed));

  bt_save = new QPushButton(fr_buttons);
  bt_save->setFixedHeight(35);
  bt_save->setFixedWidth(140);
  bt_save->setCursor(Qt::PointingHandCursor);
  bt_save->setText("Salvar");
  bt_save->setObjectName("bt_save");

  grid_buttons->addWidget(bt_save);


  grid->addWidget(fr_buttons);
}

void FrameForm::addWidget(QWidget *widget, int row, int col, int rowSpan, int colSpan, Qt::Alignment alignment) {
  form_grid->addWidget(widget, row, col, rowSpan, colSpan, alignment);

}

FrameForm::~FrameForm(){}