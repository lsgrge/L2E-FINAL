#ifndef MAILLAGE_CPP_INCLUDED
#define MAILLAGE_CPP_INCLUDED

#include "maillage.h"

void Maillage::afficher_sommets()
{
    for(size_t i=0; i<m_l_sommets.size(); ++i)
    {
        std::cout << "Sommet numero " << i << " : ";
        m_l_sommets[i]->afficher();
    }
}

void Maillage::afficher_triangle()
{
    for(size_t i=0; i<m_triangles.size(); ++i)
    {
        std::cout << "Triangle numero " << i << " : ";
        m_triangles[i]->afficher();
    }
}

void Maillage::enlever_sommet()
{
    for(unsigned int i=0; i<m_l_sommets.size(); ++i)
    {
        delete m_l_sommets[i];
        m_l_sommets.erase(m_l_sommets.begin()+i);
    }
}

void Maillage::enlever_triangle()
{
    for(unsigned int i=0; i<m_triangles.size(); ++i)
    {
        delete m_triangles[i];
        m_triangles.erase(m_triangles.begin()+i);
    }
}

void Maillage::dessiner(Svgfile& svgout)
{
    dessiner_triangle(svgout);
}

void Maillage::dessiner_triangle(Svgfile& svgout)
{
    for(size_t i=0; i<m_triangles.size(); ++i)  m_triangles[i]->dessiner(svgout);
}

void Maillage::selectionnerTout(const bool yes)
{
   for (const auto& pt: m_l_sommets) pt->selectionner(yes);
}

void Maillage::initialiser(double x, double y, Coords pt0, Coords dim, std::mt19937& graine)
{
    double largeur= x/m_nb, profondeur=y, pos;

    ///blindage pour que cela ne dépasse pas le pt (x, 900)
    do{
        pos=util::alea(0.0, dim.getX(), graine);
    }while(pos +pt0.getX()+x > 900);


    ///sommet de la ligne supérieure
    for(size_t i=0; i<=x; i+=largeur)
        ajouter_sommet(pos+ pt0.getX()+i, pt0.getY()-profondeur);

    ///sommet de la ligne du milieu
    for(size_t i=largeur/2; i<=x-largeur/2; i+=largeur)
        ajouter_sommet(pos +pt0.getX()+i, pt0.getY()-profondeur/2);

    ///sommet de la ligne supérieure
    for(size_t i=0; i<=x; i+=largeur)
        ajouter_sommet(pos +pt0.getX()+i, pt0.getY());

    for(int i=0; i<m_nb; ++i)
    {
        ajouter_triangle(i, 1+m_nb+i, (2*m_nb)+1+i, m_couleur_fonce);
        ajouter_triangle(i+1, 1+m_nb+i, 2*(m_nb+1)+i, m_couleur_fonce);
        ajouter_triangle(1+m_nb+i, (2*m_nb)+1+i, 2*(m_nb+1)+i, m_couleur_claire);
    }
}

void Maillage::ajouter_sommet(const double x, const double y)
{
    Sommet* nouveau = new Sommet;
    nouveau->remplir(x, y);
    m_l_sommets.push_back(nouveau);
}

void Maillage::ajouter_triangle(const int rang0, const int rang1, const int rang2, Couleur couleur)
{
    Triangle* nouveau = new Triangle;
    nouveau->remplir(m_l_sommets, rang0, rang1, rang2, couleur, m_couleur_flashy);
    m_triangles.push_back(nouveau);
}

void Maillage::remplir(Couleur couleur, int nb)
{
    m_couleur_flashy = couleur;

    uint8_t r=0, v=0, b=0;

    if(m_couleur_flashy.getRouge() >=255)  r+=50;
    if(m_couleur_flashy.getVert() >=255)   v+=50;
    if(m_couleur_flashy.getBleu() >=255)   b+=50;

    m_couleur_fonce= Couleur {r, v, b};

    if(m_couleur_fonce.getRouge() >=50)  r+=30;
    if(m_couleur_fonce.getVert() >=50)   v+=30;
    if(m_couleur_fonce.getBleu() >=50)   b+=30;

    m_couleur_claire = Couleur {r, v, b};

    m_nb=nb;
}

void Maillage::muter_sommet(double x, double y, Coords dim, std::mt19937& graine)
{
    double hauteur=-y-10;

    if(hauteur-y/2<dim.getY())    hauteur =dim.getY()+y/2;

    selectionner_sommetM(m_nb);

    for(size_t i=0; i<m_l_sommets.size(); ++i)
        if (m_l_sommets[i]->getSelect() !=0)
            m_l_sommets[i]->muter(Coords {-x/(5*m_nb), x/(5*m_nb)}, Coords{hauteur, -y-5}, graine);

    selectionnerTout(false);
    selectionner_sommetH(m_nb);

    hauteur=-2*x;

    if(hauteur-y<dim.getY())    hauteur = dim.getY()+y;

    for(size_t i=0; i<m_l_sommets.size(); ++i)
        if (m_l_sommets[i]->getSelect() !=0)
            m_l_sommets[i]->muter(Coords {-x/(6*m_nb), x/(6*m_nb)}, Coords{hauteur, -y-5}, graine);

    selectionnerTout(false);

    m_l_sommets[0]->deplacer(800-270-1);
    m_l_sommets[m_nb]->deplacer(800-270-1);
}

void Maillage::selectionner_sommetM(double nb)
{
    for(size_t i=nb+1; i<= 2*nb; ++i)
        m_l_sommets[i]->selectionner();
}

void Maillage::selectionner_sommetH(double nb)
{
    for(size_t i=1; i< nb; ++i)
        m_l_sommets[i]->selectionner();
}

void Maillage::centrer(double x)
{
    double dx = 500-(m_l_sommets[0]->getPosition().getX()+x/2);

    for(const auto pt: m_l_sommets)
        pt->translater(dx);
}

#endif // MAILLAGE_CPP_INCLUDED
