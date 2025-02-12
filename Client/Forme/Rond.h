//
// Created by Ahmet on 27/12/2023.
//

#ifndef CLIENT_ROND_H
#define CLIENT_ROND_H
#include <string>
#include "../Erreur.h"
#include "Groupe.h"
//#include "../Fenetre.h"

using namespace std;

class FormeVisitor;
class SauvegardeVisitor;

/**
 * @brief Représente un cercle dans le plan.
 *
 * Le cercle est défini par un point et un rayon dans le plan.
 */
class Rond : public FormeGeometrique{
private:
    /**
     * @brief Point central du rond.
     */
    Vecteur2D _point;

    /**
      * @brief Rayon du rond.
      */
    double _rayon;

    /**
     * @brief Copie les attributs d'un autre rond.
     * @param R Rond à copier.
     */
    void copier(const Rond & R);

    /**
      * @brief Libère les ressources associées au rond.
      */
    void detruire();

public:
    /**
     * @brief Constructeur de la classe Rond.
     * @param couleur Couleur du rond.
     * @param pt Point central du rond.
     * @param rayon Rayon du rond.
     */
    Rond(Couleur couleur, Vecteur2D pt, double rayon);

    /**
     * @brief Constructeur de copie de la classe Rond.
     * @param R Rond à copier.
     */
    Rond(const Rond & R);

    /**
     * @brief Obtient le point central du rond.
     * @return Vecteur2D représentant le point central du rond.
     */
    Vecteur2D getPoint() const;

    /**
     * @brief Obtient le rayon du rond.
     * @return Valeur du rayon du rond.
     */
    double getRayon() const;

    /**
     * @brief Crée une copie du rond.
     * @return Pointeur vers la copie du rond.
     */
    Rond * clone() const override;

    /**
      * @brief Destructeur de la classe Rond.
      */
    ~Rond();

    /**
     * @brief Obtient la valeur minimale en X parmi les points formant le rond.
     * @return Valeur minimale en X.
     */
    double getMinX() const override;

    /**
     * @brief Obtient la valeur minimale en Y parmi les points formant le rond.
     * @return Valeur minimale en Y.
     */
    double getMinY() const override;

    /**
     * @brief Obtient la valeur maximale en X parmi les points formant le rond.
     * @return Valeur maximale en X.
     */
    double getMaxX() const override;

    /**
     * @brief Obtient la valeur maximale en Y parmi les points formant le rond.
     * @return Valeur maximale en Y.
     */
    double getMaxY() const override;

    string algo(int eps1,int eps2,double _Lambda,int _a, int _b) const override;

    /**
     * @brief Calcule l'aire du rond.
     * @return Valeur de l'aire du rond.
     */
    double CalculAire() const;

    /**
     * @brief Effectue une translation du rond.
     * @param v Vecteur de translation.
     */
    void translation(Vecteur2D& v) override;

    /**
     * @brief Effectue une homothétie du rond.
     * @param rapport Rapport d'homothétie.
     * @param V Point invariant.
     */
    void homothetie(double rapport, const Vecteur2D &V) override;

    /**
     * @brief Effectue une rotation du rond.
     * @param angle Angle de rotation.
     * @param centreRotation Centre de rotation.
     */
    void rotation(double angle, const Vecteur2D& centreRotation) override;

    /**
     * @brief Affiche les informations du rond sur un flux de sortie.
     * @param os Flux de sortie.
     */
    void afficher(ostream &os) const override;

    /**
     * @brief Accepte un visiteur de formes pour appliquer des actions spécifiques.
     * @param F Visiteur de formes.
     */
    void accepter(FormeVisitor * F) const override;

    /**
     * @brief Accepte un visiteur de sauvegarde pour sauvegarder la forme.
     * @param S Visiteur de sauvegarde.
     */
    void accepter(SauvegardeVisitor *S) const override;

    /**
     * @brief Opérateur de conversion en chaîne de caractères.
     * @return Chaîne de caractères représentant le rond.
     */
    operator string() const override;

    /**
      * @brief Opérateur d'assignation d'un cercle.
      * @param G Cercle à assigner.
      * @return Référence vers le cercle actuel.
      */
    const Rond & operator = (const Rond &R);


};



#endif //CLIENT_ROND_H
