//
// Created by basti on 22/02/2021.
//

#ifndef CLIENT_HOMOTH_H
#define CLIENT_HOMOTH_H

#include "Transform.h"

class Homoth : public Transform {
protected:
    double rapportZoom;
    Vecteur2D PointInvar;


public:
    Homoth(const Vecteur2D & centre , const double rapZoom): PointInvar(centre-centre*rapZoom), rapportZoom(rapZoom){}

    ~Homoth(){}

    Vecteur2D visitor(const Vecteur2D& pt2D)const{
        return  (pt2D * rapportZoom) + PointInvar  ;
    }

    double getRapZoom() const {
        return rapportZoom;
    }
};


#endif //CLIENT_HOMOTH_H
