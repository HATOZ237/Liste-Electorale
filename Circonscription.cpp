//
// Created by Duroy on 04/01/2021.
//

#include "Circonscription.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <sstream>
#include "PersonneException.h"

namespace elections {

    /**
     * @brief
     * @param mNomCirconscription
     * @param mDeputeElu
     */
    Circonscription::Circonscription(const std::string &mNomCirconscription, const Candidat &mDeputeElu)
            : m_nomCirconscription(mNomCirconscription), m_deputeElu(mDeputeElu) {
        PRECONDITION(util::validerFormatNom(mNomCirconscription));
    }

    /**
     * @brief
     * @return
     */
    const std::string &Circonscription::getMNomCirconscription() const {
        return m_nomCirconscription;
    }

    /**
     * @brief
     * @return
     */
    const Candidat &Circonscription::getMDeputeElu() const {
        return m_deputeElu;
    }

    /**
     * @brief
     * @return
     */
    std::string Circonscription::reqCirconscriptionFormate() {
        std::ostringstream os, os1;
        os << "Circonscription : " << m_nomCirconscription << std::endl
           << "Depute sortant : " << std::endl
           << m_deputeElu.reqPersonneFormate()
           //<< " \n"
           << "Liste des inscrits : " << std::endl;
        //<< std::endl;
        for (const auto personne: m_vInscrits) {
            os << personne->reqPersonneFormate()
               << std::endl;
        }
        return os.str();
    }

    /**
     * @brief
     * @param nouvel_inscrit
     */
    void Circonscription::inscrire(const Personne &
    nouvel_inscrit) {
        if (!estDejaPresent(nouvel_inscrit)) {
            m_vInscrits.push_back(nouvel_inscrit.clone());
        } else {
            throw PersonneException(nouvel_inscrit.reqPersonneFormate());
        }

    }

    /**
     * @brief
     * @param p_vInscrits
     * @param nouvel_personne
     * @return
     */
    bool Circonscription::estDejaPresent(const Personne &nouvel_personne) {
        bool test = false;
        for (const auto personne:m_vInscrits) {
            if (*personne == nouvel_personne) {
                test = true;
                break;
            }
        }
        return test;
    }

    /**
     * @brief
     */
    Circonscription::~Circonscription() {
        for (const auto personne:m_vInscrits) {
            delete personne;
        }
        m_vInscrits.clear();
    }

    /**
     * @brief
     * @param rhs
     * @return
     */
    Circonscription &Circonscription::operator=(const Circonscription &rhs) {
        if (this != &rhs) {
            m_nomCirconscription = rhs.getMNomCirconscription();
            m_deputeElu = rhs.m_deputeElu;
            for (const auto personne: m_vInscrits) {
                delete personne;
            }
            m_vInscrits.clear();
            for (auto iter = m_vInscrits.begin(); iter != m_vInscrits.end(); iter++) {
                inscrire(*(*iter));
            }
            //delete rhs;
            POSTCONDITION(m_nomCirconscription == rhs.getMNomCirconscription());
        }
        return *this;
    }

    /**
     * @brief
     * @param circonscription
     */
    Circonscription::Circonscription(const Circonscription &circonscription) : m_nomCirconscription(
            circonscription.getMNomCirconscription()),
                                                                               m_deputeElu(
                                                                                       circonscription.getMDeputeElu()) {
        PRECONDITION(m_vInscrits.empty());
        for (const auto personne:circonscription.m_vInscrits) {
            inscrire(*personne);
        }
    }

    /**
     * @brief
     * @return
     */
    size_t Circonscription::nbreInscrits() {
        return m_vInscrits.size();
    }

    /**
     * @brief
     * @param Nas
     */
    void Circonscription::desinscrire(const std::string &Nas) {

    }

    /*bool Circonscription::operator==(const Circonscription &rhs) const {
        return m_nomCirconscription == rhs.m_nomCirconscription &&
               m_deputeElu == rhs.getMDeputeElu() &&
               m_vInscrits == rhs.m_vInscrits;
    }

    bool Circonscription::operator!=(const Circonscription &rhs) const {
        return !(rhs == *this);
    }*/
}