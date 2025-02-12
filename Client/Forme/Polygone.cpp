//
// Created by Ahmet on 23/02/2024.
//

#include "Polygone.h"
#include "../Visitor/FormeVisitor.h"
#include "../SauvegardeVisitor/SauvegardeVisitor.h"


Polygone::~Polygone() {
    // Éventuelles opérations de nettoyage à faire lors de la destruction
}

void Polygone::detruire() {
    // Définir les opérations de nettoyage
}

Polygone::Polygone(const Polygone & P):FormeGeometrique(P.getCouleur(),P.getNbPoints())
{
    copier(P);
}

void Polygone::copier(const Polygone & P)
{
    _TabPoints = P.getTabPoints();
}

vector<Vecteur2D*> Polygone::getTabPoints() const
{
    return  _TabPoints;
}

Polygone::Polygone(Couleur couleur,vector<Vecteur2D*> points):FormeGeometrique(couleur,points.size()),_TabPoints(points)
{}

void Polygone::translation(Vecteur2D &v) {
    for (int i = 0; i < _TabPoints.size(); i++) {
        *_TabPoints[i] = *_TabPoints[i] + v;
    }
}

void Polygone::homothetie(double rapport, const Vecteur2D &pointInvariant) {
    for (int i = 0; i < _TabPoints.size(); i++) {
        Vecteur2D vec = *_TabPoints[i] - pointInvariant;
        vec = vec * rapport;
        *_TabPoints[i] = pointInvariant + vec;
    }
}

void Polygone::rotation(double angle, const Vecteur2D &centreRotation) {
    // Calcul du centre du polygone
    Vecteur2D centre = calculerCentre();

    // Calcul du nouveau point invariant après la rotation
    Vecteur2D nouveauPointInvariant = rotationPoint(centre, angle, centreRotation);

    // Appliquer la rotation à chaque point du polygone
    for (int i = 0; i < _TabPoints.size(); ++i) {
        *_TabPoints[i] = rotationPoint(*_TabPoints[i], angle, centreRotation);
    }
}

string Polygone::algo(int eps1, int eps2, double _Lambda, int _a, int _b) const {
    string pol = "polygone";
    string couleur;

    if (recevoirGroupeParent() != nullptr) {
        Groupe *g = getGroupeParent();
        Couleur c = g->getCouleur();
        couleur = enumToString(c);
    } else {
        Couleur c = getCouleur();
        couleur = enumToString(c);
    }

    string msg = pol + "," + couleur + ",";

    for (int i = 0; i < _TabPoints.size(); i++) {
        Vecteur2D v = *_TabPoints[i];
        int x = eps1 * _Lambda * v._x + _a;
        int y = eps2 * _Lambda * v._y + _b;
        string XString = to_string(x);
        string YString = to_string(y);
        msg = msg + XString + "," + YString;
        if (i != _TabPoints.size() - 1) {
            msg = msg + ",";
        }
    }

    return msg;
}

double Polygone::CalculAire() const {
    vector<vector<Vecteur2D *>> triangles = trianguler();
    double sommeAires = 0.0;

    // Calculer l'aire totale du polygone en additionnant les aires des triangles formés
    for (int i = 0; i < triangles.size(); ++i) {
        Vecteur2D vec1(*triangles[i][1] - *triangles[i][0]);
        Vecteur2D vec2(*triangles[i][2] - *triangles[i][0]);

        double aireTriangle = determinant(vec1, vec2);
        sommeAires += aireTriangle;
    }

    return 0.5 * sommeAires;
}

double Polygone::determinant(const Vecteur2D &v1, const Vecteur2D &v2) const {
    return abs((v1._x * v2._y) - (v1._y * v2._x));
}

void Polygone::afficher(ostream &os) const {
    os << "Polygone [Couleur: " << enumToString(getCouleur()) << ", NbPoints: " << getNbPoints() << ", Points: [";

    for (size_t i = 0; i < _TabPoints.size(); ++i) {
        os << "(" << _TabPoints[i]->_x << ", " << _TabPoints[i]->_y << ")";
        if (i < _TabPoints.size() - 1) {
            os << ", ";
        }
    }

    os << "]]";
}

void Polygone::accepter(FormeVisitor *F) const {
    F->visiterPolygone(*this);
}

double Polygone::getMinX() const
{
    double x = _TabPoints[0]->_x;
    for(int i = 0;i< getNbPoints();i++)
    {
        Vecteur2D v = *_TabPoints[i];
        double z = v._x;
        if(z < x)
        {
            x = z;
        }
    }
    return x;
}

