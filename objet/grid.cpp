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

    std:: cout << std::endl << "ecart x = " << x;

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


    for(double i= -(1000); i<(1000); i+= m_ecart)
    {
    //if(i != 0)
        svgout.addLine(i+(1000/2), 800, (1000/2)+getPointFuite(i), (800-m_ymax), m_col);
    }

    for(double z = 0; z < zmax; z += m_ecart)
    {
    //y += -((ecartMax - ecartMin)/zmax)*z+ecartMax;
        y += (1-z/zmax)*(ecartMax - ecartMin) +ecartMin;
        if(800-y >= 800-m_ymax)
        svgout.addLine(-1000, 800-y, 1000, 800-y, m_col);
    }

    svgout.addLine(-1000, 800-m_ymax, 1000, 800-m_ymax, m_col);
}

void Grid::remplir(double ecart, Couleur col)
{
    m_ecart= ecart;
    m_ymax= 270;
    m_col=col;
}
