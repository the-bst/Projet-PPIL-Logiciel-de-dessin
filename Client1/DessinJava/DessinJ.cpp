//
// Created by basti on 07/03/2021.
//

#include "DessinJ.h"

DessinJ::DessinJ(const string &ip,const int port) :Dessiner(){
    socket.connectTo(ip, port);
}

DessinJ::~DessinJ(){

}

void DessinJ::visitor(const Forme2D &f) const {
    socket.envoyer(f);
}




