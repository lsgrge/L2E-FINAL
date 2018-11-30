#ifndef PALMIER_H_INCLUDED
#define PALMIER_H_INCLUDED

#include "objet.h"

class Palmier : public Objet
{
    public :
        Palmier();
        void remplir(Couleur couleur);
        void initialiser(std::mt19937& graine);
        void dessiner(Svgfile& svgout, std::mt19937& graine);
        void liberer();

    private :
        Couleur m_couleur;
        std::vector<Coords*> m_architecture;
};

#endif // PALMIER_H_INCLUDED
