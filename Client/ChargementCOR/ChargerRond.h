//
// Created by Ahmet on 04/03/2024.
//

#ifndef APP2_CHARGERROND_H
#define APP2_CHARGERROND_H


#include "ChargementCOR.h"
#include "../Forme/Rond.h"


/**
 * @brief La classe ChargerRond est une classe concrète de la chaîne de responsabilité qui traite le chargement des ronds.
 * Elle hérite de ChargementCOR.
 */
class ChargerRond : public ChargementCOR {
private:

public:

    /**
     * @brief Constructeur de ChargerRond.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     * Initialise le maillon avec le suivant de la chaîne.
     */
    ChargerRond(ChargementCOR * suivant): ChargementCOR(suivant){}


    /**
     * @brief Méthode chargée de traiter la ligne de chargement pour créer une forme de type Rond.
     * @param ligne Ligne de chargement.
     * @param pForme Pointeur vers la forme à créer et charger.
     * Si la ligne commence par "rond,", elle crée une instance de Rond avec les informations fournies et met à jour le pointeur vers la forme.
     * Sinon, elle passe la ligne au maillon suivant dans la chaîne de responsabilité.
     */
    void charger(string ligne,Forme *&pForme ) override
    {
        string prefixe = "rond,";
        if (ligne.find(prefixe) == 0)
        {
            cout << "La chaine commence par \"" << prefixe << "\"" << std::endl;
            vector<std::string> elements;

            stringstream ss(ligne);
            string element;

            while (std::getline(ss, element, ','))
            {
                elements.push_back(element);
            }
            for(int i = 0;i<elements.size();i++)
            {
                cout << elements[i] << endl;
            }
            Couleur *c = new Couleur();

            _CoulCOR->choixCouleur(elements[1],c);
            //Couleur c = yo;
            double  x1, y1,rayon;
            x1 = stod(elements[2]);

            y1 = stod(elements[3]);

            rayon = stod(elements[4]);

            Vecteur2D v(x1,y1);

            Rond *pRond = new Rond(*c, v, rayon);
            pForme = pRond;
            cout << "here" << endl;



        }
        else
        {
            cout << "La chaine ne commence pas par \"" << prefixe << "\"" << std::endl;
            this->chargerSuivant(ligne,pForme);
        }
    }

};


#endif //APP2_CHARGERROND_H
