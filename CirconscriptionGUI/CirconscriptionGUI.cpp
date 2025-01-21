/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   CirconscriptionGUI.cpp
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 18 h 1s6
 */

#include "CirconscriptionGUI.h"
using namespace elections;

Candidat unCandidat ("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date (12, 5, 1979), 0);

  

CirconscriptionGUI::CirconscriptionGUI (): circonscription("Circonscription de Québec", unCandidat)
{
  widget.setupUi (this);
  widget.affichage->setText(circonscription.reqCirconscriptionFormate ().c_str());
}

CirconscriptionGUI::~CirconscriptionGUI () { }



void CirconscriptionGUI::dialogCandidate(){
  AjoutCandidate Cand;
  if (Cand.exec()){
      Candidat candidat(Cand.reqNas(),
                        Cand.reqPrenom(),
                        Cand.reqNom(),
                        Cand.reqAdresse(),
                        Cand.reqDateNaissance(),
                        Cand.reqPartiPolitique()
                        );
      
      try{
      
      circonscription.inscrire(candidat);
        }
      catch(PersonneDejaPresenteException& e ){
          QString message (e.what());
          QMessageBox::information (this, "ERREUR", message);
          return;
        }
    }
  widget.affichage->clear();
  widget.affichage->setText(circonscription.reqCirconscriptionFormate ().c_str());
}

void CirconscriptionGUI::dialogElecteur(){
   AjoutElecteur Elect;
  if (Elect.exec()){
      Electeur electeur(Elect.reqNas(),
                        Elect.reqPrenom(),
                        Elect.reqNom(),
                        Elect.reqAdresse(),
                        Elect.reqDateNaissance()
                        );
      
      
      try{
      circonscription.inscrire(electeur);
      
        }
      catch (PersonneDejaPresenteException& e){
          QString message (e.what());
          QMessageBox::information (this, "ERREUR", message);
          return;
        }
      
      widget.affichage->clear();
      widget.affichage->setText(circonscription.reqCirconscriptionFormate ().c_str());
    }
  
}
//co;;entqire
void CirconscriptionGUI::dialogDesinscrire(){
   Desinscription Desin;
  if (Desin.exec()){
      try{
      circonscription.desinscrire (Desin.reqNas());
        }
      catch(PersonneAbsenteException & e){
          QString message (e.what());
          QMessageBox::information (this, "ERREUR", message);
          return;
          
        }
      
      
      widget.affichage->clear();
      widget.affichage->setText(circonscription.reqCirconscriptionFormate ().c_str());
    }
  
}
