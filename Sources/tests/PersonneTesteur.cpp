
#include <stdlib.h>
#include <gtest/gtest.h>
#include "Personne.h"
#include "Date.h"  
#include "ContratException.h"

using namespace elections;

/**
 * \class PersonneDeTest
 * \brief Classe de test permettant de tester la classe abstraite Personne
 */
class PersonneDeTest : public Personne {
public:
    PersonneDeTest(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
                 const std::string& p_adresse, const util::Date& p_dateNaissance)

                   : Personne(p_nas, p_prenom, p_nom, p_adresse, p_dateNaissance) {}

    virtual std::unique_ptr<Personne> clone() const 
    {
        return std::make_unique<PersonneDeTest>(*this);
    }

    virtual std::string reqPersonneFormate() const 
    {
        return Personne::reqPersonneFormate();
    }
};


TEST(Personne, Constructeur) {
  
    util:: Date date_naissance(1, 1, 1999); 
    PersonneDeTest unePersonne("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", date_naissance);

    ASSERT_EQ("046 454 237", unePersonne.reqNas());
    ASSERT_EQ("Jean", unePersonne.reqPrenom());
    ASSERT_EQ("Louis", unePersonne.reqNom());
    ASSERT_EQ("235, rue de l'Université, Québec, G1V 0A7, QC", unePersonne.reqAdresse());
    ASSERT_EQ(date_naissance, unePersonne.reqDateNaissance());
} // cas valide

TEST(Personne, ConstructeurNasInvalide) {
    util:: Date date_naissance(1, 1, 1999);
    ASSERT_THROW(PersonneDeTest unePersonne("046454237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", date_naissance), PreconditionException);
} // cas NAS  invalide


TEST(Personne, ConstructeurPrenomVide) {
    util:: Date date_naissance(1, 1, 1999);
    ASSERT_THROW(PersonneDeTest unePersonne("046 454 237", "", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", date_naissance), PreconditionException);
} // cas prénom  vide


TEST(Personne, ConstructeurNomVide) {
    util:: Date date_naissance(1, 1, 1999);
    ASSERT_THROW(PersonneDeTest unePersonne("046 454 237", "Jean", "", "235, rue de l'Université, Québec, G1V 0A7, QC", date_naissance), PreconditionException);
} // cas nom  vide


TEST(Personne, ConstructeurAdresseVide) {
    util:: Date date_naissance(1, 1, 1999);
    ASSERT_THROW(PersonneDeTest unePersonne("046 454 237", "Jean", "Louis", "", date_naissance), PreconditionException);
} // cas adresse  vide




/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class unePersonne : public ::testing::Test {
  
public:

    
unePersonne() : 
  f_personne("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", util::Date (1, 1, 1999)),
  f_personne1("046 454 237", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", util::Date (1, 1, 2000)){}

PersonneDeTest f_personne;
PersonneDeTest f_personne1;

};


/**
 * \test Test de la méthode reqNas()
 * Cas valide: vérifier le retour du nas 
 * Cas invalide: aucun
 */
TEST_F (unePersonne, reqNas)
{
  ASSERT_EQ ("046 454 237", f_personne.reqNas ());
}


/**
 * \test Test de la méthode reqNom()
 * Cas valide: vérifier le retour du nom 
 * Cas invalide: aucun
 */
TEST_F (unePersonne, reqNom)
{
  ASSERT_EQ ("Louis", f_personne.reqNom ());
}

/**
 * \test Test de la méthode reqPrenom()
 * Cas valide: vérifier le retour du prenom 
 * Cas invalide: aucun
 */

TEST_F(unePersonne, reqPrenom)
{
    ASSERT_EQ("Jean" , f_personne.reqPrenom());
}

/**
 * \test Test de la méthode reqAdresse()
 * Cas valide: vérifier le retour de l'adresse
 * Cas invalide: aucun
 */
TEST_F(unePersonne, reqAdresse)
{
    ASSERT_EQ("235, rue de l'Université, Québec, G1V 0A7, QC" , f_personne.reqAdresse());
}

 /**
 * \test Test de la méthode reqDateNaissance()
 * Cas valide: vérifier le retour de la date de naissance de la personne
 * Cas invalide: aucun
 */
TEST_F (unePersonne, reqDateNaissance)
{
  ASSERT_EQ (util::Date (1, 1, 1999), f_personne.reqDateNaissance ());
}

 /**
 * \test Test de la méthode std::string reqPersonneFormate();
 * Cas valide: vérifier le retour des informations sur l’objet Personne formaté
 * Cas invalide: aucun
 */

TEST_F(unePersonne, reqPersonneFormate)
{
    std::ostringstream os;
    
    os << "NAS         :  " << f_personne.reqNas()<<std::endl;
    os << "Prenom      :  " << f_personne.reqPrenom()<<std::endl;
    os << "Nom         :  " << f_personne.reqNom()<<std::endl;
    os << "Date de naissance : " << f_personne.reqDateNaissance().reqDateFormatee()<<std::endl;
    os << "Adresse     :  "  << f_personne.reqAdresse()<<std::endl;


        // Vérifier si la méthode reqPersonneFormate produit la chaîne attendue

  ASSERT_EQ(os.str(), f_personne.reqPersonneFormate());
}

// Test de l'opérateur d'égalité pour des objets identiques
TEST_F(unePersonne, PersonnesEgales) {
    ASSERT_TRUE(f_personne == f_personne); // Test avec le même objet pour vérifier l'égalité
}

// Test de l'opérateur d'égalité pour des objets différents
TEST_F(unePersonne, PersonnesPasEgales) {
    ASSERT_FALSE(f_personne == f_personne1); // Test avec des objets différents pour vérifier l'inégalité
}



// Test pour vérifier que l'adresse est modifiée correctement

TEST_F(unePersonne, asgAdresseValide)
{
    std::string nouvelleAdresse = "QC";
    f_personne.asgAdresse(nouvelleAdresse);
    ASSERT_EQ(f_personne.reqAdresse(), nouvelleAdresse); // Vérifie si l'adresse a bien été mise à jour
}

// Test pour vérifier qu'une exception est levée si l'adresse est vide
TEST_F(unePersonne, asgAdresseVide) {
    ASSERT_THROW(f_personne.asgAdresse(""), PreconditionException);  
    // Vérifie si une exception est levée pour une adresse vide
}
