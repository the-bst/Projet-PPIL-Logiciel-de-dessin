//
// Created by basti on 07/03/2021.
//




#include "Socket.h"

void Socket::connectTo(const string &Ip, int port) const{
    SOCKADDR_IN hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    hint.sin_addr.s_addr = inet_addr(Ip.c_str());

    int con = connect(sock, (SOCKADDR *)&hint, sizeof(hint));
    if (con == SOCKET_ERROR)
    {
        throw Erreur("Echec de la connexion au serveur");
    }
    else
    {
        cout << "Connexion au serveur reussie " << endl;

    }

}




void Socket::envoyer(const string & env) const {
    int sent = send(sock, env.c_str(), strlen(env.c_str()), 0);

    if (sent == SOCKET_ERROR)
    {
        throw Erreur("Envoi au serveur impossible" + WSAGetLastError());
        closesocket(sock);
        WSACleanup();
    }
    cout << "Envoi reussie " << endl;

}

void Socket::envoyer(const Forme2D &f) const {
    envoyer(f.print()+"\r\n");
}


Socket::Socket() {
    int familleAdresse = AF_INET; // AF_INET6
    int typeSocket = SOCK_STREAM;
    int protocole = IPPROTO_TCP;

    sock = socket(familleAdresse, typeSocket, protocole);

    if (sock == INVALID_SOCKET) {
        cerr << "creation socket impossible, Err#" << WSAGetLastError() << endl;
        WSACleanup();
        throw	Erreur("Echec de la creation de la socket");
    }
    cout << "Socket creee " << endl;
}

Socket::~Socket() {
    cout << "fermeture de la socket " << endl;
    closesocket(sock);
    WSACleanup();
}

