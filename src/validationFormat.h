/*
 * \file validationFormat.h
 * \brief ce fichier constitue l'interface des fonctions de validation
 *  \Created on: 2020-02-13
 *  \Author: etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include "Date.h"

namespace util {

    bool validerTelephone(const std::string &p_telephone);

    bool validerNumRAMQ(const std::string &p_numero, const std::string &p_nom, const
    std::string &p_prenom, long p_jourNaissance, long p_moisNaissance, long p_anneeNaissance, char p_sex);

    bool validerFormatNom(const std::string &p_nom);

    bool validerFormatNomAnnuire(const std::string &p_nom);

    bool validerAgeJoueur(const Date &date);

    bool validerAgeEntraineur(const Date &date);

    bool validerNAS(const std::string &p_nas);


}
#endif /* VALIDATIONFORMAT_H_ */
