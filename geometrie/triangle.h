#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include <vector>
#include <iostream>
#include "sommet.h"
#include "../graphisme/couleur.h"

class Triangle
{
    public:
        Triangle(Sommet* sommet0, Sommet* sommet1, Sommet* sommet2,
                 Couleur couleur_fill={0,0,0}, Couleur couleur_stroke={0,0,0});
        Triangle();
        ~Triangle();

        void afficher() const;
        void remplir(const std::vector<Sommet*> vec, const int s0, const int s1, const int s2,
                     Couleur couleur_fill={0,0,0}, Couleur couleur_stroke={0,0,0});
        void dessiner(Svgfile& svgout);

        bool getSelect() const;

    private:
        Sommet* m_sommets[3];
        Couleur m_couleur_fill;
        Couleur m_couleur_stroke;
};

#endif // TRIANGLE_H_INCLUDED
