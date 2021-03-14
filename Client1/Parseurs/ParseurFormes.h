//
// Created by basti on 25/02/2021.
//

/**
*\file ParseurFormes.h
* @brief \class ParseurPoly (hérite de ParseurBase)
*/

#ifndef CLIENT_PARSEURFORMES_H
#define CLIENT_PARSEURFORMES_H

#include "ParseurBase.h"


class ParseurFormes{

    ParseurFormes * suivant;
public:


    /**
* @brief Constructeur ParseurFormes
* @param suivant, le parseur suivant
*/
    ParseurFormes(ParseurFormes * suivant);


    /**
* @brief fait le lien dans la liste, renvoie une forme2D*
* @param s, la chaine a parser
*/
    Forme2D*  parse(const string& s) const ;


    /**
* @brief parseur implémenté dans les arseurs des formes
* @param d, texte à parser
*/
    virtual Forme2D* parse1(const string& d) const = 0;

    static vector <string> decoupage(string txt, char coupe);

};


#endif //CLIENT_PARSEURFORMES_H
