#include "Sauvegarde.h"

Sauvegarde::Sauvegarde(const string &nom_f):NFichier(nom_f) {
}


Sauvegarde::Sauvegarde(const char * ipbase,const char* nomhote, const char* mdp, const char* nom, const int portbase)
	:ipbase(ipbase), nomhote(nomhote), mdp(mdp), nom(nom),portbase(portbase){}

Sauvegarde::~Sauvegarde() {

}
