//
// Created by Ahmet on 21/02/2024.
//

#include "Vecteur2D.h"
#include "Matrice2x2.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Vecteur2D::operator string () const
{
    ostringstream o;
    o << "( " << _x << ", " << _y <<" )" ;
    return o.str();
}


const Vecteur2D Vecteur2D::operator + (const Vecteur2D &V) const
{
    return Vecteur2D( _x+V._x, _y+V._y);

}

const Vecteur2D & Vecteur2D::operator +=(const Vecteur2D &V)
{
    _x += V._x;
    _y += V._y;
    return *(this);
}

const Vecteur2D & Vecteur2D::operator -=(const Vecteur2D &V)
{
    *this += -V;
    return *this;
}


const Vecteur2D Vecteur2D::operator * (const double & a) const
{
    return Vecteur2D( _x*a, _y*a);
}



const Vecteur2D Vecteur2D::operator - (const Vecteur2D &V) const
{
    return Vecteur2D(_x - V._x, _y - V._y);
}