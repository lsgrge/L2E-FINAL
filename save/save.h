#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include "../util/util.h"
#include "../graphisme/couleur.h"


void saveScene(std::vector<int>& graineTmp, std::vector<double>& densite, std::vector<Couleur>& couleur);
void loadSaveScene(std::vector<int>& graineTmp, std::vector<double>& densite, std::vector<Couleur>& couleur);


#endif // SAVE_H_INCLUDED
