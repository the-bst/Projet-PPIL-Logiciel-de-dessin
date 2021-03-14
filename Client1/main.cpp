//
// Created by basti on 08/03/2021.
//


#define _CRTDBG_MAP_ALLOC
#define statut(a) (a==0?"OK":"ERREUR")
//#include <stdlib.h>
#include <crtdbg.h>
#include <string.h>
#include <iostream>

#include "Forme/Segment.h"
#include "Forme/Polygone.h"
#include "Forme/Triangle.h"
#include "Forme/Cercle.h"
#include "Forme/FormeComp.h"

#include "Parseurs/ParseurFormes.h"
#include "Parseurs/ParseurFormeComp.h"
#include "Parseurs/ParseurPoly.h"
#include "Parseurs/ParseurCercle.h"
#include "Parseurs/ParseurTri.h"
#include "Parseurs/ParseurSeg.h"

#include "Sauvegarde/SauveText.h"
#include "Sauvegarde/ConnexionBdd.h"

#include "Transformations/Homoth.h"
#include "Transformations/Rotation.h"
#include "Transformations/Transla.h"

#include "DessinJava/DessinJ.h"

#include "Sauvegarde/ChargeurForme.h"
#include "Sauvegarde/ChargeurBdd.h"

using namespace std;
void initialisationWSA();



int main()
{

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // port et adresse de destination (du serveur)
    int port = 8888;
    string ipAddress = "127.0.0.1";




    initialisationWSA();
    DessinJ  dessine = DessinJ(ipAddress, port);
    SauveText Save =  SauveText("Formes.txt");
   ConnexionBdd conn =  ConnexionBdd("127.0.0.1", "root", "", "forme2D", 3306 );

    //définition des couleurs ( RGB en valeur décimale)

    const int BLACK =  2097152;
    const int RED = 16711680;
    const int BLUE = 255;
    const int GREEN = 65280;


    try {

        int afficherbdd = 0;
        int affichertxt = 0;
        int afficherCollecForme = 0;

        cout << "afficher le contenu de la bdd ?   (1)" << endl;
        cin >> afficherbdd;

        if (afficherbdd == 1) {
            ChargeurBdd* chargeurB = ChargeurBdd::getCharg();

            ParseurFormes* parseur = new ParseurSeg(NULL);
            parseur = new ParseurCercle(parseur);
            parseur = new ParseurPoly(parseur);
            parseur = new ParseurTri(parseur);
            parseur = new ParseurFormeComp(parseur);

            vector<Forme2D*> v1 = chargeurB->charge("127.0.0.1", "root", "03061999", "forme2D", 3306, parseur);


            for (unsigned int i = 0; i < v1.size(); i++) {
                // cout << "bdd :" << *v1[i] << endl;
                v1[i]->dessin(dessine);

            }

        }
        else {}


        cout << "afficher le contenu de la sauvegarde texte ?   (1)" << endl;
        cin >> affichertxt;

        if (affichertxt == 1) {

            ChargeurForme* chargeur = ChargeurForme::getCharg();

            ParseurFormes* parseur = new ParseurSeg(NULL);
            parseur = new ParseurCercle(parseur);
            parseur = new ParseurPoly(parseur);
            parseur = new ParseurTri(parseur);
            parseur = new ParseurFormeComp(parseur);

            vector<Forme2D*> v = chargeur->charge("Formes.txt", parseur);


            for (unsigned int i = 0; i < v.size(); i++) {
                //cout << "txt : " << *v[i] << endl;
                v[i]->dessin(dessine);
            }

        }
        else {}



        cout << "afficher une collection de forme déjà construites ?   (1)" << endl;
        cin >> afficherCollecForme;
   
        if (afficherCollecForme == 1) {

            cout << " Formes__de_base_______________________________________________" << endl;

            Vecteur2D pt1(50, 50);
            Vecteur2D pt2(50, 90);
            Vecteur2D pt3(150, -90);
            Vecteur2D pt4(150, 50);
            Vecteur2D pt5(160, -70);
            Vecteur2D pt6(170, 280);
            Vecteur2D pt7(120, 90);
            Vecteur2D pt8(180, 390);
            Vecteur2D pt9(-180, -390);
            
            Segment S1(GREEN, Vecteur2D(10, 10), Vecteur2D(75,85));
            cout << "l'aire du Segment S1 est de " << S1.AireForme() << endl;          
            S1.dessin(dessine);

            Transla translation1(Vecteur2D(-50, 0));
            Forme2D* S2 = S1.trans(translation1);
            S2->dessin(dessine);

            Homoth homoth(Vecteur2D(10, 10), 20);
            Forme2D* S3 = S1.trans(homoth);
            S3->dessin(dessine);

            Cercle C1(GREEN, Vecteur2D(10, 10), 80);
            cout << "l'aire du Cercle C1 est de " << C1.AireForme() << endl;           
            C1.dessin(dessine);


            vector<Vecteur2D> pts;
            pts.push_back(pt1);
            pts.push_back(pt2);
            pts.push_back(pt3);
            pts.push_back(pt4);
            pts.push_back(pt8);
            pts.push_back(pt9);

            Polygone P1(BLUE, pts);
            cout << "l'aire du Rectangle P1 est de " << P1.AireForme() << endl;
            P1.dessin(dessine);


            vector<Vecteur2D> ptsT1;
            ptsT1.push_back(pt5);
            ptsT1.push_back(pt6);
            ptsT1.push_back(pt7);

            Polygone T1(RED, ptsT1);
            cout << "l'aire du Triangle T1 est de " << T1.AireForme() << endl;
            T1.dessin(dessine);
            

            // FORME COMP ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            FormeComp  FC1;
            FC1.addForme2D(P1).addForme2D(T1).addForme2D(C1);
            cout << "l'aire de la formeComp FC1 est de " << FC1.AireForme() << endl;
            FC1.dessin(dessine);
            

            FormeComp  FC2;
            FC2.addForme2D(P1).addForme2D(C1);
            cout << "l'aire de la formeComp FC2 est de " << FC2.AireForme() << endl;
            FC2.dessin(dessine);
            
                 

                 
            Transla translation(Vecteur2D(-50, 0));
            Forme2D * FC3=  FC1.trans(translation);
            cout << "l'aire de la formeComp FC3 est de " << FC3->AireForme() << endl;
            FC3->dessin(dessine);
            
                 
            Rotation rotation(0.90, Vecteur2D(0, 0));
            Forme2D* FC4 = FC3->trans(rotation);
            cout << "l'aire de la formeComp FC4 est de " << FC4->AireForme() << endl;
            FC4->dessin(dessine);
            


            
                
         }


        //SAUVEGARDE  ///////////////////////////////////////////////////////////////////////////////////////////////

       // S1.sauvegarde(Save);
        //S1.sauvegarde(conn);



    }


    catch (Erreur )
    {
        cout << "Erreur du programme" << endl;



    }
    system("pause");

    return 0;
}

void initialisationWSA() {
    WSADATA WSAData;
    WORD version = MAKEWORD(2, 0);
    int wsResult = WSAStartup(version, &WSAData);
    if (wsResult) // 0 no erreur else erreur
    {
        throw Erreur("impossible de demarrer winsock");

    }
    cout << "succes" << endl;

}

