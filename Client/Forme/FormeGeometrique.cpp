//
// Created by Ahmet on 26/02/2024.
//

#include "FormeGeometrique.h"
#include "Groupe.h"

void FormeGeometrique::copier( const FormeGeometrique & F)
{
    _nbPoints = F.getNbPoints();
    setGroupeParent(F.getGroupeParent());

}

void FormeGeometrique::detruire()
{
    cout << "destruction forme geo" << endl;
}

Groupe * FormeGeometrique::recevoirGroupeParent() const
{
    return getGroupeParent();
}


FormeGeometrique::~FormeGeometrique()
{
    detruire();
}

int FormeGeometrique::getNbPoints() const
{
    return _nbPoints;
}

const FormeGeometrique & FormeGeometrique::operator = (const FormeGeometrique &F)
{
    detruire();
    copier(F);
    return *(this);
}




Groupe & FormeGeometrique::operator + (Forme & F)
{
    Groupe g(getCouleur());
    g + *this;
    g + F;
    return g;

}



FormeGeometrique::FormeGeometrique(FormeGeometrique & F):Forme(F.getCouleur())
{
    copier(F);
}

FormeGeometrique::FormeGeometrique(Couleur couleur, int nbPoints):Forme(couleur),_nbPoints(nbPoints)
{}