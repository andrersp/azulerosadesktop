#ifndef MODEL_FORM_PRODUCT_H
#define MODEL_FORM_PRODUCT_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include "model/request.h"
#include <QDebug>

class ModelFormProduct : public QObject {
	Q_OBJECT
public:
	explicit ModelFormProduct(QObject *parent = nullptr) : QObject(parent){};
	virtual ~ModelFormProduct();

public slots:
	void get_selects();

signals:
	void signal_category(int id, QString category);
	void signal_providers(QVector<QStringList> providers);


};


#endif