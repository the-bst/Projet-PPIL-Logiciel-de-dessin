//
// Created by basti on 25/02/2021.
//

using namespace std;

#include <stdio.h>

#include <iostream>

#include "Erreur.h"


Erreur::Erreur()
{
    strcpy_s(this->message,"Erreur !");
}

Erreur::operator string() const
{
    return string(this->message);
}

ostream& operator << (ostream& os, const Erreur& erreur)
{
    os << (string)erreur;
    return os;
}

Erreur::Erreur(const char * msgErreur)
{
    strcpy_s(this->message,"Erreur : ");
    int longu = strlen(msgErreur);

    static int n = messageL-9;

    if (longu <= n) strcat_s(this->message,msgErreur);
    else
    {
        strncat_s(this->message,msgErreur,n);

        this->message[messageL] = '\0';
    }
}






