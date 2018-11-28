#ifndef IMMEUBLE_H_INCLUDED
#define IMMEUBLE_H_INCLUDED

#include "objet.h"
#include<vector>

class Immeuble : public Objet
{
    public :
        Immeuble();
        void remplirCouleur(const Couleur couleur, std::mt19937& graine);
        int calculnbligne();
        int calculnbcolonne();
        void dessinerFenetre(Svgfile& svgout, std::mt19937& graine);
        void dessinerRect(Svgfile& svgout);
        void dessiner(Svgfile& svgout, std::mt19937& graine);
        void dessiner(Svgfile& svgout);
        void verif();
        Coords choixcoord(std::mt19937& graine);
        Couleur defcouleur();
        int choixhauteur(std::mt19937& graine);
        int choixlargeur(std::mt19937& graine);

    private :
        int m_hauteur;
        int m_largeur;
        Couleur m_couleur;
        Coords m_posBG;
        Couleur m_secondaire;
};

#endif // IMMEUBLE_H_INCLUDED
