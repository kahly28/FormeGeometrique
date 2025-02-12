//
// Created by Ahmet on 08/01/2024.
//

#ifndef APP2_FENETRE_H
#define APP2_FENETRE_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Erreur.h"
#include "Forme/Forme.h"
#include "Vecteur2D.h"
#include "Forme/Forme.h"
#include "ChargementCOR/ChargerCroix.h"
#include "ChargementCOR/ChargerGroupe.h"
#include "ChargementCOR/ChargerPolygone.h"
#include "ChargementCOR/ChargerRond.h"

using namespace std;

/**
 * @class Fenetre
 * @brief Représente une fenêtre avec diverses formes géométriques.
 */
class Fenetre {
private:

    int _x; ///< Coordonnée en X de la fenêtre.
    int _y; ///< Coordonnée en Y de la fenêtre.
    int _h; ///< Hauteur de la fenêtre.
    int _l; ///< Largeur de la fenêtre.
    vector<Forme*> _TabForme; ///< Vecteur stockant des pointeurs vers des formes géométriques.

    Vecteur2D _P1Prime; ///< Point P1'.
    Vecteur2D _P2Prime; ///< Point P2'.
    double _Lambda; ///< Lambda.
    double _petitLambda1; ///< Petit Lambda1.
    double _petitLambda2; ///< Petit Lambda2.
    int _eps1;  ///< Epsilon1.
    int _eps2; ///< Epsilon2.
    Vecteur2D _C; ///< Point centre C.
    Vecteur2D _CPrime; ///< Point centre C'.
    int _a; ///< a.
    int _b; ///< b.
    bool calculsEffectues; ///< Indicateur indiquant si les calculs sont effectués.
    ChargementCOR * _COR; ///< Pointeur vers l'objet de la Chaîne de Responsabilité pour le chargement.


public:

    Vecteur2D _P1; ///< Point P1.
    Vecteur2D _P2; ///< Point P2.
    /**
    * @brief Constructeur pour la classe Fenetre.
    * @param x Coordonnée X de la fenêtre.
    * @param y Coordonnée Y de la fenêtre.
    * @param h Hauteur de la fenêtre.
    * @param l Largeur de la fenêtre.
    */
    Fenetre(int x, int y, int h,int l);

    /**
     * @brief Accesseur pour la coordonnée X de la fenêtre.
     * @return Coordonnée X de la fenêtre.
     */
    double getX() const;

    /**
     * @brief Accesseur pour la coordonnée Y de la fenêtre.
     * @return Coordonnée Y de la fenêtre.
     */
    double getY() const;

    /**
     * @brief Accesseur pour le vecteur de formes géométriques.
     * @return Vecteur de formes géométriques.
     */
    vector<Forme*> getTabForme();

    /**
    * @brief Accesseur pour la hauteur de la fenêtre.
    * @return Hauteur de la fenêtre.
    */
    double getH() const;


    /**
    * @brief Accesseur pour la largeur de la fenêtre.
    * @return Largeur de la fenêtre.
    */
    double getL() const;

    /**
    * @brief Ajoute une forme géométrique à la fenêtre.
    * @param forme Référence à la forme géométrique à ajouter.
    * @return Référence à l'objet Fenetre mis à jour.
    */
    Fenetre & ajouterForme(Forme & forme);

    /**
     * @brief Retire une forme géométrique de la fenêtre.
     * @param forme Référence à la forme géométrique à retirer.
     * @return Référence à l'objet Fenetre mis à jour.
     */
    Fenetre & retirerForme(Forme & forme);

    /**
    * @brief Accesseur pour le nombre de formes géométriques dans la fenêtre.
    * @return Nombre de formes géométriques dans la fenêtre.
    */
    int getNbForme() const;

    /**
    * @brief Calcule le point P1.
    */
    void CalculP1();

    /**
     * @brief Calcule le point P2.
     */
    void CalculP2();

    /**
    * @brief Calcule le premier point P1'.
    */
    void CalculP1Prime();

    /**
      * @brief Calcule le premier point P2'.
      */
    void CalculP2Prime();

    /**
      * @brief Calcule la valeur Lambda.
      */
    void CalculLambda();

