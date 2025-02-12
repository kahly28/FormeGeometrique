//
// Created by Ahmet on 08/01/2024.
//

#include "Fenetre.h"
#include "Visitor/FormeVisitor.h"
#include <fstream>




Fenetre::Fenetre(int x, int y, int h,int l):_x(x),_y(y),_h(h),_l(l),calculsEffectues(false)
{
    cout << "herreee" << endl;
    ChargementCOR *cor = nullptr;
    cout << "1" << endl;
    ChargerCroix * croix = new ChargerCroix(nullptr);
    cout << "1" << endl;

    ChargerPolygone * polygone = new ChargerPolygone(croix);
    cout << "1" << endl;

    ChargerRond * rond = new ChargerRond(polygone);
    cout << "1" << endl;

    ChargerGroupe * groupe = new ChargerGroupe(rond);
    cout << "1" << endl;

    cor = groupe;
    _COR = cor;
    cout << "yoo " << endl;

    string XtoString = to_string(_x);
    string YtoString = to_string(_y);
    string HtoString = to_string(_h);
    string LtoString = to_string(_l);
    string msg = XtoString + "," + YtoString + "," + HtoString + "," + LtoString;
    cout << msg << endl;
}

double Fenetre::getX() const
{
    return _x;
}


double Fenetre::getY() const
{
    return _y;
}


double Fenetre::getH() const
{
    return _h;
}

double Fenetre::getL() const
{
    return _l;
}
/*
void Fenetre::accept(FormeVisitor * v)
{
    cout << " la ? " << endl;
    v->visiter(*this);
}
 */

vector<Forme*> Fenetre::getTabForme()
{
    return _TabForme;
}


Fenetre & Fenetre::ajouterForme(Forme & forme)
{
    cout << "forme push back " << endl;
    _TabForme.push_back(&forme);
    return *(this);
}

Fenetre & Fenetre::retirerForme(Forme & forme)
{
    for(int i = 0;i< getNbForme();i++)
    {
        if(_TabForme[i] == &forme)
        {
            _TabForme.erase(std::remove(_TabForme.begin(), _TabForme.end(), &forme), _TabForme.end());

        }
    }
    return *(this);
}

int Fenetre::getNbForme() const
{
    return _TabForme.size();
}

void Fenetre::CalculP1() {

    double x = _TabForme[0]->getMinX();
    for(int i = 0;i < _TabForme.size();i++)
    {
        double z;
        Forme * f = _TabForme[i];
        z = f->getMinX();
        if(z < x)
        {
            x = z;
        }
    }

    double y = _TabForme[0]->getMinY();
    for(int i = 0;i < _TabForme.size();i++)
    {
        double z;
        Forme * F = _TabForme[i];
        z = F->getMinY();
        if(z < y)
        {
            y = z;
        }
    }

    Vecteur2D v(x,y);
    _P1 = v;
    cout <<"P1 : " <<  _P1 << endl;
}

void Fenetre::CalculP2() {
    double x = _TabForme[0]->getMaxX();
    for(int i = 0;i < _TabForme.size();i++)
    {
        double z;
        Forme * f = _TabForme[i];
        z = f->getMaxX();
        if(z > x)
        {
            x = z;
        }
    }

    double y = _TabForme[0]->getMaxY();
    for(int i = 0;i < _TabForme.size();i++)
    {
        double z;
        Forme * F = _TabForme[i];
        z = F->getMaxY();
        if(z > y)
        {
            y = z;
        }
    }


    Vecteur2D v(x,y);
    _P2 = v;
    cout <<"P2 : " <<  _P2 << endl;

}

void Fenetre::CalculP1Prime()
{
    Vecteur2D v(0,_h);
    _P1Prime = v;
}
void Fenetre::CalculP2Prime()
{
    Vecteur2D v(_l,0);
    _P2Prime = v;
}

Vecteur2D Fenetre::getP1Prime() const
{
    return _P1Prime;
}

Vecteur2D Fenetre::getP2Prime() const
{
    return _P2Prime;
}

Vecteur2D Fenetre::getP1() const
{
    return _P1;
}

Vecteur2D Fenetre::getP2() const
{
    return _P2;
}

void Fenetre::CalculLambda()
{
    double val1;
    double val2;

    val1 =  abs(getP2Prime()._x - getP1Prime()._x) / abs(getP2()._x - getP1()._x);
    val2 = abs(getP2Prime()._y - getP1Prime()._y)/ abs(getP2()._y - getP1()._y);


    _Lambda = min(val1,val2);
}



