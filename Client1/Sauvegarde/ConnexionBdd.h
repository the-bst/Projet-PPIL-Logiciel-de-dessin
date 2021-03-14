//
// Created by basti on 26/02/2021.
//


/**
*\file ConnexionBdd.h
* @brief \class ConnexionBdd (gère la sauvegarde des formes dans la bdd)
*/


#ifndef CLIENT_CONNEXIONBDD_H
#define CLIENT_CONNEXIONBDD_H

#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>

#include "Sauvegarde.h"

using namespace std;

class ConnexionBdd : public Sauvegarde {
	
	
public:
	/**
* @brief sauvegarde  dans la base de donnée une forme
* @param ipbase, adresse ip de la bdd
* @param nomhote, nom de l'uitilisateur de la bdd
* @param  mdp, le mot de passe de la bdd
* @param nom, le nom de la bdd
* @param portbase, le port d'écoute du serveur bdd
*/
	ConnexionBdd(const char * ipbase, const char * nomhote, const char* mdp, const  char* nom, const int portbase);
	~ConnexionBdd() {};

	
	/**
* @brief applique la sauegarde au format text d'une forme dans la bdd
* @param f :la forme2D à sauvegarder
*/
	void visitor(const Forme2D & b)const;

 
};


#endif //CLIENT_CONNEXIONBDD_H
