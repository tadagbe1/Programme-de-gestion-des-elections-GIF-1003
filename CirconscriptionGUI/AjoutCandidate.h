/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   AjoutCandidate.h
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 19 h 25
 */

#ifndef _AJOUTCANDIDATE_H
#define _AJOUTCANDIDATE_H

#include "ui_AjoutCandidate.h"
#include<string>
#include "Date.h"
#include <QMessageBox>
#include "Circonscription.h"
class AjoutCandidate : public QDialog
{
  Q_OBJECT
public:
  AjoutCandidate ();
  virtual ~AjoutCandidate ();
  std::string reqNas() const;
  std::string reqPrenom() const;
  std::string reqNom() const;
  std::string reqAdresse() const;
  util::Date reqDateNaissance() const;
  int reqPartiPolitique() const;
private slots:
  void validation();
private:
  Ui::AjoutCandidate widget;
  util::Date m_dateNaissance;
};

#endif /* _AJOUTCANDIDATE_H */
