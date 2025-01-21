/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   Desinscription.cpp
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 19 h 27
 */

#include "Desinscription.h"

Desinscription::Desinscription ()
{
  widget.setupUi (this);
}

Desinscription::~Desinscription () { }

std::string Desinscription::reqNas() const {
  return widget.nas->text().toStdString();
}

void Desinscription::validation(){
  if(!util::validerNas(reqNas()) ){
      QString message ("Le nas doit etre valide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  
  
  else{
      accept();
    }
  
}