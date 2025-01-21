#include "Circonscription.h"
#include "ContratException.h"
#include <sstream>
#include <algorithm>
//#include "PersonneException.h"
namespace elections
{

  /**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Circonscription à partir de valeurs passées en paramètres.
   * \param[in] p_nas est un string qui représente le nunéro d'assurance de la personne.
   * \param[in] p_nomCirconscription est un string qui représente le prénom de la personne.
   * \param[in] p_deputeElu est un string qui représente le nom de la personne.
   * \pre p_nomCirconscription non vide
   * \post m_nomCirconscription prend la valeur de p_nomCirconscription
   * \post m_deputeElu prend la valeur de p_deputeElu
   * \post m_inscrits est vide
   */

  Circonscription::Circonscription (const std::string& p_nomCirconscription, const Candidat& p_deputeElu) : m_nomCirconscription (p_nomCirconscription),
  m_deputeElu (p_deputeElu)
  {



    PRECONDITION (!p_nomCirconscription.empty ());

    POSTCONDITION (m_nomCirconscription == p_nomCirconscription);
    POSTCONDITION (m_deputeElu == p_deputeElu);
    POSTCONDITION (m_deputeElu.reqPartiPolitique () == p_deputeElu.reqPartiPolitique ());
    POSTCONDITION (m_inscrits.empty ());
    INVARIANTS ();

  }

  /**
   * \brief Constructeur copie.
   *        Création d'un objet Circonscription à partir d'un autre objet copie passé en paramètre.
   * \param[in] p_circonscription est un objet Circonscription.
   * \post m_nomCirconscription prend la valeur de p_circonscription.m_nomCirconscription
   * \post m_deputeElu prend la valeur de p_circonscription.p_deputeElu
   * \post m_incrits  contient les memes personnes que p_circonscription.m_incscrits mais à des adresses différentes
   */

  Circonscription::Circonscription (const Circonscription & p_circonscription) :
  m_nomCirconscription (p_circonscription.m_nomCirconscription),
  m_deputeElu (p_circonscription.m_deputeElu)
  {
    for (const auto & element : p_circonscription.m_inscrits)
      {
        m_inscrits.push_back (element -> clone ());

      }

    POSTCONDITION (m_deputeElu == p_circonscription.m_deputeElu);

    POSTCONDITION (m_nomCirconscription == p_circonscription.m_nomCirconscription);

    POSTCONDITION (m_inscrits.size () == p_circonscription.m_inscrits.size ());

    for (size_t i = 0; i < m_inscrits.size (); ++i)
      {
        POSTCONDITION (m_inscrits[i]->reqPersonneFormate () == p_circonscription.m_inscrits[i]->reqPersonneFormate ());
        POSTCONDITION (m_inscrits[i].get () != p_circonscription.m_inscrits[i].get ());
      }

    INVARIANTS ();

  }

  /**
   * \fn Circonscription::operator = (const Circonscription & p_circonscription)
   * \brief Surcharge de l'opérateur =
   * \param[in] p_circonscription L'autre circonscription de l'opération
   * \return Le résultat
   * \post m_nomCirconscription prend la valeur de p_circonscription.m_nomCirconscription
   * \post m_deputeElu prend la valeur de p_circonscription.p_deputeElu
   * \post m_incrits  contient les memes personnes que p_circonscription.m_incscrits mais à des adresses différentes
   */

  Circonscription & Circonscription::operator= (const Circonscription & p_circonscription)
  {

    if (!(this == &p_circonscription))
      {
        m_deputeElu = p_circonscription.m_deputeElu;
        m_nomCirconscription = p_circonscription.m_nomCirconscription;
        m_inscrits.clear ();
        for (const auto & element : p_circonscription.m_inscrits)
          {
            m_inscrits.push_back (element -> clone ());

          }

        POSTCONDITION (m_deputeElu == p_circonscription.m_deputeElu);
        POSTCONDITION (m_deputeElu.reqPartiPolitique () == p_circonscription.m_deputeElu.reqPartiPolitique ());

        POSTCONDITION (m_nomCirconscription == p_circonscription.m_nomCirconscription);

        POSTCONDITION (m_inscrits.size () == p_circonscription.m_inscrits.size ());

        for (size_t i = 0; i < m_inscrits.size (); ++i)
          {
            POSTCONDITION (m_inscrits[i]->reqPersonneFormate () == p_circonscription.m_inscrits[i]->reqPersonneFormate ());
            POSTCONDITION (m_inscrits[i].get () != p_circonscription.m_inscrits[i].get ());
          }

        INVARIANTS ();


      }
    return *this;
  }

