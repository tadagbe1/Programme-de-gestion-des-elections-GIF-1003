/**
 * \file Candidat.h
 * \brief Classe Candidat, dérivée de la classe Personne.
 * \author Tadagbé
 * \version 0.1
 * \date
 */


#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <string>
#include "Date.h"
#include <memory>
#include "Personne.h"

namespace elections
{

  class Candidat : public Personne
  {
  public:
    Candidat (const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
              const std::string& p_adresse, const util::Date& p_date_naissance, int p_partiPolitique);
    int reqPartiPolitique () const;
    virtual std::string reqPersonneFormate () const;
    virtual std::unique_ptr<Personne>
    clone () const;

    enum PartisPolitiques
    {
      BLOC_QUEBECOIS,
      CONSERVATEUR,
      INDEPENDANT,
      LIBERAL,
      NOUVEAU_PARTI_DEMOCRATIQUE
    };
  private:
    int m_partiPolitique;
    void verifieInvariant () const;

  };
}

#endif /* CANDIDAT_H */

