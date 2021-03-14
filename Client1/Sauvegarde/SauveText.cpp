#include "SauveText.h"
#include <fstream>
#include "../Erreur.h"

using namespace std;


void SauveText::visitor(const Forme2D & nom_f) const
{
	ofstream fichier(NFichier, ios::out | ios::app);
	if (fichier) {
		fichier << nom_f.print() << endl;
		fichier.close();
	}
	else
		throw Erreur("Problème d'ouverture du fichier");
	
}

SauveText::SauveText(const string &nom_f):Sauvegarde(nom_f){}


SauveText::~SauveText() {

}




