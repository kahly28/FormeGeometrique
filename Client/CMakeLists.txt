cmake_minimum_required(VERSION 3.27)
project(App2)

set(CMAKE_CXX_STANDARD 17)


add_executable(App2 main.cpp
        Erreur.cpp
        Erreur.h
        Forme/Forme.cpp
        Forme/Forme.h
        Forme/Rond.cpp
        Forme/Rond.h
        Forme/Croix.cpp
        Forme/Croix.h
        Fenetre.cpp
        Fenetre.h
        Vecteur2D.cpp
        Vecteur2D.h
        Vecteur2D.h
        Matrice2x2.cpp
        Matrice2x2.h
        Forme/Groupe.cpp
        Forme/Groupe.h
        Visitor/FormeVisitor.cpp
        Visitor/FormeVisitor.h
        Visitor/JavaLibraryVisitor.cpp
        Visitor/JavaLibraryVisitor.h
        Forme/Polygone.cpp
        Forme/Polygone.h
        Forme/FormeGeometrique.cpp
        Forme/FormeGeometrique.h
        SauvegardeVisitor/SauvegardeVisitor.cpp
        SauvegardeVisitor/SauvegardeVisitor.h
        SauvegardeVisitor/SauvegardeVisitor.h
        SauvegardeVisitor/TxtVisitor.cpp
        SauvegardeVisitor/TxtVisitor.h
        SauvegardeVisitor/TxtVisitor.h
        SauvegardeVisitor/TxtVisitor.h
        SauvegardeVisitor/TxtVisitor.h
        ChargementCOR/ChargementCOR.cpp
        ChargementCOR/ChargementCOR.h
        ChargementCOR/ChargerCroix.cpp
        ChargementCOR/ChargerCroix.h
        ChargementCOR/ChargerRond.cpp
        ChargementCOR/ChargerRond.h
        ChargementCOR/ChargerPolygone.cpp
        ChargementCOR/ChargerPolygone.h
        ChargementCOR/ChargerGroupe.cpp
        ChargementCOR/ChargerGroupe.h
        CouleurCOR/CouleurCOR.cpp
        CouleurCOR/CouleurCOR.h
        CouleurCOR/BlackCOR.cpp
        CouleurCOR/BlackCOR.h
        CouleurCOR/BlueCOR.cpp
        CouleurCOR/BlueCOR.h
        CouleurCOR/RedCOR.cpp
        CouleurCOR/RedCOR.h
        CouleurCOR/GreenCOR.cpp
        CouleurCOR/GreenCOR.h
        CouleurCOR/YellowCOR.cpp
        CouleurCOR/YellowCOR.h
        CouleurCOR/CyanCOR.cpp
        CouleurCOR/CyanCOR.h
)
