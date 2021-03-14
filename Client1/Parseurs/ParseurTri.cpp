//
// Created by basti on 25/02/2021.
//

#include "ParseurTri.h"
#include "../Forme/Triangle.h"
#include <regex>

Forme2D * ParseurTri::parse1(const string & txt) const
{
    int indiceTriangle = txt.find("Triangle", 0);

    if (indiceTriangle == std::string::npos)
        return NULL;
    else {
        double x1, y1, x2, y2, x3, y3;
        int couleur;
        int indiceCouleur = txt.find("couleur", 0);
        int indiceAccolade = txt.find("}", indiceCouleur + 1);
        string chaine = txt.substr(indiceCouleur, indiceAccolade -1);
        const char * c = chaine.c_str();

        sscanf_s(c, "couleur %d {(%lf,%lf);(%lf,%lf);(%lf,%lf)}", &couleur, &x1, &x2, &x3, &y1, &y2, &y3);
        return new Triangle(couleur, Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3));
    }
}


//virtual Forme2D* parse1(const string& d) const = 0;