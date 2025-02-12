//
// Created by Ahmet on 22/02/2024.
//

#ifndef APP2_GROUPE_H
#define APP2_GROUPE_H
using namespace std;

#include <string>
#include "FormeGeometrique.h"
#include <vector>

class FormeVisitor;
class SauvegardeVisitor;

class Groupe : public Forme {

private:
    /**
     * @brief Liste des formes géométriques contenues dans le groupe.
     */
    vector<Forme*> _ListeForme;

    /**
     * @brief Copie les attributs d'un autre groupe.
     * @param G Groupe à copier.
     */
    void copier(const Groupe &G)
    {
        _ListeForme = G.getListeForme();
    }

    /**
      * @brief Ne fait rien, car la destruction des formes est gérée par le groupe parent.
      */
    void detruire()
    {

    }
public:
    /**
     * @brief Constructeur d'un groupe avec une couleur.
     * @param couleur Couleur du groupe.
     */
    Groupe(Couleur couleur);

    /**
     * @brief Constructeur d'un groupe avec une couleur et une liste de formes.
     * @param couleur Couleur du groupe.
     * @param Tab Liste des formes à ajouter au groupe.
     * @param nb Nombre de formes dans la liste.
     */
    Groupe(Couleur couleur,vector<Forme*>Tab,int nb);


    /**
     * @brief Constructeur de copie d'un groupe.
     * @param G Groupe à copier.
     */
    Groupe(const Groupe &G);

    /**
     * @brief Retourne la liste des formes contenues dans le groupe.
     * @return Vector de formes géométriques.
     */
    vector<Forme*> getListeForme() const;

    /**
     * @brief Retourne le nombre de formes dans le groupe.
     * @return Nombre de formes dans le groupe.
     */
    int getNbForme() const;

    /**
     * @brief Retourne une forme spécifique du groupe.
     * @param i Indice de la forme dans la liste.
     * @return Pointeur vers la forme géométrique.
     */
    Forme * getForme(int i ) const;

    /**
     * @brief Ajoute une forme géométrique au groupe.
     * @param forme Forme géométrique à ajouter.
     * @return Référence vers le groupe actuel.
     */
    Groupe & ajouterFormeGeometrique(Forme & forme);


    /**
      * @brief Clone le groupe.
      * @return Pointeur vers le groupe cloné.
      */
    Groupe * clone() const override;

    /**
     * @brief Retire une forme géométrique du groupe.
     * @param forme Forme géométrique à retirer.
     * @return Référence vers le groupe actuel.
     */
    Groupe & retirerFormeGeometrique(Forme & forme);

    /**
      * @brief Opérateur d'assignation d'un groupe.
      * @param G Groupe à assigner.
      * @return Référence vers le groupe actuel.
      */
    const Groupe & operator = (const Groupe &G);

    /**
     * @brief Opérateur d'ajout d'une forme géométrique au groupe.
     * @param F Forme géométrique à ajouter.
     * @return Référence vers le groupe actuel.
     */
    Groupe & operator + (Forme &F) override;

    /**
      * @brief Vide le groupe de ses formes géométriques.
      * @return Référence vers le groupe actuel.
      */
    Groupe & clear();

    /**
     * @brief Retourne la coordonnée X minimale du groupe.
     * @return Coordonnée X minimale.
     */
    double getMinX() const override;

    /**
     * @brief Retourne la coordonnée Y minimale du groupe.
     * @return Coordonnée Y minimale.
     */
    double getMinY() const override;

    /**
     * @brief Retourne la coordonnée X maximale du groupe.
     * @return Coordonnée X maximale.
     */
    double getMaxX() const override;

    /**
     * @brief Retourne la coordonnée Y maximale du groupe.
     * @return Coordonnée Y maximale.
     */
    double getMaxY() const override;

    /**
     * @brief Calcul de l'aire du groupe (somme des aires de ses formes).
     * @return Aire du groupe.
     */
    double CalculAire() const;

    /**
     * @brief Destructeur du groupe.
     */
    ~Groupe();


    string algo(int eps1,int eps2,double _Lambda,int _a, int _b) const override;

    /**
     * @brief Translation du groupe.
     * @param v Vecteur de translation.
     */
    void translation(Vecteur2D& v) override;

    /**
     * @brief Homothétie du groupe.
     * @param rapport Rapport d'homothétie.
     * @param V Point invariant de l'homothétie.
     */
    void homothetie(double rapport,const Vecteur2D & V) override;

    /**
     * @brief Rotation du groupe.
     * @param angle Angle de rotation.
     * @param centreRotation Centre de rotation.
     */
    void rotation(double angle, const Vecteur2D& centreRotation);

    /**
     * @brief Affichage du groupe.
     * @param os Flux de sortie.
     */
    void afficher(ostream &os) const override;

    /**
     * @brief Accepte un visiteur de forme.
     * @param F Visiteur de forme.
     */
    void accepter(FormeVisitor * F) const override;

    /**
      * @brief Accepte un visiteur de sauvegarde.
      * @param S Visiteur de sauvegarde.
      */
    void accepter(SauvegardeVisitor *S) const override;

    /**
     * @brief Conversion du groupe en chaîne de caractères.
     * @return Chaîne représentant le groupe.
     */
    operator string() const override;


};


#endif //APP2_GROUPE_H
