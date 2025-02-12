//
//  Vecteur2D.hpp
//  Project
//
//  Created by Ahmet on 06/12/2023.
//

#ifndef Vecteur2D_hpp
#define Vecteur2D_hpp

#include <string>
#include <sstream>

class Matrice2x2;

using namespace std;

/**
 * @class Vecteur2D
 * @brief Représente un vecteur 2D avec des composantes x et y.
 */
class Vecteur2D{
public:
    double _x; ///< Composante x du vecteur 2D.
    double _y; ///< Composante y du vecteur 2D.


    /**
     * @brief Constructeur explicite pour Vecteur2D.
     * @param x Valeur initiale pour la composante x (par défaut, 0).
     * @param y Valeur initiale pour la composante y (par défaut, 0).
     */
    explicit Vecteur2D(const double &x = 0, const double &y = 0):_x(x),_y(y){}

    /**
       * @brief Opérateur de conversion en chaîne de caractères.
       * @return Représentation en chaîne de caractères du vecteur 2D.
       */
    operator string () const;

    /**
     * @brief Addition de deux vecteurs 2D.
     * @param V Deuxième vecteur 2D à ajouter.
     * @return Vecteur 2D résultant après l'addition.
     */
    const Vecteur2D operator + (const Vecteur2D &V) const;

    const Vecteur2D operator -() const
    {
        return Vecteur2D(-_x,-_y);
    }


    /**
      * @brief Soustraction de deux vecteurs 2D.
      * @param V Deuxième vecteur 2D à soustraire.
      * @return Vecteur 2D résultant après la soustraction.
      */
    const Vecteur2D operator - (const Vecteur2D &V) const;

    /**
     * @brief Affectation par addition d'un autre vecteur 2D.
     * @param V Deuxième vecteur 2D à ajouter.
     * @return Référence au vecteur 2D mis à jour.
     */
    const Vecteur2D & operator +=(const Vecteur2D &V);

    /**
     * @brief Multiplication scalaire du vecteur 2D.
     * @param a Valeur scalaire pour la multiplication.
     * @return Vecteur 2D résultant après la multiplication scalaire.
     */
    const Vecteur2D operator * (const double & a) const;


    /**
     * @brief Opérateur d'insertion de flux surchargé pour afficher le vecteur 2D.
     * @param s Flux de sortie.
     * @param V Vecteur 2D à afficher.
     * @return Flux de sortie.
     */
    friend ostream & operator << (ostream &s, const Vecteur2D &V);


    const Vecteur2D & operator -=(const Vecteur2D &V);


};

/**
 * @brief Opérateur d'insertion de flux surchargé pour afficher le vecteur 2D.
 * @param s Flux de sortie.
 * @param V Vecteur 2D à afficher.
 * @return Flux de sortie.
 */
inline ostream & operator << (ostream &s, const Vecteur2D &V)
{
    return s << (string)V;
}
#endif /* Vecteur2D_hpp */
