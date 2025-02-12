//
// Created by Ahmet on 05/03/2024.
//

#ifndef APP2_YELLOWCOR_H
#define APP2_YELLOWCOR_H


#include "CouleurCOR.h"

/**
 * @brief La classe YellowCOR gère la conversion du nom de couleur "yellow" vers l'énumération Couleur.
 * Elle hérite de CouleurCOR et utilise le modèle de chaîne de responsabilité.
 */
class YellowCOR : public CouleurCOR {
public :
    /**
     * @brief Constructeur de YellowCOR.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     */
    YellowCOR(CouleurCOR * suivant): CouleurCOR(suivant)
    {}

    /**
     * @brief Méthode pour choisir la couleur correspondante à partir du nom de couleur donné.
     * @param ligne Nom de la couleur à convertir.
     * @param couleur Pointeur vers l'énumération Couleur à remplir.
     * @return La couleur correspondante si elle est trouvée, sinon appelle la méthode du maillon suivant dans la chaîne.
     */
    Couleur choixCouleur(string ligne, Couleur *&couleur) const override
    {
        if(ligne == "yellow")
        {
            Couleur* c = new Couleur();
            *c = Couleur::yellow;
            couleur = c;
        }
        else
        {
            this->choixCouleurSuivant(ligne,couleur);
        }
    }

};


#endif //APP2_YELLOWCOR_H
