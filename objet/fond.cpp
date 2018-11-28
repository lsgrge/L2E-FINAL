#include "fond.h"
#include "../graphisme/couleur.h"
#include "../graphisme/lexiquec.h"

void dessinerFond(Svgfile& svgout, double limiteY)
{
	Couleur col{24,24,24};
	double nbrEtoile = util::alea(200, 1500);
    Coords	pos;

    if(limiteY >= 800 && limiteY <= 0)
        limiteY = 780;

    if(limiteY == 790)
        nbrEtoile += 200;

	svgout.addRectangle(0, 0, 1000, 0, 1000, 800, 0, 800, col);

	for(auto i = 0; i < nbrEtoile; i++)
    {
        //pos.afficher();
        pos.setX(util::alea(5.0, 990.0));
        pos.setY(util::alea(10.0, limiteY));

        svgout.addDisk(pos.getX(), pos.getY(), 1, "white");
    }


}
