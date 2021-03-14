//
// Created by basti on 25/02/2021.
//

/**
*\file Erreur.h
* @brief \class Erreur (pour l'affichage des erreurs)
*/


#ifndef CLIENT_ERREUR_H
#define CLIENT_ERREUR_H

using namespace std;

#include <string>
#include <iostream>

class Erreur
{
public:
    const static int messageL = 100;
    char message[1+messageL];
    Erreur();
    Erreur(const char * msgErreur);

    operator string() const;
};

ostream & operator << (ostream & os, const Erreur & erreur);



#endif //CLIENT_ERREUR_H
