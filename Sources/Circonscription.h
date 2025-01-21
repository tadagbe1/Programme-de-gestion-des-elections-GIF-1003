/**
 * \file Circonscription.h
 * \brief Classe Circonscription qui est composé des classes Electeur et Candidat
 * \author Tadagbé
 * \version 0.1
 * \date
 */

#ifndef CIRCONSCRIPTION_H
#define CIRCONSCRIPTION_H
#include <string>
#include "Date.h"
#include <memory>
#include "Personne.h"
#include "Electeur.h"
#include "Candidat.h"
#include <vector>
#include "PersonneException.h"
#include "PersonneAbsenteException.h"
#include "PersonneDejaPresenteException.h"

namespace elections
{

  class Circonscription
  {
  public:
    Circonscription (const std::string& p_nomCirconscription, const Candidat& p_deputeElu);
    Circonscription (const Circonscription & p_circonscription);

    ~Circonscription () { };
    const Candidat& reqDeputeElu () const;
    const std::vector<std::unique_ptr<Personne>>&reqInscrits () const;
    const std::string& reqNomCirconscription () const;
    int reqNombreInscrits () const;
    std::string reqCirconscriptionFormate () const;
    void inscrire (const Personne& p_nouvelInscrit);
    Circonscription & operator= (const Circonscription & p_circonscription);
    void desinscrire(const std::string& p_nas);
  private:
    Candidat m_deputeElu;
    std::string m_nomCirconscription;

    bool personneEstDejaPresente(const std::string& p_nas) const;
    std::vector<std::unique_ptr<Personne>> m_inscrits;
    void verifieInvariant () const;

  };
}
#endif /* CIRCONSCRIPTION_H */

