/********************************************************************************
** Form generated from reading UI file 'huarongdao.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUARONGDAO_H
#define UI_HUARONGDAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "huarongdaogamepanelwidget.h"

QT_BEGIN_NAMESPACE

class Ui_huarongdao
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetCenter;
    huarongdaogamepanelwidget *widgetGamePanel;
    QPushButton *btnStart;
    QLabel *labelTimes;
    QPushButton *btnLevelSelect;

    void setupUi(QWidget *huarongdao)
    {
        if (huarongdao->objectName().isEmpty())
            huarongdao->setObjectName(QString::fromUtf8("huarongdao"));
        huarongdao->resize(392, 696);
        huarongdao->setStyleSheet(QString::fromUtf8("QWidget#widgetCenter {\n"
"        background-image: url(://picture/background.jpg);\n"
"}"));
        verticalLayout = new QVBoxLayout(huarongdao);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetCenter = new QWidget(huarongdao);
        widgetCenter->setObjectName(QString::fromUtf8("widgetCenter"));
        widgetGamePanel = new huarongdaogamepanelwidget(widgetCenter);
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


        retranslateUi(huarongdao);

        QMetaObject::connectSlotsByName(huarongdao);
    } // setupUi

    void retranslateUi(QWidget *huarongdao)
    {
        huarongdao->setWindowTitle(QCoreApplication::translate("huarongdao", "huarongdao", nullptr));
        btnStart->setText(QCoreApplication::translate("huarongdao", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        labelTimes->setText(QCoreApplication::translate("huarongdao", "00:00:00", nullptr));
        btnLevelSelect->setText(QCoreApplication::translate("huarongdao", "\351\232\276\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class huarongdao: public Ui_huarongdao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUARONGDAO_H
