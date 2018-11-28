#ifndef TRIANGLE_CPP_INCLUDED
#define TRIANGLE_CPP_INCLUDED

#include "triangle.h"

Triangle::Triangle(Sommet* sommet0, Sommet* sommet1, Sommet* sommet2, Couleur couleur_fill, Couleur couleur_stroke)
        :m_sommets{sommet0, sommet1, sommet2}, m_couleur_fill{couleur_fill}, m_couleur_stroke{couleur_stroke}
{ }

Triangle::Triangle()
{ }

Triangle::~Triangle()
{
    for(size_t i=0; i<3; ++i)   m_sommets[i]->~Sommet();
    m_couleur_fill.~Couleur();
    m_couleur_stroke.~Couleur();
}

void Triangle::afficher() const
{
    for(size_t i=0; i<3; ++i) m_sommets[i]->afficher();
    m_couleur_fill.afficher();
}

void Triangle::dessiner(Svgfile& svgout)
{
    svgout.addTriangle(m_sommets[0]->getPosition().getX(), m_sommets[0]->getPosition().getY(),
                       m_sommets[1]->getPosition().getX(), m_sommets[1]->getPosition().getY(),
                       m_sommets[2]->getPosition().getX(), m_sommets[2]->getPosition().getY(),
                       m_couleur_fill, 2, m_couleur_stroke);

}

bool Triangle::getSelect() const
{
    for(size_t i=0; i<3; ++i)
        if(m_sommets[i]->getSelect()== 0)
            return false;

    return true;
}

void Triangle::remplir(std::vector<Sommet*> vec, const int s0, const int s1, const int s2,
                       Couleur couleur_fill, Couleur couleur_stroke)
{
    m_sommets[0]=vec[s0];
    m_sommets[1]=vec[s1];
    m_sommets[2]=vec[s2];
    m_couleur_fill=couleur_fill;
    m_couleur_stroke=couleur_stroke;
}

#endif // TRIANGLE_CPP_INCLUDED
