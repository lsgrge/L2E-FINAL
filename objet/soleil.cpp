#include "soleil.h"

Soleil::Soleil()
{ }

void Soleil::def_ton()
{
    if (m_secondaire.getRouge() == 255)
        m_secondaire.setRouge(20);

    if (m_secondaire.getVert() == 255)
        m_secondaire.setVert(20);

    if (m_secondaire.getBleu() == 255)
        m_secondaire.setBleu(20);
}

void Soleil::dessinersoleil(Svgfile& svgout, std::mt19937& graine)
{
    int choix=util::alea(1, 2, graine);
    std::cout << "choix pour le soleil (1.ton / 2.degrade) :" << choix << std::endl;

    if(choix == 1)
        def_ton();

    if(m_couleur.getRouge() == 255 && m_couleur.getVert() == 255 && m_couleur.getBleu() == 255)
        m_couleur = choixcouleur(graine);

    svgout.linearGradient("gradS", 0, 0, 10, 100, 0, m_couleur, 1, 100, m_secondaire);
    svgout.addSoleil(m_centre.getX(), m_centre.getY(), m_rayon, "gradS");

}

void Soleil::dessinerrect(Svgfile& svgout)
{
    double rayon_div20 = m_rayon / 20;

    rectangle(svgout,-rayon_div20,-3.5*rayon_div20);
    rectangle(svgout,-5*rayon_div20,-7*rayon_div20);
    rectangle(svgout,-8.5*rayon_div20,-10*rayon_div20);
    rectangle(svgout,-11.5*rayon_div20,-12.5*rayon_div20);
    rectangle(svgout, -13.8*rayon_div20,-14.5*rayon_div20);
    rectangle(svgout,-15.7*rayon_div20,-16.2*rayon_div20);
    rectangle(svgout,-17.5*rayon_div20,-17.8*rayon_div20);
}

void Soleil::rectangle(Svgfile& svgout, double h1, double h2)
{
    Couleur col_rect{24, 24, 24};
    svgout.addRectangle(m_centre.getX()-m_rayon,m_centre.getY()+h1,
                        m_centre.getX()+m_rayon,m_centre.getY()+h1,
                        m_centre.getX()+m_rayon,m_centre.getY()+h2,
                        m_centre.getX()-m_rayon,m_centre.getY()+h2,
                        col_rect);
}

void Soleil::dessiner(Svgfile& svgout, std::mt19937& graine)
{
    dessinersoleil(svgout, graine);
    dessinerrect(svgout);
}

void Soleil::remplirCouleur(const Couleur couleur, std::mt19937& graine)
{
    m_rayon = 200;
    m_centre = {500,300};
    m_couleur = couleur;
    m_secondaire = choixcouleur(graine);
    std::cout << "la deuxieme couleur : ";
    m_secondaire.afficher();
}

void Soleil::dessiner(Svgfile& svgout) //a cause de l'heritage
{ }
