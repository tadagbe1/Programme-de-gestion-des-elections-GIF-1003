/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   AjoutElecteur.h
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 19 h 26
 */

#ifndef _AJOUTELECTEUR_H
#define _AJOUTELECTEUR_H

#include "ui_AjoutElecteur.h"
#include<string>
#include "Date.h"
#include <QMessageBox>
#include "Circonscription.h"

class AjoutElecteur : public QDialog
{
  Q_OBJECT
public:
  AjoutElecteur ();
  virtual ~AjoutElecteur ();
  std::string reqNas() const;
  std::string reqPrenom() const;
  std::string reqNom() const;
  std::string reqAdresse() const;
  util::Date reqDateNaissance() const;
private slots:
  void validation();
  
private:
  Ui::AjoutElecteur widget;
  util::Date m_dateNaissance;
  
  
};

#endif /* _AJOUTELECTEUR_H */
