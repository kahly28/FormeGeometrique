//
// Created by Ahmet on 04/03/2024.
//

#ifndef APP2_CHARGERGROUPE_H
#define APP2_CHARGERGROUPE_H


#include "ChargerCroix.h"
#include "ChargerPolygone.h"
#include "ChargerRond.h"

/**
 * @brief La classe ChargerGroupe est une classe concrète de la chaîne de responsabilité qui traite le chargement des groupes.
 * Elle hérite de ChargementCOR.
 */
class ChargerGroupe : public ChargementCOR {
private:

public:

    /**
     * @brief Constructeur de ChargerGroupe.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne de responsabilité.
     * Initialise le maillon avec le suivant de la chaîne.
     */
    ChargerGroupe(ChargementCOR * suivant): ChargementCOR(suivant)
    {
    }


    /**
     * @brief Méthode chargée de traiter la ligne de chargement pour créer une forme de type Groupe.
     * @param ligne Ligne de chargement.
     * @param pForme Pointeur vers la forme à créer et charger.
     * Si la ligne commence par "groupe-", elle crée une instance de Groupe avec les informations fournies et met à jour le pointeur vers la forme.
     * Sinon, elle passe la ligne au maillon suivant dans la chaîne de responsabilité.
     */
    void charger(string ligne,Forme * &pForme) override
    {
        ChargementCOR * cor;
        ChargerCroix * croix = new ChargerCroix(cor);
        ChargerPolygone * polygone = new ChargerPolygone(croix);
        ChargerRond * rond = new ChargerRond(polygone);
        ChargerGroupe * groupe = new ChargerGroupe(rond);
        cor = groupe;

        string prefixe = "groupe-";

        if (ligne.find(prefixe) == 0)
        {
            cout << "La chaine commence par \"" << prefixe << "\"" << std::endl;
            vector<std::string> elements;
            ligne.erase(0, 7); // 7 est la longueur de "groupe:"
            size_t deuxPoints = ligne.find(":");

            // Extraire la sous-chaîne entre le début et les deux-points
            string couleur = ligne.substr(0, deuxPoints);
            ligne.erase(0, deuxPoints + 1); // +1 pour inclure les deux-points

            cout << "couleur " << couleur << endl;
            Couleur* c = new Couleur();
            _CoulCOR->choixCouleur(couleur,c);

            cout << "COULEUR : " << c << endl;
            char* cstr = new char[ligne.length() + 1];
            std::strcpy(cstr, ligne.c_str());
            char* token = std::strtok(cstr, "|");
            std::vector<std::string> result;

            while (token != nullptr)
            {
                result.push_back(token);
                token = std::strtok(nullptr, "|");
            }
            cout << "boucle pour groupe " << endl;
            for(int i = 0;i<result.size();i++)
            {
                cout << result[i] << endl;
            }
            Groupe *groupe = new Groupe(*c);
            for(int i = 0 ;i< result.size();i++)
            {

                 cor->charger(result[i],pForme);
                 cout << "ici<" << *pForme << endl;
                 *groupe + *pForme;
            }

            pForme = groupe;

        }
        else
        {
            cout << "La chaine ne commence pas par \"" << prefixe << "\"" << std::endl;
            this->chargerSuivant(ligne,pForme);
        }
    }

};


#endif //APP2_CHARGERGROUPE_H
