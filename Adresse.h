/**
 * \file Personne.cpp
 * \brief Implementation de la classe Personne
 *  Created on: 2021-01-01
 *  Author: etudiant
 * Fonction permettant de creer des joueurs pour une equipe de hockey
 */

#ifndef UNTITLED4_ADRESSE_H
#define UNTITLED4_ADRESSE_H

#include <string>
#include <ostream>

namespace util {

    class Adresse {
    public:

        virtual ~Adresse();

    private:
        int m_numeroCivic;
        std::string m_nomRue;
        std::string m_ville;
        std::string m_codePostal;
        std::string m_province;
    public:
        Adresse(int mNumeroCivic, const std::string &mNomRue, const std::string &mVille, const std::string &mCodePostal,
                const std::string &mProvince);

        friend std::ostream &operator<<(std::ostream &os, const Adresse &adresse);

        bool operator==(const Adresse &rhs) const;

        bool operator!=(const Adresse &rhs) const;

        int getMNumeroCivic() const;

        void setAdresse(int mNumeroCivic, const std::string &mNomRue, const std::string &mVille,
                        const std::string &mCodePostal,
                        const std::string &mProvince);

        const std::string &getMNomRue() const;

        const std::string &getMVille() const;

        const std::string &getMCodePostal() const;

        const std::string &getMProvince() const;
    };
}


#endif //UNTITLED4_ADRESSE_H
