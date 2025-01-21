/********************************************************************************
** Form generated from reading UI file 'AjoutCandidate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCANDIDATE_H
#define UI_AJOUTCANDIDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutCandidate
{
public:
    QLabel *label;
    QLineEdit *nas;
    QLabel *label_2;
    QLineEdit *prenom;
    QLabel *label_3;
    QLineEdit *nom;
    QLabel *label_4;
    QCalendarWidget *date_de_naissance;
    QLabel *label_5;
    QLineEdit *adresse;
    QLabel *label_6;
    QPushButton *ok;
    QSpinBox *parti;

    void setupUi(QDialog *AjoutCandidate)
    {
        if (AjoutCandidate->objectName().isEmpty())
            AjoutCandidate->setObjectName(QString::fromUtf8("AjoutCandidate"));
        AjoutCandidate->resize(784, 538);
        label = new QLabel(AjoutCandidate);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 101, 21));
        nas = new QLineEdit(AjoutCandidate);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(170, 40, 113, 28));
        label_2 = new QLabel(AjoutCandidate);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 90, 58, 16));
        prenom = new QLineEdit(AjoutCandidate);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(170, 80, 113, 28));
        label_3 = new QLabel(AjoutCandidate);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 130, 58, 16));
        nom = new QLineEdit(AjoutCandidate);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(170, 120, 113, 28));
        label_4 = new QLabel(AjoutCandidate);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 250, 141, 16));
        date_de_naissance = new QCalendarWidget(AjoutCandidate);
        date_de_naissance->setObjectName(QString::fromUtf8("date_de_naissance"));
        date_de_naissance->setGeometry(QRect(140, 170, 432, 194));
        label_5 = new QLabel(AjoutCandidate);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 390, 58, 16));
        adresse = new QLineEdit(AjoutCandidate);
        adresse->setObjectName(QString::fromUtf8("adresse"));
        adresse->setGeometry(QRect(150, 380, 113, 28));
        label_6 = new QLabel(AjoutCandidate);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 430, 91, 16));
        ok = new QPushButton(AjoutCandidate);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(320, 490, 90, 28));
        parti = new QSpinBox(AjoutCandidate);
        parti->setObjectName(QString::fromUtf8("parti"));
        parti->setGeometry(QRect(150, 430, 42, 26));

        retranslateUi(AjoutCandidate);
        QObject::connect(ok, SIGNAL(clicked()), AjoutCandidate, SLOT(validation()));

        QMetaObject::connectSlotsByName(AjoutCandidate);
    } // setupUi

    void retranslateUi(QDialog *AjoutCandidate)
    {
        AjoutCandidate->setWindowTitle(QCoreApplication::translate("AjoutCandidate", "AjoutCandidate", nullptr));
        label->setText(QCoreApplication::translate("AjoutCandidate", "NAS:", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutCandidate", "Prenom", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutCandidate", "Nom", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutCandidate", "Date de naissance", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutCandidate", "Adresse", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutCandidate", "Parti politique", nullptr));
        ok->setText(QCoreApplication::translate("AjoutCandidate", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutCandidate: public Ui_AjoutCandidate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCANDIDATE_H
