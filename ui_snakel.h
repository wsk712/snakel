/********************************************************************************
** Form generated from reading UI file 'snakel.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKEL_H
#define UI_SNAKEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_snakel
{
public:
    QWidget *centralwidget;
    QPushButton *button2048;
    QPushButton *buttonsaolei;
    QPushButton *buttonshuerte;
    QPushButton *buttonhuarongdao;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *snakel)
    {
        if (snakel->objectName().isEmpty())
            snakel->setObjectName(QString::fromUtf8("snakel"));
        snakel->resize(320, 480);
        centralwidget = new QWidget(snakel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        button2048 = new QPushButton(centralwidget);
        button2048->setObjectName(QString::fromUtf8("button2048"));
        button2048->setGeometry(QRect(110, 200, 93, 29));
        buttonsaolei = new QPushButton(centralwidget);
        buttonsaolei->setObjectName(QString::fromUtf8("buttonsaolei"));
        buttonsaolei->setGeometry(QRect(110, 150, 93, 29));
        buttonsaolei->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        buttonshuerte = new QPushButton(centralwidget);
        buttonshuerte->setObjectName(QString::fromUtf8("buttonshuerte"));
        buttonshuerte->setGeometry(QRect(110, 300, 93, 29));
        buttonhuarongdao = new QPushButton(centralwidget);
        buttonhuarongdao->setObjectName(QString::fromUtf8("buttonhuarongdao"));
        buttonhuarongdao->setGeometry(QRect(110, 250, 93, 29));
        buttonhuarongdao->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        snakel->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(snakel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        snakel->setStatusBar(statusbar);

        retranslateUi(snakel);

        QMetaObject::connectSlotsByName(snakel);
    } // setupUi

    void retranslateUi(QMainWindow *snakel)
    {
        snakel->setWindowTitle(QCoreApplication::translate("snakel", "snakel", nullptr));
        button2048->setText(QCoreApplication::translate("snakel", "PushButton", nullptr));
        buttonsaolei->setText(QCoreApplication::translate("snakel", "PushButton", nullptr));
        buttonshuerte->setText(QCoreApplication::translate("snakel", "PushButton", nullptr));
        buttonhuarongdao->setText(QCoreApplication::translate("snakel", "\346\225\260\345\255\227\345\215\216\345\256\271\351\201\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class snakel: public Ui_snakel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKEL_H
