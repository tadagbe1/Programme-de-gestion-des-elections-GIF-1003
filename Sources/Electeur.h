/**
 * \file Electeur.h
 * \brief Classe Electeur, dérivée de la classe Personne.
 * \author Tadagbé
 * \version 0.1
 * \date
 */

#ifndef ELECTEUR_H
#define ELECTEUR_H

#include <string>
#include "Date.h"
#include <memory>
#include "Personne.h"

namespace elections
{

  class Electeur : public Personne
  {
  public:
    Electeur (const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
              const std::string& p_adresse, const util::Date& p_date_naissance);
    virtual std::string reqPersonneFormate () const;
    virtual std::unique_ptr<Personne> clone () const;
  private:


  };
}

#endif /* ELECTEUR_H */

