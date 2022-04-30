/********************************************************************************
** Form generated from reading UI file 'twozerofoureight.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOZEROFOUREIGHT_H
#define UI_TWOZEROFOUREIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_twozerofoureight
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *twozerofoureight)
    {
        if (twozerofoureight->objectName().isEmpty())
            twozerofoureight->setObjectName(QString::fromUtf8("twozerofoureight"));
        twozerofoureight->resize(320, 480);
        pushButton = new QPushButton(twozerofoureight);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 450, 93, 29));

        retranslateUi(twozerofoureight);

        QMetaObject::connectSlotsByName(twozerofoureight);
    } // setupUi

    void retranslateUi(QWidget *twozerofoureight)
    {
        twozerofoureight->setWindowTitle(QCoreApplication::translate("twozerofoureight", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("twozerofoureight", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class twozerofoureight: public Ui_twozerofoureight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOZEROFOUREIGHT_H
