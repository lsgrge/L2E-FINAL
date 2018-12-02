#include "coords.h"

Coords::Coords(double x, double y)
    : m_x{x}, m_y{y}
{ }

Coords::Coords()
    : m_x{0}, m_y{0}
{ }

void Coords::afficher() const
{
    std::cout << "(" << m_x << ", " << m_y << ")";
}

void Coords::saisir()
{
    std::cout << "Veuillez saisir x et y SVP : ";
    std::cin >> m_x >> m_y;
}

double Coords::getX() const
{
    return m_x;
}

double Coords::getY() const
{
    return m_y;
}

void Coords::setX(double x)
{
    m_x = x;
}

void Coords::setY(double y)
{
    m_y = y;
}

/// Somme vectorielle
Coords operator+(const Coords& c1, const Coords& c2)
{
    return { c1.m_x + c2.m_x, c1.m_y + c2.m_y };
}

/// Soustraction vectorielle
Coords operator-(const Coords& c1, const Coords& c2)
{
    return { c1.m_x - c2.m_x, c1.m_y - c2.m_y };
}

/// Produit vectoriel
double operator*(const Coords& c1, const Coords& c2)
{
    return c1.m_x*c2.m_x + c1.m_y*c2.m_y ;
}

/// Multiplication par un réel
Coords operator*(double m, const Coords& c)
{
    return { m*c.m_x, m*c.m_y };
}

void Coords::blinderPos()
{
    if(m_x<0) m_x=0;
    if(m_y<0) m_y=0;
}

void Coords::muter(const Coords l, const Coords h, std::mt19937& graine)
{
    m_x= m_x + util::alea(l.getX(), l.getY(), graine);
    m_y= m_y + util::alea(h.getX(), h.getY(), graine);
}
