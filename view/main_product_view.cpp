#include "model/request.h"
#include "view/customshadow.h"
#include "view/main_product_view.h"
#include <QDebug>

FrameProduct::FrameProduct(QString &url_image, QString &name, QString &value,
                           int id, QWidget *parent)
    : QFrame(parent) {

  // Name For Search
  this->name = name;

  // Shadow Effect
  CustomShadow *shadow = new CustomShadow();

  shadow->setBlurRadius(10.0);
  shadow->setDistance(3.0);
  shadow->setColor(QColor(0, 0, 0, 80));
  setAutoFillBackground(true);
  setGraphicsEffect(shadow);

  setMaximumHeight(230);
  setCursor(Qt::PointingHandCursor);

  setObjectName("frame_product");

  grid = new QGridLayout(this);
  grid->setMargin(15);
  grid->setHorizontalSpacing(0);
  grid->setVerticalSpacing(5);

  lb_cover = new QLabel(this);
  lb_cover->setAlignment(Qt::AlignCenter);
  lb_cover->setFixedSize(QSize(150, 150));
  grid->addWidget(lb_cover, 0, 0, 1, 2, Qt::AlignCenter);

  lb_name = new QLabel(this);
  lb_name->setText(name);
  lb_name->setAlignment(Qt::AlignCenter);
  lb_name->setObjectName("lb_name_product");
  grid->addWidget(lb_name, 1, 0, 1, 2);

  lb_value = new QLabel(this);
  lb_value->setText(value);
  lb_value->setAlignment(Qt::AlignCenter);
  lb_value->setObjectName("lb_value_product");
  grid->addWidget(lb_value, 2, 0, 1, 1);

  set_cover(url_image);
}
void FrameProduct::set_cover(QString &url) {

  ModelRequest model = ModelRequest(this);

  QByteArray img = model.get_image(url);

  QPixmap cover;
  cover.loadFromData(img);

  lb_cover->setPixmap(cover);
}

FrameProduct::~FrameProduct() {}

MainProductView::MainProductView(QWidget *parent) : QWidget(parent) {

  grid_main_product = new QVBoxLayout(this);
  grid_main_product->setSpacing(15);
  grid_main_product->setMargin(20);

  fr_search = new FrameSearch(this);
  

  grid_main_product->addWidget(fr_search);

  fr_product = new QFrame(this);
  fr_product->setFrameShape(QFrame::NoFrame);
  fr_product->setFrameShadow(QFrame::Plain);

  grid = new QGridLayout(fr_product);
  grid->setMargin(5);
  grid->setSpacing(20);
  // grid->setAlignment(Qt::AlignTop);

  scroll = new QScrollArea;
  scroll->setFrameShape(QFrame::NoFrame);
  scroll->setWidgetResizable(true);
  scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  scroll->setWidget(fr_product);
  grid_main_product->addWidget(scroll);
}

MainProductView::~MainProductView() {}