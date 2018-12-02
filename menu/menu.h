#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>

#include "console.h"

void openFile();
int menuStd();
int interaction(int posCursL, int posCursC, int tailleMax, Console* pConsole, int ecart);
int selectPlanModif(Console* pConsole);

/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/

void affichageChoixCouleur(Console* pConsole);
void affichageChoixDensite(Console* pConsole);
int affichageChoixGraine(Console* pConsole);

#endif
