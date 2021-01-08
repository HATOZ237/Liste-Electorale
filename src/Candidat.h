//
// Created by Duroy on 01/01/2021.
//

#ifndef UNTITLED4_CANDIDAT_H
#define UNTITLED4_CANDIDAT_H

#include "Personne.h"

namespace elections {
    class Candidat : public Personne {
    public:
        int getMPartiPolitique() const;

        std::string reqPersonneFormate() const;

        Candidat(const std::string &pNas, const std::string &pNom, const std::string &pPrenom, const util::Date &date,
                 const util::Adresse &adresse, int mPartiPolitique);

        virtual Personne *clone() const;
        /*enum partisPolitiques {
            BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL,
            NOUVEAU_PARTI_DEMOCRATIQUE
        };*/

    private:
        int m_partiPolitique;

        static std::string parti(int partiPolitique);

    };
}

#endif //UNTITLED4_CANDIDAT_H
