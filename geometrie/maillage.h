#ifndef MAILLAGE_H_INCLUDED
#define MAILLAGE_H_INCLUDED

#include "triangle.h"
#include "../util/util.h"
#include <vector>

class Maillage
{
    public:
        void remplir(Couleur couleur, int nb);
        void afficher_sommets();
        void afficher_triangle();
        void ajouter_sommet(const double x, const double y);
        void ajouter_triangle(const int rang0, const int rang1, const int rang2, Couleur couleur);
        void enlever_sommet();
        void enlever_triangle();
        void dessiner(Svgfile& svgout);
        void dessiner_triangle(Svgfile& svgout);
        void selectionner_sommetM(double nb);
        void selectionner_sommetH(double nb);
        void selectionner1(const bool yes=true);
        void selectionnerTout(const bool yes=true);
        void initialiser(double x, double y, Coords pt0, Coords dim, std::mt19937& graine);
        void muter_sommet(double x, double y, Coords dim, std::mt19937& graine);
        void centrer(double x);

    private:
        Couleur m_couleur_flashy;
        Couleur m_couleur_fonce;
        Couleur m_couleur_claire;
        int m_nb;

        std::vector<Sommet*> m_l_sommets;
        std::vector<Triangle*> m_triangles;
};

#endif // MAILLAGE_H_INCLUDED
