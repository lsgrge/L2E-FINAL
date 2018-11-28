#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include "../graphisme/couleur.h"
#include "../geometrie/coords.h"

/**interface*/

class Objet
{
    public :
        virtual ~Objet()=default;
        inline virtual void dessiner(Svgfile& svgout, std::mt19937& graine)
        { }
        inline virtual void liberer()
        { }
};

#endif // OBJET_H_INCLUDED
