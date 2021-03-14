//
// Created by basti on 26/02/2021.
//
#include <iostream>
#include "ConnexionBdd.h"




ConnexionBdd::ConnexionBdd(const char* ipbase, const char* nomhote, const char* mdp, const char* nom, const int portbase)
:Sauvegarde(  ipbase, nomhote, mdp, nom,  portbase) {
}

void ConnexionBdd::visitor(const Forme2D& b) const {

    cout << "essai de client C/MySQL" << endl << endl;

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

 

   string requete = "INSERT INTO `forme` (`formeDet`) VALUES('"+b.print()+"')";

    OK = mysql_query(mysql, requete.c_str()); // int mysql_query(MYSQL *mysql, const char *query)

    if (OK == 0)
        cout << "insertion reussie dans la table Forme" << endl;
    else
        cout << "erreur dans la requete d'insertion : " << mysql_error(mysql) << endl;

    my_ulonglong clef = mysql_insert_id(mysql); // my_ulonglong mysql_insert_id(MYSQL *mysql) : pour r�cup�rer la clef primaire (g�n�r�e par autoincrement) de la ligne ins�r�e
                                            // renvoie 0 si la derni�re requ�te n'a pas g�n�r� de valeur autoincrement
    int derniere_clef = (int)clef;

    cout << "dernière clef générée : " << derniere_clef << endl;


    mysql_close(mysql);

}