  /**
   * \brief Accesseur du député sortant de la circonscription
   * \return le député sortant de la circonscription
   */

  const Candidat&
  Circonscription::reqDeputeElu () const
  {
    return m_deputeElu;
  }

  /**
   * \brief Accesseur du nom de la circonscription
   * \return le nom de la circonscription
   */

  const std::string&
  Circonscription::reqNomCirconscription () const
  {
    return m_nomCirconscription;
  }

  /**
   * \brief modifie l'attribut m_inscrits de la circonscription
   * \param[in] p_nouvelInscrit adresse de l'électeur qu'on veut inscrire a la circonscription
   * \post l'électeur a bien été rajouté a m_inscrits
   */

  void
  Circonscription::inscrire (const Personne& p_nouvelInscrit)
  {

    std::string nas = p_nouvelInscrit.reqNas ();

    if (!personneEstDejaPresente (nas))
      {


        int m = reqNombreInscrits ();

        m_inscrits.push_back (p_nouvelInscrit.clone ());

        POSTCONDITION (reqNombreInscrits () == m + 1);
        POSTCONDITION (m_inscrits[m]->reqPersonneFormate () == p_nouvelInscrit.reqPersonneFormate ());
      }
    else{
        throw PersonneDejaPresenteException(p_nouvelInscrit.reqPersonneFormate());

      }
    

    INVARIANTS ();
  }

  /**
   * \brief Accesseur des électeurs de la circonscription
   * \return les électeurs de la circonscription
   */

  const std::vector<std::unique_ptr<Personne>>&
  Circonscription::reqInscrits () const
  {
    return m_inscrits;
  }

  /**
   * \brief Accesseur du nombre d'électeur inscrit à la circonscription
   * \return le nombre d'électeur inscrit à la circonscription
   */

  int
  Circonscription::reqNombreInscrits () const
  {
    return m_inscrits.size ();
  }

  /**
   * \brief Vérifier les invariants de la classe 
   */

  void
  Circonscription::verifieInvariant () const
  {
    INVARIANT (!m_nomCirconscription.empty ());
  }

  /**
   * \brief Affichage le nom de la circonscription, le candidat sortant et les électeurs.
   * \return une chaine de caractère composé du nom de la circonscription, du candidat sortant et des électeurs
   */

  std::string
  Circonscription::reqCirconscriptionFormate () const
  {
    std::ostringstream os;
    os << "Circonscription : " << reqNomCirconscription () << std::endl;
    os << "Depute sortant : " << std::endl;
    os << reqDeputeElu ().reqPersonneFormate () << std::endl;
    os << "\n";
    os << "Liste des inscrits :" << std::endl;
    for (size_t i = 0; i < reqNombreInscrits (); i++)
      {
        os << reqInscrits ()[i] -> reqPersonneFormate () << std::endl;
      }
    return os.str ();
  }

  bool
  Circonscription::personneEstDejaPresente (const std::string& p_nas) const
  {
    std::vector<std::unique_ptr < Personne>>::const_iterator iter;

    for (iter = m_inscrits.begin (); iter != m_inscrits.end (); ++iter)
      {

        if ((*iter)->reqNas () == p_nas)
          {
            return true;
          }
      }

    return false;


  }

  void
  Circonscription::desinscrire (const std::string& p_nas)
  {
    
    PRECONDITION (util::validerNas (p_nas));

    std::vector<std::unique_ptr < Personne>>::const_iterator iter;

    if (personneEstDejaPresente (p_nas))
      {
        int m = reqNombreInscrits ();
        for (iter = m_inscrits.begin (); iter != m_inscrits.end (); ++iter)
          {

            if ((*iter)->reqNas () == p_nas)
              {
                break;
              }
          }
        
        m_inscrits.erase (iter);
        
        POSTCONDITION (reqNombreInscrits () == m  - 1);
        
        INVARIANTS ();
      }

    else{
        throw PersonneAbsenteException("Cette personne est absente de la circonsription");
    }
}
}


