#include "save.h"


void saveScene(std::vector<std::mt19937>& graine, std::vector<double>& densite, std::vector<Couleur>& couleur)
{
    std::ofstream ofs{"save/save.txt"};

    if(!ofs)
        std::cerr << "erreur creation fichier de sauvegarde";
    else{

        ofs << graine.size() << std::endl;
        for(auto i = 0; i <graine.size(); i++)
            ofs << graine[i] << std::endl;
        ofs << densite.size();
        for(auto i = 0; i <densite.size(); i++)
            ofs << densite[i] << std::endl;
        ofs << couleur.size() << std::endl;
        for(auto i = 0; i <couleur.size(); i++)
            ofs << couleur[i] << std::endl;

    }
}
