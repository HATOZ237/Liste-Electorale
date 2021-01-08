//
// Created by Duroy on 03/01/2021.
//

#include <iostream>
#include "Circonscription.h"

using namespace std;
using namespace elections;

int main() {
    string nom = "vnryny";
    string prenom = "Harold";
    string nom1 = "William";
    string prenom1 = "Poirier";
    util::Date date(13, 8, 2000);
    util::Date date1(26, 6, 1970);
    util::Adresse adresse(2524, "rue Monseigneur-Lafleche", "Quebec", "G1V 1k1", "QC");
    util::Adresse adresse1(933, "route de l'eglise", "Quebec", "G1V 3V1", "QC");
    string Nas = "000 000 000";
    string Nas1 = "111 000 111";
    //cout<<"Ici";
    Candidat candidat(Nas, nom1, prenom, date, adresse, 0);
    //Candidat candidat(Nas, nom, prenom, date, adresse, 1);
    Electeur electeur(Nas, nom, prenom, date, adresse);
    Electeur electeur1(Nas1, nom1, prenom1, date1, adresse1);
//  Electeur electeur(Nas, nom, prenom, date, adresse);
//  Electeur electeur(Nas, nom, prenom, date, adresse);
    string nom_circonscription = "Ecureuil";
    Circonscription circonscription(nom_circonscription, candidat);
    circonscription.inscrire(electeur);
    cout << circonscription.nbreInscrits() << endl;
    circonscription.inscrire(electeur1);
    //cout << circonscription.nbreInscrits()<<endl;
    //cout << candidat.reqPersonneFormate()<<endl;
    //cout <<"--------------------------------------------------------------------------------"<<endl;
    //cout << endl << electeur.reqPersonneFormate()<<endl;
    //cout <<"--------------------------------------------------------------------------------"<<endl;
    //cout << circonscription.reqCirconscriptionFormate()<<endl;
    //cout <<"--------------------------------------------------------------------------------"<<endl;
    circonscription.inscrire(candidat);
    circonscription.inscrire(electeur1);
    //cout <<"yehj"<<endl;
    cout << circonscription.reqCirconscriptionFormate();
    cout << circonscription.nbreInscrits() << endl;
    cout<< "ie90e";
    return 0;


}