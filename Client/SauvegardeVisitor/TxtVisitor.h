//
// Created by Ahmet on 03/03/2024.
//

#ifndef APP2_TXTVISITOR_H
#define APP2_TXTVISITOR_H
#include "SauvegardeVisitor.h"
//#include "../Fenetre.h"
#include <fstream>

using namespace std;

/**
 * @class TxtVisitor
 * @brief Représente un visiteur concret pour la sauvegarde de la fenêtre et ses formes dans un fichier texte.
 */
class TxtVisitor : public SauvegardeVisitor {
private:
    ofstream * _file; ///< Pointeur vers le fichier de sortie.

public:
    /**
    * @brief Constructeur de TxtVisitor.
    * @param nomFichier Nom du fichier de sauvegarde.
    * @param f Pointeur vers la fenêtre à sauvegarder.
    */
    TxtVisitor(string nomFichier,Fenetre * f): SauvegardeVisitor(nomFichier,f)
    {
        ofstream * outfile = new ofstream ();
        _file = outfile;
        _file->open("../sauvegarde/"+getNomFichier()+".txt");

    }

    /**
    * @brief Visite un groupe de formes pour la sauvegarde dans le fichier texte.
    * @param G Groupe de formes à sauvegarder.
    */
    void visiterGroupe(const Groupe & G)
    {
        string msg = G.operator string()+ "\n";
        cout << "Dans visiter Groupe : " << msg << endl;
        *_file << msg;
        _file->flush();
    }

    /**
        * @brief Visite un cercle pour la sauvegarde dans le fichier texte.
        * @param R Cercle à sauvegarder.
        */
    void visiterRond(const Rond & R)
    {
        string msg = R.operator string() + "\n";
        cout << "Dans visiter Rond " << msg << endl;
        *_file << msg;
        _file->flush();

    }

    /**
   * @brief Visite un polygone pour la sauvegarde dans le fichier texte.
   * @param P Polygone à sauvegarder.
   */
    void visiterPolygone(const Polygone & P)
    {
        string msg = P.operator string() + "\n";
        cout << "Dans visiter Polygone " << msg << endl;
        *_file << msg;
        _file->flush();

    }

    /**
    * @brief Visite une croix pour la sauvegarde dans le fichier texte.
    * @param C Croix à sauvegarder.
    */
    void visiterCroix(const Croix & C)
    {
        string msg = C.operator string() + "\n";
        cout << "Dans visiter croix : " << msg << endl;
        *_file << msg;
        _file->flush();
    }
};

#endif //APP2_TXTVISITOR_H
