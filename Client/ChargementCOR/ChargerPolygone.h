//
// Created by Ahmet on 04/03/2024.
//

#ifndef APP2_CHARGERPOLYGONE_H
#define APP2_CHARGERPOLYGONE_H


#include "ChargementCOR.h"
#include "../Forme/Polygone.h"

/**
 * @brief La classe ChargerPolygone est une classe concrète de la chaîne de responsabilité qui traite le chargement des polygones.
 * Elle hérite de ChargementCOR.
 */
class ChargerPolygone : public ChargementCOR {
private:

public:

    /**
     * @brief Constructeur de ChargerPolygone.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     * Initialise le maillon avec le suivant de la chaîne.
     */
    ChargerPolygone(ChargementCOR * suivant): ChargementCOR(suivant){}


    /**
     * @brief Méthode chargée de traiter la ligne de chargement pour créer une forme de type Polygone.
     * @param ligne Ligne de chargement.
     * @param pForme Pointeur vers la forme à créer et charger.
     * Si la ligne commence par "polygone,", elle crée une instance de Polygone avec les informations fournies et met à jour le pointeur vers la forme.
     * Sinon, elle passe la ligne au maillon suivant dans la chaîne de responsabilité.
     */
    void charger(string ligne,Forme * &pForme) override
    {
        string prefixe = "polygone,";
        if (ligne.find(prefixe) == 0)
        {
            cout << ligne << endl;
            cout << "La chaine commence par \"" << prefixe << "\"" << std::endl;
            vector<std::string> elements;
            vector<double> xPoint;
            vector<double> yPoint;
            stringstream ss(ligne);
            string element;

            while (std::getline(ss, element, ',')) {
                elements.push_back(element);
            }

            Couleur * c = new Couleur();
            _CoulCOR->choixCouleur(elements[1],c);


            vector<Vecteur2D*> points;
            while (std::getline(ss, element, ','))
            {
                elements.push_back(element);
            }
            cout << "jo " << elements.size() << endl;
            if(elements.size() %2 == 0)
            {
                for (int i = 2; i < elements.size(); i++)
                {
                    double valeur = stod(elements[i]);
                    cout << "valeur " << valeur << endl;
                    if (i % 2 == 0)
                    {
                        xPoint.push_back(valeur);
                    } else
                    {
                        yPoint.push_back(valeur);
                    }
                }
                for(int i = 0;i< xPoint.size();i++)
                {
                    cout << xPoint[i] << endl;
                }

                for(int i = 0;i< xPoint.size();i++)
                {
                    cout << yPoint[i] << endl;
                }
                for (int i = 0; i < xPoint.size(); i++)
                {
                    Vecteur2D *v = new Vecteur2D(xPoint[i], yPoint[i]);
                    cout << "vecteur : " << v << endl;
                    points.push_back(v);

                }
                Polygone * P = new Polygone(*c, points);
                pForme = P;

            }



        }
        else
        {
            cout << "La chaine ne commence pas par \"" << prefixe << "\"" << std::endl;
            this->chargerSuivant(ligne,pForme);
        }

    }

};


#endif //APP2_CHARGERPOLYGONE_H
