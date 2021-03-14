//
// Created by basti on 26/02/2021.
//


/**
*\file ChargeurForme.h
* @brief \class ChargeurForme
*/


#ifndef CLIENT_CHARGEURFORME_H
#define CLIENT_CHARGEURFORME_H


#include <vector>
#include "../Forme/Forme2D.h"
#include "../Parseurs/ParseurFormes.h"

using namespace std;

class ChargeurForme {
    /**
* @brief Constructeur de ChargeurForme
*/
    ChargeurForme();
public:

	/**
* @brief  parcour la sauvegarde grace au parseur
* @param nomfichier,nom du fichier
* @param parseur, parseur de formes (segment, cercle, polygone, ... ParseurFormes)
* @return static vector<Forme2D*>
*/
        static vector<Forme2D *> charge(const string nomFichier, const ParseurFormes *p);

		/**
		* @brief renvoi un pointeur sur le ChargeurForme cree
		* @return nouveau ChargeurrForme
		*/
        static ChargeurForme* getCharg();

};


#endif //CLIENT_CHARGEURFORME_H
