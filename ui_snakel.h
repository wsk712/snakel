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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_snakel
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *snakel)
    {
        if (snakel->objectName().isEmpty())
            snakel->setObjectName(QString::fromUtf8("snakel"));
        snakel->resize(800, 600);
        centralwidget = new QWidget(snakel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        snakel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(snakel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        snakel->setMenuBar(menubar);
        statusbar = new QStatusBar(snakel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        snakel->setStatusBar(statusbar);

        retranslateUi(snakel);

        QMetaObject::connectSlotsByName(snakel);
    } // setupUi

    void retranslateUi(QMainWindow *snakel)
    {
        snakel->setWindowTitle(QCoreApplication::translate("snakel", "snakel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class snakel: public Ui_snakel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKEL_H
