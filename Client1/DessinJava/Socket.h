//
// Created by basti on 07/03/2021.
//


/**
*\file Socket.h
* @brief \class Socket
*/


#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string>
#include <iostream>
#include <winsock.h>
#include "../Forme/Forme2D.h"

#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Socket
{

    SOCKET sock;

    /**
    * @brief prend un message et l'envoi en format text au serveur via la socket
    * @param env : message a envoy� au serveur
    */
    void envoyer(const string & env)const;

public:

    /**
    * @brief Constructeur d'un socket
    */
    Socket();

    /**
    * @brief Destructeur
    */
    ~Socket();

    /**
    * @brief Connexion au serveur (Ip, port)
    * @param Ip du serveur
    * @param port  du serveur
    */
    void connectTo(const string & Ip, int port)const;

    /**
    * @param f la forme a dessine
    * @brief prend une forme et l'envoi en format text au serveur via la socket
    */
    void envoyer(const Forme2D& f)const;

};


#endif //CLIENT_SOCKET_H
