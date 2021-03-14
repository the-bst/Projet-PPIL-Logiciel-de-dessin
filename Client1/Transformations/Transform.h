//
// Created by basti on 22/02/2021.
//

/*
* \file Transform.h
@brief	Class Transform (abstraite ,  applique une transformation � une Forme2D)
*/

#ifndef CLIENT_TRANSFORM_H
#define CLIENT_TRANSFORM_H

#include<string>
#include"../Forme/Segment.h"
#include "../Forme/Triangle.h"
#include"../Forme/Cercle.h"
#include"../Forme/Polygone.h"
#include "../Forme/FormeComp.h"

class Transform {
protected:

public:



    /**
    * @brief applique la transformation sur un Segment
    * @param seg : Segment
    */
    Forme2D* visitor(const Segment & seg)const;

    /**
    * @brief applique la transformation sur un Triangle
    * @param t : Triangle
    */
    Forme2D* visitor(const Triangle & tri)const;

    /**
     * @brief : applique la transformation sur un polygone
     * @param p : Polygone
    */
    Forme2D* visitor(const Polygone & p)const;

    /**
    * @brief applique la transformation sur un Cercle
    * @param cer : Cercle
    */
    Forme2D* visitor(const Cercle & cer)const;


    /**
    * @brief applique la transformation sur la FormeComp
    * @param fcom : FormeComp
    */
    Forme2D* visitor(const FormeComp& fcomp)const;


    virtual Vecteur2D visitor(const Vecteur2D& form)const=0;


    /**
    *Destructeur
    */
    virtual ~Transform(){}

};


#endif //CLIENT_TRANSFORM_H
