#ifndef SOLEIL_H_INCLUDED
#define SOLEIL_H_INCLUDED

#include "objet.h"

class Soleil : public Objet
{
    public:
        Soleil();
        void remplirCouleur(const Couleur couleur, std::mt19937& graine);
        void dessinersoleil(Svgfile& svgout, std::mt19937& graine);
        void dessinerrect(Svgfile& svgout);
        void rectangle(Svgfile& svgout, double h1, double h2);
        void dessiner(Svgfile& svgout, std::mt19937& graine);
        void dessiner(Svgfile& svgout);
        void def_ton();

    protected:
        double m_rayon;
        Coords m_centre;
        Couleur m_couleur;
        Couleur m_secondaire;
};

#endif // SOLEIL_H_INCLUDED
