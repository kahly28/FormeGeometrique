#include "Croix.h"
#include "../Visitor/FormeVisitor.h"
#include "../SauvegardeVisitor/SauvegardeVisitor.h"
using namespace std;


Croix::Croix(Couleur couleur, Vecteur2D & hautGauche, Vecteur2D& basDroite):
FormeGeometrique(couleur,2),_HautGauche(hautGauche),_BasDroite(basDroite), _HautDroite(getBasDroite()._x,getHautGauche()._y),
_BasGauche(getHautGauche()._x,getBasDroite()._y)
{

}

const Croix & Croix::operator = (const Croix &C)
{
    detruire();
    copier(C);
    return *(this);
}

Croix::Croix(const Croix & C):FormeGeometrique(C.getCouleur(),C.getNbPoints())
{
    copier(C);
}

void Croix::copier(const Croix & C)
{
    _HautGauche = C.getHautGauche();
    _BasDroite = C.getBasDroite();
    _HautDroite = C.getHautDroite();
    _BasGauche = C.getBasGauche();
}

void Croix::detruire()
{

}

Vecteur2D Croix::getHautGauche() const
{
    return _HautGauche;
}

Vecteur2D Croix::getBasDroite() const
{
    return _BasDroite;
}

Vecteur2D Croix::getHautDroite() const
{
    return _HautDroite;
}

Vecteur2D Croix::getBasGauche() const
{
    return _BasGauche;
}




Croix * Croix::clone() const
{
return new Croix(*(this));
}

double Croix::getMinX() const
{
    cout << "la ? " << endl;
    return _HautGauche._x;
}


double Croix::getMinY() const
{
    return _BasDroite._y;
}



double Croix::getMaxX() const
{
return _BasDroite._x;
}

double Croix::getMaxY() const
{
return _HautGauche._y;
}




void Croix::afficher(ostream& os) const
{
os << "Croix [Couleur: " << enumToString(getCouleur()) << ", HautGauche: " << getHautGauche() << ", BasDroite: " << getBasDroite()
<< ", HautDroite: " << getHautDroite() << ", BasGauche: " << getBasGauche() << "]";
}

Croix::operator string() const
{
    double x1,x2,y1,y2;

    string x1String = to_string(_HautGauche._x);
    string y1String = to_string(_HautGauche._y);
    string x2String = to_string(_BasDroite._x);
    string y2String = to_string(_BasDroite._y);
    string croix = "croix";
    string couleur;

    if(recevoirGroupeParent() != nullptr)
    {
        Groupe * g = getGroupeParent();
        Couleur c = g->getCouleur();
        couleur = enumToString(c);

    }
    else
    {
        Couleur c =getCouleur();
        couleur = enumToString(c);

    }
    cout << "fin  ? " << endl;
    string msg = croix + "," + couleur + "," + x1String + "," + y1String + ","+
                 x2String + "," + y2String;
    return msg;

}


double Croix::CalculAire() const
{
    return 0;
}

void Croix::translation(Vecteur2D & v)
{
_HautGauche = _HautGauche + v;
_HautDroite = _HautDroite + v;
_BasDroite = _BasDroite + v;
_BasGauche = _BasGauche + v;
}

string Croix::algo(int eps1,int eps2,double _Lambda,int _a, int _b) const
{
    cout << "algo " << endl;
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cout << eps1 << endl;
    cout << eps2 << endl;
    cout << _Lambda << endl;
    cout << _a << endl;
    cout << _b << endl;
    cout << *this << endl;
    x1 = eps1 * _Lambda * _BasGauche._x + _a;
    y1 = eps2 * _Lambda * _BasGauche._y + _b;
    cout << eps1 * _Lambda * _BasGauche._x + _a << endl;
    cout << eps2 * _Lambda * _BasGauche._y + _b <<endl;
    cout << x1 << endl;
    cout << x2 << endl;

    x2 = eps1 * _Lambda * _HautGauche._x + _a;
    y2 = eps2 * _Lambda * _HautGauche._y + _b;

    x3 = eps1 * _Lambda * _HautDroite._x + _a;
    y3 = eps2 * _Lambda * _HautDroite._y + _b;

    x4 = eps1 * _Lambda * _BasDroite._x + _a;
    y4 = eps2 * _Lambda * _BasDroite._y + _b;

    string StringX1 = to_string(x1);
    string StringY1 = to_string(y1);
    string StringX2 = to_string(x2);
    string StringY2 = to_string(y2);
    string StringX3 = to_string(x3);
    string StringY3 = to_string(y3);
    string StringX4 = to_string(x4);
    string StringY4 = to_string(y4);
    string croix = "croix";
    string couleur;

    if(getGroupeParent() != nullptr)
    {
    Groupe * g = getGroupeParent();
    Couleur c = g->getCouleur();
    couleur = enumToString(c);

    }
    else
    {
    Couleur c =getCouleur();
    couleur = enumToString(c);

    }
    cout << "fin algo ? " << endl;
    string msg = croix + "," + couleur + "," + StringX1 + "," + StringY1 + ","+
                 StringX2 + "," + StringY2 + "," + StringX3 + "," + StringY3 + "," + StringX4 + "," + StringY4;
    cout << "msg : " << endl;
    cout << msg << endl;
    return msg;

}


/*
    string dessiner(int eps1,int eps2,double _Lambda,int _a, int _b) const override
    {
        string msg = algo(eps1,eps2,_Lambda,_a,_b);
        return msg;
    }
*/
void Croix::homothetie(double rapport,const Vecteur2D& pointInvariant)
{

/*
for(int i = 0 ;i < _TabPoints.size();i++)
{
    Vecteur2D vec = *_TabPoints[i] - pointInvariant;
    vec = vec*rapport;
    *_TabPoints[i] = pointInvariant + vec;
}

 */

Vecteur2D vec = _HautGauche - pointInvariant;
vec = vec * rapport;
_HautGauche = pointInvariant + vec;

Vecteur2D vec2 = _HautDroite - pointInvariant;
vec2 = vec2 * rapport;
_HautDroite =  pointInvariant + vec2;

Vecteur2D vec3 = _BasGauche - pointInvariant;
vec3 = vec3 * rapport;
_BasGauche = pointInvariant + vec3;

Vecteur2D vec4 = _BasDroite - pointInvariant;
vec4 = vec4 * rapport;
_BasDroite = pointInvariant+ vec4;

}

void Croix::rotation(double angle, const Vecteur2D& centreRotation)
{
// Appliquer la rotation à chaque point de la croix
_HautGauche = rotationPoint(_HautGauche, angle, centreRotation);
_HautDroite = rotationPoint(_HautDroite, angle, centreRotation);
_BasGauche = rotationPoint(_BasGauche, angle, centreRotation);
_BasDroite = rotationPoint(_BasDroite, angle, centreRotation);
}


void Croix::accepter(FormeVisitor * F) const
{
    cout << "croix accepter : " << endl;
    F->visiterCroix(*this);
}

void Croix::accepter(SauvegardeVisitor *S) const
{

    S->visiterCroix(*this);

}

Croix::~Croix()
{
    detruire();
}
