#ifndef CLIENT_SAUVEGARDE_H
#define CLIENT_SAUVEGARDE_H


/*
* \file Sauvegarde.h
@brief	Class Sauvegarde (abstraite, sauvegarder une forme sous un format TXT /BDD)
*/

#include "../Forme/Forme2D.h"
#include <string>



class Sauvegarde
{

protected : 
	string NFichier;
    const char* ipbase;
    int portbase;
    const char* mdp;
    const char* nom;
    const char* nomhote;


public :



    /*
    * @brief Constructeur sauvegarde
    * @param nom_f, nom du fichier dans le quel on veut sauvegarder
    */
    Sauvegarde(const string & nom_f);

    Sauvegarde( const char * ipbase, const char* nomhote, const char* mdp, const char* nom, const int portbase);

    /*
    * @brief Destructeur de sauvegarde
    */
virtual ~Sauvegarde();

	virtual void visitor(const Forme2D &f)const = 0;
};


#endif //CLIENT_SAUVEGARDE_H