//
// Created by basti on 25/02/2021.
//

/**
*\file ParseurPoly.h
* @brief \class ParseurPoly (h�rite de ParseurFormes)
*/


#ifndef CLIENT_PARSEURPOLY_H
#define CLIENT_PARSEURPOLY_H

#include "ParseurFormes.h"
#include "../Forme/Polygone.h"

class ParseurPoly : public ParseurFormes {
public:

    /**
* @brief Constructeur ParseurSeg chain� au ParseurFormes pf
* @param pf, le parseur suivant
*/
    ParseurPoly(ParseurFormes *pf): ParseurFormes(pf){}

    /**
* @brief renvoi un Cercle* si le texte contient "Cercle"
* @param txt, texte � parser
*/
    Forme2D* parse1(const string& txt) const;


};


#endif //CLIENT_PARSEURPOLY_H
