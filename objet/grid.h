#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <math.h>

#include "objet.h"

/*------------------------------------------*/

class Grid : public Objet
{
    public :
        Grid();
        //Grid(double ecart, Couleur col);
        void remplir(double ecart, Couleur col);
        void dessiner(Svgfile& svgout, std::mt19937& graine);
        double getPointFuite(double x);

    protected :
        double m_ecart;
        double m_ymax;
        Couleur m_col;
};

/*------------------------------------------*/

double AskEcartLignes(int densite, std::mt19937& graine);


#endif
