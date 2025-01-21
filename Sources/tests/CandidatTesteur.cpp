#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <memory>
#include "Candidat.h"
#include "Date.h"
#include "ContratException.h"

using namespace elections;




/**
 * \brief Test du constructeur
 * Cas valides: Création d'un objet Candidat et vérification de l'assignation de tous les attributs
 *    
 */
TEST(Candidat,ConstructeurDefaut)
{
 Candidat unCandidat ("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                   util::Date(1, 1, 1999),0);
        
 ASSERT_EQ(unCandidat.reqPartiPolitique(), 0);
	
       
}

TEST(Candidat,ConstructeurPartieInvalide)
{
  
	
 ASSERT_THROW (
   Candidat unCandidat ("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                   util::Date(1, 1, 1999), 6) , PreconditionException);
         
} // Cas invalide : Tentative de création d'un candidat avec un parti politique invalide







/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class CandidatTest : public ::testing::Test {
public:
    CandidatTest()
        : candidat("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC",
                   util::Date(12, 5, 1979),0) {}

    Candidat candidat;
};

/**
 * \test Test de l'accesseur reqPartiPolitique()
 */
TEST_F(CandidatTest, reqPartiPolitique) {
    ASSERT_EQ(0, candidat.reqPartiPolitique());
}

/**
 * \test Test de la méthode reqPersonneFormate() pour vérifier le formatage correct des informations
 */

TEST_F(CandidatTest, reqPersonneFormate) {
    // Formater la chaîne attendue en utilisant les méthodes d'accès
    std::ostringstream os;
    os << "Candidat"<<std::endl;
    os << "----------------------------------------------"<<std::endl;
    os << "NAS         :  " << candidat.reqNas()<<std::endl;
    os << "Prenom      :  " << candidat.reqPrenom()<<std::endl;
    os << "Nom         :  " << candidat.reqNom()<<std::endl;
    os << "Date de naissance : " << candidat.reqDateNaissance().reqDateFormatee()<<std::endl;
    os << "Adresse     :  "  << candidat.reqAdresse()<<std::endl;
    os << "Parti politique   : " << "BLOC_QUEBECOIS";

    // Vérifier si la méthode reqPersonneFormate produit la chaîne attendue
    ASSERT_EQ(os.str(), candidat.reqPersonneFormate());
}
    /**
 * \test Test de la méthode clone() pour vérifier la création d'une copie
 */
TEST_F(CandidatTest, clone) {
    std::unique_ptr<Personne> candidat1 = candidat.clone();
    ASSERT_EQ(candidat.reqNas(), candidat1->reqNas());
    ASSERT_EQ(candidat.reqPrenom(), candidat1->reqPrenom());
    ASSERT_EQ(candidat.reqNom(), candidat1->reqNom());
    ASSERT_EQ(candidat.reqDateNaissance(), candidat1->reqDateNaissance());
    ASSERT_EQ(candidat.reqAdresse(), candidat1->reqAdresse());
}



