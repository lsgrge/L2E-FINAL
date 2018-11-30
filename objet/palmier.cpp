#include "palmier.h"

Palmier::Palmier()
{ }

void Palmier::dessiner(Svgfile& svgout, std::mt19937& graine)
{
    Couleur fond{24, 24, 24};

    /**dessin du tronc*/
    for(size_t i=0; i<8; ++i)
        svgout.addTriangle(m_architecture[i]->getX(), m_architecture[i]->getY(),
                           m_architecture[i+1]->getX(), m_architecture[i+1]->getY(),
                           m_architecture[i+2]->getX(), m_architecture[i+2]->getY(),
                           fond, 2, m_couleur);

    /**dessin des palmes*/
    for(size_t i=10; i<30; i+=2)
    {
        svgout.addTriangle(m_architecture[9]->getX(), m_architecture[9]->getY(),
                           m_architecture[i]->getX(), m_architecture[i]->getY(),
                           m_architecture[i+1]->getX(), m_architecture[i+1]->getY(),
                           fond, 2, m_couleur);
    }
}

void Palmier::initialiser(std::mt19937& graine)
{
    Coords posBG = {util::alea(0.0, 1000.0, graine), util::alea(540.0, 800.0, graine)};
    double dep=40; //(2*800)/(800-posBG.getY());

    /**Tronc*/
    m_architecture.push_back(new Coords{posBG}); ///pt0
    m_architecture.push_back(new Coords{posBG.getX() +dep*2, posBG.getY()}); ///pt1
    m_architecture.push_back(new Coords{posBG.getX() +dep*0.5, posBG.getY() -dep*0.5}); ///pt2
    m_architecture.push_back(new Coords{posBG.getX() +dep, posBG.getY() -dep}); ///pt3
    m_architecture.push_back(new Coords{posBG.getX() +dep*0.5, posBG.getY() -dep*1.5}); ///pt4
    m_architecture.push_back(new Coords{posBG.getX() +dep, posBG.getY() -dep*1.5}); ///pt5
    m_architecture.push_back(new Coords{posBG.getX() +dep, posBG.getY() -dep*3.5}); ///pt6
    m_architecture.push_back(new Coords{posBG.getX() +dep*1.5, posBG.getY() -dep*3.5}); ///pt7
    m_architecture.push_back(new Coords{posBG.getX() +dep*1.5, posBG.getY() -dep*5}); ///pt8
    m_architecture.push_back(new Coords{posBG.getX() +dep*2.5, posBG.getY() -dep*6}); ///pt9

    /**Palmes*/
    m_architecture.push_back(new Coords{posBG.getX() +dep*3, posBG.getY() -dep*3}); ///pt10
    m_architecture.push_back(new Coords{posBG.getX() +dep*3.5, posBG.getY() -dep*4}); ///pt11
    m_architecture.push_back(new Coords{posBG.getX() +dep*5, posBG.getY() -dep*3}); ///pt12
    m_architecture.push_back(new Coords{posBG.getX() +dep*4.5, posBG.getY() -dep*4.5}); ///pt13
    m_architecture.push_back(new Coords{posBG.getX() +dep*6, posBG.getY() -dep*4}); ///pt14
    m_architecture.push_back(new Coords{posBG.getX() +dep*5, posBG.getY() -dep*5.5}); ///pt15
    m_architecture.push_back(new Coords{posBG.getX() +dep*6, posBG.getY() -dep*5}); ///pt16
    m_architecture.push_back(new Coords{posBG.getX() +dep*4.5, posBG.getY() -dep*6.5}); ///pt17
    m_architecture.push_back(new Coords{posBG.getX() +dep*5.5, posBG.getY() -dep*8}); ///pt18
    m_architecture.push_back(new Coords{posBG.getX() +dep*3.5, posBG.getY() -dep*7.5}); ///pt19
    m_architecture.push_back(new Coords{posBG.getX() +dep*4.5, posBG.getY() -dep*8}); ///pt20
    m_architecture.push_back(new Coords{posBG.getX() +dep*3, posBG.getY() -dep*7.5}); ///pt21
    m_architecture.push_back(new Coords{posBG.getX() +dep*1.5, posBG.getY() -dep*8}); ///pt22
    m_architecture.push_back(new Coords{posBG.getX() +dep*2.5, posBG.getY() -dep*7.5}); ///pt23
    m_architecture.push_back(new Coords{posBG.getX() , posBG.getY() -dep*8}); ///pt24
    m_architecture.push_back(new Coords{posBG.getX() +dep*0.5, posBG.getY() -dep*6.5}); ///pt25
    m_architecture.push_back(new Coords{posBG.getX() -dep*0.5, posBG.getY() -dep*7}); ///pt26
    m_architecture.push_back(new Coords{posBG.getX() +dep, posBG.getY() -dep*7.5}); ///pt27
    m_architecture.push_back(new Coords{posBG.getX() -dep*0.5, posBG.getY() -dep*4.5}); ///pt28
    m_architecture.push_back(new Coords{posBG.getX() +dep*0.5, posBG.getY() -dep*6}); ///pt29

}

void Palmier::liberer()
{
    for(const auto& pt: m_architecture)
        delete pt;
}


void Palmier::remplir(Couleur couleur)
{
    m_couleur=couleur;
}
