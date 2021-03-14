//
// Created by basti on 07/03/2021.
//

#include "ParseurFormeComp.h"
#include "../Forme/FormeComp.h"
#include "ParseurCercle.h"
#include "ParseurTri.h"
#include "ParseurSeg.h"
#include "ParseurPoly.h"

ParseurFormeComp::ParseurFormeComp(ParseurFormes * f)
        :ParseurFormes(f)
{
}

ParseurFormeComp::~ParseurFormeComp()
{
}

Forme2D * ParseurFormeComp::parse1(const string & txt) const
{

    int indicePolygone = txt.find("FormeComplexe", 0);

    if (indicePolygone == std::string::npos)
        return NULL;
    else {
        const char * chaine = txt.c_str();
        // r�cup�ration de la couleur
        int couleur;
        sscanf_s(chaine, "FormeComplexe couleur %d", &couleur);

        int indiceAccolladeO = txt.find("[");

        int indiceAccolladeF = txt.rfind("]");

        string ligne = txt.substr(indiceAccolladeO + 1, indiceAccolladeF - indiceAccolladeO - 1);

        vector<Forme2D*> v;
        vector<string> res = decoupage(ligne, '|');

        ParseurFormes * p = new ParseurSeg(NULL);
        p = new ParseurCercle(p);

        p = new ParseurPoly(p);
        p = new ParseurFormeComp(p);



        for (unsigned int  i = 0; i < res.size(); i++)
        {
            Forme2D * forme = p->parse(res[i]);
            v.push_back(forme);
        }

        FormeComp * f = new FormeComp();
        f->setCouleur(couleur);
        for (unsigned int  i = 0; i < v.size(); i++)
            f->addForme2D(*v[i]);


        return f;
    }
}