//
// Created by basti on 22/01/2021.
//

/**

*\file Forme2D.h
* @brief \class Forme2D ( abstraite, mère de tous les types de forme2D (segments, polygones, cercles, triangles)
*/

#ifndef CLIENT_FORME2D_H
#define CLIENT_FORME2D_H

#define _USE_MATH_DEFINES

#include <iostream>

#include <sstream>
#include <math.h>
#include <vector>
#include <exception>


#include "../Geom/Vecteur2D.h"
#include "../Erreur.h"



class Dessiner;
class Sauvegarde;
class Transform;
class ParseurFormes;
class ConnexionBdd;

using namespace std;

class Forme2D {

protected:

    unsigned int couleur;

public:

    /**
    * @brief Constructeur de Forme2D vide
    */
    Forme2D();


    /**
    * @brief Constructeur de forme2D
    * @param couleur : forme de couleur ...
    */
    Forme2D(unsigned int couleur);


    /**
    * @brief Constructeur par recopie Forme2D
    * @param f2d : Forme2D a recopier
    */
    Forme2D(const Forme2D &f2d);

    /**
    * @brief Clonage d'une Forme2D
    * @return Forme2D * : Nouvelle forme identique à une forme2D
    */
    virtual Forme2D *Clone() const = 0; // cloneur de forme (crée une forme identique)


    /**
    * @brief Destructeur de Forme2D (vide)
    */
    virtual ~Forme2D() {}


    /**
    * @brief renvoi la couleur de forme2D
    * @return  unsigned int
    */
    unsigned int getCouleur() const {
        return couleur;
    }

    /**
    * @brief définit la couleur d'une forme2D
    * @param c :  couleur ( RGB en valeur décimale)
    */
    void setCouleur(const unsigned int c) {
        couleur = c;
    }

    /**
    *  @brief sauvgarde une Fomre2D (sa définition) dans un fichier txt (et dans BDD)
    *  @param s :  Sauvegarde
    */
    void sauvegarde(const Sauvegarde &s) const;

    void sauvegardeBdd(const Sauvegarde & b)const;

    /**
    * @brief calcule de l'aire d'une forme2D
    * @return  double (aire de la forme2D)
    */
    virtual double AireForme() const = 0;  // calcul de l'air de la forme



    /**
    * @brief forme2D vers txt
    */
    virtual operator string() const;


    /**
    *  @brief Forme2D un format définis
    */
    virtual string print() const = 0;


    friend ostream &operator<<(ostream &f, const Forme2D &f2d);


    /**
    *  @brief Dessine une Forme2D
    *  @param d :  Dessine de la forme2D (class dessin)
    */
    void dessin(const Dessiner &d) const;


    /**
    * @brief appliqqe une transformation à une Forme2D
    * @param t : type de transformation à appliquer a la Forme2D
    * @return  Forme2D* : Forme2D transformée
    */
    virtual Forme2D *trans(const Transform &t) const = 0;  //transformation d'une forme

};


#endif //CLIENT_FORME2D_H