    /**
     * @brief Accesseur pour le point P1'.
     * @return point P1'.
     */
    Vecteur2D getP1Prime() const;

    /**
     * @brief Accesseur pour le point P2'.
     * @return point P2'.
     */
    Vecteur2D getP2Prime() const;

    /**
     * @brief Accesseur pour le point P1.
     * @return point P1.
     */
    Vecteur2D getP1() const;

    /**
     * @brief Accesseur pour le point P2.
     * @return point P2.
     */
    Vecteur2D getP2() const;

    /**
     * @brief Calcule la valeur Epsilon 1.
     */
    void CalculEps1();

    /**
     * @brief Calcule la valeur Epsilon 2.
     */
    void CalculEps2();

    /**
     * @brief Accesseur pour la valeur Lambda.
     * @return Valeur Lambda.
     */
    double getLambda() const;

    /**
     * @brief Accesseur pour la valeur Petit Lambda 1.
     * @return Petit Lambda 1.
     */
    double getPetitLambda1() const;

    /**
     * @brief Accesseur pour la valeur Petit Lambda 2.
     * @return Petit Lambda 2.
     */
    double getPetitLambda2() const;

    /**
     * @brief Accesseur pour la valeur Epsilon 1.
     * @return Valeur Epsilon 1.
     */
    int getEps1() const;

    /**
     * @brief Accesseur pour la valeur Epsilon 2.
     * @return Valeur Epsilon 2.
     */
    int getEps2() const;

    /**
     * @brief Accesseur pour la valeur 'a'.
     * @return Valeur 'a'.
     */
    int aGet() const;

    /**
     * @brief Accesseur pour la valeur 'b'.
     * @return Valeur 'b'.
     */
    int bGet() const;

    /**
     * @brief Calcule le centre C.
     */
    void CalculC();

    /**
     * @brief Calcule le centre C'.
     */
    void CalculCPrime();

    /**
      * @brief Calcule la valeur petit Lambda 1.
      */
    void CalculPetitLambda1();

    /**
     * @brief Calcule la valeur petit Lambda 2.
     */
    void CalculPetitLambda2();

    /**
      * @brief Calcule la valeur 'a'.
      */
    void aCalcul();

    /**
     * @brief Calcule la valeur 'b'.
     */
    void bCalcul();

    /**
     * @brief Effectue une translation par le vecteur donné.
     * @param v Vecteur de translation.
     */
    void translation(Vecteur2D v);

    /**
     * @brief Effectue une homothétie par rapport à un point donné.
     * @param rapport Rapport d'homothétie.
     * @param V Vecteur représentant le point de référence.
     */
    void homothetie(double rapport,const Vecteur2D &V);

    /**
        * @brief Effectue une rotation par rapport à un centre de rotation donné.
        * @param angle Angle de rotation en degrés.
        * @param centreRotation Vecteur représentant le centre de rotation.
        */
    void rotation(double angle, const Vecteur2D& centreRotation);

    /**
     * @brief Vérifie si les calculs sont effectués.
     * @return True si les calculs sont effectués, sinon False.
     */
    bool isCalculEffectue() const;

    /**
     * @brief Modifie l'état des calculs.
     * @param b Nouvelle valeur d'état des calculs.
     */
    void setCalculEffectue(bool b);

    /**
      * @brief Accesseur pour la liste des formes géométriques.
      * @return Liste des formes géométriques.
      */
    vector<Forme*> getListeForme() const;

    /**
     * @brief Dessine les formes géométriques en utilisant le visiteur donné.
     * @param F Pointeur vers le visiteur de formes.
     */
    void dessiner(FormeVisitor* F);

    /**
     * @brief Sauvegarde les formes géométriques en utilisant le visiteur donné.
     * @param S Pointeur vers le visiteur de sauvegarde.
     */
    void sauvegarder(SauvegardeVisitor * S) const;

    /**
     * @brief Charge les formes géométriques à partir d'un fichier spécifié.
     * @param nomFichier Nom du fichier de chargement.
     */
    void charger(string nomFichier);




};


#endif //APP2_FENETRE_H
