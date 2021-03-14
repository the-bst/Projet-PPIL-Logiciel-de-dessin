//
// Created by basti on 26/02/2021.
//

#include "ChargeurBdd.h"

static   ChargeurBdd* chargeur = ChargeurBdd::getCharg();

ChargeurBdd* ChargeurBdd::getCharg() {
    return chargeur;
}


vector<Forme2D*> ChargeurBdd::charge(const char* ipbase, const char* nomhote, const char* mdp, const  char* nom, const int portbase, const ParseurFormes* p) {
    vector<Forme2D*> listeForme;
    cout << "Client C/MySQL" << endl << endl;
    MYSQL* mysql;			// structure repr�sentant le client MySQL
    mysql = mysql_init(NULL);		// cr�ation du client 
    cout << "mysql = " << mysql << endl;
    int OK = mysql_options(mysql, MYSQL_READ_DEFAULT_GROUP, "mes_options");		// on peut pr�ciser quelques options pour le client. cf. documents indiqu�s ci-dessus
                                                                         // si une erreur est survenue, la fonction renvoie une valeur non nulle
                                                                                // en l'absence d'erreur, renvoie 0
    cout << "OK = " << OK << endl;

    // nom de la base � requ�ter
    char* socket = NULL;
    unsigned long client_flag = 0;

    MYSQL* resultat = mysql_real_connect(mysql, ipbase, nomhote, mdp, nom, portbase, socket, client_flag);


    if (!resultat)
        cout << mysql_error(mysql);		// cette fonction indique toujours l'erreur qui s'est produite lors de la derni�re requ�te. Elle retourne un char *
    else
        cout << "connexion reussie" << endl;


    const char* requete = "SELECT `formedet` FROM `forme2d`.`forme`";

    OK = mysql_query(mysql, requete);

    if (OK == 0)
        cout << "selection reussie sur la table Forme" << endl;
    else
        cout << "erreur dans la requete de selection : " << mysql_error(mysql) << endl;

    MYSQL_RES* resultatSELECT = mysql_use_result(mysql); // MYSQL_RES *mysql_use_result(MYSQL *mysql)
// resultatSELECT permet d'acc�der aux lignes de la table r�sultat de la requ�te de s�lection

    if (resultatSELECT == NULL)
        cout << "la requete SELECT a echoue, l'erreur est : " << mysql_error(mysql) << endl;
    else
        cout << "parcourons des ligne du résultat de la requête" << endl;


    unsigned int nombreColonnes = mysql_num_fields(resultatSELECT); // unsigned int mysql_num_fields(MYSQL_RES *result)
        // nombre de colonnes de la table r�sultat

    MYSQL_ROW ligne; // c'est un tableau de pointeurs qui permet de boucler sur les lignes du r�sultat

    // on va boucler sur les lignes

    while (ligne = mysql_fetch_row(resultatSELECT))		// MYSQL_ROW mysql_fetch_row(MYSQL_RES *result) : renvoie NULL si il n'y a plus de nouvelle ligne dans le r�sultat
    {
        unsigned int i;
        unsigned long* longueurs = mysql_fetch_lengths(resultatSELECT); // tableau des longueurs des colonnes de cette ligne . unsigned long *mysql_fetch_lengths(MYSQL_RES *result)
        // le r�sultat est uniquement valable pour la ligne courante : la derni�re ligne acc�d�e par mysql_fetch_row

        //on parcourt une ligne du r�sultat
        // Attention !!! le contenu d'une case est fourni comme un tableau de caract�res pas n�cessairement termin� par '\0'

        for (i = 0; i < nombreColonnes; ++i)
        {
            int l = longueurs[i];
            char* element = new char[1 + l];
            strncpy(element, ligne[i], l); element[l] = '\0';

            
           

            Forme2D* forme = NULL;
            try {

                forme = p->parse(string(element));
            }
            catch (exception excep) {
                cout << excep.what();
            }
            if (forme != NULL) {
                listeForme.push_back(forme);
            }

            cout << element << ", ";

            delete[] element;


        }
        cout << endl;
    }

    mysql_free_result(resultatSELECT); // mysql_free_result(MYSQL_RES *result)
                                        // lib�re la m�moire associ�e au r�sultat de la s�lection

    
    return listeForme;

    mysql_close(mysql);
}