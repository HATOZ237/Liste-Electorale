//
// Created by Duroy on 04/01/2021.
//

#ifndef UNTITLED4_ELECTEUR_H
#define UNTITLED4_ELECTEUR_H


#include "Personne.h"

namespace elections {
    class Electeur : public Personne {
    public:
        Electeur(const std::string &pNas, const std::string &pNom, const std::string &pPrenom, const util::Date &date,
                 const util::Adresse &adresse);

        std::string reqPersonneFormate() const;

        virtual Personne *clone() const;


    };

}


#endif //UNTITLED4_ELECTEUR_H
