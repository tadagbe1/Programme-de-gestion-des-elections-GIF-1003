/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   AjoutElecteur.cpp
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 19 h 26
 */

#include "AjoutElecteur.h"

AjoutElecteur::AjoutElecteur ()
{
  widget.setupUi (this);
}

AjoutElecteur::~AjoutElecteur () { }

std::string AjoutElecteur::reqNas() const{
  return widget.nas->text().toStdString();
  
}
  std::string AjoutElecteur::reqPrenom() const{
    return widget.prenom->text().toStdString();
    
  }
  std::string AjoutElecteur::reqNom() const{
    return widget.nom->text().toStdString();
    
  }
  std::string AjoutElecteur::reqAdresse() const{
    return widget.adresse->text().toStdString();
    
  }
  util::Date AjoutElecteur::reqDateNaissance() const{
    return m_dateNaissance;
    
  }
void AjoutElecteur::validation(){
  
  if(!util::validerNas(reqNas()) ){
      QString message ("Le nas doit etre valide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
   if (reqPrenom().empty())
    {
      QString message ("Le prénom ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  
  if (reqNom().empty())
    {
      QString message ("Le nom ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  
  if (reqAdresse().empty())
    {
      QString message ("Adresse ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  
  QDate dateCourant = QDate::currentDate ();
  if (widget.date_de_naissance->selectedDate () >= dateCourant)
    {
      QString message ("Le date ne doit pas etre celle daujourdhui ou une date du futur");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  
  else{
  m_dateNaissance.asgDate (widget.date_de_naissance->selectedDate().day (), 
                           widget.date_de_naissance->selectedDate().month (), 
                           widget.date_de_naissance->selectedDate().year () );
  accept ();
    }
  
  
}