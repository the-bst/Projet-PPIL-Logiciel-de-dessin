//
// Created by basti on 22/02/2021.
//

#include "Cercle.h"
#include "../Transformations/Transform.h"

const Cercle &Cercle::operator=(const Cercle &c){
    rayon = c.rayon;
    centre = c.centre;
    couleur = c.couleur;
    return *this;
}

string Cercle::print() const {
    ostringstream os;
    os << "Cercle rayon " << rayon << " couleur " << couleur << " "<< centre;
    return os.str();

}

Forme2D *Cercle::Clone() const {
    return new Cercle(*this);

}

double Cercle::AireForme() const {
    return  M_PI * rayon * rayon;
}

Forme2D *Cercle::trans(const Transform &t) const {
    return t.visitor(*this);
}


Cercle::operator string() const {
    ostringstream os;
    os << FormeSimple::operator string() << " de type Cercle [centre " << centre << " ,rayon " << rayon << "]";
    return os.str();

}

