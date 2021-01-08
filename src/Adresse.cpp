//
// Created by Duroy on 01/01/2021.
//

#include "Adresse.h"
#include "ContratException.h"

namespace util {
/**
 * @brief
 */
    Adresse::~Adresse() {

    }

    /**
     * @brief
     * @param mNumeroCivic
     * @param mNomRue
     * @param mVille
     * @param mCodePostal
     * @param mProvince
     */
    Adresse::Adresse(int mNumeroCivic, const std::string &mNomRue, const std::string &mVille,
                     const std::string &mCodePostal, const std::string &mProvince) : m_numeroCivic(mNumeroCivic),
                                                                                     m_nomRue(mNomRue), m_ville(mVille),
                                                                                     m_codePostal(mCodePostal),
                                                                                     m_province(mProvince) {
        PRECONDITION(mNumeroCivic >= 0);
        PRECONDITION(!mNomRue.empty());
        PRECONDITION(!mCodePostal.empty());
        PRECONDITION(!mProvince.empty());
        PRECONDITION(!mVille.empty());

        POSTCONDITION(m_ville == mVille);
        POSTCONDITION(m_numeroCivic == mNumeroCivic);
        POSTCONDITION(m_codePostal == mCodePostal);
        POSTCONDITION(m_nomRue == mNomRue);
        POSTCONDITION(m_province == mProvince);

    }

    /**
     * @brief
     * @return
     */
    int Adresse::getMNumeroCivic() const {
        return m_numeroCivic;
    }

    /**
     * @brief
     * @return
     */
    const std::string &Adresse::getMNomRue() const {
        return m_nomRue;
    }

    /**
     * @brief
     * @return
     */
    const std::string &Adresse::getMVille() const {
        return m_ville;
    }

    /**
     * @brief
     * @return
     */
    const std::string &Adresse::getMCodePostal() const {
        return m_codePostal;
    }

    /**
     * @brief
     * @return
     */
    const std::string &Adresse::getMProvince() const {
        return m_province;
    }

    /**
     * @brief
     * @param rhs
     * @return
     */
    bool Adresse::operator==(const Adresse &rhs) const {
        return m_numeroCivic == rhs.m_numeroCivic &&
               m_nomRue == rhs.m_nomRue &&
               m_ville == rhs.m_ville &&
               m_codePostal == rhs.m_codePostal &&
               m_province == rhs.m_province;
    }

    /**
     * @brief
     * @param rhs
     * @return
     */
    bool Adresse::operator!=(const Adresse &rhs) const {
        return !(rhs == *this);
    }

    /**
     * @brief
     * @param os
     * @param adresse
     * @return
     */
    std::ostream &operator<<(std::ostream &os, const Adresse &adresse) {
        os << adresse.m_numeroCivic << ", " << adresse.m_nomRue << ", "
           << adresse.m_ville << ", " << adresse.m_codePostal << ", " << adresse.m_province;
        return os;
    }

    /**
     * @brief
     * @param mNumeroCivic
     * @param mNomRue
     * @param mVille
     * @param mCodePostal
     * @param mProvince
     */
    void Adresse::setAdresse(int mNumeroCivic, const std::string &mNomRue, const std::string &mVille,
                             const std::string &mCodePostal, const std::string &mProvince) {
        PRECONDITION(mNumeroCivic >= 0);
        PRECONDITION(!mNomRue.empty());
        PRECONDITION(!mCodePostal.empty());
        PRECONDITION(!mProvince.empty());
        PRECONDITION(!mVille.empty());

        m_province = mProvince;
        m_ville = mVille;
        m_nomRue = mNomRue;
        m_codePostal = mCodePostal;
        m_numeroCivic = mNumeroCivic;

        POSTCONDITION(m_ville == mVille);
        POSTCONDITION(m_numeroCivic == mNumeroCivic);
        POSTCONDITION(m_codePostal == mCodePostal);
        POSTCONDITION(m_nomRue == mNomRue);
        POSTCONDITION(m_province == mProvince);


    }

}