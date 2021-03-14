//
// Created by basti on 08/03/2021.
//


/**
*\file FormeSimple.h
* @brief \class FormeSimple
*/


#ifndef CLIENT_FORMESIMPLE_H
#define CLIENT_FORMESIMPLE_H

#include "Forme2D.h"


class FormeSimple : public Forme2D{
protected:

public:

    /**
    * Constructeur vide formeSimple
    */
    FormeSimple();

    /**
    * Constructeur FormeSimple
    * @param couleur : couleur de la formeSimple
    */
    FormeSimple(unsigned int couleur);

    FormeSimple(const FormeSimple &f){}

    /**
    * Destructeur
    */
    virtual ~FormeSimple(){}  //Destructeur de Forme Simple

    virtual operator string() const;

};


#endif //CLIENT_FORMESIMPLE_H



