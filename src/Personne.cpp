/**
 * \file Personne.cpp
 * \brief Implementation de la classe Personne
 *  Created on: 2020-02-21
 *  Author: etudiant
 * Fonction permettant de creer des joueurs pour une equipe de hockey
 */

#include "Personne.h"
#include "ContratException.h"
#include "validationFormat.h"
#include <sstream>
#include <string>


/**
 * \namespace hockey
 */
namespace elections {
/**
 * \brief Constructeur avec parametres
 * \param[in] p_nom pour le non de la personne
 * \param[in] p_prenom pour le prenom de la personne
 * \param[in] p_date pour sa date de naissance
 * \param[in] p_telephone pour son numero de telephone
 * Author: etudiant
 */

    Personne::Personne(const std::string p_NAS, const std::string p_nom, const std::string p_prenom, util::Date p_date,
                       util::Adresse adresse) : m_nom(p_nom), m_NAS(p_NAS),
                                                m_prenom(p_prenom), m_dateNaissance(p_date),
                                                m_adresse(adresse) {
        // TODO Auto-generated constructor stub
        PRECONDITION(util::validerFormatNom(p_nom));
        PRECONDITION(util::validerFormatNom(p_prenom));
        //PRECONDITION(util::validerTelephone(p_telephone));
        PRECONDITION(util::validerNAS(p_NAS));

        POSTCONDITION(p_nom == m_nom);
        POSTCONDITION(p_prenom == m_prenom);
        //POSTCONDITION(p_telephone == m_telephone);
        POSTCONDITION(p_date == m_dateNaissance);
        POSTCONDITION(p_NAS == m_NAS);


    }

/**
 * \fn std::string Personne::reqNom() const
 * \brief accesseur pour le nom
 * \return m_nom le nom de la personne
 */
    const std::string &Personne::reqNom() const {
        return m_nom;
    }

/**
 * \fn const std::string Personne::reqPrenom() const
 * \brief accesseur pour le prenom
 * \return m_prenom le prenom de la personne
 */
    const std::string &Personne::reqPrenom() const {
        return m_prenom;
    }

/**
 * \fn bool Personne::operator ==(const Personne& personne)
 * \brief surcharge de l'operateur de comparaision
 * \param[in] personne un objet de la classe personne
 * \return true si la personne entree en parametre possede les memes attributs aue l'objet courant
 */
    bool Personne::operator==(const Personne &personne) const {
        return ((m_nom == personne.m_nom) && (m_prenom == personne.m_prenom) &&
                (m_dateNaissance == personne.m_dateNaissance));
    }

/**
 * \fn std::string Personne::reqPersonneFormate() const
 * \brief cette fonction affiche les parametres de l'objet personne
 * \return les parametres formatees d'un objet personne
 */
    std::string Personne::reqPersonneFormate() const {
        std::ostringstream os;
        os << "NAS               : " << m_NAS << std::endl
           << "Nom               : " << m_nom << std::endl
           << "Prenom            : " << m_prenom << std::endl
           << "Date de naissance : " << m_dateNaissance.reqDateFormatee() << std::endl
           << "Adresse           : " << m_adresse << std::endl;

        return os.str();
    }

/**
 * \fn util::Date Personne::reqDateNaissance() const
 * \brief accesseur sur la date de l'objet personne
 * \return m_dateNaissance
 */
    util::Date Personne::reqDateNaissance() const {
        return m_dateNaissance;
    }

/**
 * \fn void Personne::verifieInvariant() const
 * \brief methode permettant a la classe de garder sa coherence(contrat sur les attributs) durant toute son utilisation
 */
    void Personne::verifieInvariant() const {
        INVARIANT(util::validerFormatNom(m_prenom));
        INVARIANT(util::validerFormatNom(m_nom));
        //INVARIANT(util::validerTelephone(m_telephone));
    }

    const util::Adresse &Personne::getMAdresse() const {
        return m_adresse;
    }

    void Personne::asgMAdresse(const util::Adresse &mAdresse) {
        m_adresse = mAdresse;
    }
}


