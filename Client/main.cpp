#include <iostream>
//#include "Fenetre.h"
#include "Visitor/JavaLibraryVisitor.h"
#include "Forme/Croix.h"
#include "Forme/Rond.h"
#include "Forme/Groupe.h"
#include "Forme/Polygone.h"
#include "SauvegardeVisitor/TxtVisitor.h"

namespace fs = std::filesystem;


int main() {
   // test t(0);
    Fenetre * fenetre = new Fenetre (300,300,500,500);
    JavaLibraryVisitor * f = JavaLibraryVisitor::getInstance("127.0.0.1",9111,fenetre);


    //Rectangle bleu
    vector<Vecteur2D*> _TabPoints;
    Vecteur2D r1(1,-1);
    Vecteur2D r2(5,-1);
    Vecteur2D r3(5,1);
    Vecteur2D r4(1,1);

    _TabPoints.push_back(&r1);
    _TabPoints.push_back(&r2);
    _TabPoints.push_back(&r3);
    _TabPoints.push_back(&r4);
    Polygone R1(Couleur::blue,_TabPoints);


    vector<Vecteur2D*> _TabPoints2;
    Vecteur2D t1(6,-1);
    Vecteur2D t2(8,0);
    Vecteur2D t3(6,1);
    _TabPoints2.push_back(&t1);
    _TabPoints2.push_back(&t2);
    _TabPoints2.push_back(&t3);
    Polygone T1(Couleur::green,_TabPoints2);

    Vecteur2D c1(11,0);
    Rond C1(Couleur::yellow,c1,2);

    Groupe g(Couleur::red);
    g.ajouterFormeGeometrique(C1);
    g.ajouterFormeGeometrique(T1);
    g.ajouterFormeGeometrique(R1);

    Vecteur2D translation(-1,0);
    g.translation(translation);


    Vecteur2D rotation(0,0);
    double angle = M_PI / 4.0;
    g.rotation(angle,rotation);
    double Aire = g.CalculAire();
    cout << "L'aire du groupe est : " << Aire << endl;

    Vecteur2D marge(1,1);
    fenetre->ajouterForme(g);

    fenetre->_P1 -= marge;
    fenetre->_P2 += marge;
    fenetre->dessiner(f);
    TxtVisitor * txt = new TxtVisitor("mabellefigure1",fenetre);
    fenetre->sauvegarder(txt);

    fenetre->charger("mabellefigure1.txt");
    Vecteur2D tr(0.5,1);
    fenetre->translation(tr);

    fenetre->dessiner(f);





    /*

    Vecteur2D v(-2,3);
    Rond r(Couleur::cyan,v,5);

    Vecteur2D v3(5,6);
    Vecteur2D v4(7,6);
    Croix c(Couleur::blue,v3,v4);

    Groupe g(Couleur::red);
    g+ c + r;

    cout << g << endl;

    fenetre->ajouterForme(g);
    fenetre->dessiner(f);

    g.retirerFormeGeometrique(r);
    Vecteur2D m(0.5,-2);
    r.translation(m);
    fenetre->ajouterForme(r);
    fenetre->dessiner(f);
    TxtVisitor * txt = new TxtVisitor("formeSauvegarder",fenetre);
    fenetre->sauvegarder(txt);

*/

    cout << "Lambda : " << fenetre->getLambda() << endl;
    cout << "Eps1 : " << fenetre->getEps1() << endl;
    cout << "Eps 2 "<<fenetre->getEps2() << endl;
    cout << "a : " << fenetre->aGet() << endl;
    cout << "b : " << fenetre->bGet() << endl;

  //  cout << fen->getY() << endl;
  /*
    while(true)
    {
        cout << "connecté \n";
    }

*/


}
