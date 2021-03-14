//
// Created by basti on 22/02/2021.
//

#include "Forme2D.h"
#include "../DessinJava/Dessiner.h"
#include "../Sauvegarde/Sauvegarde.h"
#include "../Parseurs/ParseurFormes.h"
#include <fstream>
#include <exception>

void Forme2D::dessin(const Dessiner& d) const {
    d.visitor(*this);
}

Forme2D::operator string() const {
    ostringstream os;
    os << "Couleur Forme: " << couleur ;
    return os.str();
}


void Forme2D::sauvegarde(const Sauvegarde &s) const {  //sauvegarde forme
    s.visitor(*this);
}

void Forme2D::sauvegardeBdd(const Sauvegarde & b) const {  //sauvegarde bdd
    b.visitor(*this);
}

Forme2D::Forme2D(const Forme2D &f2d) :couleur(f2d.couleur){

}

Forme2D::Forme2D(unsigned int couleur) :couleur(couleur){

}

Forme2D::Forme2D() : couleur(0){}

ostream &operator << (ostream &f, const Forme2D &f2d) {
    f<<(string)f2d;
    return f;
}


