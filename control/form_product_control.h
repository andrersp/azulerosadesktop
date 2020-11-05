#ifndef FORM_PRODUCT_CONTROL_H
#define FORM_PRODUCT_CONTROL_H
#include "view/productForm.h"
#include "model/model_completer.h"
#include "model/model_form_product.h"
#include "view/dialog_ui.h"

class ProductFormControl : public ProductForm {
	Q_OBJECT
public:
	explicit ProductFormControl(QWidget *parent = nullptr);
	virtual ~ProductFormControl();

public slots:
	void get_selects();
	void set_categories(const int &id, const QString &category);
	void set_units(const int &id, const QString &unit);
	void set_brands(const int &id, const QString &brand);
	void select_provider(const QModelIndex &index);

	void check_id();
private slots:
	void save_product();
	void set_product(const QJsonObject &product);
	void remove_image(const QString &id_image);
	void dialog_err(int status, QString msg);
private:
	ModelCompleter *complete_provider, *model_provider, *model_category;
	void dialog_add_category();

	void add_category(const QString &category);




};

#endif