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
	retro.liberer();

    return 0;
}


