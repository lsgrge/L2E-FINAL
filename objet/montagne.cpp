#include "montagne.h"

Montagne::Montagne()
{ }

void Montagne::remplirAttr(Couleur couleur, Coords dim, Coords ptBG, int nb)
{
    m_couleur=couleur;
    m_dim=dim;
    m_ptBG=ptBG;
    m_nb=nb;
}

void Montagne::dessiner(Svgfile& svgout, std::mt19937& graine)
{
    for(auto pt: m_montagnes)
        pt->dessiner(svgout);
}

void Montagne::initialiser(std::mt19937& graine)
{
    std::cout << m_nb << std::endl;

    int monts=m_nb+2;
    if(monts>7) monts=7;
    double tailleX = util::alea(5*250/monts, 5*500/monts, graine), tailleY = util::alea(tailleX/(4*monts), 75.0, graine);

    for(int i=0; i<m_nb; ++i)
    {
        Maillage* nouveau = new Maillage;
        nouveau->remplir(m_couleur, monts);
        m_montagnes.push_back(nouveau);
    }

    m_montagnes[0]->initialiser(tailleX, tailleY, m_ptBG, m_dim, graine);
    m_montagnes[0]->centrer(tailleX);

    for(size_t i=1; i< m_montagnes.size(); ++i)
        m_montagnes[i]->initialiser(tailleX, tailleY, m_ptBG, m_dim, graine);

    for(const auto pt : m_montagnes)
        pt->muter_sommet(tailleX, tailleY, m_dim, graine);
}

void Montagne::liberer()
{
   // std::cout << "Testtttt\n";
    for(const auto pt:m_montagnes)
    {
        pt->enlever_triangle();
        pt->enlever_sommet();
    }

    for(unsigned int i=0; i<m_montagnes.size(); ++i)
    {
        delete m_montagnes[i];
        m_montagnes.erase(m_montagnes.begin()+i);
    }
}
