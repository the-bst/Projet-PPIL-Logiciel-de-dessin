//
// Created by basti on 25/02/2021.
//

/**
*\file ParseurSeg.h
* @brief \class ParseurSeg (hérite de ParseurFormes)
*/

#ifndef CLIENT_PARSEURSEG_H
#define CLIENT_PARSEURSEG_H

#include "ParseurFormes.h"

class ParseurSeg : public ParseurFormes{
public:
    /**
* @brief Constructeur ParseurSeg
* @param f, le parseur suivant
*/
    ParseurSeg(ParseurFormes* f);

    /**
* @brief renvoi un Segment* si le texte contient "Segment"
* @param d, texte à parser
*/
    Forme2D* parse1(const string & d) const;
};


#endif //CLIENT_PARSEURSEG_H
