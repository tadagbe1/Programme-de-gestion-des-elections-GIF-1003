/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   CirconscriptionGUI.h
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 18 h 16
 */

#ifndef _CIRCONSCRIPTIONGUI_H
#define _CIRCONSCRIPTIONGUI_H
#include "Circonscription.h"
#include "AjoutCandidate.h"
#include "AjoutElecteur.h"
#include "Desinscription.h"
#include "Electeur.h"
#include <QMessageBox>

#include "ui_CirconscriptionGUI.h"

using namespace elections;

class CirconscriptionGUI : public QMainWindow
{
  Q_OBJECT
public:
  CirconscriptionGUI ();
  virtual ~CirconscriptionGUI ();
  
private slots:
  void dialogCandidate();
  void dialogElecteur();
  void dialogDesinscrire();
private:
  Ui::CirconscriptionGUI widget;
  Circonscription circonscription;
};

#endif /* _CIRCONSCRIPTIONGUI_H */
