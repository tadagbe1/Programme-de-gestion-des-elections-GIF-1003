/**
 * \file Date.h
 * \brief Fichier qui contient l'interface de la classe Date qui sert au maintien et à la manipulation des dates.
 * \author Yves Roy Version initiale, THE
 * \version 2.2
 */
#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <fstream>
namespace util
{   
    bool validerNas(const std::string& p_nas);
    bool validerFormatFichier(std::istream& p_is);
    bool validerDate(const std::string date);
    bool validerElecteur(const std::string& nas, const std::string& prenom, const std::string& nom, const std::string& date,const std::string& adresse );
    bool validerParti(const std::string& parti);
    void getInfoElecteur(std::istream& p_is, std::string& nas, std::string& prenom, std::string& nom,  std::string& date, std::string& adresse);
    void decomposerNombre(int n, int& unite, int& dizaine, int& centaine);
    int convertirUnChiffre(int produit);
    bool validerNasPreliminaire(const std::string& p_nas);


  /**
   * \class Date
   * \brief Cette classe sert au maintien et à la manipulation des dates.
   *
   *             La classe maintient dans un état cohérent ces renseignements.
   *             Elle valide ce qu'on veut lui assigner.
   *              <p>
   *              Cette classe peut aussi servir à prendre la date courante du
   *              système et à faire des calculs avec des dates.
   *              <p>
   *              La classe n'accepte que des dates valides, c'est la
   *              responsabilité de l'utilisateur de la classe de s'en assurer.
   *              <p>
   *  Attributs:   time_t m_temps   Nombre de secondes écoulé depuis le premier janvier 1970 <p>
   * 				time_t m_temps pour long m_temps
   * \invariant m_temps >= 1er janvier 1970 et >= au 31 décembre 2037
   * \invariant La validité peut être vérifiée avec la méthode statique
   *              bool Date::verifierDate(jour, mois, annee).
   */
  class Date
  {
  public:
    Date ();
    Date (long p_jour, long p_mois, long p_annee);

    void asgDate (long p_jour, long p_mois, long p_annee);
    bool ajouteNbJour (long p_nbjour);

    long reqJour () const;
    long reqMois () const;
    long reqAnnee () const;

    long reqJourAnnee () const;
    std::string reqDateFormatee () const;

    bool operator== (const Date& p_date) const;
    bool operator< (const Date& p_date) const;
    int operator- (const Date& p_date) const;

    static bool estBissextile (long p_annee);
    static bool validerDate (long p_jour, long p_mois, long p_annee);

    friend std::ostream& operator<< (std::ostream& p_os, const Date& p_date);

  private:
    std::string reqNomJourSemaine () const;
    std::string reqNomMois () const;
    void verifieInvariant () const;
    time_t m_temps;
  };

} // namespace util

#endif /* DATE_H_ */

