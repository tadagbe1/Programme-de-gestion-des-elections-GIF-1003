/**
 * \file Personne.h
 * \brief Implémentation de la classe de base abstraite Personne
 * \author Tadagbé
 * \version 0.1
 * \date
 */

#include "Personne.h"
#include <iostream>
#include <sstream>
#include <string>
#include "ContratException.h"
#include "Date.h"



namespace elections
{

  /**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Personne à partir de valeurs passées en paramètres.
   * \param[in] p_nas est un string qui représente le nunéro d'assurance de la personne.
   * \param[in] p_prenom est un string qui représente le prénom de la personne.
   * \param[in] p_nom est un string qui représente le nom de la personne.
   * \param[in] p_adresse est un string qui représente l'adresse de la personne.
   * \param[in] p_dateNaissance est une date qui représente la date de naissance de la personne.
   * \pre p_nas est un numéro d'assurance valide
   * \pre p_prenom non vide
   * \pre p_nom non vide
   * \pre p_adresse non vide
   * \pre p_date_naissance est une date de naissance valide dont l'année est comprise entre 1960 et 2037
   * \post m_nas prend la valeur de p_nas
   * \post m_prenom prend la valeur de p_prenom
   * \post m_nom prend la valeur de p_nom
   * \post m_adresse prend la valeur de p_adresse
   * \post m_date_naissance prend la valeur de p_date)naissance
   */

  Personne::Personne (const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom, const std::string& p_adresse, const util::Date& p_date_naissance) :
  m_nas (p_nas), m_nom (p_nom), m_prenom (p_prenom), m_adresse (p_adresse), m_date_naissance (p_date_naissance)
  {
    PRECONDITION (util::validerNas (p_nas));
    PRECONDITION (!p_nom.empty ());
    PRECONDITION (!p_prenom.empty ());
    PRECONDITION (!p_adresse.empty ());


    POSTCONDITION (m_nas == p_nas);
    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_prenom == p_prenom);
    POSTCONDITION (m_adresse == p_adresse);
    POSTCONDITION (m_date_naissance == p_date_naissance);

    INVARIANTS ();

  }

    /**
   * \brief Accesseur nas de la personne
   * \return le nas
   */

  const std::string&
  Personne::reqNas () const
  {
    return m_nas;
  }

    /**
   * \brief Accesseur nom de la personne
   * \return le nom
   */

  const std::string&
  Personne::reqNom () const
  {
    return m_nom;
  }

    /**
   * \brief Accesseur prénom de la personne
   * \return le prénom
   */

  const std::string&
  Personne::reqPrenom () const
  {
    return m_prenom;
  }

  /**
   * \brief Accesseur adresse de la personne
   * \return l'adresse
   */

  const std::string&
  Personne::reqAdresse () const
  {
    return m_adresse;
  }

    /**
   * \brief Accesseur date de naissance de la personne
   * \return la date de naissance
   */

  const util::Date&
  Personne::reqDateNaissance () const
  {
    return m_date_naissance;
  }

    /**
   * \brief Change l'adresse de la personne
   * \param[in] p_adresse nouvelle adresse de la personne
   * \pre p_adresse non vide
   * \post m_adresse prend la valeur de p_adresse
   */

  void
  Personne::asgAdresse (const std::string& p_adresse)
  {
    PRECONDITION (!p_adresse.empty ());
    m_adresse = p_adresse;
    POSTCONDITION (m_adresse == p_adresse);
    INVARIANTS ();
  }

  /**
   * \fn Personne::operator== (const Personne& p_personne)
   * \brief Surcharge de l'opérateur ==
   * \param[in] p_personne L'autre personne de l'opération
   * \return Le résultat
   */

  bool Personne::operator== (const Personne& p_personne) const
  {
    bool estEgal = true;
    estEgal = estEgal && ((this-> m_nas) == p_personne.m_nas);
    estEgal = estEgal && ((this-> m_nom) == p_personne.m_nom);
    estEgal = estEgal && ((this-> m_prenom) == p_personne.m_prenom);
    estEgal = estEgal && ((this-> m_adresse) == p_personne.m_adresse);
    estEgal = estEgal && ((this-> m_date_naissance) == p_personne.m_date_naissance);

    return estEgal;
  }

    /**
   * \brief Affichage du nas, du prénom, du nom, de la date de naissance et de l'adresse de la personne.
   * \return une chaine de caractère composé du nas, du prénom, du nom, de la date de naissance et de l'adresse de la personne.
   */

  std::string
  Personne::reqPersonneFormate () const
  {
    std::ostringstream os;
    os << "NAS         :  " << reqNas () << std::endl;
    os << "Prenom      :  " << reqPrenom () << std::endl;
    os << "Nom         :  " << reqNom () << std::endl;
    os << "Date de naissance : " << reqDateNaissance ().reqDateFormatee () << std::endl;
    os << "Adresse     :  " << reqAdresse () << std::endl;

    return os.str ();
  }

    /**
   * \brief Vérifier les invariants de la classe 
   */

  void
  Personne::verifieInvariant () const
  {

    INVARIANT (util::validerNas (m_nas));
    INVARIANT (!m_nom.empty ());
    INVARIANT (!m_prenom.empty ());
    INVARIANT (!m_adresse.empty ());


  }

}



