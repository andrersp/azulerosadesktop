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

class ProductForm : public FrameForm {

public:
	explicit ProductForm(QWidget *parent = nullptr);
	virtual ~ProductForm();
// private:
// 	QVBoxLayout *grid;
// 	FrameTitle *fr_title;
// 	QFrame *form_frame;
// 	QGridLayout *grid_form;



private:
	DefaultLabel *label;
	DefaultLineEdit *tx_id, *tx_product_name;
	DefaultTextEdit *tx_description;
	DefaultComboBox *cb_enable, *cb_category, *cb_brand, *cb_unit;
	DefaultLineEditFloat *tx_weight, *tx_height, *tx_widht, *tx_length,
						 *tx_minimum_stock, *tx_maximum_stock;

};

#endif