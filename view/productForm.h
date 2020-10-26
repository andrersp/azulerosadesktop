#ifndef FORMPRODUCT_H
#define FORMPRODUCT_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QGridLayout>

#include "view/defaultsLabel.h"
#include "view/defaultsLineEdit.h"
#include "view/defaultComboBox.h"
#include "view/default_widgets.h"
#include "view/mrichtextedit.h"
#include <QPushButton>

class ProductForm : public FrameForm {

public:
	explicit ProductForm(QWidget *parent = nullptr);
	virtual ~ProductForm();
	DefaultLineEdit *tx_id;
// private:
// 	QVBoxLayout *grid;
// 	FrameTitle *fr_title;
// 	QFrame *form_frame;
// 	QGridLayout *grid_form;



protected:
	DefaultLabel *label;
	DefaultLineEdit *tx_product_name, *tx_internal_code;
	DefaultTextEdit *tx_description;
	DefaultComboBox *cb_enable, *cb_category, *cb_brand, *cb_unit, *cb_subtract;
	DefaultLineEditFloat *tx_weight, *tx_height, *tx_widht, *tx_length,
						 *tx_minimum_stock, *tx_maximum_stock,
						 *tx_available_stock, *tx_purchase_price, 
						 *tx_minimum_sale, *tx_sale_price, *tx_maximum_discount;
	MRichTextEdit *tx_long_description;
	LabelUploadImage *img_cover;

	void save_product();

};

#endif