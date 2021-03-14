//
// Created by basti on 22/02/2021.
//

#include "Transform.h"

Forme2D *Transform::visitor(const FormeComp &fcomp) const{
    FormeComp* res = new FormeComp();
    res->setCouleur(fcomp.getCouleur());

    vector<Forme2D*>::const_iterator formC;

    for (formC = fcomp.getFormes().begin(); formC != fcomp.getFormes().end(); formC++){
        res->addForme2D(*((*formC)->trans(*this)));
    }

    return res;
}

Forme2D *Transform::visitor(const Polygone &p) const {
    vector<Vecteur2D>::const_iterator formC;
    vector<Vecteur2D> plusPt;
    for (formC = p.getPts().begin(); formC != p.getPts().end(); formC++) {
        plusPt.push_back(visitor(*formC));
    }
    return new Polygone(p.getCouleur(), plusPt);
}

Forme2D *Transform::visitor(const Triangle &tri) const{
    vector<Vecteur2D>::const_iterator formC;
    vector<Vecteur2D> plusPt;
    for (formC = tri.getPts().begin(); formC != tri.getPts().end(); formC++) {
        plusPt.push_back(visitor(*formC));
    }
    return new Triangle(tri.getCouleur(), plusPt[0],plusPt[1],plusPt[2]);
}

Forme2D *Transform::visitor(const Cercle &cer) const {
    return new Cercle(cer.getCouleur(), visitor(cer.getCentre()), cer.getRayon());
}

Forme2D *Transform::visitor(const Segment &seg) const {
    return new Segment(seg.getCouleur(), visitor(seg.getPt1()), visitor(seg.getPt2()));
}

