#include "menu.h"
#include <string>

void openFile()
{
	std::ifstream ifs{"menu/menu.txt"};
	if(!ifs)
		//std::runtime_error("Erreur ouverture fichier");
		std::cerr << "erreur fichier";
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

int menuStd()
{
	int key = 110;
	int action;
	int curseur = 0, last_curseur = 0;
	Console* pConsole = NULL;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();
	pConsole->setColor(COLOR_GREEN);
	do
    {
        system("cls");
		openFile();
        //cette boucle affiche un curseur pour choisir son menu et supprime le précedend

        while(key != 13)
        {



            pConsole->gotoLigCol(7 + 2* last_curseur , 10 );
            std::cout << " ";

            pConsole->gotoLigCol(7 + 2* curseur , 10 );
            std::cout <<">";

            pConsole->gotoLigCol(0,0);

            last_curseur = curseur;
            while(pConsole->isKeyboardPressed()==0);
				key = pConsole->getInputKey();

            if( key == 'z')
                curseur--;

            if( key == 's')
                curseur++;

            if(curseur < 0 || curseur > 4)
                curseur = 4 - last_curseur;
        }

        switch (curseur)
        {
            case 0: //scene alea
                system("cls");
                std::cout << "test 0!";
                action = 1;
                break;
			case 1: //selec plan modif
				system("cls");
                std::cout << "test 1!";
				action = 2;
				break;
			case 2: //selec param modif
				system("cls");
                std::cout << "test 2!";
				action = 3;
				break;
            case 3: //parametre modif(couleur grad...)
				system("cls");
                std::cout << "test 3!";
				action = 4;
				break;
            case 4:	//Quitter
                system("cls");
                std::cout << "AU REVOIR!";
                action = 5;
                break;
        }

        key = 'A';

    }while (!action);

    Console::deleteInstance();
//system("cls");


    return action;
}
