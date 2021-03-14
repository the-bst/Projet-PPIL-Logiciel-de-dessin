//
// Created by basti on 07/03/2021.
//

/**
*\file ParseurFormeComp.h
* @brief \class ParseurFormeComp (hérite de ParseurFormes)
*/

#ifndef CLIENT_PARSEURFORMECOMP_H
#define CLIENT_PARSEURFORMECOMP_H

#include "ParseurFormes.h"

class ParseurFormeComp : public ParseurFormes{
public:

    /**
    * @brief Constructeur ParseurFormeCompl chainé au ParseurFormes p
    * @param p, le parseur suivant
    */
    ParseurFormeComp(ParseurFormes * p);

    /**
    * @brief Destructeur de ParseurFormeComp
    */
    ~ParseurFormeComp();

    /**
    * @brief renvoie FormeComplexe* si le txt contient une FormeComp
    * @param chaine : la chaine a convertir en forme
    */
    Forme2D* parse1(const string& txt) const;
};


#endif //CLIENT_PARSEURFORMECOMP_H
