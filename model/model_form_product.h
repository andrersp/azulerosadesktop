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
	void get_product(const int &id);
	void delete_image(const QString &id_image);
	void save_product(const QJsonObject &data, const int &product_id = 0);
	void save_category(const QJsonObject &data);
	void save_brand(const QJsonObject &data);
	
	

signals:
	void signal_category(QVector<QStringList> categories);
	void signal_providers(QVector<QStringList> providers);
	void signal_units(int id, QString unit);
	void signal_brands(QVector<QStringList> brands);
	void signal_check_id();
	void signal_product(QJsonObject product);
	void signal_msg(int status, QString msg);
	void signal_new_category(int id_category, QString name_category);
	void signal_new_brand(int id_category, QString name_category);
	void signal_msg_sucess(int status, QString msg, int product_id);
};


#endif