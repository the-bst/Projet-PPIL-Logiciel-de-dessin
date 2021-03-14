//
// Created by basti on 25/02/2021.
//

/**
*\file ParseurBase.h
* @brief \class ParseurBase
* @brief prend une chaine et la renvoi sous le bon format
*/


//repris sur correction exos fractions

#ifndef CLIENT_PARSEURBASE_H
#define CLIENT_PARSEURBASE_H

#include "../Forme/Forme2D.h"

class ParseurBase {
public:
/**
* @brief transforme texte en un objet forme
*Convention : en cas d'�chec (format non reconnu) retourne NULL
*/
    virtual Forme2D * parse(const char * texte) const = 0;
};


#endif //CLIENT_PARSEURBASE_H
