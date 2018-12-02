#include "menu.h"
#include <string>

void openFile()
{
	std::ifstream ifs{"menu/menu.txt"};
	if(!ifs)
		std::cerr << "erreur fichier menu.txt";
	else
	{
		char c;
		while(!ifs.eof())
		{
			ifs.get(c);
			std::cout << c;
		//	ifs.seekg(1, ios::cur);
		}
	}
}

/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/

int menuStd()
{
	int action;
	int curseur;
	Console* pConsole = NULL;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();
	pConsole->setColor(COLOR_GREEN);
	do
    {
        system("cls");
		openFile();
        //cette boucle affiche un curseur pour choisir son menu et supprime le précedend
		curseur = interaction(7, 10, 4, pConsole, 2);

        switch (curseur)
        {
            case 0: //scene alea

                action = 1;
                break;
			case 1: //selec plan modif
				action = selectPlanModif(pConsole);
				break;
			case 2: //Save
				action = 3;
				break;
            case 3: //load Save
				action = 4;
				break;
            case 4:	//Quitter
                action = 10;
                break;
        }

    }while (!action);

    Console::deleteInstance();

    return action;
}

int selectPlanModif(Console* pConsole)
{
    int action;
    pConsole->gotoLigCol(7, 51);
    std::cout << "|     1er Plan";
    pConsole->gotoLigCol(8, 51);
    std::cout << "|";
    pConsole->gotoLigCol(9, 51);
    std::cout << "|     Plan Median";
    pConsole->gotoLigCol(10, 51);
    std::cout << "|";
    pConsole->gotoLigCol(11, 51);
    std::cout << "|     Background";

    int curseur = interaction(7, 54, 2, pConsole, 2);

    switch(curseur)
    {
    case 0: //Modif Premier Plan
        system("cls");
        std::cout << "> MODIFICATION DU 1ER PLAN : \n\n  >  Choix de la couleur majeur\n\n     Mesures de la grille\n\n     Graine";
        action = 210 + interaction(2, 2, 2, pConsole, 2);
        break;

    case 1:  //Plan Median
        system("cls");
        std::cout << "> MODIFICATION DU PLAN MEDIAN: \n\n  >  Choix de la couleur majeur\n\n     Densite des montagnes/batiments\n\n     Graine";
        action = 220 + interaction(2, 2, 2, pConsole, 2);
        break;

    case 2:
        //Background
        system("cls");
        std::cout << "> MODIFICATION DU PLAN MEDIAN: \n\n  >  Choix de la couleur majeur\n\n     Densite des etoiles\n\n     Graine";
        action = 230 + interaction(2, 2, 2, pConsole, 2);
        break;
    }
    return action;
}

int interaction(int posCursL, int posCursC, int tailleMax, Console* pConsole, int ecart)
{
    int curseur = 0, last_curseur = 0;
    int key = 110;
    while(key != 13)
    {
        pConsole->gotoLigCol(posCursL + ecart* last_curseur , posCursC );
        std::cout << " ";

        pConsole->gotoLigCol(posCursL + ecart* curseur , posCursC );
        std::cout <<">";

        pConsole->gotoLigCol(0,0);

        last_curseur = curseur;
        while(pConsole->isKeyboardPressed()==0);
            key = pConsole->getInputKey();

        if( key == 'z' || key == 72)
            curseur--;

        if( key == 's'|| key == 80)
            curseur++;

        if(curseur < 0 || curseur > tailleMax)
            curseur = tailleMax - last_curseur;
    }
	return curseur;
}


/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/

void affichageChoixCouleur(Console* pConsole)
{
    pConsole->gotoLigCol(2, 37);
    std::cout << "|     ";
  	pConsole->setColor(COLOR_WHITE);
    std::cout << "Blanc";
    pConsole->setColor(COLOR_GREEN);
    pConsole->gotoLigCol(3, 37);
    std::cout << "|     ";
    pConsole->setColor(COLOR_RED);
    std::cout << "Rouge";
    pConsole->setColor(COLOR_GREEN);
    pConsole->gotoLigCol(4, 37);
    std::cout << "|     ";
    pConsole->setColor(COLOR_YELLOW);
    std::cout << "Jaune";
    pConsole->setColor(COLOR_GREEN);
    pConsole->gotoLigCol(5, 37);
    std::cout << "|     ";
    pConsole->setColor(COLOR_PURPLE);
    std::cout << "Magenta";
    pConsole->setColor(COLOR_GREEN);
    pConsole->gotoLigCol(6, 37);
    std::cout << "|     ";
    pConsole->setColor(COLOR_BLUE);
    std::cout << "Bleu";
    pConsole->setColor(COLOR_GREEN);
    pConsole->gotoLigCol(7, 37);
    std::cout << "|     ";
    pConsole->setColor(COLOR_CYAN);
    std::cout << "Cyan";
    pConsole->setColor(COLOR_GREEN);
    pConsole->gotoLigCol(8, 37);
    std::cout << "|     Vert";
}

void affichageChoixDensite(Console* pConsole)
{
    pConsole->gotoLigCol(4, 37);
    std::cout << "|     Defaut";
    pConsole->gotoLigCol(5, 37);
    std::cout << "|     Superieur";
    pConsole->gotoLigCol(6, 37);
    std::cout << "|     Minimal";

}

int affichageChoixGraine(Console* pConsole)
{
    pConsole->gotoLigCol(6, 37);
    std::cout << "|     Quelle graine souhaitez-vous : ";
    int cast;
    std::cin >> cast;
    return cast;
}

