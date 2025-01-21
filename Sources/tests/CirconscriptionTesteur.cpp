#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <memory>
#include "Circonscription.h"
#include "Candidat.h"
#include "Date.h"
#include "ContratException.h"
#include "Electeur.h"

using namespace elections;

TEST (Circonscription, ConstructeurCopie)
{
  // Création d'un candidat sortant
  util::Date date_naissance (1, 1, 1999); // Date valide
  Candidat deputeSortant ("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                          date_naissance, 0);

  // Création de la circonscription initiale
  Circonscription circonscriptionOriginale ("Circonscription 1", deputeSortant);

  // Ajout de quelques inscrits
  Electeur electeur1 ("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));
  Electeur electeur2 ("046 454 385", "Marie Antoinette", "Gipsy", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));

  circonscriptionOriginale.inscrire (electeur1);
  circonscriptionOriginale.inscrire (electeur2);

  // Création d'une copie de la circonscription
  Circonscription circonscriptionCopie (circonscriptionOriginale);

  // Vérification de la copie
  EXPECT_EQ (circonscriptionOriginale.reqNomCirconscription (), circonscriptionCopie.reqNomCirconscription ());
  EXPECT_EQ (circonscriptionOriginale.reqDeputeElu ().reqPersonneFormate (),
             circonscriptionCopie.reqDeputeElu ().reqPersonneFormate ());
  EXPECT_EQ (circonscriptionOriginale.reqNombreInscrits (),
             circonscriptionCopie.reqNombreInscrits ());

  // Vérification des objets du vecteur
  const auto& inscritsOriginale = circonscriptionOriginale.reqInscrits ();
  const auto& inscritsCopie = circonscriptionCopie.reqInscrits ();

  ASSERT_EQ (inscritsOriginale.size (), inscritsCopie.size ()); // Les tailles doivent être égales

  for (size_t i = 0; i < inscritsOriginale.size (); ++i)
    {
      EXPECT_EQ (inscritsOriginale[i]->reqPersonneFormate (), inscritsCopie[i]->reqPersonneFormate ());
      EXPECT_NE (inscritsOriginale[i].get (), inscritsCopie[i].get ()); // Vérifie que les objets sont des clones
    }


}

/**
 * \brief Test du constructeur valide
 *  Cas valides : Création d'une circonscription et vérification de l'assignation de tous les attributs
 */
TEST (Circonscription, ConstructeurValide)
{
  Candidat unCandidat ("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date (12, 5, 1979), 0);

  Circonscription uneCirconscription ("Circonscription de Québec", unCandidat);

  ASSERT_EQ ("Circonscription de Québec", uneCirconscription.reqNomCirconscription ());
  ASSERT_EQ (unCandidat, uneCirconscription.reqDeputeElu ());
  ASSERT_EQ (0, uneCirconscription.reqNombreInscrits ());
}

/**
 * \brief Test du constructeur invalide
 *  Cas invalide : Tentative de création d'une circonscription avec un nom vide
 */
TEST (Circonscription, ConstructeurNomVide)
{
  Candidat unCandidat ("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date (1, 1, 1999), 0);

  ASSERT_THROW (Circonscription uneCirconscription ("", unCandidat), PreconditionException);
}

/**
 * \test Test de la méthode reqNomCirconscription()
 * Cas valide: vérifier le retour du nom de la Circonscription
 * Cas invalide: aucun
 */
TEST (Circonscription, reqNomCirconscription)
{
  Candidat unCandidat ("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date (12, 5, 1979), 0);

  Circonscription uneCirconscription ("Québec", unCandidat);

  ASSERT_EQ ("Québec", uneCirconscription.reqNomCirconscription ());
}

/**
 * \test Test de la méthode reqDeputeElu()
 * Cas valide : vérifier que la méthode retourne correctement le député élu.
 * Cas invalide : aucun.
 */
TEST (Circonscription, reqDeputeElu)
{
  Candidat unCandidat ("046 454 237", "Jean", "Louis",
                       "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date (1, 1, 1999),
                       0);

  Circonscription uneCirconscription ("Circonscription de Québec", unCandidat);

  ASSERT_EQ (unCandidat.reqPersonneFormate (), uneCirconscription.reqDeputeElu ().reqPersonneFormate ());

}

/**
 * \test Test de la méthode inscrire()
 *      Cas valide: Ajouter une personne à la liste des inscrits.
 *      Cas invalide: aucun

 */
TEST (Circonscription, inscrire)
{
  // Création d'un candidat sortant
  util::Date date_naissance (1, 1, 1999); // Date valide
  Candidat deputeSortant ("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                          date_naissance, 0);

  // Création de la circonscription initiale
  Circonscription circonscriptionOriginale ("Circonscription 1", deputeSortant);

  // Ajout de quelques inscrits
  Electeur electeur1 ("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));
  Electeur electeur2 ("046 454 385", "Marie Antoinette", "Gipsy", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));

  circonscriptionOriginale.inscrire (electeur1);
  circonscriptionOriginale.inscrire (electeur2);

  
  ASSERT_EQ(2, circonscriptionOriginale.reqNombreInscrits());
  
  
}

/**
 * \test Test de la méthode inscrire()
 *      Cas valide: Aucun
 *      Cas invalide: on essaie d inscrire un personne qui existe déja

 */


TEST (Circonscription, inscrireUnePersonneExistante)
{
  // Création d'un candidat sortant
  util::Date date_naissance (1, 1, 1999); // Date valide
  Candidat deputeSortant ("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                          date_naissance, 0);

  // Création de la circonscription initiale
  Circonscription circonscriptionOriginale ("Circonscription 1", deputeSortant);

  // Ajout de quelques inscrits
  Electeur electeur1 ("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));
  

  circonscriptionOriginale.inscrire (electeur1);
  

  
  
  ASSERT_THROW (circonscriptionOriginale.inscrire(electeur1), PersonneDejaPresenteException);
  
}

/**
 * \test Test de la méthode NombreInscrits()
 *      Cas valide: compter le nombre de personne à la liste des inscrits.
 *      Cas invalide: aucun,
 */
TEST (CirconscriptionTest, reqNombreInscrits)
{
  // Création d'un candidat
  Candidat unCandidat ("046 454 237", "Jean", "Louis",
                       "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date (1, 1, 1999), 0);

  // Création d'une circonscription avec un député élu
  Circonscription uneCirconscription ("Québec", unCandidat);

  // Vérification du nombre initial d'inscrits (devrait être 0)
  ASSERT_EQ (0, uneCirconscription.reqNombreInscrits ());


  uneCirconscription.inscrire (unCandidat);


  // Vérification du nombre d'inscrits 
  ASSERT_EQ (1, uneCirconscription.reqNombreInscrits ());
}

/**
 * \test Test de la méthode ReqCirconscriptionFormate() pour vérifier le formatage correct des informations
 */

TEST (CirconscriptionTest, ReqCirconscriptionFormate)
{

  Candidat unCandidat ("046 454 237", "Jean", "Louis",
                       "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date (1, 1, 1999), 0);

  Circonscription uneCirconscription ("Québec", unCandidat);

  Electeur unElecteur ("046 454 385", "Marie Antoinette", "Gipsy",
                       "235, rue de l'Université, Québec, G1V 0A7, QC", util::Date (1, 5, 1980));

  uneCirconscription.inscrire (unElecteur);
  uneCirconscription.inscrire (unCandidat);

  // Utilisation de std::ostringstream pour construire la chaîne attendue
  std::ostringstream os;
  os << "Circonscription : Québec\n";
  os << "Depute sortant : \n" << unCandidat.reqPersonneFormate () << "\n\n";
  os << "Liste des inscrits :\n";
  os << unElecteur.reqPersonneFormate () << "\n";
  os << unCandidat.reqPersonneFormate () << "\n";

  ASSERT_EQ (uneCirconscription.reqCirconscriptionFormate (), os.str ());
}

TEST (Circonscription, OperateurAssignation)
{
  // Création d'un candidat sortant
  util::Date dateNaissance (12, 5, 1979); // Jour, Mois, Année
  Candidat deputeSortant ("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                          dateNaissance, 0);

  // Création de la circonscription source
  Circonscription circonscriptionSource ("Circonscription Source", deputeSortant);

  // Ajout de quelques inscrits
  Electeur electeur1 ("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (12, 5, 1980)); // Jour, Mois, Année
  Electeur electeur2 ("046 454 385", "Marie Antoinette", "Gipsy", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (12, 5, 1980)); // Jour, Mois, Année
  circonscriptionSource.inscrire (electeur1);
  circonscriptionSource.inscrire (electeur2);

  // Création d'une circonscription cible
  Circonscription circonscriptionCible ("Circonscription Vide", deputeSortant);

  // Opération d'assignation
  circonscriptionCible = circonscriptionSource;

  // Vérifications après assignation
  ASSERT_EQ (circonscriptionCible.reqNomCirconscription (), "Circonscription Source");
  ASSERT_EQ (circonscriptionCible.reqDeputeElu ().reqPersonneFormate (), deputeSortant.reqPersonneFormate ());
  ASSERT_EQ (circonscriptionCible.reqNombreInscrits (), 2);

  // Vérification des inscrits (indépendance et contenu)
  ASSERT_EQ (circonscriptionCible.reqInscrits ()[0]->reqPersonneFormate (),
             circonscriptionSource.reqInscrits ()[0]->reqPersonneFormate ());
  ASSERT_EQ (circonscriptionCible.reqInscrits ()[1]->reqPersonneFormate (),
             circonscriptionSource.reqInscrits ()[1]->reqPersonneFormate ());

  // Vérification que les objets sont des clones (adresses mémoire différentes)
  EXPECT_NE (circonscriptionCible.reqInscrits ()[0].get (),
             circonscriptionSource.reqInscrits ()[0].get ());
  EXPECT_NE (circonscriptionCible.reqInscrits ()[1].get (),
             circonscriptionSource.reqInscrits ()[1].get ());

  // Vérification de l'auto-assignation
  circonscriptionCible = circonscriptionCible; // Auto-assignation
  ASSERT_EQ (circonscriptionCible.reqNomCirconscription (), "Circonscription Source");
  ASSERT_EQ (circonscriptionCible.reqNombreInscrits (), 2);
}

/*
TEST(CirconscriptionTest, personneEstDejaPresente) {
     util::Date date_naissance(1, 1, 1999); // Date valide
    Candidat deputeSortant("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                           date_naissance, 0);

    // Création de la circonscription initiale
    Circonscription circonscriptionOriginale("Circonscription 1", deputeSortant);

    // Ajout de quelques inscrits
    Electeur electeur1("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date(1, 1, 1999));
    Electeur electeur2("046 454 385", "Marie Antoinette", "Gipsy", "235, rue de l'Université, Québec, G1V 0A7, QC",
                       util::Date(1, 1, 1999));
    
    circonscriptionOriginale.inscrire(electeur1);
    circonscriptionOriginale.inscrire(electeur2);


    EXPECT_TRUE(circonscriptionOriginale.personneEstDejaPresente("640 454 286"));
    
    EXPECT_TRUE(circonscriptionOriginale.personneEstDejaPresente("046 454 385"));
    
    EXPECT_FALSE(circonscriptionOriginale.personneEstDejaPresente("046 454 286"));
    
    
    
}*/


/**
 * \test Test de la méthode desinscrire()
 *      Cas valide: desinscrire une personne existante
 *      Cas invalide: aucun
 */

TEST (Circonscription, desinscrire)
{
  // Création d'un candidat sortant
  util::Date date_naissance (1, 1, 1999); // Date valide
  Candidat deputeSortant ("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                          date_naissance, 0);

  // Création de la circonscription initiale
  Circonscription circonscriptionOriginale ("Circonscription 1", deputeSortant);

  // Ajout de quelques inscrits
  Electeur electeur1 ("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));
  Electeur electeur2 ("046 454 385", "Marie Antoinette", "Gipsy", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));

  circonscriptionOriginale.inscrire (electeur1);
  circonscriptionOriginale.inscrire (electeur2);

  circonscriptionOriginale.desinscrire (electeur2.reqNas ());

  ASSERT_EQ(1, circonscriptionOriginale.reqNombreInscrits());
  


}

/**
 * \test Test de la méthode desinscrire()
 *      Cas valide: aucun
 *      Cas invalide: desinscrire une personne qui est absente,
 */

TEST (Circonscription, desinscrireUnePersonneAbsente)
{
  // Création d'un candidat sortant
  util::Date date_naissance (1, 1, 1999); // Date valide
  Candidat deputeSortant ("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                          date_naissance, 0);

  // Création de la circonscription initiale
  Circonscription circonscriptionOriginale ("Circonscription 1", deputeSortant);

  // Ajout de quelques inscrits
  Electeur electeur1 ("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));
  Electeur electeur2 ("046 454 385", "Marie Antoinette", "Gipsy", "235, rue de l'Université, Québec, G1V 0A7, QC",
                      util::Date (1, 1, 1999));

  circonscriptionOriginale.inscrire (electeur1);
  circonscriptionOriginale.inscrire (electeur2);

  
  ASSERT_THROW(circonscriptionOriginale.desinscrire ("046 454 286"), PersonneAbsenteException);


}