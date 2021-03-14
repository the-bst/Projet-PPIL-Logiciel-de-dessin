//
// Created by basti on 22/02/2021.
//

/**
*\file FormeComp.h
* @brief \class FormeComp
*/



#ifndef CLIENT_FORMECOMP_H
#define CLIENT_FORMECOMP_H
#include "Forme2D.h"
#include <vector>
#include "CmpF2D.h"

using namespace std;

class Transform;


class FormeComp : public Forme2D{

    vector<Forme2D*> Formes;

public:
    /**
    * @brief Constructeur FormeComp vide
    */
    FormeComp();

    /**
    * @brief  Constructeur par copie de FormeComp
    */
    FormeComp(const FormeComp & f);

    /**
    * @brief Destructeur de FormeComp
    */
    ~FormeComp();

    /**
    * @brief Clone la FormeComplexe
    * @return Nouvelle Forme2D * FormeComplexe identique � la premi�re
    */
    Forme2D * Clone()const;

    /**
    * @brief r�cup�re les Forme2D qui compose  la FormeComp
    * @return tableau des Forme2D
    */
    const vector<Forme2D *>& getFormes()const{
        return Formes;
    }


    void setFormes(const vector<Forme2D *> &formes) {
        Formes = formes;
    }





    // verifie si la forme f est deja dans le tableau ou pas //////////////////////////////////




    /**
    * @brief v�ification de l'existance d'une forme
    * @param f2 : forme dont on v�rifie l'existance
    * @return Si la forme existe : iterator constant sur la forme recherch� 
    * @return Si la forme n'xiste pas : fin du tableau des formes
    */
    vector<Forme2D*>::const_iterator  existe(const Forme2D * f2 )const;

    /**
    * @brief op�rateur d'�galit�
    * @param f, FormeComp
	* @return FormeComp
    */
    const FormeComp & operator = (const FormeComp & f);



    // Ajout / sppr //////////////////////////////////////////////////////////////////////////

    
    /**
    * @brief  ajoute une nouvelle forme2D au tableau de forme complexe
    * @param f, Forme2D a ajouter
    * @return FormeComp
    */
    FormeComp & addForme2D(const Forme2D & f);


   
    /**
    *@brief supprime une forme f du tableau des formes
    * @param f : la forme a supprimer
	* @return : FormeComp - la forme supprim�e 
    */
    const FormeComp & supForme2D(const Forme2D & f);

    /**
    * @brief supprime la ieme forme du tableau des formes
    * @param i : l'indice de la forme a supprimer 
    * @return FormeComp - la forme supprim�e si la suppression est possible
    */
    const FormeComp & supForme2D(const unsigned int i);

////////////////////////////////////////////////////////////////////////////////////////////////
 
        /**
* @brief Aire dde FormeComp
* @return double aire FormeComp
*/
    double AireForme() const;



    /**
* @brief Applique une transformation a la FormeComp (via class Transform)
* @param t
* @return  FormeComp transform�e
*/
    Forme2D* trans(const Transform & t)const;


    /**
    * @brief cast la formeComp en String
    */
    operator string()const;




     /**
     * @brief FormeComp vers format String (ligne avec toutes les infos de la FormeComp)
     * @return la foremComp en string
     */
    string print() const;




};


#endif //CLIENT_FORMECOMP_H
