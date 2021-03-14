//
// Created by basti on 22/02/2021.
//

/**
*\file Cercle.h
* @brief \class Cercle (h�rite de formeSimple)
*/


#ifndef CLIENT_CERCLE_H
#define CLIENT_CERCLE_H

#include "FormeSimple.h"



class Cercle: public FormeSimple {
protected:

    Vecteur2D centre;
    double rayon;
public:


    /**
* @brief retourne Centre
* @return  Vecteur2D
*/
    const Vecteur2D &getCentre() const {
        return centre;
    }


    /**
* @brief modifie le centre du cercle par le centre re�u en parametre
* @param c : centre
*/
    void setCentre(const Vecteur2D &centre) {
        Cercle::centre = centre;
    }

    /**
* @brief Retourne le rayon
* @return rayon Cercle
*/
    double getRayon() const {
        return rayon;
    }

    /**
* @brief Constructeur vide  Cercle 
*
**/
    Cercle():FormeSimple(){}


    /**
* @brief Constructeur du Cercle
* @param couleur : couleur Cercle
* @param centre : centre Cercle
* @param centre : rayon Cercle
*/
    Cercle(unsigned int couleur, const Vecteur2D &centre, double rayon)	: FormeSimple(couleur), centre(centre){
        setRayon(rayon);
    }


    /**
* @brief Clonage du Cercle
* @return Forme2D* : Cercle identique au premier
*/
    Forme2D * Clone() const;

    /**
* @brief modifie le rayon du cercle par le rayon r recu en parametre
* @param rayon : le nouveau rayon
*/
    void setRayon(const double ray){
        if (ray > 0)  
            rayon = ray;
        else
            throw Erreur("Le rayon du cercle doit avoir une valeur positive, valeur n�gative impossible"); 
    }

    /**
* @brief Destructeur de Cercle (vide)
*/
    ~Cercle(){}


    /**
* @brief Aire du cercle
* @return double aire cercle
*/
    double AireForme()const;


    /**
* @brief Applique une transformation au Cercle (via class Transform)
* @param t
* @return  Cercle transform�e
*/
    Forme2D* trans(const Transform & t)const;


    /**
* @brief cast Cercle vers String
*/
    operator string() const;


    /**
* @brief Compare un Cercle avec un Cercle donn�
* @param Cercle a comparer
* @return Cercle 
*/
    const Cercle & operator = (const Cercle &c);


    /**
* @brief  Cercle vers format String (ligne avec toutes les infos du cercle)
* @return le  Cercle en string
*/
    string print() const;

};


#endif //CLIENT_CERCLE_H
