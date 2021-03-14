/**
*\file Dessiner.h
* @brief \class Dessiner (abstraite, dessine une forme2D)
*/


#pragma once
#include "../Forme/Forme2D.h"

/**
    class est abstraite
    Dessine une forme selectionner
*/

class Dessiner {
public:
	/**
	* @brief destructeur de dessin
	*/
	virtual ~Dessiner(){};


    /**
    * @brief applique dessin sur une Forme2D
    * @param f, forme2D � dessiner
    */
	virtual void visitor(const Forme2D & f)const = 0;
};


