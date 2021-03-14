//
// Created by basti on 25/02/2021.
//

#include "ParseurFormes.h"

ParseurFormes::ParseurFormes(ParseurFormes * suivant): suivant(suivant){}

Forme2D * ParseurFormes::parse(const string & f) const{

    Forme2D * res;

    res = this->parse1(f);
    if (res)
        return res;
    else
    if (this->suivant)

        return this->suivant->parse(f);
    else
        return NULL;
}

vector <string> ParseurFormes::decoupage(string txt, char coupe) {
    vector<string> tab;
    istringstream f(txt.c_str());
    string s;
    while (getline(f, s, coupe)) {
        tab.push_back(s);
    }
    return tab;
}


