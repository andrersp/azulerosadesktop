#include "view/main_product_view.h"
#include <QDebug>
#include "model/request.h"
#include "view/customshadow.h"

FrameProduct::FrameProduct(QWidget *parent) : QFrame(parent) {
  // Name For Search

  // Shadow Effect
  CustomShadow *shadow = new CustomShadow();

  shadow->setBlurRadius(5.0);
  shadow->setDistance(1.0);
  shadow->setColor(QColor(0, 0, 0, 80));
  setAutoFillBackground(true);
  setGraphicsEffect(shadow);

  // setMaximumHeight(270);
  // setCursor(Qt::PointingHandCursor);

  setObjectName("frame_product");

  grid = new QGridLayout(this);
  grid->setMargin(15);
  grid->setHorizontalSpacing(0);
  grid->setVerticalSpacing(1);

  lb_cover = new QLabel(this);
  lb_cover->setAlignment(Qt::AlignCenter);
  lb_cover->setMinimumSize(150, 150);
  lb_cover->setObjectName("lb_cover");
  // lb_cover->setScaledContents(true);
  grid->addWidget(lb_cover, 0, 0, 1, 2);

  lb_name = new QLabel(this);
  lb_name->setText(name);
  lb_name->setAlignment(Qt::AlignCenter);
  lb_name->setFixedHeight(20);
  lb_name->setObjectName("lb_name_product");
  grid->addWidget(lb_name, 1, 0, 1, 2);

  label = new QLabel(this);
  label->setText("Categoria: ");
  label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  label->setFixedHeight(20);
  label->setObjectName("lb_category");
  grid->addWidget(label, 2, 0, 1, 1);

  lb_category = new QLabel(this);
  // lb_category->setText("Caneca");
  lb_category->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  lb_category->setFixedHeight(20);
  lb_category->setObjectName("lb_category");
  grid->addWidget(lb_category, 2, 1, 1, 1);

  label = new QLabel(this);
  label->setText("Disponível: ");
  label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  label->setFixedHeight(20);
  label->setObjectName("lb_category");
  grid->addWidget(label, 3, 0, 1, 1);

  lb_qtde = new QLabel(this);
  // lb_qtde->setText("25");
  lb_qtde->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  lb_qtde->setFixedHeight(20);
  lb_qtde->setObjectName("lb_category");
  grid->addWidget(lb_qtde, 3, 1, 1, 1);

  lb_value = new QLabel(this);
  // lb_value->setText(value);
  lb_value->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  lb_value->setMinimumWidth(80);
  lb_value->setFixedHeight(30);
  lb_value->setObjectName("lb_value_product");
  grid->addWidget(lb_value, 4, 0, 1, 1);

  bt_add = new QPushButton(this);
  bt_add->setText("EDITAR");
  bt_add->setMinimumWidth(80);
  bt_add->setFixedHeight(30);
  bt_add->setCursor(Qt::PointingHandCursor);
  bt_add->setObjectName("bt_edit");
  bt_add->setIcon(QIcon(":Images/Images/icon_edit.svg"));
  bt_add->setIconSize(QSize(13, 13));

  grid->addWidget(bt_add, 4, 1, 1, 1);

  // Connect QPushButton Add a singal send id product
  connect(bt_add, &QPushButton::clicked, [=] (const int &id) {emit send_product_id(product_id);} );


  // set_cover(url_image);
}

// Set Values to Labels and Get Cover
void FrameProduct::set_data(QJsonObject &obj) {
  product_name = obj.value("name").toString();
  product_category = obj.value("category").toString();
  product_value = QString::number(obj.value("sale_price").toDouble(), 'f', 2);
  qtde_available =
      QString::number(obj.value("available_stock").toDouble(), 'f', 2);
  product_id = obj.value("id").toInt();

  url_image = obj.value("cover").toString();

  set_cover(url_image);

  lb_name->setText(product_name);
  lb_category->setText(product_category);
  lb_qtde->setText(qtde_available);
  lb_value->setText(product_value);
}
void FrameProduct::set_cover(QString &url) {
  ModelRequest request = ModelRequest(this);

  QByteArray img = request.get_image(url);

  QPixmap cover;
  cover.loadFromData(img);

  try {
    if (cover.isNull()) {
      throw 1;
    } else {
      lb_cover->setPixmap(
          cover.scaledToHeight(lb_cover->height(), Qt::SmoothTransformation));
    }

  } catch (int e) {
    if (e == 1) {
      QPixmap cover(":Images/Images/products.svgz");
      lb_cover->setPixmap(
          cover.scaledToHeight(lb_cover->height(), Qt::SmoothTransformation));
      
    }
  }
}

FrameProduct::~FrameProduct() {}

MainProductView::MainProductView(QWidget *parent) : QWidget(parent) {
  grid_main_product = new QVBoxLayout(this);
  grid_main_product->setSpacing(20);
  grid_main_product->setMargin(20);

  fr_search = new FrameSearch("Produtos", this);

  grid_main_product->addWidget(fr_search);

  fr_product = new QFrame(this);
  fr_product->setFrameShape(QFrame::NoFrame);
  fr_product->setFrameShadow(QFrame::Plain);
  fr_product->setObjectName("fr_product");

  grid = new QGridLayout(fr_product);
  grid->setMargin(10);
  grid->setSpacing(20);
  // grid->setAlignment(Qt::AlignTop);

  scroll = new QScrollArea;
  scroll->setFrameShape(QFrame::NoFrame);
  scroll->setFrameShadow(QFrame::Plain);
  scroll->setWidgetResizable(true);
  scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  scroll->setObjectName("scroll_area");

  scroll->setWidget(fr_product);
  grid_main_product->addWidget(scroll);
}

void MainProductView::set_frame_product(QWidget *frame, int x, int y) {
  grid->addWidget(frame, x, y, 1, 1);
}

MainProductView::~MainProductView() {}