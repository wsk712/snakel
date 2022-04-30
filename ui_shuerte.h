/********************************************************************************
** Form generated from reading UI file 'shuerte.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHUERTE_H
#define UI_SHUERTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "shuertegamepanelwidget.h"

QT_BEGIN_NAMESPACE

class Ui_shuerte
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetCenter;
    shuertegamepanelwidget *widgetGamePanel;
    QPushButton *btnStart;
    QLabel *labelTimes;
    QPushButton *btnLevelSelect;

    void setupUi(QWidget *shuerte)
    {
        if (shuerte->objectName().isEmpty())
            shuerte->setObjectName(QString::fromUtf8("shuerte"));
        shuerte->resize(392, 696);
        shuerte->setStyleSheet(QString::fromUtf8("QWidget#widgetCenter {\n"
"        background-image: url(://picture/background.jpg);\n"
"}"));
        verticalLayout = new QVBoxLayout(shuerte);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetCenter = new QWidget(shuerte);
        widgetCenter->setObjectName(QString::fromUtf8("widgetCenter"));
        widgetGamePanel = new shuertegamepanelwidget(widgetCenter);
        widgetGamePanel->setObjectName(QString::fromUtf8("widgetGamePanel"));
        widgetGamePanel->setGeometry(QRect(52, 197, 285, 285));
        widgetGamePanel->setStyleSheet(QString::fromUtf8(""));
        btnStart = new QPushButton(widgetCenter);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(129, 514, 131, 48));
        btnStart->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 20px;"));
        labelTimes = new QLabel(widgetCenter);
        labelTimes->setObjectName(QString::fromUtf8("labelTimes"));
        labelTimes->setGeometry(QRect(160, 110, 70, 25));
        QFont font;
        font.setPointSize(10);
        labelTimes->setFont(font);
        labelTimes->setStyleSheet(QString::fromUtf8(""));
        labelTimes->setAlignment(Qt::AlignCenter);
        btnLevelSelect = new QPushButton(widgetCenter);
        btnLevelSelect->setObjectName(QString::fromUtf8("btnLevelSelect"));
        btnLevelSelect->setGeometry(QRect(70, 110, 41, 21));
        btnLevelSelect->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 20px;"));

        verticalLayout->addWidget(widgetCenter);


        retranslateUi(shuerte);

        QMetaObject::connectSlotsByName(shuerte);
    } // setupUi

    void retranslateUi(QWidget *shuerte)
    {
        shuerte->setWindowTitle(QCoreApplication::translate("shuerte", "shuerte", nullptr));
        btnStart->setText(QCoreApplication::translate("shuerte", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        labelTimes->setText(QCoreApplication::translate("shuerte", "00:00:00", nullptr));
        btnLevelSelect->setText(QCoreApplication::translate("shuerte", "\351\232\276\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shuerte: public Ui_shuerte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHUERTE_H
