//
// Created by Duroy on 01/01/2021.
//

#include <sstream>
#include <iostream>
#include "Candidat.h"

namespace elections {
    /**
     * @brief
     * @return
     */
    int Candidat::getMPartiPolitique() const {
        return m_partiPolitique;
    }

    /**
     * @brief
     * @return
     */
    std::string Candidat::reqPersonneFormate() const {
        std::ostringstream os;
        os << "Candidat" << std::endl
           << "--------------------------------------" << std::endl
           << Personne::reqPersonneFormate()
           << "Parti politique   : " << parti(m_partiPolitique) << "\n";
        return os.str();
    }

    /**
     * @brief
     * @return
     */
    Personne *Candidat::clone() const {
        return new Candidat(*this);
    }

    /**
     * @brief
     * @param pNas
     * @param pNom
     * @param pPrenom
     * @param date
     * @param adresse
     * @param mPartiPolitique
     */
    Candidat::Candidat(const std::string &pNas, const std::string &pNom, const std::string &pPrenom,
                       const util::Date &date, const util::Adresse &adresse, int mPartiPolitique) : Personne(pNas, pNom,
                                                                                                             pPrenom,
                                                                                                             date,
                                                                                                             adresse),
                                                                                                    m_partiPolitique(
                                                                                                            mPartiPolitique) {
        PRECONDITION(mPartiPolitique >= 0 and mPartiPolitique < 5);
    }

    /**
     * @brief
     * @param partiPolitique
     * @return
     */
    std::string Candidat::parti(int partiPolitique) {
        std::string parti_politique;
        switch (partiPolitique) {
            case 0:
                parti_politique = "Bloc quebecois\n";
                break;
            case 1:
                parti_politique = "Conservateur\n";
                break;
            case 2:
                parti_politique = "Independant\n";
                break;
            case 3:
                parti_politique = "Liberal\n";
                break;
            case 4:
                parti_politique = "Nouveau parti democratique\n";
                break;
            default:
                parti_politique = "Bloc quebecois\n";
        }
        return parti_politique;
    }


}