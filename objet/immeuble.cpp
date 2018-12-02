#include "immeuble.h"

Immeuble::Immeuble()
{ }

int Immeuble::calculnbligne()
{
    int nbligne = ( m_hauteur / (11) );
    return nbligne;
}

int Immeuble::calculnbcolonne()
{
    int nbcolonne = ( m_largeur / (11) );
    return nbcolonne;
}

Coords Immeuble::choixcoord(std::mt19937& graine)
{
   Coords ok;
   ok.setX(util::alea(100,(700-m_largeur), graine));
   ok.setY(800-270-3);
   return ok;
}

int Immeuble::choixhauteur(std::mt19937& graine)
{
   int hauteur = util::alea(75, 210, graine);
   return hauteur;
}

int Immeuble::choixlargeur(std::mt19937& graine)
{
    int largeur = util::alea(45, 210, graine);
    return largeur;
}

Couleur Immeuble::defcouleur()
{
    Couleur fonce;

    if (m_couleur.getRouge() != 0)
        fonce.setRouge(85);

    if (m_couleur.getBleu() != 0)
        fonce.setBleu(85);

    if (m_couleur.getVert() != 0)
        fonce.setVert(85);

    return fonce;
}

void Immeuble::verif()
{
    while(calculnbligne()*11 +4 != m_hauteur)
        m_hauteur-=1;

    while(calculnbcolonne()*11 +4 != m_largeur)
        m_largeur-=1;
}

void Immeuble::dessinerFenetre(Svgfile& svgout, std::mt19937& graine)
{

    Couleur gris{24,24,24};

    int ecart = 4;
    int fenetre = 7;
    int dec = 11;
    double ratio = 0.3;

    for (int j = m_posBG.getY()- ecart; j> m_posBG.getY()-m_hauteur ; j = j - dec)
    {
        for (int i = m_posBG.getX()+ ecart; i<m_posBG.getX()+m_largeur; i = i + dec)
        {
            if (util::alea(0.0,1.0,graine) <= ratio ) ///fenetres allumees
            {
                svgout.addRectangle(i, j,
                                    i, j-fenetre,
                                    i+fenetre, j-fenetre,
                                    i+fenetre, j,
                                    m_couleur, 1, "black");
            }
            else //fenetres eteintes
            {
                svgout.addRectangle(i, j,
                                    i, j-fenetre,
                                    i+fenetre, j-fenetre,
                                    i+fenetre, j,
                                    gris, 1, "black");
            }
        }
    }
}

void Immeuble::dessinerRect(Svgfile& svgout) //pour faire la base de l'immeuble
{
    svgout.addRectangle(m_posBG.getX(), m_posBG.getY(),
                        m_posBG.getX(), m_posBG.getY()-m_hauteur,
                        m_posBG.getX()+m_largeur, m_posBG.getY()-m_hauteur,
                        m_posBG.getX()+m_largeur, m_posBG.getY(),
                        m_secondaire, 2, "black");
}

void Immeuble::dessiner(Svgfile& svgout, std::mt19937& graine)
{
    verif();
    dessinerRect(svgout);

    ///pour savoir le nombre de lignes et de colonnes
    //int nbligne = calculnbligne();
    //int nbcolonne = calculnbcolonne();
    //std::cout << nbligne << " + "<< nbcolonne <<std::endl;

    dessinerFenetre(svgout,graine);
}

void Immeuble::remplirCouleur(const Couleur couleur, std::mt19937& graine)
{
    m_couleur=couleur;
    m_hauteur=choixhauteur(graine);
    m_largeur=choixlargeur(graine);
    m_posBG=choixcoord(graine);
    m_secondaire=defcouleur();
}

void Immeuble::dessiner(Svgfile& svgout)
{ }
