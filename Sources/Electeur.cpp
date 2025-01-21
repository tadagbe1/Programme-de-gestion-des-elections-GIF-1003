#include <string>
#include "Date.h"
#include <memory>
#include "Electeur.h"
#include "ContratException.h"
#include <iostream>
#include <sstream>

namespace elections
{

/**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Electeur à partir de valeurs passées en paramètres.
   * \param[in] p_nas est un string qui représente le nunéro d'assurance de l'électeur.
   * \param[in] p_prenom est un string qui représente le prénom de l'électeur.
   * \param[in] p_nom est un string qui représente le nom de l'électeur.
   * \param[in] p_adresse est un string qui représente l'adresse de l'électeur.
   * \param[in] p_dateNaissance est une date qui représente la date de naissance de l'électeur.
   */

  Electeur::Electeur (const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom, const std::string& p_adresse, const util::Date& p_date_naissance) :
  Personne (p_nas, p_prenom, p_nom, p_adresse, p_date_naissance)
 {
 }

  /**
   * \brief Affichage du nas, du prénom, du nom, de la date de naissance et de l'adresse de l'électeur.
   * \return une chaine de caractère composé du nas, du prénom, du nom, de la date de naissance et de l'adresse de l'électeur.
   */

  std::string
  Electeur::reqPersonneFormate () const
  {
    std::ostringstream os;
    os << "Electeur" << std::endl;
    os << "----------------------------------------------" << std::endl;
    os << Personne::reqPersonneFormate ();
    return os.str ();
  }

  /**
   * \brief retourne le clone de l'électeur.
   *        methode virtuelle
   * \return le clone de l'électeur
   */

  std::unique_ptr<Personne>
  Electeur::clone () const
  {
    return std::make_unique < Electeur > (*this);
  }
}

