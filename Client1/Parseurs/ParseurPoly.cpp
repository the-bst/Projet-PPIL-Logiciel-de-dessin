//
// Created by basti on 25/02/2021.
//

#include "ParseurPoly.h"

Forme2D * ParseurPoly::parse1(const string & d) const{

    int indicePolygone = d.find("Polygone", 0);

    if (indicePolygone == std::string::npos)
        return NULL;
    else {
        const char * chaine = d.c_str();
        // récupération de la couleur
        int couleur;
        sscanf_s(chaine, "Polygone couleur %d", &couleur);

        int indiceCrDeb = d.find("{");
        int indiceCrFin = d.find("}");

        string ligne = d.substr(indiceCrDeb + 1,indiceCrFin-indiceCrDeb-1);

        vector<Vecteur2D> v;
        vector<string> res = decoupage(ligne, ';');
        for (unsigned int i = 0; i < res.size(); i++)
        {
            v.push_back(Vecteur2D(res[i].c_str()));
        }

        return new Polygone(couleur, v);
    }
}