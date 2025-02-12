//
// Created by Ahmet on 27/12/2023.
//

#ifndef CLIENT_FORME_H
#define CLIENT_FORME_H

#include <string>
#include <iostream>
#include <string.h>
#include "../Vecteur2D.h"
using namespace std;

class Groupe;
class FormeVisitor;
class SauvegardeVisitor;


/**
 * @enum Couleur
 * @brief Enumération des couleurs possibles pour les formes.
 */
enum Couleur
{
    black,blue,red,green,yellow,cyan //Mauvaise idée
};

/**
 * @class Forme
 * @brief Représente une forme abstraite.
 */
class Forme {
    friend class Fenetre;
    friend class FormeVisitor;
    friend class JavaLibraryVisitor;
    friend class SauvegardeVisitor;
private:
    Groupe* _groupeParent; ///< Pointeur vers le groupe parent de la forme.
    Couleur _couleur;      ///< Couleur de la forme.

    /**
      * @brief Détruit la forme.
      */
    virtual void detruire();

    /**
     * @brief Copie les attributs d'une forme donnée.
     * @param F Forme à copier.
     */
    virtual void copier(const Forme & F);

protected :
    /**
     * @brief Accepte un visiteur de formes pour la visite dynamique.
     * @param F Visiteur de formes.
     */
    virtual void accepter(FormeVisitor *F) const = 0;

    /**
     * @brief Accepte un visiteur de sauvegarde pour la sauvegarde dynamique.
     * @param S Visiteur de sauvegarde.
     */
    virtual void accepter(SauvegardeVisitor *S) const = 0;

public:

    /**
     * @brief Constructeur de Forme.
     * @param couleur Couleur de la forme.
     */
    Forme(Couleur couleur);

    /**
     * @brief Constructeur de copie de Forme.
     * @param F Forme à copier.
     */
    Forme(const Forme & F);


    /**
     * @brief Définit le groupe parent de la forme.
     * @param nouveauGroupeParent Nouveau groupe parent.
     */
    void setGroupeParent(Groupe* nouveauGroupeParent);

    /**
     * @brief Obtient le groupe parent de la forme.
     * @return Pointeur vers le groupe parent.
     */
    virtual Groupe * getGroupeParent() const;

    /**
     * @brief Définit la couleur de la forme.
     * @param couleur Nouvelle couleur.
     */
    void setCouleur(Couleur couleur);

    /**
     * @brief Obtient la couleur de la forme.
     * @return Couleur de la forme.
     */
    Couleur getCouleur () const;

    /**
     * @brief Surcharge de l'opérateur d'addition pour l'ajout d'une forme à un groupe.
     * @param F Forme à ajouter.
     * @return Référence vers le groupe résultant.
     */
    virtual Groupe & operator + (Forme & F) = 0;


    /**
     * @brief Surcharge de l'opérateur de sortie pour l'affichage.
     * @param os Flux de sortie.
     * @param F Forme à afficher.
     * @return Flux de sortie mis à jour.
     */
    friend ostream & operator << (ostream &s, const Forme & F);

    /**
      * @brief Clone la forme actuelle.
      * @return Pointeur vers la copie de la forme.
      */
    virtual Forme* clone() const = 0;

    /**
     * @brief Obtient la coordonnée minimale en X de la forme.
     * @return Coordonnée minimale en X.
     */
    virtual double getMinX() const = 0;

    /**
     * @brief Obtient la coordonnée minimale en Y de la forme.
     * @return Coordonnée minimale en Y.
     */
    virtual double getMinY() const = 0;

    /**
     * @brief Obtient la coordonnée maximale en X de la forme.
     * @return Coordonnée maximale en X.
     */
    virtual double getMaxX() const = 0;

    /**
     * @brief Obtient la coordonnée maximale en Y de la forme.
     * @return Coordonnée maximale en Y.
     */
    virtual double getMaxY() const = 0;


    virtual string algo(int eps1,int eps2,double _Lambda,int _a, int _b) const = 0;


    /**
      * @brief Destructeur virtuel de Forme.
      */
    virtual ~Forme();

    /**
     * @brief Convertit une valeur de l'énumération Couleur en une chaîne de caractères.
     * @param c Couleur à convertir.
     * @return Chaîne de caractères représentant la couleur.
     */
    string enumToString(Couleur c) const;

    /**
     * @brief Affiche la forme sur le flux de sortie donné.
     * @param os Flux de sortie.
     */
    virtual void afficher(ostream& os) const =0;

    /**
     * @brief Surcharge de l'opérateur de sortie pour l'affichage d'une forme.
     * @param os Flux de sortie.
     * @param forme Forme à afficher.
     * @return Flux de sortie mis à jour.
     */
    friend ostream& operator<<(ostream& os, const Forme& forme);

    /**
     * @brief Calcule l'aire de la forme.
     * @return Aire de la forme.
     */
    virtual double CalculAire() const = 0;
    /**
     * @brief Effectue une translation de la forme.
     * @param v Vecteur de translation.
     */
    virtual void translation(Vecteur2D& v) = 0;

    /**
     * @brief Effectue une homothétie de la forme.
     * @param rapport Facteur d'échelle.
     * @param pointInvariant Point invariant de l'homothétie.
     */
    virtual void homothetie(double rapport,const Vecteur2D& pointInvariant) = 0;

    /**
     * @brief Effectue une rotation de la forme.
     * @param angle Angle de rotation en degrés.
     * @param centreRotation Centre de rotation.
     */
    virtual void rotation(double angle, const Vecteur2D& centreRotation) = 0;

    /**
     * @brief Convertit la forme en une chaîne de caractères.
     * @return Chaîne de caractères représentant la forme.
     */
    virtual operator string() const =0;

    /**
     * @brief Effectue la rotation d'un point autour d'un centre donné.
     * @param point Point à rotation.
     * @param angle Angle de rotation en degrés.
     * @param centreRotation Centre de rotation.
     * @return Nouveau point après rotation.
     */
    Vecteur2D rotationPoint(const Vecteur2D& point, double angle, const Vecteur2D& centreRotation) const;

};

/**
 * @brief Surcharge de l'opérateur de sortie pour l'affichage d'une forme.
 * @param os Flux de sortie.
 * @param forme Forme à afficher.
 * @return Flux de sortie mis à jour.
 */
inline ostream & operator << (ostream& os, const Forme& forme)
{

    forme.afficher(os);
    return os;
}



#endif //CLIENT_FORME_H
