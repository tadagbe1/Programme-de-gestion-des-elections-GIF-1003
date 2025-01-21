#include "Personne.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Date.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Circonscription.h"
#include "ContratException.h"

using namespace elections;

/*
 * 
 */
int
main ()
{
  // affichage
  std::cout << "--------------------------------------------" << std::endl;
  std::cout << "Bienvenue a l'outil de gestion des listes électorales" << std::endl;
  std::cout << "--------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::string nom_circonscription;

  char buffer[256];

  do
    { // demande le nom de la circonscription
      std::cout << "Nom de circonscription : ";
      std::cin.getline (buffer, 256);
      nom_circonscription = buffer;
    }
  while (nom_circonscription.empty ());

  int parti;
  do
    { // demande le parti
      std::cout << "Inscription d'un candidat" << std::endl;
      std::cout << "Choisissez un parti:" << std::endl;
      std::cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << std::endl;
      std::cin>> parti;
      std::cout << std::endl;
      
      
      
      
    }
  while (!(parti <= 4 && parti >= 0) );

 

  int jour;
  int mois;
  int annee;
  do
    { // demande la date de naissance
      std::cout << "Veuillez saisir sa date de naissance :" << std::endl;
      std::cout << "Le jour [1..31]: ";
      std::cin >> jour;

      std::cout << "Le mois [1..12]: ";
      std::cin >> mois;
      std::cout << "L'annee [1970..2037]: ";
      std::cin >> annee;
      std::cout << std::endl;
    }
  while (!(util::Date::validerDate (jour, mois, annee)));

  std::cin.ignore ();



  std::string adresse;
  do
    {
      // demande l adresse
      std::cout << "Veuillez saisir son adresse :" << std::endl;

      std::cin.getline (buffer, 256);
      adresse = buffer;
      std::cout << std::endl;
    }
  while (adresse.empty ());

  std::string nom;
  std::string prenom;
  std::string nas;



  do
    {
      // demande le nom
      std::cout << "Entrez le nom : ";
      std::cin.getline (buffer, 256);
      nom = buffer;
      std::cout << std::endl;
    }
  while (nom.empty ());

  do
    {
      // demande le prénom
      std::cout << "Entrez le prénom : ";
      std::cin.getline (buffer, 256);
      prenom = buffer;
      std::cout << std::endl;
    }
  while (prenom.empty ());

  do
    {
      // demande le nas
      std::cout << "Entrez le numero d'assurance sociale : ";

      std::cin.getline (buffer, 256);
      nas = buffer;
      std::cout << std::endl;
    }
  while (!(util::validerNas (nas)));
  
  // on crée un candidat

  Candidat un_candidat (nas, prenom, nom, adresse, util::Date (jour, mois, annee), parti);






  std::cout << "Inscription d’un électeur" << std::endl;



  do
    {
      // demande la date de naissance
      std::cout << "Veuillez saisir sa date de naissance :" << std::endl;
      std::cout << "Le jour [1..31]: ";
      std::cin >> jour;

      std::cout << "Le mois [1..12]: ";
      std::cin >> mois;
      std::cout << "L'annee [1970..2037]: ";
      std::cin >> annee;
      std::cout << std::endl;
    }
  while (!(util::Date::validerDate (jour, mois, annee)));


  std::cin.ignore ();




  do
    {
      // demande l adresse
      std::cout << "Veuillez saisir son adresse :" << std::endl;

      std::cin.getline (buffer, 256);
      adresse = buffer;
      std::cout << std::endl;

    }
  while (adresse.empty ());





  do
    { // demande le nom
      std::cout << "Entrez le nom : ";
      std::cin.getline (buffer, 256);
      nom = buffer;

      std::cout << std::endl;
    }
  while (nom.empty ());

  do
    { 
      // demande le prénom
      std::cout << "Entrez le prénom : ";
      std::cin.getline (buffer, 256);
      prenom = buffer;

      std::cout << std::endl;
    }
  while (prenom.empty ());

  do
    {
      // demande le nas
      std::cout << "Entrez le numero d'assurance sociale : ";

      std::cin.getline (buffer, 256);
      nas = buffer;
      std::cout << std::endl;
    }
  while (!(util::validerNas (nas)));

  // on crée un candidat sortant
  Candidat candidatSortant ("640 454 286", "inconnu", "inconnu", "bénin", util::Date (1, 1, 1980), 1);

  // on crée une circonscription
  Circonscription une_circonscription (nom_circonscription, candidatSortant);
  // on crée un électeur
  Electeur un_electeur (nas, prenom, nom, adresse, util::Date (jour, mois, annee));

  // on ajoute l électeur et le candidat a la lsite des électeurs de la circonscription
  une_circonscription.inscrire (un_electeur);

  une_circonscription.inscrire (un_candidat);
  
  
  
  // on affiche la circonscription

  std::cout << une_circonscription.reqCirconscriptionFormate () << std::endl;

  
  
  std::cout << "************************************************************" << std::endl;
  
  une_circonscription.desinscrire (nas);

  std::cout << une_circonscription.reqCirconscriptionFormate () << std::endl;
  
  
  return 0;
}

