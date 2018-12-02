#ifndef PALMIER_H_INCLUDED
#define PALMIER_H_INCLUDED

#include "objet.h"

class Palmier : public Objet
{
    public :
        Palmier();
        void remplir(Couleur couleur);
        void initialiser(std::mt19937& graine, double dep, Coords posBG={400, 800}, double signe=1, double taille = 1);
        void dessiner(Svgfile& svgout, std::mt19937& graine);
        void liberer();

    private :
        Couleur m_couleur;
        std::vector<Coords*> m_architecture;
};

#endif // PALMIER_H_INCLUDED
