//
// Created by basti on 22/02/2021.
//

/**
*\file Transla.h
* @brief \class Transla (hérite de Transform) -> translation
*/

#ifndef CLIENT_TRANSLA_H
#define CLIENT_TRANSLA_H

#include "Transform.h"

class Transla:  public Transform {
protected:
    Vecteur2D vecteur;

public:

    /**
    * @brief Constucteur une Translation
    * @param vect : le vecteur de translation
    */
    Transla( const Vecteur2D & vect): vecteur(vect){}

    const Vecteur2D & getVecteur()const{
        return vecteur;
    };


    /**
    * @brief Translation sur un Point2D
    * @param pt2D :point qui subbit la translation
    */
    Vecteur2D visitor(const Vecteur2D& pt2D)const{
        return getVecteur() + pt2D;
    }

    /**
    *Destructieur de Translation
    */
    ~Transla(){}

};


#endif //CLIENT_TRANSLA_H
