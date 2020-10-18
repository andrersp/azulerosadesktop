#include "view/dashboard_view.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include "view/customshadow.h"
QT_CHARTS_USE_NAMESPACE


FrameInfo::FrameInfo(QString text, QPixmap *img, QWidget *parent) : QFrame(parent) {

    setObjectName("frame_info");
    setFixedHeight(100);

    CustomShadow *shadow = new CustomShadow();
    shadow->setBlurRadius(10.0);
    shadow->setDistance(3.0);
    shadow->setColor(QColor(0, 0, 0, 80));
    setAutoFillBackground(true);
    setGraphicsEffect(shadow);


    grid = new QGridLayout(this);
    grid->setContentsMargins(30, 20, 30, 20);
    grid->setHorizontalSpacing(10);
    grid->setVerticalSpacing(0);
    grid->setAlignment(Qt::AlignCenter);

    lb_img = new QLabel(this);
    lb_img->setFixedSize(QSize(50, 50));
    lb_img->setPixmap(img->scaled(lb_img->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    grid->addWidget(lb_img, 0, 0, 2, 1);

    lb_value = new QLabel(this);
    lb_value->setFixedHeight(30);
    lb_value->setText("0.00");
    lb_value->setObjectName("info_value");

    grid->addWidget(lb_value, 0, 1, 1, 1);


    lb_title = new QLabel(this);
    lb_title->setFixedHeight(20);
    lb_title->setText(text);
    lb_title->setObjectName("info_title");
    lb_title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    lb_title->setAlignment(Qt::AlignLeft);
    grid->addWidget(lb_title, 1, 1, 1, 1);


}

void FrameInfo::set_value(QString value){
    this->lb_value->setText(value);

}

FrameInfo::~FrameInfo(){};

DashBoardView::DashBoardView(QWidget *parent): QFrame(parent){

    grid = new QGridLayout(this);
    grid->setSpacing(20);
    grid->setMargin(20);
    grid->setAlignment(Qt::AlignTop);



    

    QPixmap *clients_icon = new QPixmap(":Images/Images/clients_info.svgz");

    info_client = new FrameInfo("Clientes", clients_icon, this);

    grid->addWidget(info_client, 0, 0, 1, 1);

    QPixmap *icon_products = new QPixmap(":Images/Images/box.svgz");

    info_product = new FrameInfo("Produtos", icon_products, this);
    
    grid->addWidget(info_product, 0, 1, 1, 1);

    QPixmap *icon_sale = new QPixmap(":Images/Images/cart.svgz");
    info_sale = new FrameInfo("Vendas", icon_sale, this);
    
    grid->addWidget(info_sale, 0, 2, 1, 1);

    QPixmap *icon_revenue = new QPixmap(":Images/Images/cash.svgz");

    info_revenue = new FrameInfo("Receita", icon_revenue, this);
    
    grid->addWidget(info_revenue, 0, 3, 1, 1);

	// QPieSeries *series = new QPieSeries(this);
	// series->setHoleSize(0.35);
 //    series->append("Protein 4.2%", 4.2);
 //    QPieSlice *slice = series->append("Fat 15.6%", 15.6);
 //    slice->setExploded();
 //    slice->setLabelVisible();
 //    series->append("Other 23.8%", 23.8);
 //    series->append("Carbs 56.4%", 56.4);

 //    QChartView *chartView = new QChartView(this);
 //    chartView->setRenderHint(QPainter::Antialiasing);
 //    chartView->chart()->setTitle("Donut with a lemon glaze (100g)");
 //    chartView->chart()->addSeries(series);
 //    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
 //    chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
 //    chartView->chart()->legend()->setFont(QFont("Arial", 7));
    
 //    grid->addWidget(chartView, 0, 0, 1, 1);

 //    QBarSet *set0 = new QBarSet("Jane");
 //    QBarSet *set1 = new QBarSet("John");
 //    QBarSet *set2 = new QBarSet("Axel");
 //    QBarSet *set3 = new QBarSet("Mary");
 //    QBarSet *set4 = new QBarSet("Samantha");
 //    set0->append(9);

 //    *set0 << 2 << 3 << 4 << 5 << 6;
 //    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
 //    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
 //    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
 //    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

 //    QBarSeries *series2 = new QBarSeries();
 //    series2->append(set0);
 //    series2->append(set1);
 //    series2->append(set2);
 //    series2->append(set3);
 //    series2->append(set4);
 //    // series->setUseOpenGL(false);

 //    QChart *chart = new QChart();
 //    chart->addSeries(series2);
 //    chart->setTitle("Mais Vendidos últimos 6 meses");
 //    chart->setAnimationOptions(QChart::SeriesAnimations);

 //    QStringList categories;
 //    categories << "Jan" << "Fev" << "Mar" << "Abr" << "Mai" << "Jun";
 //    QBarCategoryAxis *axisX = new QBarCategoryAxis();
 //    axisX->append(categories);
 //    chart->addAxis(axisX, Qt::AlignBottom);
 //    series2->attachAxis(axisX);

 //    QValueAxis *axisY = new QValueAxis();
 //    axisY->setRange(0,15);
 //    chart->addAxis(axisY, Qt::AlignLeft);
 //    series2->attachAxis(axisY);

 //    chart->legend()->setVisible(true);
 //    chart->legend()->setAlignment(Qt::AlignBottom);

 //    QChartView *chartView2 = new QChartView(chart);
 //    chartView->setRenderHint(QPainter::Antialiasing);
 //    grid->addWidget(chartView2, 0, 1, 1, 1);

}
DashBoardView::~DashBoardView(){}