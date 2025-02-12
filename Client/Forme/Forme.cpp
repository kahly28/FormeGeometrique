//
// Created by Ahmet on 08/01/2024.
//

#include "Forme.h"
#include "Groupe.h"

Forme::Forme(const Forme & F):_groupeParent(nullptr)
{
    copier(F);
}

Forme::Forme(Couleur couleur):_couleur(couleur),_groupeParent(nullptr)
{}

void Forme::detruire()
{
    cout << "destruction forme" << endl;
}

void Forme::copier(const Forme & F)
{
    setGroupeParent(F.getGroupeParent());
    setCouleur(F.getCouleur());
}



Groupe * Forme::getGroupeParent() const
{
    return _groupeParent;
}

void Forme::setGroupeParent(Groupe* nouveauGroupeParent)
{
    _groupeParent = nouveauGroupeParent;
}


void Forme::setCouleur(Couleur couleur)
{
    _couleur = couleur;
}

Couleur Forme::getCouleur () const
{
    if(getGroupeParent() == nullptr) {
        return _couleur;
    }
    else
    {
        Groupe * g = getGroupeParent();
        return g->getCouleur();
    }
}

string Forme::enumToString(Couleur c) const
{
    switch(c)
    {
        case Couleur::black: return "black";
        case Couleur::blue: return "blue";
        case Couleur::red: return "red";
        case Couleur::green: return "green";
        case Couleur::yellow: return "yellow";
        case Couleur::cyan: return "cyan";

    }
}

Vecteur2D Forme::rotationPoint(const Vecteur2D& point, double angle, const Vecteur2D& centreRotation) const
{
    // Transposer le point pour qu'il soit centré autour du centre de rotation
    Vecteur2D transposedPoint = point - centreRotation;

    // Appliquer la rotation
    double x_prime = transposedPoint._x * cos(angle) - transposedPoint._y * sin(angle);
    double y_prime = transposedPoint._x * sin(angle) + transposedPoint._y * cos(angle);

    // Transposer le point de retour à sa position d'origine
    return Vecteur2D(x_prime, y_prime) + centreRotation;
}


Forme::~Forme()
{
    detruire();
}

