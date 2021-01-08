/*
 * \file Personne.h
 * \brief fichier aui conyient l'interface de la classe personne aui servira pour enregistrer les infor;ations sur des joueurs
 *  Created on: 2020-02-21
 *      Author: etudiant
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include "Date.h"
#include "Adresse.h"

namespace elections {
/**
 * \brief cette classe Personne construit un objet Personne a partir de son nom,
 * 		son prenom, sa date de naisssance et son numero de telephone.
 * 		les limites de cet objet obeissent aux limites de sa date de sa naissance
 */
    class Personne {
    public:
        Personne(const std::string p_NAS, const std::string p_nom, const std::string p_prenom, util::Date date,
                 util::Adresse adresse);

        virtual ~Personne() {};

        const std::string &reqNom() const;

        const std::string &reqPrenom() const;

        const util::Adresse &getMAdresse() const;

        void asgMAdresse(const util::Adresse &mAdresse);

        util::Date reqDateNaissance() const;

        //void asgNumero(std::string& p_numero);
        bool operator==(const Personne &personne) const;

        virtual std::string reqPersonneFormate() const = 0;

        virtual Personne *clone() const = 0;

    private:
        std::string m_nom;
        std::string m_prenom;
        util::Date m_dateNaissance;
        util::Adresse m_adresse;
        std::string m_NAS;

        void verifieInvariant() const;
    };
}

#endif /* PERSONNE_H_ */
