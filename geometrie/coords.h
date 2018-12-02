#ifndef COORDS_H_INCLUDED
#define COORDS_H_INCLUDED

#include "../util/util.h"
#include <iostream>

class Coords
{
    public :
        Coords(double x, double y);
        Coords();

        void afficher() const;
        void saisir();
        void blinderPos();
        void muter(const Coords l, const Coords h, std::mt19937& graine);

        double getX() const;
        double getY() const;

        void setY(double y);
        void setX(double x);

        /// Somme vectorielle
        friend Coords operator+(const Coords& c1, const Coords& c2);

        /// Soustraction vectorielle
        friend Coords operator-(const Coords& c1, const Coords& c2);

        /// Produit vectoriel
        friend double operator*(const Coords& c1, const Coords& c2);

        /// Multiplication par un réel
        friend Coords operator*(double m, const Coords& c);


    private :
        double m_x;
        double m_y;
};


#endif // COORDS_H_INCLUDED
