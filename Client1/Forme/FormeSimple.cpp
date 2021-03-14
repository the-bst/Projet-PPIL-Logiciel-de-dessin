//
// Created by basti on 22/02/2021.
//

#include "FormeSimple.h"


FormeSimple:: operator string() const{
    ostringstream os;
    os << "FormeSimple [ " <<  Forme2D::operator string() << " ]";
    return os.str();
}

FormeSimple::FormeSimple():Forme2D() {

}

FormeSimple::FormeSimple(unsigned int couleur): Forme2D(couleur) {

}

