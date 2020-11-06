#pragma once

#include <QDialog>
#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QPainterPath>
#include <QRegion>
#include <QRectF>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QPixmap>
#include <widgets/defaultsLineEdit.h>
class MaskWidget : public QWidget
{
  Q_OBJECT

public:
  MaskWidget(QWidget *parent = nullptr);
  ~MaskWidget();
public slots:
  void show();
};

class DialogMsg : public QDialog
{
  Q_OBJECT

public:
  DialogMsg(QWidget *frame, const int status, const QString msg);

  QLabel *label_titulo, *lb_icon, *lb_msg, *lb_dica;
  QPushButton *bt_close, *bt_confirm, *bt_cancel;
  QVBoxLayout *grid_dialog;
  QHBoxLayout *grid_titulo;
  QDialogButtonBox *button_box;
  QPixmap *icon_dialog;
  MaskWidget *mask;
  ~DialogMsg();
public slots:
  int show();
};

class DialogImg : public QDialog
{
public:
  DialogImg(const QPixmap &img);
  ~DialogImg();
  QLabel *label_titulo, *lb_imagem;
  QPushButton *bt_close;
  QVBoxLayout *grid_dialog;
  QHBoxLayout *grid_titulo;
};


class DialogInput : public QDialog {
  Q_OBJECT
public:
  DialogInput(const QString &title, QWidget *frame = nullptr);
  ~DialogInput();
  QLabel *label_titulo, *lb_dica;
  DefaultLineEdit *tx_name;
  DefaultTextEdit *tx_description;
  QPushButton  *bt_confirm, *bt_cancel;
  QVBoxLayout *grid_dialog;
  QHBoxLayout *grid_titulo;
  QDialogButtonBox *button_box;
  QPixmap *icon_dialog;
  MaskWidget *mask;
private:
  QPushButton *bt_close;


};
