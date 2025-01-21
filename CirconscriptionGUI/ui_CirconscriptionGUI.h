/********************************************************************************
** Form generated from reading UI file 'CirconscriptionGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCONSCRIPTIONGUI_H
#define UI_CIRCONSCRIPTIONGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CirconscriptionGUI
{
public:
    QAction *actionCandidate;
    QAction *actionElecteur;
    QAction *actionD_sinscription_d_une_personne;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuInscription_d_une_personne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CirconscriptionGUI)
    {
        if (CirconscriptionGUI->objectName().isEmpty())
            CirconscriptionGUI->setObjectName(QString::fromUtf8("CirconscriptionGUI"));
        CirconscriptionGUI->resize(973, 600);
        actionCandidate = new QAction(CirconscriptionGUI);
        actionCandidate->setObjectName(QString::fromUtf8("actionCandidate"));
        actionElecteur = new QAction(CirconscriptionGUI);
        actionElecteur->setObjectName(QString::fromUtf8("actionElecteur"));
        actionD_sinscription_d_une_personne = new QAction(CirconscriptionGUI);
        actionD_sinscription_d_une_personne->setObjectName(QString::fromUtf8("actionD_sinscription_d_une_personne"));
        actionQuitter = new QAction(CirconscriptionGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(CirconscriptionGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(20, 24, 741, 391));
        CirconscriptionGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CirconscriptionGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 973, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuInscription_d_une_personne = new QMenu(menuMenu);
        menuInscription_d_une_personne->setObjectName(QString::fromUtf8("menuInscription_d_une_personne"));
        CirconscriptionGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(CirconscriptionGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CirconscriptionGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuInscription_d_une_personne->menuAction());
        menuMenu->addAction(actionD_sinscription_d_une_personne);
        menuMenu->addAction(actionQuitter);
        menuInscription_d_une_personne->addAction(actionCandidate);
        menuInscription_d_une_personne->addAction(actionElecteur);

        retranslateUi(CirconscriptionGUI);
        QObject::connect(actionQuitter, SIGNAL(triggered()), CirconscriptionGUI, SLOT(close()));
        QObject::connect(actionCandidate, SIGNAL(triggered()), CirconscriptionGUI, SLOT(dialogCandidate()));
        QObject::connect(actionElecteur, SIGNAL(triggered()), CirconscriptionGUI, SLOT(dialogElecteur()));
        QObject::connect(actionD_sinscription_d_une_personne, SIGNAL(triggered()), CirconscriptionGUI, SLOT(dialogDesinscrire()));

        QMetaObject::connectSlotsByName(CirconscriptionGUI);
    } // setupUi

    void retranslateUi(QMainWindow *CirconscriptionGUI)
    {
        CirconscriptionGUI->setWindowTitle(QCoreApplication::translate("CirconscriptionGUI", "CirconscriptionGUI", nullptr));
        actionCandidate->setText(QCoreApplication::translate("CirconscriptionGUI", "Candidate", nullptr));
        actionElecteur->setText(QCoreApplication::translate("CirconscriptionGUI", "Electeur", nullptr));
        actionD_sinscription_d_une_personne->setText(QCoreApplication::translate("CirconscriptionGUI", "D\303\251sinscription d'une personne", nullptr));
        actionQuitter->setText(QCoreApplication::translate("CirconscriptionGUI", "Quitter", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("CirconscriptionGUI", "Op\303\251rations", nullptr));
        menuInscription_d_une_personne->setTitle(QCoreApplication::translate("CirconscriptionGUI", "Inscription d\342\200\231une personne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CirconscriptionGUI: public Ui_CirconscriptionGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCONSCRIPTIONGUI_H
