//
// Created by basti on 25/02/2021.
//

/**
*\file ParseurTri.h
* @brief \class ParseurTri (hérite de ParseurFormes)
*/


#ifndef CLIENT_PARSEURTRI_H
#define CLIENT_PARSEURTRI_H

#include "ParseurFormes.h"


class ParseurTri : public ParseurFormes{
public:


    /**
* @brief Constructeur ParseurSeg 
* @param s, le parseur suivant
*/
    ParseurTri(ParseurFormes * s):ParseurFormes(s){}


    /**
* @brief renvoi un Triangle* si le texte contient "Triangle"
* @param txt, texte à parser
*/
    Forme2D * parse1(const string & txt) const;

};


#endif //CLIENT_PARSEURTRI_H

