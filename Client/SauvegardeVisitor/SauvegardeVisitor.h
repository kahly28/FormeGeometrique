//
// Created by Ahmet on 03/03/2024.
//

#ifndef APP2_SAUVEGARDEVISITOR_H
#define APP2_SAUVEGARDEVISITOR_H
#include <string>
#include "../Fenetre.h"
#include "../Forme/Groupe.h"
#include "../Forme/Croix.h"
#include "../Forme/Polygone.h"
#include "../Forme/Rond.h"
#include <fstream>



/**
 * @class SauvegardeVisitor
 * @brief Représente un visiteur abstrait pour la sauvegarde de la fenêtre et ses formes dans un fichier.
 */
class SauvegardeVisitor {
private:
    string _nomFichier;   ///< Nom du fichier de sauvegarde.
    Fenetre* _fenetre;     ///< Pointeur vers la fenêtre à sauvegarder.
public:
    /**
   * @brief Constructeur de SauvegardeVisitor.
   * @param nomFichier Nom du fichier de sauvegarde.
   * @param f Pointeur vers la fenêtre à sauvegarder.
   */
    SauvegardeVisitor(string nomFichier,Fenetre *f):_nomFichier(nomFichier),_fenetre(f)
    {


    }


    /**
     * @brief Obtient le nom du fichier de sauvegarde.
     * @return Nom du fichier de sauvegarde.
     */
    string getNomFichier() const
    {
        return _nomFichier;
    }

    /**
     * @brief Obtient le pointeur vers la fenêtre à sauvegarder.
     * @return Pointeur vers la fenêtre à sauvegarder.
     */
    Fenetre * getFenetre() const
    {
        return _fenetre;
    }

    /**
    * @brief Visite un groupe de formes pour la sauvegarde.
    * @param G Groupe de formes à sauvegarder.
    */
    virtual void visiterGroupe(const Groupe & G) = 0;

    /**
  * @brief Visite les formes pour la sauvegarde.
  * @param forme Forme à sauvegarder.
  */
    virtual void visiterForme( Forme&  forme)
    {
        vector<Forme*> ListeForme = _fenetre->getListeForme();
        for(int i = 0;i< ListeForme.size();i++)
        {
            ListeForme[i]->accepter(this);
        }
    }

    /**
  * @brief Visite un cercle pour la sauvegarde.
  * @param R Cercle à sauvegarder.
  */
    virtual void visiterRond(const Rond & R) = 0;

    /**
    * @brief Visite un polygone pour la sauvegarde.
    * @param P Polygone à sauvegarder.
    */
    virtual void visiterPolygone(const Polygone & P) = 0;

    /**
     * @brief Visite une croix pour la sauvegarde.
     * @param C Croix à sauvegarder.
     */
    virtual void visiterCroix(const Croix & C) = 0;
};


#endif //APP2_SAUVEGARDEVISITOR_H
