#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include "../util/util.h"

void saveScene(std::vector<std::mt19937>& graine, std::vector<double>& densite, std::vector<Couleur>& couleur);


#endif // SAVE_H_INCLUDED
