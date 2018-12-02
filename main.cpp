#include <iostream>
#include <windows.h>
#include <vector>

#include "menu/console.h"
#include "menu/menu.h"
#include "scene.h"
#include "save/save.h"

/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/

int main()
{

    std::vector<std::mt19937> graine;
    std::vector<double> densite;
    std::vector<Couleur> couleur;

    Scene* retro;
    Console* pConsole = NULL;
    pConsole = Console::getInstance();


    int choix = 0;

    for(int i = 0; i<3; i++)
            {
                graine.push_back((std::mt19937)util::alea(1, 100000));
                densite.push_back(util::alea(0, 2));
                couleur.push_back(choixcouleur(graine[i]));
            }

    do{

        retro = new Scene();
        retro->initialiser(graine, densite, couleur);
        retro->dessiner();
        retro->liberer();

        delete retro;
      	ShellExecute(NULL, "open", "dessin.svg", NULL, NULL, SW_SHOWNORMAL);

        choix = menuStd();

        switch(choix)
        {
        case 1: /// SCENE ALEATOIRE
            system("cls");

            graine.clear();
            densite.clear();
            couleur.clear();

            for(int i = 0; i<3; i++)
            {
                graine.push_back((std::mt19937)util::alea(1, 100000));
                densite.push_back(util::alea(0, 2));
                couleur.push_back(choixcouleur(graine[i]));
            }
           	//ShellExecute(NULL, "open", "dessin.svg", NULL, NULL, SW_SHOWNORMAL);

            break;

/*-------------------------------------------------------------------------*/
/*                          Modif  1er Plan                              */
/*-------------------------------------------------------------------------*/

        case 210 : /// selection plan 1 à modif + couleur majeur
            affichageChoixCouleur(pConsole);
            couleur[2] = choixcouleur(interaction(2, 38, 6, pConsole, 1));

            break;
        case 211: /// selection plan 1 à modif + changement densite
            pConsole->gotoLigCol(4, 37);
            std::cout << "|     Defaut";
            pConsole->gotoLigCol(5, 37);
            std::cout << "|     Superieur";
            pConsole->gotoLigCol(6, 37);
            std::cout << "|     Minimal";

            densite[2] = (double)interaction(4, 40, 2, pConsole, 1);
            break;

        case 212: /// selection plan 1 à modif + graine
            graine[2] = (std::mt19937)affichageChoixGraine(pConsole);
            break;

/*-------------------------------------------------------------------------*/
/*                          Modif Plan Médian                              */
/*-------------------------------------------------------------------------*/

        case 220: /// selection plan median à modif + couleur majeur
            affichageChoixCouleur(pConsole);
            couleur[1] = choixcouleur(interaction(2, 40, 6, pConsole, 1));
            break;
        case 221: /// selection plan médian à modif + densite
            affichageChoixDensite(pConsole);
            densite[1] = (double)interaction(4, 40, 2, pConsole, 1);
            break;
        case 222: /// selection plan médian à modif + graine
            graine[1] = (std::mt19937)affichageChoixGraine(pConsole);
            break;

/*-------------------------------------------------------------------------*/
/*                          Modif Background                               */
/*-------------------------------------------------------------------------*/

        case 230: /// selection background à modif + Couleur
            affichageChoixCouleur(pConsole);
            couleur[0] = choixcouleur(interaction(2, 38, 6, pConsole, 1));
            break;
        case 231 : /// selection background à modif + densite etoiles
            affichageChoixDensite(pConsole);
            densite[0] = (double)interaction(4, 40, 2, pConsole, 1);
            break;
        case 232: /// selection background à modif + Graine
            graine[0] = (std::mt19937)affichageChoixGraine(pConsole);
            break;


/*-------------------------------------------------------------------------*/
/*                                  Save                                   */
/*-------------------------------------------------------------------------*/

        case 3: ///Sauvegarde
            saveScene(graine, densite, couleur);
            break;
        case 4: ///Loading Save

            break;

        case 10: // QUITTER
            system("cls");
        }


    }while(choix != 10);


    graine.clear();
    densite.clear();
    couleur.clear();
    Console::deleteInstance();


	//ShellExecute(NULL, "open", "dessin.svg", NULL, NULL, SW_SHOWNORMAL);

    return 0;
}

/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/
