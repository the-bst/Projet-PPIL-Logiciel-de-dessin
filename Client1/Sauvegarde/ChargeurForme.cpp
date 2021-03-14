//
// Created by basti on 26/02/2021.
//

#include "ChargeurForme.h"
#include <fstream>

static   ChargeurForme * chargeur = ChargeurForme::getCharg();

ChargeurForme *ChargeurForme::getCharg() {
    return chargeur;
}

vector<Forme2D *> ChargeurForme::charge(const string nomFichier, const ParseurFormes *p) {
    vector<Forme2D *> listeForme;
    ifstream fichier;
    fichier.open(nomFichier, std::fstream::in);
    if (fichier.is_open()) {
        string  s;
        while (getline(fichier, s)) {
            Forme2D * f = NULL;
            try {
                f = p->parse(s);
            }
            catch (exception e) {
                cout << e.what();
            }
            if (f != NULL){
                listeForme.push_back(f);
            }
        }
    }
    else
        cout << "Erreur d'ouverture du fichier" <<endl;
    return listeForme;
}



