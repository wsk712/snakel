/********************************************************************************
** Form generated from reading UI file 'saolei.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAOLEI_H
#define UI_SAOLEI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saolei
{
public:

    void setupUi(QWidget *saolei)
    {
        if (saolei->objectName().isEmpty())
            saolei->setObjectName(QString::fromUtf8("saolei"));
        saolei->resize(400, 300);

        retranslateUi(saolei);

        QMetaObject::connectSlotsByName(saolei);
    } // setupUi

    void retranslateUi(QWidget *saolei)
    {
        saolei->setWindowTitle(QCoreApplication::translate("saolei", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saolei: public Ui_saolei {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAOLEI_H
