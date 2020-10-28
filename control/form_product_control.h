#ifndef FORM_PRODUCT_CONTROL_H
#define FORM_PRODUCT_CONTROL_H
#include "view/productForm.h"
#include "model/model_completer.h"
#include "model/model_form_product.h"

class ProductFormControl : public ProductForm {
	Q_OBJECT
public:
	explicit ProductFormControl(QWidget *parent = nullptr);
	virtual ~ProductFormControl();

public slots:
	void get_selects();
	void set_categories(const int &id, const QString &category);		
private slots:
	void save_product();
private:
	ModelCompleter *complete_provider, *model_provider;


};

#endif