#ifndef MONTAGNE_H_INCLUDED
#define MONTAGNE_H_INCLUDED

#include "../geometrie/maillage.h"
#include "objet.h"

class Montagne : public Objet
{
    public :
        Montagne();
        void remplirAttr(Couleur couleur, Coords dim, Coords ptBG, int nb);
        void dessiner(Svgfile& svgout, std::mt19937& graine);
        void initialiser(std::mt19937& graine);
        void liberer();

    private :
        Couleur m_couleur;
        Coords m_dim;
        Coords m_ptBG;
        int m_nb;
        std::vector<Maillage*> m_montagnes;

};

#endif // MONTAGNE_H_INCLUDED
