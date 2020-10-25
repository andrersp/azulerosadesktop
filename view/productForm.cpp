#include "view/productForm.h"

ProductForm::ProductForm(QWidget *parent)
    : FrameForm("Cadastro de Produto", parent) {

  // Row 0
  label = new DefaultLabel("ID Produto", this);
  addWidget(label, 0, 0, 1, 1);

  label = new DefaultLabel("Ativo?", this);
  addWidget(label, 0, 1, 1, 1);

  // Row 1
  tx_id = new DefaultLineEdit("ID Produto", this);
  tx_id->setReadOnly(true);
  addWidget(tx_id, 1, 0, 1, 1);

  cb_enable = new DefaultComboBox(this);
  addWidget(cb_enable, 1, 1, 1, 1);

  // Row 2
  label = new DefaultLabel("Nome Produto", this);
  addWidget(label, 2, 0, 1, 2);

  label = new DefaultLabel("Categoria", this);
  addWidget(label, 2, 2, 1, 1);

  label = new DefaultLabel("Marca", this);
  addWidget(label, 2, 3, 1, 1);

  label = new DefaultLabel("Unidade", this);
  addWidget(label, 2, 4, 1, 1);

  label = new DefaultLabel("Descrição", this);
  addWidget(label, 2, 5, 1, 1);

  // Row 3
  tx_product_name = new DefaultLineEdit("Nome Produto", this);
  tx_product_name->setMinimumWidth(350);
  addWidget(tx_product_name, 3, 0, 1, 2);

  cb_category = new DefaultComboBox(this);
  addWidget(cb_category, 3, 2, 1, 1);

  cb_brand = new DefaultComboBox(this);
  addWidget(cb_brand, 3, 3, 1, 1);

  cb_unit = new DefaultComboBox(this);
  addWidget(cb_unit, 3, 4, 1, 1);

  tx_description = new DefaultTextEdit("Descrição curta", this);
  addWidget(tx_description, 3, 5, 3, 1);

  // Row 4
  label = new DefaultLabel("Peso", this);
  addWidget(label, 4, 0, 1, 1);

  label = new DefaultLabel("Altura", this);
  addWidget(label, 4, 1, 1, 1);

  label = new DefaultLabel("Largura", this);
  addWidget(label, 4, 2, 1, 1);

  label = new DefaultLabel("Comprimento", this);
  addWidget(label, 4, 3, 1, 1);

  label = new DefaultLabel("Estoque Mínimo", this);
  addWidget(label, 4, 4, 1, 1);

  // Row 5
  tx_weight = new DefaultLineEditFloat("Peso", this);
  addWidget(tx_weight, 5, 0, 1, 1);

  tx_height = new DefaultLineEditFloat("Altura", this);
  addWidget(tx_height, 5, 1, 1, 1);

  tx_widht = new DefaultLineEditFloat("Largura", this);
  addWidget(tx_widht, 5, 2, 1, 1);

  tx_length = new DefaultLineEditFloat("Comprimento", this);
  addWidget(tx_length, 5, 3, 1, 1);

  tx_minimum_stock = new DefaultLineEditFloat("Estoque Mínimo", this);
  addWidget(tx_minimum_stock, 5, 4, 1, 1);


  // grid_form->addWidget(label, 0, 0, 1, 1);

  // grid->addWidget(form_frame);
}

ProductForm::~ProductForm() {}