//
// Created by basti on 22/02/2021.
//

#include "FormeComp.h"
#include "../Transformations/Transform.h"
using namespace std;

FormeComp::operator string() const{
    ostringstream os;
    os << "FormeComp [ " << Forme2D::operator string() << " ] [ " << endl ;

    for (unsigned int i = 0; i < Formes.size(); i++)
        os <<"\t" << i << "-" << *(Formes[i]) << endl;

    os <<" ] " ;

    return os.str();
}


FormeComp::FormeComp(const FormeComp &f) : Forme2D(f.couleur){
    vector<Forme2D*>::const_iterator form;
    for (form = f.Formes.begin(); form != f.Formes.end(); form++)
        Formes.push_back((*form)->Clone());
}

Forme2D *FormeComp::Clone() const{
    return new FormeComp(*this);
}

const FormeComp &FormeComp::operator=(const FormeComp &f){
    couleur = f.couleur;
    vector<Forme2D*>::const_iterator form;
    for (form = f.Formes.begin(); form != f.Formes.end(); form++)
        Formes.push_back((*form)->Clone());

    return *this;
}

FormeComp &FormeComp::addForme2D(const Forme2D &f){

    vector<Forme2D *>::const_iterator form = existe(&f);
    if (form == Formes.end())
    {
        if (Formes.size() == 0)
            setCouleur(f.getCouleur());

        Forme2D * f2 = f.Clone();
        if (Formes.size() != 0)
            f2->setCouleur(getCouleur());

        Formes.push_back(f2);
    }
    return *this;
}

double FormeComp::AireForme() const{
    double total=0;
    vector<Forme2D*>::const_iterator form;
    for (form = Formes.begin(); form != Formes.end(); form++)
        total += (*form)->AireForme();

    return total;
}


string FormeComp::print() const {
    ostringstream os;
    os << "FormeComplexe couleur " << couleur << " [";
    for (unsigned int i = 0; i < Formes.size() - 1; i++)
        os << Formes[i]->print() << "|";
    os << Formes[Formes.size() - 1]->print();
    os << "]";
    return os.str();
}

vector<Forme2D *>::const_iterator FormeComp::existe(const Forme2D *f2) const{
    return find_if(Formes.begin(), Formes.end(), CmpF2D(f2));
}

Forme2D *FormeComp::trans(const Transform &t) const {
    return t.visitor(*this);
}

FormeComp::FormeComp():Forme2D() {

}

const FormeComp &FormeComp::supForme2D(const Forme2D &f){
    vector<Forme2D *>::const_iterator form = existe(&f);
    if (form != Formes.end())
    {
        delete *form;
        Formes.erase(form);
    }

    return *this;
}

const FormeComp &FormeComp::supForme2D(const unsigned int i) {
    if ( i >= Formes.size())
        throw Erreur("Cette forme n'existe pas");

    delete Formes[i];
    Formes.erase(Formes.begin() + i);

    return *this;

}

FormeComp::~FormeComp() {
    unsigned int i;
    for (i=0; i < Formes.size(); i++)
    {
        delete Formes[i];
    }
    Formes.clear();
}
