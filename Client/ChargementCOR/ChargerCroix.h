//
// Created by Ahmet on 04/03/2024.
//

#ifndef APP2_CHARGERCROIX_H
#define APP2_CHARGERCROIX_H
#include "ChargementCOR.h"
#include "../Forme/Croix.h"

/**
 * @brief La classe ChargerCroix est une classe concrète de la chaîne de responsabilité qui traite le chargement des croix.
 * Elle hérite de ChargementCOR.
 */
class ChargerCroix : public ChargementCOR{

public:
    /**
     * @brief Constructeur de ChargerCroix.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     * Initialise le maillon avec le suivant de la chaîne.
     */
    ChargerCroix(ChargementCOR * suivant): ChargementCOR(suivant)
    {}

    /**
     * @brief Méthode chargée de traiter la ligne de chargement pour créer une forme de type Croix.
     * @param ligne Ligne de chargement.
     * @param pForme Pointeur vers la forme à créer et charger.
     * Si la ligne commence par "croix,", elle crée une instance de Croix avec les informations fournies et met à jour le pointeur vers la forme.
     * Sinon, elle passe la ligne au maillon suivant dans la chaîne de responsabilité.
     */
    void charger(string ligne,Forme * &pForme) override
    {
        string prefixe = "croix,";
        if (ligne.find(prefixe) == 0) {
            cout << "La chaine commence par \"" << prefixe << "\"" << std::endl;
            vector<string> elements;

            stringstream ss(ligne);
            string element;

            while (std::getline(ss, element, ',')) {
                elements.push_back(element);
            }
            for(int i = 0;i<elements.size();i++)
            {
                cout << elements[i] << endl;

            }
            Couleur *c = new Couleur();
            _CoulCOR->choixCouleur(elements[1],c);
            cout << "couleur croix " << c << endl;
            double x1 = stod(elements[2]);
            double y1 = stod(elements[3]);
            double x2 = stod(elements[4]);
            double y2 = stod(elements[5]);
            Vecteur2D v1(x1,y1);
            Vecteur2D v2(x2,y2);
            Croix * croix = new Croix(*c,v1,v2);
            pForme = croix;


        } else {
            this->chargerSuivant(ligne,pForme);
        }
    }

};


#endif //APP2_CHARGERCROIX_H
