//
// Created by Ahmet on 21/02/2024.
//

#ifndef APP2_MATRICE2X2_H
#define APP2_MATRICE2X2_H


#include "Vecteur2D.h"
#include <iostream>

/**
 * @class Matrice2x2
 * @brief Représente une matrice 2x2 avec des colonnes représentées par des vecteurs 2D.
 */
class Matrice2x2 {

private:

    Vecteur2D colonne1; ///< Première colonne de la matrice 2x2.
    Vecteur2D colonne2; ///< Deuxième colonne de la matrice 2x2.


public:

    /**
     * @brief Constructeur pour Matrice2x2.
     * @param col1 Première colonne de la matrice.
     * @param col2 Deuxième colonne de la matrice.
     */
    Matrice2x2( Vecteur2D col1, Vecteur2D col2): colonne1(col1),colonne2(col2)
    {
        std::cout << "fdmjdmjdfd" << endl;

    }


    /**
     * @brief Surcharge de l'opérateur d'addition pour les matrices 2x2.
     * @param V Matrice 2x2 à ajouter.
     * @return Matrice 2x2 résultante après l'addition.
     */
    const Matrice2x2 operator + (const Matrice2x2 &V) const
    {
        Vecteur2D vec1(colonne1 + V.colonne1);
        Vecteur2D vec2(colonne2 + V.colonne2);
        return Matrice2x2(vec1,vec2);
    }


    /**
     * @brief Surcharge de l'opérateur de multiplication pour les matrices 2x2.
     * @param V Matrice 2x2 à multiplier.
     * @return Matrice 2x2 résultante après la multiplication.
     */
    const Matrice2x2 operator * (const Matrice2x2 &V) const
    {
        Vecteur2D vec1( (colonne1._x*V.colonne1._x) + (colonne2._x*V.colonne1._y),
                        (colonne1._y*V.colonne1._x) + (colonne2._y * V.colonne1._y));

        Vecteur2D vec2( (colonne1._x*V.colonne2._x) + (colonne2._x*V.colonne2._y),
                        (colonne1._y * V.colonne2._x) + (colonne2._y* V.colonne2._y));

        return Matrice2x2(vec1,vec2);

    }


    /**
     * @brief Surcharge de l'opérateur de multiplication pour une matrice 2x2 avec un vecteur 2D.
     * @param V Vecteur 2D à multiplier.
     * @return Vecteur 2D résultant après la multiplication.
     */
    const Vecteur2D operator * (const Vecteur2D &V) const
    {
        return Vecteur2D( (colonne1._x * V._x) + (colonne2._x * V._y),
                        (colonne1._y*V._x ) + (colonne2._y * V._y));



    }

    /**
     * @brief Conversion implicite en chaîne de caractères.
     * @return Représentation en chaîne de caractères de la matrice 2x2.
     */
    operator string () const
    {
        ostringstream o;
        o << "{ " << colonne1 << ", " << colonne2 <<" }" << endl;
        return o.str();
    }

};

/**
 * @brief Surcharge de l'opérateur d'insertion de flux pour afficher la matrice 2x2.
 * @param s Flux de sortie.
 * @param V Matrice 2x2 à afficher.
 * @return Flux de sortie.
 */
inline ostream & operator << (ostream &s, const Matrice2x2 &V)
{
    return s << (string)V;
}

#endif //APP2_MATRICE2X2_H
