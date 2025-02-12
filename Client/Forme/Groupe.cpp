//
// Created by Ahmet on 22/02/2024.
//

#include "Groupe.h"
#include "FormeGeometrique.h"
#include "../Visitor/FormeVisitor.h"
#include "../SauvegardeVisitor/SauvegardeVisitor.h"

Groupe & Groupe::operator + (Forme &F)
{
    ajouterFormeGeometrique(F);
    return *this;
}

/*
Groupe & Groupe::operator + ( Groupe & G)
{
    for(int i = 0;i< G.getListeForme().size() ;i++)
    {
        ajouterFormeGeometrique(*G.getListeForme()[i]);
        G.retirerFormeGeometrique(*G.getListeForme()[i]);
    }
    return *(this);

}

Groupe & Groupe::operator + (FormeGeometrique & F)
{
    ajouterFormeGeometrique(F);
    return *(this);
}
 */

Groupe::Groupe(Couleur couleur):Forme(couleur)
{

}

Groupe::Groupe(Couleur couleur,vector<Forme*>Tab,int nb):Forme(couleur),_ListeForme(Tab)
{}

Groupe::Groupe(const Groupe &G):Forme(G.getCouleur())
{
    copier(G);

}


vector<Forme*> Groupe::getListeForme() const
{
    return _ListeForme;
}

int Groupe::getNbForme() const
{
    return _ListeForme.size();
}

Forme * Groupe::getForme(int i ) const
{
    return _ListeForme[i];
}

Groupe & Groupe::ajouterFormeGeometrique(Forme & forme)
{
    /*
    if(forme.getGroupeParent() != nullptr)
    {
        forme.getGroupeParent()->retirerFormeGeometrique(forme);
    }

     */
    _ListeForme.push_back(&forme);
    forme.setGroupeParent(this);

    /*
    Couleur c = forme.getAncienneCouleur();
    forme.setAncienneCouleur(c);
    _ListeForme.push_back(&forme);
    forme.setGroupeParent(this);
    forme.setCouleur(this->getCouleur());
     */
    return *(this);
}




Groupe * Groupe::clone() const
{
    return new Groupe(*this);
}



Groupe & Groupe::retirerFormeGeometrique(Forme & forme)
{
    for(int i = 0;i< getNbForme();i++)
    {
        if(_ListeForme[i] == &forme)
        {
            cout << "icci" << endl;
            _ListeForme.erase(std::remove(_ListeForme.begin(), _ListeForme.end(), &forme), _ListeForme.end());
            forme.setGroupeParent(nullptr);

        }
    }


    return *(this);
}


const Groupe & Groupe::operator = (const Groupe &G)
{
    detruire();
    copier(G);
    return *(this);
}


Groupe & Groupe::clear()
{
    _ListeForme.clear();
    return *(this);
}

double Groupe::getMinX() const
{
    double x = _ListeForme[0]->getMinX();
    for(int i = 0;i<_ListeForme.size();i++)
    {
        double z = _ListeForme[i]->getMinX();
        if(z < x)
        {
            x = z;
        }
    }
    return x;
}

double Groupe::getMinY() const
{
    double y = _ListeForme[0]->getMinY();
    for(int i = 0;i<_ListeForme.size();i++)
    {
        double z = _ListeForme[i]->getMinY();
        if(z < y)
        {
            y = z;
        }
    }
    return y;
}

double Groupe::getMaxX() const
{
    double x = _ListeForme[0]->getMaxX();
    for(int i = 0;i<_ListeForme.size();i++)
    {
        double z = _ListeForme[i]->getMaxX();
        if(z > x)
        {
        x = z;
        }
    }
    return x;
}



double Groupe::getMaxY() const
{
    double y = _ListeForme[0]->getMaxY();
    for(int i = 0;i<_ListeForme.size();i++)
    {
        double z = _ListeForme[i]->getMaxY();
        if(z > y)
        {
            y = z;
        }
    }
    return y;
}


double Groupe::CalculAire() const
{
    double resultat=0;
    for(int i = 0;i<_ListeForme.size();i++)
    {
        resultat = resultat + _ListeForme[i]->CalculAire();
    }
    return resultat;
}



/*
void dessiner(FormeVisitor& visiteur) const {
    visiteur.visiterGroupe(*this);
}
 */

string Groupe::algo(int eps1,int eps2,double _Lambda,int _a, int _b) const
{
    string groupe = "groupe:";

    string msg = groupe ;
    for(int i = 0;i < _ListeForme.size();i++)
    {
        Forme * f = _ListeForme[i];
        string rep = f->algo(eps1,eps2,_Lambda,_a,_b);
        msg = msg + rep + "|";
    }

    return msg;
}

void Groupe::translation(Vecteur2D& v)
{
    for(int i = 0;i<_ListeForme.size();i++)
    {
        Forme * f = _ListeForme[i];
        f->translation(v);
    }
}

void Groupe::homothetie(double rapport,const Vecteur2D & V)
{
    for(int i = 0;i<_ListeForme.size();i++)
    {
        Forme * f = _ListeForme[i];
        f->homothetie(rapport,V);
    }
}

void Groupe::rotation(double angle, const Vecteur2D& centreRotation)
{
    for(int i = 0;i<_ListeForme.size();i++)
    {
        Forme * f = _ListeForme[i];
        f->rotation(angle,centreRotation);
    }
}

void Groupe::afficher(ostream &os) const
{
    os << "Groupe [Couleur: " << enumToString(getCouleur()) << ", NbFormes: " << getNbForme() << ", Formes: [";
    os << endl;
    for (int i = 0; i < getNbForme(); ++i) {
        os << *getForme(i);
        if (i < getNbForme() - 1) {
            os << ", ";
        }
        os << endl;
    }

    os << "]]";
}

void Groupe::accepter(FormeVisitor * F) const
{
    F->visiterGroupe(*this);
}

void Groupe::accepter(SauvegardeVisitor *S) const
{
    S->visiterGroupe(*this);
}

Groupe::operator string() const
{
    string groupe = "groupe-";
    string couleur = enumToString(getCouleur());
    string msg = groupe + couleur+":";
    for(int i = 0;i < _ListeForme.size();i++)
    {
        Forme * f = _ListeForme[i];
        string rep = f->operator string();
        msg = msg + rep + "|";
    }

    return msg;
}

Groupe::~Groupe()
{
    detruire();
}



