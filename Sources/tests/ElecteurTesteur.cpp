#include <gtest/gtest.h>
#include <sstream>
#include "Electeur.h"
#include "Date.h"
#include "ContratException.h"

using namespace elections;



class ElecteurTest : public ::testing::Test {
public:
    Electeur electeur;

    // Constructeur pour initialiser un électeur avec des valeurs par défaut pour les tests
    ElecteurTest()
        : electeur("046 454 237", "joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC", util::Date(1, 1, 1980)) {}
};

/**
 * \test Test de la méthode reqPersonneFormate() pour vérifier le formatage correct des informations
 */
TEST_F(ElecteurTest, reqPersonneFormate) {
    // Formater la chaîne attendue en utilisant les méthodes d'accès
    std::ostringstream os;
    os << "Electeur\n";
    os << "----------------------------------------------\n";
    os << "NAS         :  " << electeur.reqNas()<<std::endl;
    os << "Prenom      :  " << electeur.reqPrenom()<<std::endl;
    os << "Nom         :  " << electeur.reqNom()<<std::endl;
    os << "Date de naissance : " << electeur.reqDateNaissance().reqDateFormatee()<<std::endl;
    os << "Adresse     :  "  << electeur.reqAdresse()<<std::endl;

    // Vérifier si la méthode reqPersonneFormate produit la chaîne attendue
    ASSERT_EQ(os.str(), electeur.reqPersonneFormate());
}

/**
 * \test Test de la méthode clone() pour vérifier la création d'une copie
 */
TEST_F(ElecteurTest, clone) {
    // Test du clonage de l'objet Electeur
    std::unique_ptr<Personne> electeurClone = electeur.clone();
    ASSERT_EQ(electeurClone->reqPersonneFormate(), electeur.reqPersonneFormate());
}