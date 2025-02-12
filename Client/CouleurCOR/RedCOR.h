//
// Created by Ahmet on 05/03/2024.
//

#ifndef APP2_REDCOR_H
#define APP2_REDCOR_H


#include "CouleurCOR.h"

/**
 * @brief La classe RedCOR gère la conversion du nom de couleur "red" vers l'énumération Couleur.
 * Elle hérite de CouleurCOR et utilise le modèle de chaîne de responsabilité.
 */
class RedCOR : public CouleurCOR{
public:
    /**
     * @brief Constructeur de RedCOR.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     */
    RedCOR(CouleurCOR * suivant): CouleurCOR(suivant)
    {}

    /**
     * @brief Méthode pour choisir la couleur correspondante à partir du nom de couleur donné.
     * @param ligne Nom de la couleur à convertir.
     * @param couleur Pointeur vers l'énumération Couleur à remplir.
     * @return La couleur correspondante si elle est trouvée, sinon appelle la méthode du maillon suivant dans la chaîne.
     */
    Couleur choixCouleur(string ligne,Couleur *&couleur) const override
    {
        if(ligne == "red")
        {
            Couleur* c = new Couleur();
            *c = Couleur::red;
            couleur = c;
        }
        else
        {
            this->choixCouleurSuivant(ligne,couleur);
        }
    }

};


#endif //APP2_REDCOR_H
