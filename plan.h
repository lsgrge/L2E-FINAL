#ifndef PLAN_H_INCLUDED
#define PLAN_H_INCLUDED

#include "objet/grid.h"
#include "objet/immeuble.h"
#include "objet/montagne.h"
#include "objet/soleil.h"
#include "objet/palmier.h"

class Plan
{
    public :
        void remplir(const std::mt19937& graine, const Couleur couleur, const double densite);
        void paramtre_graine(const std::mt19937& graine);
        void parametre_couleur(const Couleur couleur);
        void parametre_densite(const int choix);
        void dessiner(Svgfile& svgout);
        void gradient(Svgfile& svgout, const Couleur fond);
        void etoiles(Svgfile& svgout);

        /**dernier plan : background étoiles + gradient milieu + soleil*/
        void plan0();
        /**plan médian : immeubles ou montagnes*/
        void plan1();
        /**1er plan : grid + objet spécial*/
        void plan2();

        void liberer();
        void amplitude(int& min, int& max);

    private :
        std::mt19937 m_graine;
        Couleur m_couleur;
        int m_densite;
        std::vector<Objet*> m_objets;
};

#endif // PLAN_H_INCLUDED
