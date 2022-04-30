/********************************************************************************
** Form generated from reading UI file 'huarongdaolevelselectwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUARONGDAOLEVELSELECTWIDGET_H
#define UI_HUARONGDAOLEVELSELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_huarongdaolevelselectwidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetCenter;
    QPushButton *btnLevel3;
    QPushButton *btnLevel4;
    QPushButton *btnLevel5;
    QPushButton *btnLevel6;
    QPushButton *btnRanking;
    QPushButton *btnShare;

    void setupUi(QWidget *huarongdaolevelselectwidget)
    {
        if (huarongdaolevelselectwidget->objectName().isEmpty())
            huarongdaolevelselectwidget->setObjectName(QString::fromUtf8("huarongdaolevelselectwidget"));
        huarongdaolevelselectwidget->resize(229, 492);
        huarongdaolevelselectwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(huarongdaolevelselectwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetCenter = new QWidget(huarongdaolevelselectwidget);
        widgetCenter->setObjectName(QString::fromUtf8("widgetCenter"));
        widgetCenter->setStyleSheet(QString::fromUtf8("QWidget#widgetCenter {\n"
"\n"
"        background-image: url(://picture/background.jpg);\n"
"}\n"
"\n"
"QPushButton {\n"
"        border: none;\n"
"        border-radius: 8px;\n"
"}"));
        btnLevel3 = new QPushButton(widgetCenter);
        btnLevel3->setObjectName(QString::fromUtf8("btnLevel3"));
        btnLevel3->setGeometry(QRect(52, 169, 118, 38));
        btnLevel3->setStyleSheet(QString::fromUtf8(""));
        btnLevel4 = new QPushButton(widgetCenter);
        btnLevel4->setObjectName(QString::fromUtf8("btnLevel4"));
        btnLevel4->setGeometry(QRect(52, 217, 118, 38));
        btnLevel4->setStyleSheet(QString::fromUtf8(""));
        btnLevel5 = new QPushButton(widgetCenter);
        btnLevel5->setObjectName(QString::fromUtf8("btnLevel5"));
        btnLevel5->setGeometry(QRect(53, 265, 118, 38));
        btnLevel5->setStyleSheet(QString::fromUtf8(""));
        btnLevel6 = new QPushButton(widgetCenter);
        btnLevel6->setObjectName(QString::fromUtf8("btnLevel6"));
        btnLevel6->setGeometry(QRect(52, 312, 118, 38));
        btnLevel6->setStyleSheet(QString::fromUtf8(""));
        btnRanking = new QPushButton(widgetCenter);
        btnRanking->setObjectName(QString::fromUtf8("btnRanking"));
        btnRanking->setGeometry(QRect(40, 428, 40, 40));
        btnShare = new QPushButton(widgetCenter);
        btnShare->setObjectName(QString::fromUtf8("btnShare"));
        btnShare->setGeometry(QRect(146, 427, 40, 40));

        verticalLayout->addWidget(widgetCenter);


        retranslateUi(huarongdaolevelselectwidget);

        QMetaObject::connectSlotsByName(huarongdaolevelselectwidget);
    } // setupUi

    void retranslateUi(QWidget *huarongdaolevelselectwidget)
    {
        huarongdaolevelselectwidget->setWindowTitle(QCoreApplication::translate("huarongdaolevelselectwidget", "Form", nullptr));
        btnLevel3->setText(QCoreApplication::translate("huarongdaolevelselectwidget", "3X3", nullptr));
        btnLevel4->setText(QCoreApplication::translate("huarongdaolevelselectwidget", "4X4", nullptr));
        btnLevel5->setText(QCoreApplication::translate("huarongdaolevelselectwidget", "5X5", nullptr));
        btnLevel6->setText(QCoreApplication::translate("huarongdaolevelselectwidget", "6X6", nullptr));
        btnRanking->setText(QCoreApplication::translate("huarongdaolevelselectwidget", "\346\216\222\350\241\214", nullptr));
        btnShare->setText(QCoreApplication::translate("huarongdaolevelselectwidget", "\345\210\206\344\272\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class huarongdaolevelselectwidget: public Ui_huarongdaolevelselectwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUARONGDAOLEVELSELECTWIDGET_H
