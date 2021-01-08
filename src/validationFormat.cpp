/*
 * \file validationFormat.cpp
 *\brief ce fichier implemente les fonctions de validation
 *\Created on: 2020-02-13
 *\Author: etudiant
 */

#include <iostream>
#include <string>
#include <ctype.h>
#include "validationFormat.h"
#include <locale>
#include <vector>
//#include "Joueur.h"

using namespace std;
namespace util {
/**
 * \fn bool validerTelephone(const std::string& p_telephone)
 * \brief cette fonction permet de valider le format national du numero de telephone canadien
 * \param[in] p_telephone le telephoen dont on doit verifier le format
 * \return true si le for4nat est valide false s'il ne l'est pas
 */
    bool validerTelephone(const std::string &p_telephone) {
        string copie_telephone = p_telephone;
        string tab_numero[] = {"403", "780", "604", "236", "250", "778", "902", "204", "506", "905",
                               "519", "289", "705", "613", "807", "416", "647", "438", "514", "450", "579", "418",
                               "581", "819", "873", "306", "709", "867", "800", "866", "877", "888", "855", "966"};
        bool resultat;
        locale loc;
        int longueur = copie_telephone.length();
        resultat = true;
        int t = 0;
        for (int i = 0; i < 34; i++) {
            if (tab_numero[i] != (copie_telephone.substr(0, 3))) {
                t++;
            }
        }
        if (t == 34) resultat = false;
        if (copie_telephone[3] != ' ' || copie_telephone[7] != '-') resultat = false;
        for (int i = 4; i < 7; i++) {
            if (!isdigit(copie_telephone[i], loc)) resultat = false;
        }
        for (int i = 8; i < 12; i++) {
            if (!isdigit(copie_telephone[i], loc)) resultat = false;
        }
        if (longueur != 12) {
            resultat = false;
        }
        return resultat;
    }

/**
 * \fn bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex)
 * \brief cette fonction valide le format du numero ramq
 * \param[in] p_numero le numero dont on verifie le format
 * \param[in] p_nom le nom de la personne dont on verifie la ramq
 * \param[in] p_prenom son prenom
 * \param[in] p_jourNaissance son jour de naissance en entier
 * \param[in] p_moisNaisssance son mois de naissance en entier
 * \param[in] p_anneeNaissance son annee de naissance en entier
 * \param[in] p_sex une chaine de caractere designant le sexe
 * \return true si le format du numero est correct, false sinon(un booleen)
 */
    bool validerNumRAMQ(const std::string &p_numero, const std::string &p_nom, const std::string &p_prenom,
                        long p_jourNaissance, long p_moisNaissance, long
                        p_anneeNaissance, char p_sex) {
        string c_numero = p_numero;
        string c_nom = p_nom;
        string c_prenom = p_prenom;
        string c_jour;
        string c_mois;
        string c_annnee = to_string(p_anneeNaissance).substr(2, 2);
        char test1 = toupper(c_prenom[0]);
        char test2 = c_numero[3];
        char test3 = c_numero[9];
        char test4 = c_numero[4];
        string test5 = c_numero.substr(5, 2);

        if (p_jourNaissance < 10) {
            c_jour = "0" + to_string(p_jourNaissance);
        } else c_jour = to_string(p_jourNaissance);

        if (p_moisNaissance < 10) {
            c_mois = "0" + to_string(p_moisNaissance);
        } else c_mois = to_string(p_moisNaissance);

        bool resultat = true;

        for (int i = 0; i < 3; i++) {
            if (c_numero[i] != toupper(c_nom[i])) resultat = false;
        }

        if (test1 != test2) resultat = false;

        if (c_numero.substr(10, 2) != c_jour) resultat = false;

        if (toupper(p_sex) == 'M') {
            if ((c_numero.substr(7, 2)) != c_mois) resultat = false;
        }
        if (toupper(p_sex) == 'F') {
            if (stoi(c_numero.substr(7, 2)) != p_moisNaissance + 50) resultat = false;
        }
        if (test3 != ' ') resultat = false;
        if (test4 != ' ') resultat = false;
        if (test5 != c_annnee) resultat = false;
        if (p_sex != 'M' && p_sex != 'F') resultat = false;
        if (c_numero.size() != 14) resultat = false;

        return resultat;
    }

/**
 * \fn bool validerFormatNom(const std::string& p_nom)
 * \brief cette fonction valide le nom passe en parametre
 * \param[in] p_nom le nom a verifier
 * \return true si le nom de contient aue des lettres et est non vide, false sinon
 */
    bool validerFormatNom(const std::string &p_nom) {
        std::string c_nom = p_nom;
        bool result = true;
        if (p_nom.empty()) return false;
        int tailleMot = c_nom.length();
        for (int i = 0; i < tailleMot; i++) {
            if (!isalpha(c_nom[i])) result = false;
        }
        return result;

    }

    bool validerAgeJoueur(const Date &date) {
        Date dateJoueur = date;
        Date datesys;
        int anneeJoueur;
        bool valide = true;
        anneeJoueur = datesys - dateJoueur;
        if (anneeJoueur < 15 * 365.25 || anneeJoueur > 17 * 365.25) {
            valide = false;
        }
        return valide;
    }

    bool validerAgeEntraineur(const Date &date) {
        Date dateJoueur = date;
        Date datesys;
        int anneeJoueur;
        bool valide = true;
        anneeJoueur = datesys - dateJoueur;
        if (anneeJoueur < 18 * 365.25) {
            valide = false;
        }
        return valide;
    }

    bool validerFormatNomAnnuire(const std::string &p_nom) {
        std::string c_nom = p_nom;
        bool result = true;
        int tailleMot = c_nom.length();
        for (int i = 0; i < tailleMot; i++) {
            if (!isalpha(c_nom[i]) && c_nom[i] != ' ') result = false;
        }
        return result;
    }

    bool validerNAS(const string &p_nas) {
        bool result = true;
        //string copie_nas = p_nas;
        if (p_nas.length() != 11) return false;
        if (p_nas[3] != ' ' or p_nas[7] != ' ') return false;
        string premier_morceau = p_nas.substr(0, 3);
        string deuxieme_morceau = p_nas.substr(4, 3);
        string troisieme_morceau = p_nas.substr(8, 9);
        vector<string> cases;
        cases.push_back(premier_morceau);
        cases.push_back(deuxieme_morceau);
        cases.push_back(troisieme_morceau);
        for (const auto &cas: cases) {
            for (int j = 0; j < cas.length(); j++) {
                if (!isdigit(cas[j]));
            }
        }
        return true;
    }
}


