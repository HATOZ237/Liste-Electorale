//
// Created by Duroy on 04/01/2021.
//

#include <sstream>
#include "Electeur.h"

namespace elections {


    Electeur::Electeur(const std::string &pNas, const std::string &pNom, const std::string &pPrenom,
                       const util::Date &date, const util::Adresse &adresse) : Personne(pNas, pNom, pPrenom, date,
                                                                                        adresse) {}

    Personne *Electeur::clone() const {
        return new Electeur(*this);
    }

    std::string Electeur::reqPersonneFormate() const {
        std::ostringstream os;
        os << "Electeur" << std::endl;
        os << "--------------------------------------" << std::endl;
        os << Personne::reqPersonneFormate();
        return os.str();
    }
}