double Polygone::getMinY() const
{
    double y = _TabPoints[0]->_y;
    for(int i = 0;i< getNbPoints();i++)
    {
        Vecteur2D v = *_TabPoints[i];
        double z = v._y;
        if(z < y)
        {
            y = z;
        }
    }
    return y;
}


double Polygone::getMaxX() const
{
    double x = _TabPoints[0]->_x;
    for(int i = 0;i< getNbPoints();i++)
    {
        Vecteur2D v = *_TabPoints[i];
        double z = v._x;
        if(z > x)
        {
        x = z;
        }
    }
    return x;
}


double Polygone::getMaxY() const
{
    double y = _TabPoints[0]->_y;

    for(int i = 0;i< getNbPoints();i++)
    {
        Vecteur2D v = *_TabPoints[i];
        double z = v._y;
        if(z > y)
        {
        y = z;
        }
    }
    return y;
}

Polygone * Polygone::clone() const
{
    return new Polygone(*(this));
}

vector<vector<Vecteur2D*>> Polygone::trianguler() const {
    vector<vector<Vecteur2D*>> triangles;
    vector<Vecteur2D*> sommetsRestants = _TabPoints;
    cout << sommetsRestants.size() << endl;

    while (sommetsRestants.size() > 3) {
        int i = 0;
        while (!estOreille(sommetsRestants, i)) {
            i = (i + 1) % sommetsRestants.size();
        }

        Vecteur2D* a = sommetsRestants[(i - 1 + sommetsRestants.size()) % sommetsRestants.size()];
        Vecteur2D* b = sommetsRestants[i];
        Vecteur2D* c = sommetsRestants[(i + 1) % sommetsRestants.size()];

        triangles.push_back({a, b, c});

        // Supprimer le sommet auquel l'oreille appartient
        sommetsRestants.erase(sommetsRestants.begin() + i);
    }

    // Ajouter le dernier triangle
    triangles.push_back(sommetsRestants);

    return triangles;
}

bool Polygone::estOreille(const std::vector<Vecteur2D*>& polygone, int i) const {
    int n = polygone.size();

    Vecteur2D* a = polygone[(i - 1 + n) % n];
    Vecteur2D* b = polygone[i];
    Vecteur2D* c = polygone[(i + 1) % n];

    for (int j = 0; j < n; ++j) {
        if (j != i && j != (i - 1 + n) % n && j != (i + 1) % n) {
            if (estInterieurDuTriangle(a, b, c, polygone[j])) {
                return false;
            }
        }
    }

    return true;
}

bool Polygone::estInterieurDuTriangle(Vecteur2D* a, Vecteur2D* b, Vecteur2D* c, Vecteur2D* p) const {
    double detT = (b->_x - a->_x) * (c->_y - a->_y) - (c->_x - a->_x) * (b->_y - a->_y);
    double det1 = (p->_x - a->_x) * (c->_y - a->_y) - (c->_x - a->_x) * (p->_y - a->_y);
    double det2 = (b->_x - a->_x) * (p->_y - a->_y) - (p->_x - a->_x) * (b->_y - a->_y);
    double det3 = (c->_x - a->_x) * (p->_y - a->_y) - (p->_x - a->_x) * (c->_y - a->_y);

    return (det1 >= 0 && det2 >= 0 && det3 >= 0) || (det1 <= 0 && det2 <= 0 && det3 <= 0);
}

Vecteur2D Polygone::calculerCentre() const
{
    double sommeX = 0.0;
    double sommeY = 0.0;

    for (int i = 0; i < _TabPoints.size(); ++i)
    {
        sommeX += _TabPoints[i]->_x;
        sommeY += _TabPoints[i]->_y;
    }

    return Vecteur2D(sommeX / _TabPoints.size(), sommeY / _TabPoints.size());
}

void Polygone::accepter(SauvegardeVisitor *S) const
{
    cout << "croix sauvegarder " << endl;
    S->visiterPolygone(*this);
}

Polygone::operator string() const
{
    string pol = "polygone";
    string couleur;

    if (getGroupeParent() != nullptr) {
        Groupe *g = getGroupeParent();
        Couleur c = g->getCouleur();
        couleur = enumToString(c);
    } else {
        Couleur c = getCouleur();
        couleur = enumToString(c);
    }

    string msg = pol + "," + couleur + ",";

    for (int i = 0; i < _TabPoints.size(); i++) {
        Vecteur2D v = *_TabPoints[i];
        double x = v._x;
        double y =v._y;
        string XString = to_string(x);
        string YString = to_string(y);
        msg = msg + XString + "," + YString;
        if (i != _TabPoints.size() - 1) {
            msg = msg + ",";
        }
    }

    return msg;
}


const Polygone & Polygone::operator = (const Polygone &P)
{
    detruire();
    copier(P);
    return *(this);
}