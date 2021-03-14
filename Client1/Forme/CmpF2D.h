//
// Created by basti on 08/03/2021.
//

#ifndef CLIENT_CMPF2D_H
#define CLIENT_CMPF2D_H

#include "Forme2D.h"

class CmpF2D{


    Forme2D * f1;
public:

    /**
* @brief Constructeur 
* @param f2 : forme2D � comparer
*/
    CmpF2D(const Forme2D * f2)
    {
        f1 = const_cast <Forme2D *> (f2);
    }

    /**
* @brief compare string de deux chaines
* @param f2 : f2 a convertir en forme
*/
    bool operator()(const Forme2D * f2)const {
        return (string(*f2)) == (string(*f1));
    }
};

#endif //CLIENT_CMPF2D_H
