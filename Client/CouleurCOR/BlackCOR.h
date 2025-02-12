//
// Created by Ahmet on 05/03/2024.
//

#ifndef APP2_BLACKCOR_H
#define APP2_BLACKCOR_H


#include "CouleurCOR.h"

/**
 * @brief La classe BlackCOR gère la conversion du nom de couleur "black" vers l'énumération Couleur.
 * Elle hérite de CouleurCOR et utilise le modèle de chaîne de responsabilité.
 */
class BlackCOR : public CouleurCOR {
private:

public:
    /**
     * @brief Constructeur de BlackCOR.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     */
    BlackCOR(CouleurCOR * suivant): CouleurCOR(suivant)
    {}


    /**
     * @brief Méthode pour choisir la couleur correspondante à partir du nom de couleur donné.
     * @param ligne Nom de la couleur à convertir.
     * @param couleur Pointeur vers l'énumération Couleur à remplir.
     * @return La couleur correspondante si elle est trouvée, sinon appelle la méthode du maillon suivant dans la chaîne.
     */
    Couleur choixCouleur(string ligne, Couleur *&couleur) const override
    {
        if(ligne == "black")
        {
            Couleur* c = new Couleur();
            *c = Couleur::black;
            couleur = c;
        }
        else
        {
            this->choixCouleurSuivant(ligne,couleur);
        }
    }

};


#endif //APP2_BLACKCOR_H
