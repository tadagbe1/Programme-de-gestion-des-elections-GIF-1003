/********************************************************************************
** Form generated from reading UI file 'Desinscription.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESINSCRIPTION_H
#define UI_DESINSCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Desinscription
{
public:
    QLabel *label;
    QLineEdit *nas;
    QPushButton *ok;

    void setupUi(QDialog *Desinscription)
    {
        if (Desinscription->objectName().isEmpty())
            Desinscription->setObjectName(QString::fromUtf8("Desinscription"));
        Desinscription->resize(596, 300);
        label = new QLabel(Desinscription);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 70, 58, 16));
        nas = new QLineEdit(Desinscription);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(120, 60, 113, 28));
        ok = new QPushButton(Desinscription);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(210, 230, 90, 28));

        retranslateUi(Desinscription);
        QObject::connect(ok, SIGNAL(clicked()), Desinscription, SLOT(validation()));

        QMetaObject::connectSlotsByName(Desinscription);
    } // setupUi

    void retranslateUi(QDialog *Desinscription)
    {
        Desinscription->setWindowTitle(QCoreApplication::translate("Desinscription", "Desinscription", nullptr));
        label->setText(QCoreApplication::translate("Desinscription", "NAS :", nullptr));
        ok->setText(QCoreApplication::translate("Desinscription", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Desinscription: public Ui_Desinscription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESINSCRIPTION_H
