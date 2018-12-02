#include "plan.h"

void Plan::remplir(const std::mt19937& graine, const Couleur couleur, const double densite)
{
    m_graine=graine;
    m_couleur=couleur;
    m_densite=densite;
}

void Plan::plan0()
{
    Soleil* sol= new Soleil;
    sol->remplirCouleur(m_couleur, m_graine);
    m_objets.push_back(sol);
}

void Plan::plan1()
{
    int test=util::alea(0,1, m_graine);
    int de, a;

    amplitude(de, a);

    switch(test)
    {
        case 0 : ///choix montagne
            {double hauteur_plan = -200, largeur_plan = 800;
            Coords ptBG_plan {100, 800-270-1};
            Montagne* monts = new Montagne;
            monts->remplirAttr(m_couleur, Coords{largeur_plan, hauteur_plan}, ptBG_plan, util::alea(de, a, m_graine));
            monts->initialiser(m_graine);
            m_objets.push_back(monts);}
            break;
        case 1 : ///choix immeuble
            int nbre = util::alea(de*5,a*5,m_graine);
            for (int i=0; i<nbre; i++)
            {
                Immeuble* nouv = new Immeuble;
                nouv->remplirCouleur(m_couleur, m_graine);
                m_objets.push_back(nouv);
            }
            break;
    }
}

void Plan::plan2()
{
    double tailleCase=AskEcartLignes(m_densite, m_graine);
    Grid* maGrid = new Grid;
    maGrid->remplir(tailleCase, m_couleur);
    m_objets.push_back(maGrid);

    Palmier* coteG2 = new Palmier;
    coteG2->remplir(m_couleur);
    coteG2->initialiser(m_graine, tailleCase*0.7, Coords{0, 800-tailleCase}); //i/tailleTmp +0.1);
    m_objets.push_back(coteG2);

    Palmier* coteD2 = new Palmier;
    coteD2->remplir(m_couleur);
    coteD2->initialiser(m_graine, tailleCase*0.7, Coords{1000, 800-tailleCase}, -1);//, //i/tailleTmp +0.1);
    m_objets.push_back(coteD2);

}

void Plan::dessiner(Svgfile& svgout)
{
    for(const auto& pt: m_objets)
        pt->dessiner(svgout, m_graine);
}

void Plan::etoiles(Svgfile& svgout)
{
    double limiteY=800-270;
    int nbrEtoile=0;
    Couleur col{24, 24, 24};
    Coords	pos;

    switch(m_densite)
    {
        case 0: /**intervalle normal*/
            nbrEtoile= util::alea(500, 1500, m_graine);
            break;
        case 1: /** intervalle grand*/
            nbrEtoile= util::alea(1000, 2000, m_graine);
            break;
        case 2: /** intervalle petit*/
            nbrEtoile= util::alea(50, 800, m_graine);
            break;
    }

    if(limiteY >= 800 && limiteY <= 0)  limiteY = 780;
    if(limiteY == 790)  nbrEtoile += 200;

	for(auto i = 0; i < nbrEtoile; ++i)
    {
        pos.setX(util::alea(5.0, 990.0, m_graine));
        pos.setY(util::alea(10.0, limiteY, m_graine));

        svgout.addDisk(pos.getX(), pos.getY(), 1, "white");
    }
}

void Plan::gradient(Svgfile& svgout, const Couleur fond)
{
    svgout.radialGradient("gradM", 50, 50, 50, 50, 50, 0, m_couleur, 1, 100, fond, 0);
    svgout.addRectangle(-400, 200, 1800, 500, "gradM");
}

void Plan::liberer()
{
    for (const auto& pt : m_objets)
    {
        Montagne* pM=dynamic_cast<Montagne*>(pt);
        Palmier* pP=dynamic_cast<Palmier*>(pt);

        if(pM)
            pt->liberer();
        if(pP)
            pt->liberer();



        delete pt;
    }
}

void Plan::amplitude(int& min, int& max)
{
    switch(m_densite)
    {
        case 0: /**intervalle normal*/
            min=2;
            max=4;
            break;
        case 1: /** intervalle grand*/
            min=4;
            max=6;
            break;
        case 2: /** intervalle petit*/
            min=1;
            max=2;
            break;
    }
}
