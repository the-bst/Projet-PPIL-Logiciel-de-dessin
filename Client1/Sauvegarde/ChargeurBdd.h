//
// Created by basti on 26/02/2021.
//

/**
*\file ChargeurForme.h
* @brief \class ChargeurBdd (charge les forme pour les dessiner depuis la bdd)
*/

#ifndef CLIENT_CHARGEURBDD_H
#define CLIENT_CHARGEURBDD_H
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <winsock.h>
#include <mysql.h>
#include "../Forme/Forme2D.h"
#include "../Parseurs/ParseurFormes.h"

class ChargeurBdd {
	ChargeurBdd();
public:
	/**
* @brief  parcour la sauvegarde bdd grace au parseur
* @param ipbase, adresse ip de la bdd
* @param nomhote, nom de l'uitilisateur de la bdd
* @param  mdp, le mot de passe de la bdd
* @param nom, le nom de la bdd
* @param portbase, le port d'écoute du serveur bdd
* @param parseur, parseur de formes (segment, cercle, polygone, -> ParseurFormes)
* @return static vector<Forme2D*>
*/
	static vector<Forme2D*> charge(const char* ipbase, const char* nomhote, const char* mdp, const  char* nom, const int portbase, const ParseurFormes* p);


	/**
* @brief renvoi un pointeur sur le ChargeurBdd cree
* @return nouveau ChargeurBdd
*/
	static ChargeurBdd* getCharg();

};


#endif //CLIENT_CHARGEURBDD_H
