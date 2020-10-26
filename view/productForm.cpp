#include "view/productForm.h"
#include <QDebug>

ProductForm::ProductForm(QWidget *parent)
    : FrameForm("Cadastro de Produto", parent) {
  // Row 0
  label = new DefaultLabel("ID Produto", this);
  addWidget(label, 0, 0, 1, 1);

  label = new DefaultLabel("Cód. Interno", this);
  addWidget(label, 0, 1, 1, 1);

  label = new DefaultLabel("Ativo?", this);
  addWidget(label, 0, 2, 1, 1);

  // Row 1
  tx_id = new DefaultLineEdit("ID Produto", this);
  tx_id->setReadOnly(true);
  addWidget(tx_id, 1, 0, 1, 1);

  tx_internal_code = new DefaultLineEdit("Cód Interno", this);
  addWidget(tx_internal_code, 1, 1, 1, 1);

  cb_enable = new DefaultComboBox(this);
  addWidget(cb_enable, 1, 2, 1, 1);

  // Row 2
  label = new DefaultLabel("Nome Produto", this);
  addWidget(label, 2, 0, 1, 2);

  label = new DefaultLabel("Categoria", this);
  addWidget(label, 2, 2, 1, 1);

  label = new DefaultLabel("Marca", this);
  addWidget(label, 2, 3, 1, 1);

  

  label = new DefaultLabel("Descrição", this);
  addWidget(label, 2, 4, 1, 1);

  // Row 3
  tx_product_name = new DefaultLineEdit("Nome Produto", this);
  tx_product_name->setMinimumWidth(350);
  addWidget(tx_product_name, 3, 0, 1, 2);

  cb_category = new DefaultComboBox(this);
  addWidget(cb_category, 3, 2, 1, 1);

  cb_brand = new DefaultComboBox(this);
  addWidget(cb_brand, 3, 3, 1, 1);

  
  tx_description = new DefaultTextEdit("Descrição curta", this);
  addWidget(tx_description, 3, 4, 3, 1);

  // Row 4
  label = new DefaultLabel("Peso", this);
  addWidget(label, 4, 0, 1, 1);

  label = new DefaultLabel("Altura", this);
  addWidget(label, 4, 1, 1, 1);

  label = new DefaultLabel("Largura", this);
  addWidget(label, 4, 2, 1, 1);

  label = new DefaultLabel("Comprimento", this);
  addWidget(label, 4, 3, 1, 1);

  // Row 5
  tx_weight = new DefaultLineEditFloat("Peso", this);
  addWidget(tx_weight, 5, 0, 1, 1);

  tx_height = new DefaultLineEditFloat("Altura", this);
  addWidget(tx_height, 5, 1, 1, 1);

  tx_widht = new DefaultLineEditFloat("Largura", this);
  addWidget(tx_widht, 5, 2, 1, 1);

  tx_length = new DefaultLineEditFloat("Comprimento", this);
  addWidget(tx_length, 5, 3, 1, 1);

  // Row 6

  label = new DefaultLabel("Valor de Compra (R$)", this);
  addWidget(label, 6, 0, 1, 1);

  label = new DefaultLabel("Valor de Venda (R$)", this);
  addWidget(label, 6, 1, 1, 1);

  label = new DefaultLabel("Desconto Máximo (%)", this);
  addWidget(label, 6, 2, 1, 1);

  label = new DefaultLabel("Mínimo por venda", this);
  addWidget(label, 6, 3, 1, 1);

  // Row 7

  tx_purchase_price = new DefaultLineEditFloat("Valor de Compra R$", this);
  addWidget(tx_purchase_price, 7, 0, 1, 1);  

  tx_sale_price = new DefaultLineEditFloat("Valor de Venda R$", this);
  addWidget(tx_sale_price, 7, 1, 1, 1);

  tx_maximum_discount = new DefaultLineEditFloat("Desconto Máximo %", this);
  addWidget(tx_maximum_discount, 7, 2, 1, 1);

  tx_minimum_sale = new DefaultLineEditFloat("Mínimo por venda", this);
  addWidget(tx_minimum_sale, 7, 3, 1, 1);

  // Row 8
  label = new DefaultLabel("Unidade", this);
  addWidget(label, 8, 0, 1, 1);

  label = new DefaultLabel("Estoque Mínimo", this);
  addWidget(label, 8, 1, 1, 1);

  label = new DefaultLabel("Estoque Máximo", this);
  addWidget(label, 8, 2, 1, 1);

  label = new DefaultLabel("Estoque Atual", this);
  addWidget(label, 8, 3, 1, 1);

  label = new DefaultLabel("Reduzir Estoque?", this);
  addWidget(label, 8, 4, 1, 1);

  

  // Row 9
  cb_unit = new DefaultComboBox(this);
  addWidget(cb_unit, 9, 0, 1, 1);

  tx_minimum_stock = new DefaultLineEditFloat("Estoque Mínimo", this);
  addWidget(tx_minimum_stock, 9, 1, 1, 1);

  tx_maximum_stock = new DefaultLineEditFloat("Estoque Máximo", this);
  addWidget(tx_maximum_stock, 9, 2, 1, 1);

  tx_available_stock = new DefaultLineEditFloat("Estoque Atual", this);
  tx_available_stock->setReadOnly(true);
  addWidget(tx_available_stock, 9, 3, 1, 1);

  cb_subtract = new DefaultComboBox(this);
  addWidget(cb_subtract, 9, 4, 1, 1);

  // Row 10
  label = new DefaultLabel("Descrição Completa", this);
  addWidget(label, 10, 0, 1, 2);

  label = new DefaultLabel("Imagens", this);
  addWidget(label, 10, 2, 1, 2);

  label = new DefaultLabel("Fornecedores", this);
  addWidget(label, 10, 4, 1, 1);

  // Row 11

  tx_long_description = new MRichTextEdit(this);
  addWidget(tx_long_description, 11, 0, 1, 2);

  QPushButton *button = new QPushButton(this);
  button->setText("AAAAA");
  addWidget(button, 12, 0, 1, 1);


  




  // grid_form->addWidget(label, 0, 0, 1, 1);

  connect(button, &QPushButton::clicked, this, &ProductForm::save_product);

  // grid->addWidget(form_frame);
}

void ProductForm::save_product(){

  qDebug() << tx_long_description->toHtml();
}

ProductForm::~ProductForm() {}