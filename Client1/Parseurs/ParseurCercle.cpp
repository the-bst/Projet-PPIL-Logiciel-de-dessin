//
// Created by basti on 25/02/2021.
//

#include "ParseurCercle.h"


Forme2D * ParseurCercle::parse1(const string & d) const{

    int indiceCercle = d.find("Cercle", 0);
    if (indiceCercle == std::string::npos)
        return NULL;
    else {
        const char * c = d.c_str();
        double r, x, y;
        int couleur;
        sscanf_s(c, "Cercle rayon %lf couleur %d (%lf,%lf)", &r, &couleur, &x, &y);
        return new Cercle(couleur, Vecteur2D(x, y), r);
    }
}
