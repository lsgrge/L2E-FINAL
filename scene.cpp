#include "scene.h"

void filtre(Svgfile& svgout)
{
    double hauteur=8;
    for(size_t i=0; i<=800; i+=(hauteur*1.25))
        svgout.addTraits(0, i, 1000, hauteur, "blue", "pink");
}

void Scene::initialiser()
{
    m_couleur_fond=Couleur{24, 24, 24};
    std::mt19937 graine{69};

    for(size_t i=0; i<3; ++i)
    {
        m_plans.push_back(new Plan);
        Couleur couleur=choixcouleur(graine);
        int densite=util::alea(0, 2, graine);
        m_plans[i]->remplir(graine, couleur, densite);
    }

    /**initialisation*/
    /**background*/
    m_plans[0]->plan0();

    /**plan médian*/
    m_plans[1]->plan1();

    /**premier plan*/
    m_plans[2]->plan2();
}

void Scene::dessiner()
{
    Svgfile visuel;

    visuel.addRectangle(0, 0, 1000, 0, 1000, 8000, 0, 800, m_couleur_fond);

    m_plans[0]->gradient(visuel,m_couleur_fond);
    m_plans[0]->etoiles(visuel);

    for(const auto& pt:m_plans)
        pt->dessiner(visuel);

    filtre(visuel);
}
