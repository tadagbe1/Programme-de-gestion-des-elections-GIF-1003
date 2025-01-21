/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   Desinscription.h
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 19 h 27
 */

#ifndef _DESINSCRIPTION_H
#define _DESINSCRIPTION_H

#include "ui_Desinscription.h"
#include <string>
#include "Date.h"
#include <QMessageBox>
#include "Circonscription.h"


class Desinscription : public QDialog
{
  Q_OBJECT
public:
  Desinscription ();
  virtual ~Desinscription ();
  std::string reqNas() const;
private slots:
  void validation();
  
private:
  Ui::Desinscription widget;
};

#endif /* _DESINSCRIPTION_H */
