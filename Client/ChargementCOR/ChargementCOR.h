//
// Created by Ahmet on 04/03/2024.
//

#ifndef APP2_CHARGEMENTCOR_H
#define APP2_CHARGEMENTCOR_H


#include "../Forme/Forme.h"
#include "../CouleurCOR/BlackCOR.h"
#include "../CouleurCOR/BlueCOR.h"
#include "../CouleurCOR/CyanCOR.h"
#include "../CouleurCOR/GreenCOR.h"
#include "../CouleurCOR/RedCOR.h"
#include "../CouleurCOR/YellowCOR.h"

/**
 * @brief La classe ChargementCOR représente un maillon de la chaîne de responsabilité pour le chargement des couleurs.
 * Elle définit une interface commune pour les classes concrètes de la chaîne.
 */
class ChargementCOR {
private:
    ChargementCOR * _suivant;  /**< Pointeur vers le maillon suivant dans la chaîne de responsabilité. */


protected: CouleurCOR * _CoulCOR; /**< Pointeur vers l'objet responsable du traitement de la couleur. */


public:
    /**
     * @brief Constructeur de ChargementCOR.
     * @param suivant Pointeur vers le maillon suivant dans la chaîne.
     * Initialise la chaîne de responsabilité avec une séquence prédéfinie de responsabilités pour le traitement des couleurs.
     */
    ChargementCOR(ChargementCOR * suivant): _suivant(suivant)
    {
        CouleurCOR * cor = nullptr;
        BlackCOR * black = new BlackCOR(nullptr);
        BlueCOR * blue = new BlueCOR(black);
        CyanCOR * cyan = new CyanCOR(blue);
        GreenCOR * green = new GreenCOR(cyan);
        RedCOR * red = new RedCOR(green);
        YellowCOR * yellow = new YellowCOR(red);
        cor = yellow;
        _CoulCOR = cor;
    }

    /**
     * @brief Méthode virtuelle pure chargée de traiter la ligne de chargement pour créer une forme avec la couleur appropriée.
     * @param ligne Ligne de chargement.
     * @param pForme Pointeur vers la forme à créer et charger.
     */
    virtual void charger(string ligne,Forme * &pForme) = 0;

    /**
     * @brief Méthode permettant de passer la ligne au maillon suivant dans la chaîne de responsabilité.
     * @param ligne Ligne de chargement.
     * @param pForme Pointeur vers la forme à créer et charger.
     */
    void chargerSuivant(string ligne,Forme *& pForme)
    {
        _suivant->charger(ligne,pForme);
    }




};


#endif //APP2_CHARGEMENTCOR_H
