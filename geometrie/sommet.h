#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include "coords.h"

class Sommet
{
    public:
        Sommet(Coords position={0,0}, bool select=false);
        ~Sommet();

        void afficher()const;
        void remplir(double x, double y);
        void muter(const Coords l, const Coords h, std::mt19937& graine);
        void deplacer(const double pos_y);
        void blinderPos();
        void selectionner(const bool yes=true);

        Coords getPosition() const;
        bool getSelect() const;
        void translater(double dx);

    private:
        Coords m_position;
        bool m_select;
};

#endif // SOMMET_H_INCLUDED
