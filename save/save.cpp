#include "save.h"


void saveScene(std::vector<int>& graineTmp, std::vector<double>& densite, std::vector<Couleur>& couleur)
{
    std::ofstream ofs{"save/save.txt"};

    if(!ofs)
        std::cerr << "erreur creation fichier de sauvegarde";
    else
    {
        ofs << graineTmp.size() << std::endl;
        for(auto val : graineTmp)
            ofs << val << std::endl;

        ofs << densite.size()<<std::endl;
        for(auto val : densite)
            ofs << val << std::endl;

        ofs << couleur.size() << std::endl;
        for(size_t i = 0; i < couleur.size(); i++)
        {
            ofs << (int)couleur[i].getRouge() << std::endl;
            ofs << (int)couleur[i].getVert() << std::endl;
            ofs << (int)couleur[i].getBleu() << std::endl;

        }

        ofs.close();

    }
}


void loadSaveScene(std::vector<int>& graineTmp, std::vector<double>& densite, std::vector<Couleur>& couleur)
{
    std::ifstream ifs{"save/save.txt"};
    if(!ifs)
        std::cerr << "Can't read/open vecdata.txt\n";
    else
    {
        int r, v, b;

        size_t vecSize;

        ifs >> vecSize;
        graineTmp.clear();
        for(size_t i = 0; i<vecSize; i++)
            ifs >> graineTmp[i];

        ifs >> vecSize;
        densite.clear();
        for(size_t i = 0; i< vecSize; i++)
           ifs >> densite[i];

        ifs >> vecSize;
        couleur.clear();
        for(size_t i = 0; i < vecSize; i++)
        {
            ifs >> r;
            ifs >> v;
            ifs >> b;

            couleur.push_back(Couleur{(uint8_t)r, (uint8_t)v, (uint8_t)b});

        }


        ifs.close();

    }


}

