#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "plan.h"

class Scene
{
    public :
        void initialiser(std::vector<std::mt19937>& graine, std::vector<double>& densite, std::vector<Couleur>& couleur);
        void dessiner();
        void liberer();

    private :
        Couleur m_couleur_fond;
        std::vector<Plan*> m_plans;
};

/**filtre retro créé à partir de traits opaque*/
void filtre(Svgfile& svgout);


#endif // SCENE_H_INCLUDED
