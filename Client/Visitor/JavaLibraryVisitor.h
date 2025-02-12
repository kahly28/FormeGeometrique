//
// Created by Ahmet on 22/02/2024.
//

#ifndef APP2_JAVALIBRARYVISITOR_H
#define APP2_JAVALIBRARYVISITOR_H


#include "FormeVisitor.h"
#include "../Erreur.h"

/**
 * @class JavaLibraryVisitor
 * @brief Représente un visiteur spécifique pour la connexion avec une librairie Java.
 */
class JavaLibraryVisitor : public  FormeVisitor {
private:
    friend Forme;

    static JavaLibraryVisitor* instance; ///< Instance unique de JavaLibraryVisitor.

    /**
    * @brief Constructeur privé de JavaLibraryVisitor.
    * @param adr Adresse IP du serveur.
    * @param port Port de connexion au serveur.
    * @param f Pointeur vers la fenêtre à visiter.
    */
    JavaLibraryVisitor(string adr, int port,Fenetre * f): FormeVisitor(adr,port,f)
    {
    }

    /**
     * @brief Destructeur privé de JavaLibraryVisitor.
     */
    void detruire()
    {
        delete instance;
    }


public:
    /**
        * @brief Obtient l'instance unique de JavaLibraryVisitor ou en crée une nouvelle si elle n'existe pas.
        * @param adr Adresse IP du serveur.
        * @param port Port de connexion au serveur.
        * @param f Pointeur vers la fenêtre à visiter.
        * @return Instance unique de JavaLibraryVisitor.
        */
    static JavaLibraryVisitor* getInstance(string adr, int port, Fenetre* f) {
        if (!instance) {
            instance = new JavaLibraryVisitor(adr, port, f);
        }
        return instance;
    }


    /**
     * @brief Visite un groupe de formes géométriques dans le contexte de la librairie Java.
     * @param G Groupe de formes à visiter.
     */
    void visiterGroupe(const Groupe & G) override
    {

        string groupe = "groupe:";

        string rep = groupe ;
        for(int i = 0;i < G.getListeForme().size();i++)
        {
            Forme * f = G.getListeForme()[i];
            //string fo = visiterForme(this);
            f->accepter(this);
            //rep = rep + fo + "|";
        }

    }

    /**
     * @brief Visite un cercle dans le contexte de la librairie Java.
     * @param R Cercle à visiter.
     */
    virtual void visiterRond(const Rond & R) override
    {
        int x, y, rayon;
        double xCoinSuperieurGauche = R.getPoint()._x - R.getRayon();
        double yCoinSuperieurGauche = R.getPoint()._y + R.getRayon();

        x = (getEps1() * getLambda() * xCoinSuperieurGauche) + aGet();
        y = (getEps2() * getLambda() * yCoinSuperieurGauche) + bGet();
        rayon = R.getRayon() * getLambda();

        string XString = to_string(x);
        string YString = to_string(y);
        string rond = "rond";
        string couleur;

        if (R.recevoirGroupeParent() != nullptr) {
            Groupe *g = R.getGroupeParent();
            Couleur c = g->getCouleur();
            couleur = R.enumToString(c);
        } else {
            Couleur c = R.getCouleur();
            couleur = R.enumToString(c);
        }
        string msg = rond + "," + couleur + "," + XString + "," + YString + "," + to_string(rayon);
        sendMessage(msg);

        /*
         cout << "visiteur rond" << endl;
         string rep = R.algo(getEps1(),getEps2(),getLambda(),aGet(),bGet());
         cout << rep << endl;
          */

    }


    /**
     * @brief Visite un polygone dans le contexte de la librairie Java.
     * @param P Polygone à visiter.
     */
    void visiterPolygone(const Polygone & P) override
    {
        string pol = "polygone";
        string couleur;

        if (P.recevoirGroupeParent() != nullptr) {
            Groupe *g = P.getGroupeParent();
            Couleur c = g->getCouleur();
            couleur = P.enumToString(c);
        } else {
            Couleur c = P.getCouleur();
            couleur = P.enumToString(c);
        }

        string msg = pol + "," + couleur + ",";

        for (int i = 0; i < P.getTabPoints().size(); i++) {
            Vecteur2D v = *P.getTabPoints()[i];
            int x = getEps1() * getLambda() * v._x + aGet();
            int y = getEps2() * getLambda() * v._y + bGet();
            string XString = to_string(x);
            string YString = to_string(y);
            msg = msg + XString + "," + YString;
            if (i != P.getTabPoints().size() - 1) {
                msg = msg + ",";
            }
        }

        /*
        string rep = P.algo(getEps1(),getEps2(),getLambda(),aGet(),bGet());
        cout << rep << endl;
         */
        sendMessage(msg);
    }


    /**
     * @brief Visite une croix dans le contexte de la librairie Java.
     * @param C Croix à visiter.
     */
    void visiterCroix(const Croix & C) override
    {
        int x1,x2,x3,x4,y1,y2,y3,y4;
        x1 = getEps1() * getLambda() * C.getBasGauche()._x + aGet();
        y1 = getEps2() * getLambda() * C.getBasGauche()._y + bGet();

        x2 = getEps1() * getLambda() * C.getHautGauche()._x + aGet();
        y2 = getEps2() * getLambda() * C.getHautGauche()._y + bGet();

        x3 = getEps1() * getLambda() * C.getHautDroite()._x + aGet();
        y3 = getEps2() * getLambda() * C.getHautDroite()._y + bGet();

        x4 = getEps1() * getLambda() * C.getBasDroite()._x + aGet();
        y4 = getEps2() * getLambda() * C.getBasDroite()._y + bGet();

        string StringX1 = to_string(x1);
        string StringY1 = to_string(y1);
        string StringX2 = to_string(x2);
        string StringY2 = to_string(y2);
        string StringX3 = to_string(x3);
        string StringY3 = to_string(y3);
        string StringX4 = to_string(x4);
        string StringY4 = to_string(y4);
        string croix = "croix";
        string couleur;

        if(C.getGroupeParent() != nullptr)
        {
            Groupe * g = C.getGroupeParent();
            Couleur c = g->getCouleur();
            couleur = C.enumToString(c);

        }
        else
        {
            Couleur c = C.getCouleur();
            couleur = C.enumToString(c);

        }
        cout << "fin algo ? " << endl;
        string msg = croix + "," + couleur + "," + StringX1 + "," + StringY1 + ","+
                     StringX2 + "," + StringY2 + "," + StringX3 + "," + StringY3 + "," + StringX4 + "," + StringY4;
        cout << "msg : " << endl;
        cout << msg << endl;
        /*
        cout << "visiteurr de  croix " << endl;
       // calcul();
        string rep = C.algo(getEps1(),getEps2(),getLambda(),aGet(),bGet());
        cout << rep << endl;
         */
        sendMessage(msg);
    }


    /**
     * @brief Destructeur de JavaLibraryVisitor.
     */
    ~JavaLibraryVisitor()
    {
        detruire();
    }
};


#endif //APP2_JAVALIBRARYVISITOR_H
