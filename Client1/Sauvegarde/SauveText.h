
/**
* \file SauveTxt.h
* @brief class SauveTxt ( prend une forme et la sauvegarde sous un format txt) (hérite de Sauvegarde)
*/

#pragma once
#include "Sauvegarde.h"

class SauveText : public Sauvegarde{

public :

    /*
    * @brief Constructeur de Sauvegarde
    * @param nom_f : le nom du fichier ou on veut faire l'enregistrement
    */
	SauveText(const string & nom_f);


    virtual ~SauveText();

    /**
    * @brief applique la sauegarde au format text d'une forme
    * @param f :la forme2D à sauvegarder
    */
	void visitor(const Forme2D & f)const;

  

};
