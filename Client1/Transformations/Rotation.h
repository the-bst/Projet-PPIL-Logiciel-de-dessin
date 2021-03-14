//
// Created by basti on 22/02/2021.
//

#ifndef CLIENT_ROTATION_H
#define CLIENT_ROTATION_H

#include "Transform.h"
#include "../Geom/Matrice22.h"

class Rotation : public Transform{
        Vecteur2D ptInvariant;
        Matrice22 angle;

        public:

        Rotation(const double & alpha,Vecteur2D c ): angle(Matrice22::rotaC_Pi(alpha)),ptInvariant(c-angle*c){}

        Vecteur2D visitor(const Vecteur2D& v)const{
            return  angle*v + ptInvariant;
        }
};


#endif //CLIENT_ROTATION_H
