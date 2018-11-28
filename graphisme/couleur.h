#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <string>
#include <cstdint>
#include "../svg/svgfile.h"
#include "../util/util.h"
#include <iostream>

class Couleur
{
    public :
        Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Couleur();

        void afficher() const;

        uint8_t getRouge();
        uint8_t getVert();
        uint8_t getBleu();

        void setRouge(uint8_t r);
        void setVert(uint8_t v);
        void setBleu(uint8_t b);

        operator std::string() const;

        /// Somme vectorielle
        friend Couleur operator+(const Couleur& c1, const Couleur& c2);

    private :
        // uint8_t équivalent à unsigned char :
        // unsigned 8 bits (8 bits non signé)
        uint8_t m_rouge, m_vert, m_bleu;
};

Couleur choixcouleur(std::mt19937& graine);

#endif // COULEUR_H_INCLUDED
