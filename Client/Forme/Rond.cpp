//
// Created by Ahmet on 08/01/2024.
//

#include "Rond.h"
#include "../Visitor/FormeVisitor.h"
#include "../SauvegardeVisitor/SauvegardeVisitor.h"


Rond::~Rond() {
    detruire();
    // Éventuelles opérations de nettoyage à faire lors de la destruction
}


Rond * Rond::clone() const
{
    return new Rond(*this);
}

void Rond::copier(const Rond & R)
{
    _point = R.getPoint();
    _rayon = R.getRayon();
}

void Rond::detruire() {
    cout << "desutrction de rond " << endl;
    // Définir les opérations de nettoyage
}

Rond::Rond(Couleur couleur, Vecteur2D pt, double rayon):FormeGeometrique(couleur,1), _point(pt),_rayon(rayon)
{}

Rond::Rond(const Rond & R):FormeGeometrique(R.getCouleur(),1)
{
    copier(R);
}





void Rond::translation(Vecteur2D &v) {
    _point = _point + v;
}

void Rond::homothetie(double rapport, const Vecteur2D &V) {
    // Calcul du nouveau point du centre après l'homothétie
    Vecteur2D nouveauPointInvariant = (V - _point) * rapport + V;
    _rayon = _rayon * abs(rapport);

    Vecteur2D vec = _point - V;
    vec = vec * rapport;
    // Mise à jour du point du centre avec le nouveau centre calculé
    _point = V + vec;
}

void Rond::rotation(double angle, const Vecteur2D &centreRotation) {
    // Appliquer la rotation au centre du rond
    _point = rotationPoint(_point, angle, centreRotation);
}

string Rond::algo(int eps1, int eps2, double _Lambda, int _a, int _b) const
{
    int x, y, rayon;
    double xCoinSuperieurGauche = _point._x - _rayon;
    double yCoinSuperieurGauche = _point._y + _rayon;

    x = (eps1 * _Lambda * xCoinSuperieurGauche) + _a;
    y = (eps2 * _Lambda * yCoinSuperieurGauche) + _b;
    rayon = _rayon * _Lambda;

    string XString = to_string(x);
    string YString = to_string(y);
    string rond = "rond";
    string couleur;

    if (recevoirGroupeParent() != nullptr) {
        Groupe *g = getGroupeParent();
        Couleur c = g->getCouleur();
        couleur = enumToString(c);
    } else {
        Couleur c = getCouleur();
        couleur = enumToString(c);
    }
    string msg = rond + "," + couleur + "," + XString + "," + YString + "," + to_string(rayon);
    return msg;
}

double Rond::CalculAire() const {
    const double Pi = 3.141592;
    double Aire = _rayon * _rayon * Pi;
    return Aire;
}

void Rond::afficher(ostream &os) const {
    os << "Rond [Couleur: " << enumToString(getCouleur()) << ", Centre: " << getPoint() << ", Rayon: " << getRayon() << "]";
}

void Rond::accepter(FormeVisitor *F) const {
    F->visiterRond(*this);
}

double Rond::getRayon() const
{
    return _rayon;
}

Vecteur2D Rond::getPoint() const
{
    return _point;
}

double Rond::getMinX() const
{
    return Rond::_point._x - _rayon;
}

double Rond::getMinY() const
{
return _point._y - _rayon;
}

double Rond::getMaxX() const
{
return _point._x + _rayon;
}


double Rond::getMaxY() const
{
return _point._y + _rayon;
}

void Rond::accepter(SauvegardeVisitor *S) const
{
    S->visiterRond(*this);
}


Rond::operator string() const
{
    double x, y, rayon;


    x = _point._x;
    y = _point._y;
    rayon = _rayon;

    string XString = to_string(x);
    string YString = to_string(y);
    string rond = "rond";
    string couleur;

    if (getGroupeParent() != nullptr) {
        Groupe *g = getGroupeParent();
        Couleur c = g->getCouleur();
        couleur = enumToString(c);
    } else {
        Couleur c = getCouleur();
        couleur = enumToString(c);
    }
    string msg = rond + "," + couleur + "," + XString + "," + YString + "," + to_string(rayon);
    return msg;
}


const Rond & Rond::operator = (const Rond &R)
{
    detruire();
    copier(R);
    return *(this);
}