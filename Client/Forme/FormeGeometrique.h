//
// Created by Ahmet on 26/02/2024.
//

#ifndef APP2_FORMEGEOMETRIQUE_H
#define APP2_FORMEGEOMETRIQUE_H




#include "Forme.h"
#include "../Vecteur2D.h"

class Groupe;

class FormeGeometrique : public Forme {
private:
    int _nbPoints;


    /**
     * @brief Copie les attributs d'une forme géométrique.
     * @param F Forme géométrique à copier.
     */
   void copier( const FormeGeometrique & F);

    /**
      * @brief Ne fait rien, car la destruction des formes géométriques est gérée par le groupe parent.
      */
   virtual void detruire() override;


protected :
    /**
     * @brief Accepte un visiteur de forme.
     * @param F Visiteur de forme.
     */
    virtual void accepter(FormeVisitor *F) const = 0;

    /**
     * @brief Accepte un visiteur de sauvegarde.
     * @param S Visiteur de sauvegarde.
     */
    virtual void accepter(SauvegardeVisitor *S) const = 0;

public:
    /**
     * @brief Constructeur de copie d'une forme géométrique.
     * @param F Forme géométrique à copier.
     */
    FormeGeometrique(FormeGeometrique & F);

    /**
     * @brief Constructeur d'une forme géométrique avec couleur et nombre de points.
     * @param couleur Couleur de la forme géométrique.
     * @param nbPoints Nombre de points.
     */
    FormeGeometrique(Couleur couleur, int nbPoints);

    /**
     * @brief Retourne le nombre de points de la forme géométrique.
     * @return Nombre de points.
     */
    int getNbPoints() const;

    /**
      * @brief Retourne le groupe parent de la forme géométrique.
      * @return Pointeur vers le groupe parent ou nullptr s'il n'y en a pas.
      */
    Groupe * recevoirGroupeParent() const;

    /**
      * @brief Opérateur d'ajout d'une forme au groupe.
      * @param F Forme à ajouter.
      * @return Référence vers le groupe actuel.
      */
    Groupe & operator + (Forme & F)  override;

    /**
     * @brief Clone la forme géométrique.
     * @return Pointeur vers la forme géométrique clonée.
     */
    virtual FormeGeometrique * clone() const = 0;

    /**
     * @brief Retourne la coordonnée X minimale de la forme géométrique.
     * @return Coordonnée X minimale.
     */
    virtual double getMinX() const = 0;

    /**
     * @brief Retourne la coordonnée Y minimale de la forme géométrique.
     * @return Coordonnée Y minimale.
     */
    virtual double getMinY() const = 0;

    /**
      * @brief Retourne la coordonnée X maximale de la forme géométrique.
      * @return Coordonnée X maximale.
      */
    virtual double getMaxX() const = 0;

    /**
      * @brief Retourne la coordonnée Y maximale de la forme géométrique.
      * @return Coordonnée Y maximale.
      */
    virtual double getMaxY() const = 0;

    /**
     * @brief Calcul de l'aire de la forme géométrique.
     * @return Aire de la forme géométrique.
     */
    virtual double CalculAire() const = 0;

    /**
      * @brief Translation de la forme géométrique.
      * @param v Vecteur de translation.
      */
    virtual void translation(Vecteur2D & v) = 0;

    /**
     * @brief Homothétie de la forme géométrique.
     * @param rapport Rapport d'homothétie.
     * @param pointInvariant Point invariant de l'homothétie.
     */
    virtual void homothetie(double rapport,const Vecteur2D& pointInvariant) = 0;

    /**
     * @brief Rotation de la forme géométrique.
     * @param angle Angle de rotation.
     * @param centreRotation Centre de rotation.
     */
    virtual void rotation(double angle, const Vecteur2D& centreRotation) = 0;


    virtual string algo(int eps1,int eps2,double _Lambda,int _a, int _b) const = 0;

    /**
     * @brief Conversion de la forme géométrique en chaîne de caractères.
     * @return Chaîne représentant la forme géométrique.
     */
    virtual operator string() const =0;

    /**
     * @brief Destructeur de la forme géométrique.
     */
    virtual ~FormeGeometrique();

    /**
     * @brief Affichage de la forme géométrique.
     * @param os Flux de sortie.
     */
    virtual void afficher(ostream& os) const =0;

    const FormeGeometrique & operator = (const FormeGeometrique &F);


};


#endif //APP2_FORMEGEOMETRIQUE_H
