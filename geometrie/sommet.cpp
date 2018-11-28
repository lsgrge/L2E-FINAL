#include "sommet.h"

Sommet::Sommet(Coords position, bool select)
    :m_position{position}, m_select{select}
{ }

Sommet::~Sommet()
{
    m_position.~Coords();
}

Coords Sommet::getPosition() const
{
    return {m_position.getX(), m_position.getY()};
}

void Sommet::afficher() const
{
    m_position.afficher();
    std::cout << "Le sommet est selectionne : " << m_select << std::endl;
}

void Sommet::selectionner(const bool yes)
{
    m_select= yes;
}

bool Sommet::getSelect() const
{
    return m_select;
}

void Sommet::remplir(double x, double y)
{
    m_position= Coords{x,y};
}

void Sommet::blinderPos()
{
    m_position.blinderPos();
}

void Sommet::muter(const Coords l, const Coords h, std::mt19937& graine)
{
    m_position.muter(l, h, graine);
}

void Sommet::deplacer(const double pos_y)
{
    m_position.setY(pos_y);
}

void Sommet::translater(double dx)
{
    m_position= {m_position.getX() + dx, m_position.getY()};
}
