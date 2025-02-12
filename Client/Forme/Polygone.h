//
// Created by Ahmet on 23/02/2024.
//

#ifndef APP2_POLYGONE_H
#define APP2_POLYGONE_H

#include "Groupe.h"
#include "../Vecteur2D.h"

class FormeVisitor;

/**
 * @brief Représente un polygone dans le plan.
 *_
 * Le polygone est défini par une liste de points dans le plan.
 */
class Polygone : public FormeGeometrique {
private:
    vector<Vecteur2D*> _TabPoints; /**< Liste des points du polygone. */

    /**
     * @brief Copie les attributs du polygone source.
     * @param P Polygone source.
     */
    void copier(const Polygone & P);

    /**
     * @brief Libère la mémoire allouée dynamiquement par le polygone.
     */
    void detruire() override;
public:
    /**
     * @brief Constructeur de la classe Polygone.
     * @param couleur Couleur du polygone.
     * @param points Liste des points du polygone.
     */
    Polygone(Couleur couleur,vector<Vecteur2D*> points);

    /**
     * @brief Constructeur de copie de la classe Polygone.
     * @param P Polygone à copier.
     */
    Polygone(const Polygone & P);

    /**
      * @brief Obtient la liste des points du polygone.
      * @return Liste des points du polygone.
      */
    vector<Vecteur2D*> getTabPoints() const;

    /**
     * @brief Crée une copie du polygone.
     * @return Pointeur vers le nouveau polygone.
     */
    Polygone * clone() const override;

    /**
      * @brief Destructeur de la classe Polygone.
      */
    ~Polygone();

    /**
     * @brief Affiche le polygone sur le flux de sortie donné.
     * @param os Flux de sortie.
     */
    void afficher(ostream& os) const override;

    /**
     * @brief Obtient la coordonnée minimale en x du polygone.
     * @return Coordonnée minimale en x.
     */
    double getMinX() const override;

    /**
     * @brief Obtient la coordonnée minimale en y du polygone.
     * @return Coordonnée minimale en y.
     */
    double getMinY() const override;

    /**
      * @brief Obtient la coordonnée maximale en x du polygone.
      * @return Coordonnée maximale en x.
      */
    double getMaxX() const override;

    /**
     * @brief Obtient la coordonnée maximale en y du polygone.
     * @return Coordonnée maximale en y.
     */
    double getMaxY() const override;

    /**
     * @brief Calcule l'aire du polygone.
     * @return Aire du polygone.
     */
    double CalculAire() const;

    /**
     * @brief Calcule le déterminant de deux vecteurs.
     * @param v1 Premier vecteur.
     * @param v2 Deuxième vecteur.
     * @return Valeur du déterminant.
     */
    double determinant(const Vecteur2D& v1, const Vecteur2D& v2) const;


    string algo(int eps1,int eps2,double _Lambda,int _a, int _b) const;

    /**
     * @brief Triangule le polygone en triangles convexes.
     * @return Liste des triangles formant la triangulation.
     */
    vector<vector<Vecteur2D*>> trianguler() const;

    /**
     * @brief Vérifie si un point est une oreille du polygone.
     * @param polygon Liste des points du polygone.
     * @param i Indice du point.
     * @return Vrai si le point est une oreille, sinon faux.
     */
    bool estOreille(const std::vector<Vecteur2D*>& polygon, int i) const;

    /**
     * @brief Effectue une translation du polygone.
     * @param v Vecteur de translation.
     */
    void translation(Vecteur2D& v) override;

    /**
     * @brief Effectue une homothétie du polygone.
     * @param rapport Facteur d'échelle.
     * @param pointInvariant Point invariant de l'homothétie.
     */
    void homothetie(double rapport, const Vecteur2D & pointInvariant) override;

    /**
       * @brief Effectue une rotation du polygone.
       * @param angle Angle de rotation en degrés.
       * @param centreRotation Centre de rotation.
       */
    void rotation(double angle, const Vecteur2D& centreRotation) override;

    /**
     * @brief Calcule le centre du polygone.
     * @return Vecteur2D représentant le centre du polygone.
     */
    Vecteur2D calculerCentre() const;

    /**
     * @brief Vérifie si un point est à l'intérieur d'un triangle défini par trois points.
     * @param a Premier sommet du triangle.
     * @param b Deuxième sommet du triangle.
     * @param c Troisième sommet du triangle.
     * @param p Point à vérifier.
     * @return true si le point est à l'intérieur, false sinon.
     */
    bool estInterieurDuTriangle(Vecteur2D* a, Vecteur2D* b, Vecteur2D* c, Vecteur2D* p) const;

    /**
     * @brief Accepte un visiteur de formes pour appliquer des actions spécifiques.
     * @param F Visiteur de formes.
     */
    void accepter(FormeVisitor *F) const override;

    /**
     * @brief Accepte un visiteur de sauvegarde pour sauvegarder la forme.
     * @param S Visiteur de sauvegarde.
     */
    void accepter(SauvegardeVisitor *S) const override;

    /**
     * @brief Opérateur de conversion en chaîne de caractères.
     * @return Chaîne de caractères représentant la forme.
     */
    operator string() const override;

/**
      * @brief Opérateur d'assignation d'un polygone.
      * @param G polygone à assigner.
      * @return Référence vers le polygone actuel.
      */
    const Polygone & operator = (const Polygone &P);

};


#endif //APP2_POLYGONE_H
