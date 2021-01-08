//
// Created by Duroy on 04/01/2021.
//

#ifndef UNTITLED4_CIRCONSCRIPTION_H
#define UNTITLED4_CIRCONSCRIPTION_H

#include <string>
#include "Personne.h"
#include "Candidat.h"
#include "Electeur.h"
#include <vector>

namespace elections {
    class Circonscription {
    private:
        std::string m_nomCirconscription;
        Candidat m_deputeElu;
        std::vector<Personne *> m_vInscrits;

        bool estDejaPresent(const Personne &nouvel_personne);

    public:
        const std::string &getMNomCirconscription() const;

        const Candidat &getMDeputeElu() const;

        virtual ~Circonscription();

        //bool operator==(const Circonscription &rhs) const;
        Circonscription &operator=(const Circonscription &rhs);

        Circonscription(const Circonscription &circonscription);

        //bool operator!=(const Circonscription &rhs) const;

        Circonscription(const std::string &mNomCirconscription, const Candidat &mDeputeElu);

        std::string reqCirconscriptionFormate();

        void inscrire(const Personne &nouvel_inscrit);

        void desinscrire(const std::string &Nas);

        size_t nbreInscrits();
    };

}


#endif //UNTITLED4_CIRCONSCRIPTION_H
