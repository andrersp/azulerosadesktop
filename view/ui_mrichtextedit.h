/********************************************************************************
** Form generated from reading UI file 'mrichtextedit.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRICHTEXTEDIT_H
#define UI_MRICHTEXTEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mtextedit.h"

QT_BEGIN_NAMESPACE

class Ui_MRichTextEdit
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *f_toolbar;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *f_paragraph;
    QFrame *line_4;
    QToolButton *f_undo;
    QToolButton *f_redo;
    QToolButton *f_cut;
    QToolButton *f_copy;
    QToolButton *f_paste;
    QFrame *line;
    QToolButton *f_link;
    QFrame *line_3;
    QToolButton *f_fgcolor;
    QToolButton *f_bgcolor;
    QFrame *line_6;
    QToolButton *f_image;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *f_fontsize;
    QToolButton *f_bold;
    QToolButton *f_italic;
    QToolButton *f_underline;
    QToolButton *f_strikeout;
    QToolButton *f_list_ordered;
    QToolButton *f_list_bullet;
    QToolButton *f_indent_dec;
    QToolButton *f_indent_inc;
    QFrame *line_7;
    QToolButton *f_menu;
    MTextEdit *f_textedit;

    void setupUi(QWidget *MRichTextEdit)
    {
        if (MRichTextEdit->objectName().isEmpty())
            MRichTextEdit->setObjectName(QStringLiteral("MRichTextEdit"));
        MRichTextEdit->resize(837, 312);
        MRichTextEdit->setWindowTitle(QStringLiteral(""));
        MRichTextEdit->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(MRichTextEdit);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        f_toolbar = new QWidget(MRichTextEdit);
        f_toolbar->setObjectName(QStringLiteral("f_toolbar"));
        f_toolbar->setMinimumSize(QSize(0, 70));
        f_toolbar->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(f_toolbar);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 10, 5, 2);
        frame = new QFrame(f_toolbar);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 20));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        f_paragraph = new QComboBox(frame);
        f_paragraph->setObjectName(QStringLiteral("f_paragraph"));
        f_paragraph->setMaximumSize(QSize(250, 23));
        f_paragraph->setFocusPolicy(Qt::ClickFocus);
        f_paragraph->setEditable(true);

        horizontalLayout_3->addWidget(f_paragraph);

        line_4 = new QFrame(frame);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        f_undo = new QToolButton(frame);
        f_undo->setObjectName(QStringLiteral("f_undo"));
        f_undo->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(f_undo->sizePolicy().hasHeightForWidth());
        f_undo->setSizePolicy(sizePolicy);
        f_undo->setMaximumSize(QSize(16777215, 23));
        f_undo->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        QString iconThemeName = QStringLiteral("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_undo->setIcon(icon);
        f_undo->setIconSize(QSize(16, 16));

        horizontalLayout_3->addWidget(f_undo);

        f_redo = new QToolButton(frame);
        f_redo->setObjectName(QStringLiteral("f_redo"));
        f_redo->setEnabled(false);
        sizePolicy.setHeightForWidth(f_redo->sizePolicy().hasHeightForWidth());
        f_redo->setSizePolicy(sizePolicy);
        f_redo->setMaximumSize(QSize(16777215, 23));
        f_redo->setFocusPolicy(Qt::ClickFocus);
        QIcon icon1;
        iconThemeName = QStringLiteral("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_redo->setIcon(icon1);
        f_redo->setIconSize(QSize(16, 16));

        horizontalLayout_3->addWidget(f_redo);

        f_cut = new QToolButton(frame);
        f_cut->setObjectName(QStringLiteral("f_cut"));
        sizePolicy.setHeightForWidth(f_cut->sizePolicy().hasHeightForWidth());
        f_cut->setSizePolicy(sizePolicy);
        f_cut->setMaximumSize(QSize(16777215, 23));
        f_cut->setFocusPolicy(Qt::ClickFocus);
        QIcon icon2;
        iconThemeName = QStringLiteral("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_cut->setIcon(icon2);
        f_cut->setIconSize(QSize(16, 16));

        horizontalLayout_3->addWidget(f_cut);

        f_copy = new QToolButton(frame);
        f_copy->setObjectName(QStringLiteral("f_copy"));
        sizePolicy.setHeightForWidth(f_copy->sizePolicy().hasHeightForWidth());
        f_copy->setSizePolicy(sizePolicy);
        f_copy->setMaximumSize(QSize(16777215, 23));
        f_copy->setFocusPolicy(Qt::ClickFocus);
        QIcon icon3;
        iconThemeName = QStringLiteral("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_copy->setIcon(icon3);
        f_copy->setIconSize(QSize(16, 16));

        horizontalLayout_3->addWidget(f_copy);

        f_paste = new QToolButton(frame);
        f_paste->setObjectName(QStringLiteral("f_paste"));
        sizePolicy.setHeightForWidth(f_paste->sizePolicy().hasHeightForWidth());
        f_paste->setSizePolicy(sizePolicy);
        f_paste->setMaximumSize(QSize(16777215, 23));
        f_paste->setFocusPolicy(Qt::ClickFocus);
        QIcon icon4;
        iconThemeName = QStringLiteral("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_paste->setIcon(icon4);
        f_paste->setIconSize(QSize(16, 16));

        horizontalLayout_3->addWidget(f_paste);

        line = new QFrame(frame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        f_link = new QToolButton(frame);
        f_link->setObjectName(QStringLiteral("f_link"));
        sizePolicy.setHeightForWidth(f_link->sizePolicy().hasHeightForWidth());
        f_link->setSizePolicy(sizePolicy);
        f_link->setMaximumSize(QSize(16777215, 23));
        f_link->setFocusPolicy(Qt::ClickFocus);
        QIcon icon5;
        iconThemeName = QStringLiteral("applications-internet");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_link->setIcon(icon5);
        f_link->setIconSize(QSize(16, 16));
        f_link->setCheckable(true);

        horizontalLayout_3->addWidget(f_link);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        f_fgcolor = new QToolButton(frame);
        f_fgcolor->setObjectName(QStringLiteral("f_fgcolor"));
        sizePolicy.setHeightForWidth(f_fgcolor->sizePolicy().hasHeightForWidth());
        f_fgcolor->setSizePolicy(sizePolicy);
        f_fgcolor->setMinimumSize(QSize(100, 23));
        f_fgcolor->setMaximumSize(QSize(1666, 23));
        f_fgcolor->setFocusPolicy(Qt::ClickFocus);
        f_fgcolor->setIconSize(QSize(16, 16));
        f_fgcolor->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(f_fgcolor);

        f_bgcolor = new QToolButton(frame);
        f_bgcolor->setObjectName(QStringLiteral("f_bgcolor"));
        sizePolicy.setHeightForWidth(f_bgcolor->sizePolicy().hasHeightForWidth());
        f_bgcolor->setSizePolicy(sizePolicy);
        f_bgcolor->setMinimumSize(QSize(100, 23));
        f_bgcolor->setMaximumSize(QSize(16, 23));
        f_bgcolor->setFocusPolicy(Qt::ClickFocus);
        f_bgcolor->setIconSize(QSize(16, 16));
        f_bgcolor->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(f_bgcolor);

        line_6 = new QFrame(frame);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_6);

        f_image = new QToolButton(frame);
        f_image->setObjectName(QStringLiteral("f_image"));
        sizePolicy.setHeightForWidth(f_image->sizePolicy().hasHeightForWidth());
        f_image->setSizePolicy(sizePolicy);
        f_image->setMaximumSize(QSize(23, 23));
        f_image->setText(QStringLiteral(""));
        QIcon icon6(QIcon::fromTheme(QStringLiteral("insert-image")));
        f_image->setIcon(icon6);
        f_image->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(f_image);


        verticalLayout_2->addWidget(frame);

        frame_2 = new QFrame(f_toolbar);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(0, 20));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        f_fontsize = new QComboBox(frame_2);
        f_fontsize->setObjectName(QStringLiteral("f_fontsize"));
        f_fontsize->setMaximumSize(QSize(250, 23));
        f_fontsize->setFocusPolicy(Qt::ClickFocus);
        f_fontsize->setEditable(true);

        horizontalLayout_2->addWidget(f_fontsize);

        f_bold = new QToolButton(frame_2);
        f_bold->setObjectName(QStringLiteral("f_bold"));
        sizePolicy.setHeightForWidth(f_bold->sizePolicy().hasHeightForWidth());
        f_bold->setSizePolicy(sizePolicy);
        f_bold->setFocusPolicy(Qt::ClickFocus);
#ifndef QT_NO_TOOLTIP
        f_bold->setToolTip(QStringLiteral("Bold (CTRL+B)"));
#endif // QT_NO_TOOLTIP
        QIcon icon7;
        iconThemeName = QStringLiteral("format-text-bold");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_bold->setIcon(icon7);
        f_bold->setIconSize(QSize(16, 16));
        f_bold->setCheckable(true);

        horizontalLayout_2->addWidget(f_bold);

        f_italic = new QToolButton(frame_2);
        f_italic->setObjectName(QStringLiteral("f_italic"));
        sizePolicy.setHeightForWidth(f_italic->sizePolicy().hasHeightForWidth());
        f_italic->setSizePolicy(sizePolicy);
        f_italic->setFocusPolicy(Qt::ClickFocus);
        QIcon icon8;
        iconThemeName = QStringLiteral("format-text-italic");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_italic->setIcon(icon8);
        f_italic->setIconSize(QSize(16, 16));
        f_italic->setCheckable(true);

        horizontalLayout_2->addWidget(f_italic);

        f_underline = new QToolButton(frame_2);
        f_underline->setObjectName(QStringLiteral("f_underline"));
        sizePolicy.setHeightForWidth(f_underline->sizePolicy().hasHeightForWidth());
        f_underline->setSizePolicy(sizePolicy);
        f_underline->setFocusPolicy(Qt::ClickFocus);
        QIcon icon9;
        iconThemeName = QStringLiteral("format-text-underline");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_underline->setIcon(icon9);
        f_underline->setIconSize(QSize(16, 16));
        f_underline->setCheckable(true);

        horizontalLayout_2->addWidget(f_underline);

        f_strikeout = new QToolButton(frame_2);
        f_strikeout->setObjectName(QStringLiteral("f_strikeout"));
        sizePolicy.setHeightForWidth(f_strikeout->sizePolicy().hasHeightForWidth());
        f_strikeout->setSizePolicy(sizePolicy);
        f_strikeout->setMaximumSize(QSize(16777215, 23));
        f_strikeout->setCheckable(true);

        horizontalLayout_2->addWidget(f_strikeout);

        f_list_ordered = new QToolButton(frame_2);
        f_list_ordered->setObjectName(QStringLiteral("f_list_ordered"));
        sizePolicy.setHeightForWidth(f_list_ordered->sizePolicy().hasHeightForWidth());
        f_list_ordered->setSizePolicy(sizePolicy);
        f_list_ordered->setMaximumSize(QSize(16777215, 23));
        f_list_ordered->setFocusPolicy(Qt::ClickFocus);
        QIcon icon10(QIcon::fromTheme(QStringLiteral("view-sort-ascending")));
        f_list_ordered->setIcon(icon10);
        f_list_ordered->setIconSize(QSize(16, 16));
        f_list_ordered->setCheckable(true);
        f_list_ordered->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(f_list_ordered);

        f_list_bullet = new QToolButton(frame_2);
        f_list_bullet->setObjectName(QStringLiteral("f_list_bullet"));
        sizePolicy.setHeightForWidth(f_list_bullet->sizePolicy().hasHeightForWidth());
        f_list_bullet->setSizePolicy(sizePolicy);
        f_list_bullet->setMaximumSize(QSize(16777215, 23));
        f_list_bullet->setFocusPolicy(Qt::ClickFocus);
        f_list_bullet->setIcon(icon10);
        f_list_bullet->setIconSize(QSize(16, 16));
        f_list_bullet->setCheckable(true);
        f_list_bullet->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(f_list_bullet);

        f_indent_dec = new QToolButton(frame_2);
        f_indent_dec->setObjectName(QStringLiteral("f_indent_dec"));
        f_indent_dec->setFocusPolicy(Qt::ClickFocus);
        QIcon icon11;
        iconThemeName = QStringLiteral("format-indent-less");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_indent_dec->setIcon(icon11);
        f_indent_dec->setIconSize(QSize(16, 16));

        horizontalLayout_2->addWidget(f_indent_dec);

        f_indent_inc = new QToolButton(frame_2);
        f_indent_inc->setObjectName(QStringLiteral("f_indent_inc"));
        f_indent_inc->setFocusPolicy(Qt::ClickFocus);
        QIcon icon12;
        iconThemeName = QStringLiteral("format-indent-more");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_indent_inc->setIcon(icon12);
        f_indent_inc->setIconSize(QSize(16, 16));

        horizontalLayout_2->addWidget(f_indent_inc);

        line_7 = new QFrame(frame_2);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_7);

        f_menu = new QToolButton(frame_2);
        f_menu->setObjectName(QStringLiteral("f_menu"));
        f_menu->setMaximumSize(QSize(23, 23));
        QIcon icon13(QIcon::fromTheme(QStringLiteral("applications-system")));
        f_menu->setIcon(icon13);
        f_menu->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(f_menu);


        verticalLayout_2->addWidget(frame_2);


        verticalLayout->addWidget(f_toolbar);

        f_textedit = new MTextEdit(MRichTextEdit);
        f_textedit->setObjectName(QStringLiteral("f_textedit"));
        f_textedit->setFrameShape(QFrame::NoFrame);
        f_textedit->setFrameShadow(QFrame::Plain);
        f_textedit->setAutoFormatting(QTextEdit::AutoNone);
        f_textedit->setTabChangesFocus(true);

        verticalLayout->addWidget(f_textedit);


        retranslateUi(MRichTextEdit);

        QMetaObject::connectSlotsByName(MRichTextEdit);
    } // setupUi

    void retranslateUi(QWidget *MRichTextEdit)
    {
#ifndef QT_NO_TOOLTIP
        f_paragraph->setToolTip(QApplication::translate("MRichTextEdit", "Paragraph formatting", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        f_undo->setToolTip(QApplication::translate("MRichTextEdit", "Undo (CTRL+Z)", nullptr));
#endif // QT_NO_TOOLTIP
        f_undo->setText(QApplication::translate("MRichTextEdit", "Undo", nullptr));
#ifndef QT_NO_TOOLTIP
        f_redo->setToolTip(QApplication::translate("MRichTextEdit", "Redo", nullptr));
#endif // QT_NO_TOOLTIP
        f_redo->setText(QApplication::translate("MRichTextEdit", "Redo", nullptr));
#ifndef QT_NO_TOOLTIP
        f_cut->setToolTip(QApplication::translate("MRichTextEdit", "Cut (CTRL+X)", nullptr));
#endif // QT_NO_TOOLTIP
        f_cut->setText(QApplication::translate("MRichTextEdit", "Cut", nullptr));
#ifndef QT_NO_TOOLTIP
        f_copy->setToolTip(QApplication::translate("MRichTextEdit", "Copy (CTRL+C)", nullptr));
#endif // QT_NO_TOOLTIP
        f_copy->setText(QApplication::translate("MRichTextEdit", "Copy", nullptr));
#ifndef QT_NO_TOOLTIP
        f_paste->setToolTip(QApplication::translate("MRichTextEdit", "Paste (CTRL+V)", nullptr));
#endif // QT_NO_TOOLTIP
        f_paste->setText(QApplication::translate("MRichTextEdit", "Paste", nullptr));
#ifndef QT_NO_TOOLTIP
        f_link->setToolTip(QApplication::translate("MRichTextEdit", "Link (CTRL+L)", nullptr));
#endif // QT_NO_TOOLTIP
        f_link->setText(QApplication::translate("MRichTextEdit", "Link", nullptr));
#ifndef QT_NO_TOOLTIP
        f_fgcolor->setToolTip(QApplication::translate("MRichTextEdit", "Text foreground color", nullptr));
#endif // QT_NO_TOOLTIP
        f_fgcolor->setText(QApplication::translate("MRichTextEdit", "Fonte", nullptr));
#ifndef QT_NO_TOOLTIP
        f_bgcolor->setToolTip(QApplication::translate("MRichTextEdit", "Text background color", nullptr));
#endif // QT_NO_TOOLTIP
        f_bgcolor->setText(QApplication::translate("MRichTextEdit", "Fundo", nullptr));
#ifndef QT_NO_TOOLTIP
        f_fontsize->setToolTip(QApplication::translate("MRichTextEdit", "Font size", nullptr));
#endif // QT_NO_TOOLTIP
        f_bold->setText(QApplication::translate("MRichTextEdit", "Bold", nullptr));
#ifndef QT_NO_TOOLTIP
        f_italic->setToolTip(QApplication::translate("MRichTextEdit", "Italic (CTRL+I)", nullptr));
#endif // QT_NO_TOOLTIP
        f_italic->setText(QApplication::translate("MRichTextEdit", "Italic", nullptr));
#ifndef QT_NO_TOOLTIP
        f_underline->setToolTip(QApplication::translate("MRichTextEdit", "Underline (CTRL+U)", nullptr));
#endif // QT_NO_TOOLTIP
        f_underline->setText(QApplication::translate("MRichTextEdit", "Underline", nullptr));
        f_strikeout->setText(QApplication::translate("MRichTextEdit", "Cortar", nullptr));
#ifndef QT_NO_TOOLTIP
        f_list_ordered->setToolTip(QApplication::translate("MRichTextEdit", "Ordered list (CTRL+=)", nullptr));
#endif // QT_NO_TOOLTIP
        f_list_ordered->setText(QApplication::translate("MRichTextEdit", "Lista Ordenada", nullptr));
#ifndef QT_NO_TOOLTIP
        f_list_bullet->setToolTip(QApplication::translate("MRichTextEdit", "Bullet list (CTRL+-)", nullptr));
#endif // QT_NO_TOOLTIP
        f_list_bullet->setText(QApplication::translate("MRichTextEdit", "Lista Ponto", nullptr));
#ifndef QT_NO_TOOLTIP
        f_indent_dec->setToolTip(QApplication::translate("MRichTextEdit", "Decrease indentation (CTRL+,)", nullptr));
#endif // QT_NO_TOOLTIP
        f_indent_dec->setText(QApplication::translate("MRichTextEdit", "Decrease indentation", nullptr));
#ifndef QT_NO_TOOLTIP
        f_indent_inc->setToolTip(QApplication::translate("MRichTextEdit", "Increase indentation (CTRL+.)", nullptr));
#endif // QT_NO_TOOLTIP
        f_indent_inc->setText(QApplication::translate("MRichTextEdit", "Increase indentation", nullptr));
        f_menu->setText(QString());
        Q_UNUSED(MRichTextEdit);
    } // retranslateUi

};

namespace Ui {
    class MRichTextEdit: public Ui_MRichTextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRICHTEXTEDIT_H
