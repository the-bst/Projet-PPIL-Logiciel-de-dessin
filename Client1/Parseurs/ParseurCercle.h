//
// Created by basti on 25/02/2021.
//



/**
*\file ParseurCercle.h
* @brief \class ParseurCercle (h�rite de ParseurFormes)
*/


#ifndef CLIENT_PARSEURCERCLE_H
#define CLIENT_PARSEURCERCLE_H


#include "ParseurFormes.h"
#include "../Forme/Cercle.h"

class ParseurCercle :public ParseurFormes{
public:

	/**
* @brief Constructeur de ParseurSegment en le chainant au ParseurForme s
* @param s : le parseur suivant
*/
    ParseurCercle(ParseurFormes* f): ParseurFormes(f){}


	/**
* @brief renvoi un Cercle* si lle texte contient "Cercle"
* @param txt, texte � parser
*/
    Forme2D* parse1(const string& txt) const;
};


#endif //CLIENT_PARSEURCERCLE_H
