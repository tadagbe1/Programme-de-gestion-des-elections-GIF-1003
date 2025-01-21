/**
 * \file Personne.h
 * \brief Classe de base abstraite Personne
 * \author Tadagbé
 * \version 0.1
 * \date
 */

#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>
#include "Date.h"
#include <memory>
#include "Personne.h"

namespace elections
{

  class Personne
  {
  public:
    Personne (const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom, const std::string& p_adresse, const util::Date& p_date_naissance);
    const std::string& reqNas () const;
    const std::string& reqNom () const;
    const std::string& reqPrenom () const;
    const std::string& reqAdresse () const;
    const util::Date& reqDateNaissance () const;
    virtual std::string reqPersonneFormate () const;
    void asgAdresse (const std::string& p_adresse);
    bool operator== (const Personne& p_personne) const;

    virtual
    ~Personne () { };
    virtual std::unique_ptr<Personne> clone () const = 0; // virtuelle pure


  private:
    std::string m_nas;
    std::string m_nom;
    std::string m_prenom;
    std::string m_adresse;
    util::Date m_date_naissance;
    void verifieInvariant () const;


  };
}

#endif /* PERSONNE_H */

