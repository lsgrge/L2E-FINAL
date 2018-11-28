#include "couleur.h"
#include "lexiquec.h"

Couleur::Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu)
    : m_rouge{rouge}, m_vert{vert}, m_bleu{bleu}
{ }

Couleur::Couleur()
    : Couleur(0, 0, 0) // Délégation de constructeur
{ }

void Couleur::afficher() const
{
    std::cout << "(" << (int)m_rouge << ", " << (int)m_vert << ", " << (int)m_bleu << ")" << std::endl;
}

Couleur::operator std::string() const
{
    return Svgfile::makeRGB(m_rouge, m_vert, m_bleu);
}

Couleur operator+(const Couleur& c1, const Couleur& c2)
{
    uint8_t r = c1.m_rouge + c2.m_rouge;
    uint8_t v = c1.m_vert + c2.m_vert;
    uint8_t b = c1.m_bleu + c2.m_bleu;

    return Couleur(r,v,b);
}

uint8_t Couleur::getRouge()
{
    return m_rouge;
}

uint8_t Couleur::getVert()
{
    return m_vert;
}

uint8_t Couleur::getBleu()
{
    return m_bleu;
}


void Couleur::setRouge(uint8_t r)
{
    m_rouge = r;
}

void Couleur::setVert(uint8_t v)
{
    m_vert = v;
}

void Couleur::setBleu(uint8_t b)
{
    m_bleu = b;
}

Couleur choixcouleur(std::mt19937& graine)
{
   Couleur ok;
   ok = dicocouleur[ util::alea(0, dicocouleur.size()-1, graine) ];
   return ok;
}
