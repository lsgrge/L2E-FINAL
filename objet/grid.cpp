#include "grid.h"

/*------------------------------------------*/


double AskEcartLignes(int densite, std::mt19937& graine)
{
   double x = 0;
    /*
      do{
        std::cout << std::endl << "Quel ecart de lignes voulez vous : ";
        std::cin >> x;
      }while(x<=0 && x >= 1000);
    */

    if(densite == 0)//parametre de densite par défaut
        x = util::alea(30.0, 60.0, graine);
    if(densite == 1)//densité superieur choisi
        x = util::alea(15.0, 30.0, graine);
    if(densite == 2)//densite minimale choisi
        x = util::alea(60.0, 75.0, graine);

    std:: cout << std::endl << "Ecart case x = " << x;

    return x;

}


/*------------------------------------------*/
/*------------    Grid    ------------------*/
/*------------------------------------------*/


Grid::Grid()
{ }

/*Grid::Grid(double ecart, Couleur col)
    : m_ecart{ecart}, m_ymax{270}, m_col{col}
{ }*/


double Grid::getPointFuite(double x)
{
    double a;

    a = tan(x/(800));
    x = atan(a)*(800-m_ymax);

    return x;
}

void Grid::dessiner(Svgfile &svgout, std::mt19937& graine)
{
    //double x = AskEcartLignes(); à appeller avant en créant l'objet Grid
    double zmax = 500;
    double ecartMin = 1, ecartMax = m_ecart;
    double y = 0;

    Couleur m_colFin=choixcouleur(graine);
    while(m_col.getRouge()==m_colFin.getRouge() && m_col.getVert()==m_colFin.getVert() &&m_col.getBleu()==m_colFin.getBleu()) m_colFin=choixcouleur(graine);

    svgout.linearGradient("gradL", 0, 0, 100, 0, 0, m_col, 1, 100, m_colFin);

    for(double i= -(1000); i<(1000); i+= m_ecart)
    {
    //if(i != 0)
        svgout.addLineG(i+(1000/2), 800, (1000/2)+getPointFuite(i), (800-m_ymax), 2, "gradL");
    }

    for(double z = 0; z < zmax; z += m_ecart)
    {
    //y += -((ecartMax - ecartMin)/zmax)*z+ecartMax;
        y += (1-z/zmax)*(ecartMax - ecartMin) +ecartMin;
        if(800-y >= 800-m_ymax)
        svgout.addLineG(0, 800-y, 1000, 800-y+0.1, 2, "gradL");
    }

    svgout.addLine(0, 800-m_ymax, 1000, 800-m_ymax, 1, "gradL");
}

void Grid::remplir(double ecart, Couleur col)
{
    m_ecart= ecart;
    m_ymax= 270;
    m_col=col;
}
