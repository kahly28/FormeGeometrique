//
// Created by Ahmet on 05/03/2024.
//

#ifndef APP2_GREENCOR_H
#define APP2_GREENCOR_H


#include "CouleurCOR.h"

class GreenCOR : public CouleurCOR {
public:
    /**
     * @brief Constructeur de GreenCOR.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     */
    GreenCOR(CouleurCOR * suivant): CouleurCOR(suivant)
    {}


    /**
     * @brief Méthode pour choisir la couleur correspondante à partir du nom de couleur donné.
     * @param ligne Nom de la couleur à convertir.
     * @param couleur Pointeur vers l'énumération Couleur à remplir.
     * @return La couleur correspondante si elle est trouvée, sinon appelle la méthode du maillon suivant dans la chaîne.
     */
    Couleur choixCouleur(string ligne, Couleur *&couleur) const override
    {
        if(ligne == "green")
        {
            Couleur* c = new Couleur();
            *c = Couleur::green;
            couleur = c;
        }
        else
        {
            this->choixCouleurSuivant(ligne,couleur);
        }
    }

};


#endif //APP2_GREENCOR_H
