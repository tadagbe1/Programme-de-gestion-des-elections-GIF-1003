/**
 * \file Candidat.h
 * \brief Implémentation de la classe dérivée Personne
 * \author Tadagbé
 * \version 0.1
 * \date
 */


#include <string>
#include "Date.h"
#include <memory>
#include "Candidat.h"
#include "ContratException.h"
#include <iostream>
#include <sstream>

namespace elections
{

/**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Candidat à partir de valeurs passées en paramètres.
   * \param[in] p_nas est un string qui représente le nunéro d'assurance du candidat.
   * \param[in] p_prenom est un string qui représente le prénom du candidat.
   * \param[in] p_nom est un string qui représente le nom du candidat.
   * \param[in] p_adresse est un string qui représente l'adresse du candidat.
   * \param[in] p_dateNaissance est une date qui représente la date de naissance du candidat.
   * \param[in] p_partiPolitique est un entier qui représente le parti politique du candidat.
   * \pre p_partiPolitique est compris entre 0 et 4 inclusivement
   * \post m_partiPolitique prend la valeur de p_partiPolitique
   */

  Candidat::Candidat (const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
                      const std::string& p_adresse, const util::Date& p_date_naissance, int p_partiPolitique) :
  Personne (p_nas, p_prenom, p_nom, p_adresse, p_date_naissance), m_partiPolitique (p_partiPolitique)

  {
    PRECONDITION (p_partiPolitique <= 4 && p_partiPolitique >= 0);

    POSTCONDITION (m_partiPolitique == p_partiPolitique);

    INVARIANTS ();

  }

  /**
   * \brief Accesseur parti politique du candidat
   * \return le parti politique du candidat
   */

  int
  Candidat::reqPartiPolitique () const
  {
    return m_partiPolitique;
  }

  /**
   * \brief Affichage du nas, du prénom, du nom, de la date de naissance, de l'adresse et du parti politique du candidat.
   * \return une chaine de caractère composé du nas, du prénom, du nom, de la date de naissance de l'adresse et du parti politique du candidat.
   */

  std::string
  Candidat::reqPersonneFormate () const
  {
    std::ostringstream os;
    os << "Candidat" << std::endl;
    os << "----------------------------------------------" << std::endl;
    os << Personne::reqPersonneFormate ();
    std::string parti;
    if (m_partiPolitique == 0)
      parti = "BLOC_QUEBECOIS";
    else if (m_partiPolitique == 1)
      parti = "CONSERVATEUR";
    else if (m_partiPolitique == 2)
      parti = "INDEPENDANT";
    else if (m_partiPolitique == 3)
      parti = "LIBERAL";
    else
      parti = "NOUVEAU_PARTI_DEMOCRATIQUE";
    os << "Parti politique   : " << parti;

    return os.str ();
  }

  /**
   * \brief retourne le clone du candidat.
   *        methode virtuelle
   * \return le clone du candidat
   */

  std::unique_ptr<Personne>
  Candidat::clone () const
  {

    return std::unique_ptr <Personne> (new Candidat (*this));
  }

  /**
   * \brief Vérifier les invariants de la classe 
   */

  void
  Candidat::verifieInvariant () const
  {
    INVARIANT (m_partiPolitique >= 0 && m_partiPolitique <= 4);
  }

}
