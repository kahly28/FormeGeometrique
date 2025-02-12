//
// Created by Ahmet on 27/12/2023.
//

#ifndef CLIENT_CROIX_H
#define CLIENT_CROIX_H

#include <string>
#include "Groupe.h"
#include "../Erreur.h"

using namespace std;

class FormeVisitor;
class SauvegardeVisitor;

/**
 * @brief Représente une croix dans le plan.
 *
 * La croix est définie par deux points, HautGauche et BasDroite, formant les coins opposés du rectangle englobant de la croix.
 */
class Croix : public FormeGeometrique {
private:
    Vecteur2D _HautGauche; /**< Position du coin supérieur gauche de la croix. */
    Vecteur2D _BasDroite; /**< Position du coin inférieur droit de la croix. */
    Vecteur2D _HautDroite; /**< Position du coin supérieur droit de la croix. */
    Vecteur2D _BasGauche; /**< Position du coin inférieur gauche de la croix. */

    /**
     * @brief Copie les attributs de la croix source.
     * @param C Croix source.
     */
    void copier(const Croix & C);

    /**
      * @brief Libère la mémoire allouée dynamiquement par la croix.
      */
    void detruire() override;

public:
    /**
     * @brief Constructeur de la classe Croix.
     * @param couleur Couleur de la croix.
     * @param hautGauche Position du coin supérieur gauche.
     * @param basDroite Position du coin inférieur droit.
     */
    Croix(Couleur couleur, Vecteur2D &hautGauche, Vecteur2D & basDroite);

    /**
     * @brief Constructeur de copie de la classe Croix.
     * @param C Croix à copier.
     */
    Croix(const Croix & C);

    /**
     * @brief Obtient la position du coin supérieur gauche de la croix.
     * @return Position du coin supérieur gauche.
     */
    Vecteur2D getHautGauche() const;

    /**
     * @brief Obtient la position du coin inférieur droit de la croix.
     * @return Position du coin inférieur droit.
     */
    Vecteur2D getBasDroite() const;

    /**
     * @brief Obtient la position du coin supérieur droit de la croix.
     * @return Position du coin supérieur droit.
     */
    Vecteur2D getHautDroite() const;

    /**
     * @brief Obtient la position du coin inférieur gauche de la croix.
     * @return Position du coin inférieur gauche.
     */
    Vecteur2D getBasGauche() const;

    /**
     * @brief Destructeur de la classe Croix.
     */
    ~Croix();

    /**
     * @brief Crée une copie de la croix.
     * @return Pointeur vers la nouvelle croix.
     */
    Croix * clone() const override;

    /**
     * @brief Obtient la coordonnée minimale en x de la croix.
     * @return Coordonnée minimale en x.
     */
    double getMinX() const override;

    /**
      * @brief Obtient la coordonnée minimale en y de la croix.
      * @return Coordonnée minimale en y.
      */
    double getMinY() const override;

    /**
     * @brief Obtient la coordonnée maximale en x de la croix.
     * @return Coordonnée maximale en x.
     */
    double getMaxX() const override;

    /**
     * @brief Obtient la coordonnée maximale en y de la croix.
     * @return Coordonnée maximale en y.
     */
    double getMaxY() const override;

    /**
     * @brief Affiche la croix sur le flux de sortie donné.
     * @param os Flux de sortie.
     */
    void afficher(ostream& os) const override;

        /**
      * @brief Calcule l'aire de la croix.
      * @return Aire de la croix.
      */
    double CalculAire() const;

    /**
     * @brief Effectue une translation de la croix.
     * @param v Vecteur de translation.
     */
    void translation(Vecteur2D & v) override;

    /**
     * @brief Génère une représentation algorithmique de la croix.
     * @param eps1 Paramètre epsilon 1.
     * @param eps2 Paramètre epsilon 2.
     * @param _Lambda Paramètre lambda.
     * @param _a Paramètre a.
     * @param _b Paramètre b.
     * @return Chaîne de caractères représentant l'algorithme.
     */
    string algo(int eps1,int eps2,double _Lambda,int _a, int _b) const override;

    /**
     * @brief Effectue une homothétie de la croix.
     * @param rapport Facteur d'échelle.
     * @param pointInvariant Point invariant de l'homothétie.
     */
    void homothetie(double rapport,const Vecteur2D& pointInvariant) override;

    /**
      * @brief Effectue une rotation de la croix.
      * @param angle Angle de rotation en degrés.
      * @param centreRotation Centre de rotation.
      */
    void rotation(double angle, const Vecteur2D& centreRotation) override;

    /**
     * @brief Accepte un visiteur de forme pour la croix.
     * @param F Visiteur de forme.
     */
    void accepter(FormeVisitor * F) const override;

    /**
     * @brief Accepte un visiteur de sauvegarde pour la croix.
     * @param S Visiteur de sauvegarde.
     */
    void accepter(SauvegardeVisitor * S) const override;

    /**
     * @brief Convertit la croix en une chaîne de caractères.
     * @return Chaîne de caractères représentant la croix.
     */
    operator string() const override;

    /**
      * @brief Opérateur d'assignation d'une croix.
      * @param G croix à assigner.
      * @return Référence vers la croix actuel.
      */
    const Croix & operator = (const Croix &C);

};




#endif //CLIENT_CROIX_H
