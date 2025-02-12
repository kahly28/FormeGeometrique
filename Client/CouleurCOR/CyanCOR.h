//
// Created by Ahmet on 05/03/2024.
//

#ifndef APP2_CYANCOR_H
#define APP2_CYANCOR_H


#include "CouleurCOR.h"

/**
 * @brief La classe CyanCOR gère la conversion du nom de couleur "cyan" vers l'énumération Couleur.
 * Elle hérite de CouleurCOR et utilise le modèle de chaîne de responsabilité.
 */
class CyanCOR : public CouleurCOR {
public :
    /**
     * @brief Constructeur de CyanCOR.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     */
    CyanCOR(CouleurCOR * suivant): CouleurCOR(suivant)
    {}

    /**
     * @brief Méthode pour choisir la couleur correspondante à partir du nom de couleur donné.
     * @param ligne Nom de la couleur à convertir.
     * @param couleur Pointeur vers l'énumération Couleur à remplir.
     * @return La couleur correspondante si elle est trouvée, sinon appelle la méthode du maillon suivant dans la chaîne.
     */
    Couleur choixCouleur(string ligne, Couleur *&couleur) const override
    {
        if(ligne == "cyan")
        {
            Couleur* c = new Couleur();
            *c = Couleur::cyan;
            couleur = c;
        }
        else
        {
            this->choixCouleurSuivant(ligne, couleur);
        }
    }

};


#endif //APP2_CYANCOR_H
