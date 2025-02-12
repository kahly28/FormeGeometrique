//
// Created by Ahmet on 05/03/2024.
//

#ifndef APP2_COULEURCOR_H
#define APP2_COULEURCOR_H


#include "../Forme/Forme.h"

/**
 * @brief La classe CouleurCOR est une classe abstraite de la chaîne de responsabilité qui gère le choix de la couleur.
 */
class CouleurCOR {
private:

    CouleurCOR * _suivant;  ///< Pointeur vers le maillon suivant dans la chaîne de responsabilité.

public:
    /**
     * @brief Constructeur de CouleurCOR.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     * Initialise le maillon avec le suivant de la chaîne.
     */
    CouleurCOR(CouleurCOR * suivant): _suivant(suivant)
    {}

    /**
     * @brief Méthode abstraite chargée de choisir la couleur à partir de la ligne de chargement.
     * @param ligne Ligne de chargement.
     * @param c Pointeur vers la couleur à mettre à jour.
     * Méthode pure virtuelle qui doit être implémentée par les sous-classes.
     */
    virtual Couleur choixCouleur(string ligne, Couleur *&c) const = 0;

    /**
     * @brief Méthode permettant de passer la demande de choix de couleur au maillon suivant dans la chaîne de responsabilité.
     * @param ligne Ligne de chargement.
     * @param c Pointeur vers la couleur à mettre à jour.
     */
    void choixCouleurSuivant(string ligne, Couleur *&c ) const
    {
        _suivant->choixCouleur(ligne,c);
    }

};


#endif //APP2_COULEURCOR_H
