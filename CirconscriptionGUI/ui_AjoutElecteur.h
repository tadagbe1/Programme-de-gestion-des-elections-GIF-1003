/********************************************************************************
** Form generated from reading UI file 'AjoutElecteur.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTELECTEUR_H
#define UI_AJOUTELECTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjoutElecteur
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *nas;
    QLineEdit *prenom;
    QLineEdit *nom;
    QLineEdit *adresse;
    QCalendarWidget *date_de_naissance;
    QPushButton *ok;

    void setupUi(QDialog *AjoutElecteur)
    {
        if (AjoutElecteur->objectName().isEmpty())
            AjoutElecteur->setObjectName(QString::fromUtf8("AjoutElecteur"));
        AjoutElecteur->resize(770, 589);
        buttonBox = new QDialogButtonBox(AjoutElecteur);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 400, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AjoutElecteur);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 58, 16));
        label_2 = new QLabel(AjoutElecteur);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 58, 16));
        label_3 = new QLabel(AjoutElecteur);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 160, 58, 16));
        label_4 = new QLabel(AjoutElecteur);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 220, 58, 16));
        label_5 = new QLabel(AjoutElecteur);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 400, 151, 16));
        nas = new QLineEdit(AjoutElecteur);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(150, 20, 421, 28));
        prenom = new QLineEdit(AjoutElecteur);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(150, 80, 421, 28));
        nom = new QLineEdit(AjoutElecteur);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(160, 150, 411, 28));
        adresse = new QLineEdit(AjoutElecteur);
        adresse->setObjectName(QString::fromUtf8("adresse"));
        adresse->setGeometry(QRect(160, 210, 411, 28));
        date_de_naissance = new QCalendarWidget(AjoutElecteur);
        date_de_naissance->setObjectName(QString::fromUtf8("date_de_naissance"));
        date_de_naissance->setGeometry(QRect(160, 300, 432, 194));
        ok = new QPushButton(AjoutElecteur);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(240, 530, 90, 28));

        retranslateUi(AjoutElecteur);
        QObject::connect(buttonBox, SIGNAL(accepted()), AjoutElecteur, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AjoutElecteur, SLOT(reject()));
        QObject::connect(ok, SIGNAL(clicked()), AjoutElecteur, SLOT(validation()));

        QMetaObject::connectSlotsByName(AjoutElecteur);
    } // setupUi

    void retranslateUi(QDialog *AjoutElecteur)
    {
        AjoutElecteur->setWindowTitle(QCoreApplication::translate("AjoutElecteur", "AjoutElecteur", nullptr));
        label->setText(QCoreApplication::translate("AjoutElecteur", "NAS :", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutElecteur", "Prenom :", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutElecteur", "Nom :", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutElecteur", "Adresse :", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutElecteur", "Date de naissance :", nullptr));
        ok->setText(QCoreApplication::translate("AjoutElecteur", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutElecteur: public Ui_AjoutElecteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTELECTEUR_H
