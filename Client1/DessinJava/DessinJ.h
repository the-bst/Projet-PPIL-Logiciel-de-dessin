//
// Created by basti on 07/03/2021.
//

/**
* \file DessinJ.h
* @brief Class DessinJ ( Abstraite, prend une forme2D pour la dessiner (vers Java))
*/

#ifndef CLIENT_DESSINJ_H
#define CLIENT_DESSINJ_H

#include "Socket.h"
#include "Dessiner.h"

class DessinJ : public Dessiner {
    Socket socket;
public:

    /**
    *@brief Constructeur de DessinJ
    * @param ip : Ip serveur
    * @param port : port du serveur
    */
    DessinJ(const string &ip, const int port);

    /**
    *@brief Destructeur de DessinJ
    */
    virtual ~DessinJ();

    /**
    *création dessin vers java avec socket
    * @param f la forme2D a dessiner
    */
    void visitor(const Forme2D &f) const;

};


#endif //CLIENT_DESSINJ_H
