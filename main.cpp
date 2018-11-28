#include <iostream>
#include "menu/console.h"
#include "menu/menu.h"
#include "scene.h"

int main()
{
    /** Initialisation
        Affichage d'une sc�ne avec param�tres al�atoires
        Affichage menu avec :
        -> s�lection du ou des plans dont le ou les param�tres pourront �tre modifi�s
        -> s�lection du ou des param�tres � modifier pour chaque plan
        --> param�tres : couleurs, densit�s, graines
        Rechargement de la sc�ne tant que l'utilisateur n'a pas s�lectionner quitter dans le menu
    */


	//int choix = menuStd();

	Scene retro;

	retro.initialiser();
	retro.dessiner();



    /*int densite = 0;
	std::mt19937 graine{509};
    Svgfile svgout;
    Couleur majeure = choixcouleur(graine);
    double dy=200;
    Grid maGrid(AskEcartLignes(densite, graine), majeure);
    double hauteur_plan = -200, largeur_plan = 800;
    Coords ptBG_plan {100, 800-270-1};
    Montagne monts;
    Soleil sol;
    double limiteY=800-270;

    Couleur col{24, 24, 24};
	double nbrEtoile = util::alea(200, 1500, graine);
    Coords	pos;

    if(limiteY >= 800 && limiteY <= 0)
        limiteY = 780;
    if(limiteY == 790)
        nbrEtoile += 200;

	svgout.addRectangle(0, 0, 1000, 0, 1000, 8000, 0, 800, col);

	for(auto i = 0; i < nbrEtoile; i++)
    {
        pos.setX(util::alea(5.0, 990.0, graine));
        pos.setY(util::alea(10.0, limiteY, graine));

        svgout.addDisk(pos.getX(), pos.getY(), 1, "white ");
    }

	svgout.addGradient("grad", 0, 0, 0, 100, 0, col, 1, 100, majeure);

    svgout.addRectangle(0, 800-270-dy, 1000, dy, "grad");

    maGrid.dessiner(svgout);

    sol.remplirCouleur(majeure,graine);
    sol.dessiner(svgout,graine);

    ///plan 2
    //void plan2(std::mt19937& graine)

    int test=util::alea(0,1, graine);
    std::vector<Immeuble*> ville;

    switch(test)
    {
        ///choix montagne
        case 0: monts.remplirAttr(majeure, Coords{largeur_plan, hauteur_plan}, ptBG_plan, util::alea(1, 4, graine));
            monts.initialiser(graine);
            monts.dessiner(svgout);
            break;
        ///choix immeuble
        case 1:
            int nbre = util::alea(10,20,graine);
            std::cout << "Nombre immeuble choisi " << nbre << std::endl;
            for (int i=0; i<nbre; i++)
            {
                Immeuble* nouv = new Immeuble;
                nouv->remplirCouleur(majeure, graine);
                nouv->dessiner(svgout, graine);
                ville.push_back(nouv);
            }
            break;
    }

    dessinerTraits(svgout);

    for (const auto& pr : ville)
        delete pr;

    monts.liberer();*/

    return 0;
}


