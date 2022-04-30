/********************************************************************************
** Form generated from reading UI file 'saoleidialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAOLEIDIALOG_H
#define UI_SAOLEIDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saoleiDialog
{
public:

    void setupUi(QWidget *saoleiDialog)
    {
        if (saoleiDialog->objectName().isEmpty())
            saoleiDialog->setObjectName(QString::fromUtf8("saoleiDialog"));
        saoleiDialog->resize(400, 300);

        retranslateUi(saoleiDialog);

        QMetaObject::connectSlotsByName(saoleiDialog);
    } // setupUi

    void retranslateUi(QWidget *saoleiDialog)
    {
        saoleiDialog->setWindowTitle(QCoreApplication::translate("saoleiDialog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saoleiDialog: public Ui_saoleiDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAOLEIDIALOG_H
