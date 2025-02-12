//
// Created by Ahmet on 05/03/2024.
//

#ifndef APP2_BLUECOR_H
#define APP2_BLUECOR_H


#include "CouleurCOR.h"

/**
 * @brief La classe BlueCOR gère la conversion du nom de couleur "blue" vers l'énumération Couleur.
 * Elle hérite de CouleurCOR et utilise le modèle de chaîne de responsabilité.
 */
class BlueCOR : public CouleurCOR {
private:

public:
    /**
     * @brief Constructeur de BlueCOR.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     */
    BlueCOR(CouleurCOR * suivant): CouleurCOR(suivant)
    {}

    /**
     * @brief Méthode pour choisir la couleur correspondante à partir du nom de couleur donné.
     * @param ligne Nom de la couleur à convertir.
     * @param couleur Pointeur vers l'énumération Couleur à remplir.
     * @return La couleur correspondante si elle est trouvée, sinon appelle la méthode du maillon suivant dans la chaîne.
     */
    Couleur choixCouleur(string ligne, Couleur *&couleur) const override
    {
        if(ligne == "blue")
        {
            Couleur* c = new Couleur();
            *c = Couleur::blue;
            couleur = c;
        }
        else
        {
            this->choixCouleurSuivant(ligne,couleur);
        }
    }

};


#endif //APP2_BLUECOR_H