void Fenetre::CalculEps1()
{
    int rep = (( (getP2()._x - getP1()._x >= 0) && (getP2Prime()._x - getP1Prime()._x >= 0) ) ||
    (getP2()._x - getP1()._x < 0 && getP2Prime()._x - getP1Prime()._x < 0) ) ? 1 : -1;
    _eps1 = rep;
}

void Fenetre::CalculEps2()
{
    int rep = (( (getP2()._y - getP1()._y >= 0) && (getP2Prime()._y - getP1Prime()._y >= 0) ) ||
               (getP2()._y - getP1()._y < 0 && getP2Prime()._y - getP1Prime()._y < 0) ) ? 1 : -1;
    _eps2 = rep;
}


void Fenetre::CalculC()
{
    double x;
    double y;

    x = (getP1()._x + getP2()._x)/2;
    y = (getP1()._y + getP2()._y)/2;
    Vecteur2D v(x,y);
    _C = v;
}

void Fenetre::CalculCPrime()
{
    double x;
    double y;
    x = (getP1Prime()._x + getP2Prime()._x)/2;
    y = (getP1Prime()._y + getP2Prime()._y)/2;
    Vecteur2D v(x,y);
    _CPrime = v;
}

void Fenetre::CalculPetitLambda1()
{
    double rep = _eps1 * _Lambda;
    _petitLambda1 = rep;
}

void Fenetre::CalculPetitLambda2()
{
    double rep = _eps2 * _Lambda;
    _petitLambda2 = rep;
}

void Fenetre::aCalcul()
{
    double rep = _CPrime._x - (_petitLambda1*_C._x);
    int x = (int) rep;

    _a = x;
}

void Fenetre::bCalcul()
{
    double rep = _CPrime._y - (_petitLambda2*_C._y);
    int x = (int) rep;
    _b = x;
}

double Fenetre::getLambda() const
{
    return _Lambda;
}
double Fenetre::getPetitLambda1() const
{
    return _petitLambda1;
}

double Fenetre::getPetitLambda2() const
{
    return _petitLambda2;
}

int Fenetre::getEps1() const
{
    return _eps1;
}

int Fenetre::getEps2() const
{
    return _eps2;
}

int Fenetre::aGet() const
{
    return _a;
}
int Fenetre::bGet() const
{
   return _b;
}

void Fenetre::translation(Vecteur2D v)
{
    for(int i = 0;i< _TabForme.size();i++)
    {
        Forme *f = _TabForme[i];
        f->translation(v);
    }
}


void Fenetre::homothetie(double rapport,const Vecteur2D &V)
{
    for(int i = 0;i< _TabForme.size();i++)
    {
        Forme *f = _TabForme[i];
        f->homothetie(rapport,V);
    }
}

void Fenetre::rotation(double angle, const Vecteur2D& centreRotation)
{
    for(int i = 0;i< _TabForme.size();i++)
    {
        Forme *f = _TabForme[i];
        f->rotation(angle,centreRotation);
    }
}

bool Fenetre::isCalculEffectue() const
{
    return calculsEffectues;
}

void Fenetre::setCalculEffectue(bool b)
{
    calculsEffectues = b;
}

vector<Forme*> Fenetre::getListeForme() const
{
    return _TabForme;
}


void Fenetre::dessiner(FormeVisitor* F)
{
    if(!isCalculEffectue()) {
        //Détermination de lambda
        CalculP1();
        CalculP2();
        CalculP1Prime();
        CalculP2Prime();
        CalculLambda();
        getP1Prime();
        getP2Prime();
        getP1();
        getP2();
        CalculEps1();
        CalculEps2();
        CalculC();
        CalculCPrime();
        CalculPetitLambda1();
        CalculPetitLambda2();
        aCalcul();
        bCalcul();
        setCalculEffectue(true);
    }
    for(int i = 0;i<_TabForme.size();i++)
    {
        _TabForme[i]->accepter(F);
    }
}

void Fenetre::sauvegarder(SauvegardeVisitor * S) const
{
    for(int i = 0;i<_TabForme.size();i++)
    {
        _TabForme[i]->accepter(S);
    }
}

void Fenetre::charger(string nomFichier)
{
    ifstream * outfile = new ifstream ();
    size_t dotPos = nomFichier.find_last_of('.');
    if (dotPos != std::string::npos)
    {
        if(nomFichier.substr(dotPos + 1) == "txt")
        {
            outfile->open(nomFichier);
            string ligne;
            if (outfile->is_open())
            {
                while (getline(*outfile, ligne))
                {
                    cout << ligne << "\n";
                    Forme *pForme = nullptr;
                    _COR->charger(ligne,pForme);
                    ajouterForme(*pForme);
                }
                outfile->close();
            }
        }

    }


}
