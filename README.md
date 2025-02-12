Gestion de Formes Géométriques en 2D

Ce projet a été réalisé dans le cadre du cours "Premiers Pas vers l’Ingénierie du Logiciel" (PPIL). L'objectif est de développer une application distribuée permettant de gérer des formes géométriques en 2D. L'architecture repose sur un client en C++ et un serveur en Java qui communiquent via TCP/IP.

Objectifs :
- Développer une application distribuée client-serveur.
- Gérer des formes géométriques simples (segments, cercles, triangles, polygones) et composées (groupes de formes).
- Permettre des transformations géométriques (translation, homothétie, rotation).
- Utiliser des Design Patterns (Visitor, Chain of Responsibility, Singleton) pour assurer la flexibilité du code.
- Implémenter des fonctionnalités de sauvegarde et chargement des formes.
- Assurer un code propre, modulaire et extensible.

Architecture :
- Client C++ : Interface utilisateur permettant la création, manipulation et envoi des formes.
- Serveur Java : Gère les requêtes et effectue le dessin des formes via une bibliothèque graphique.
- Communication TCP/IP : Le client envoie des instructions de dessin et de gestion des formes au serveur.

Fonctionnalités :
- Création et manipulation de formes simples et composées.
- Application de transformations géométriques.
- Affichage graphique des formes via le serveur Java.
- Sauvegarde et chargement des formes dans des fichiers texte.
- Support multi-client pour la gestion simultanée des requêtes.

Technologies utilisées :
- C++ (Client, gestion des formes, communication réseau).
- Java (Serveur, gestion du dessin).
- Sockets TCP/IP (Communication client-serveur).

Compiler et exécuter le serveur Java :
javac Server.java
java Server

Compiler et exécuter le client C++ :
Le point d’entrée du projet se trouve dans le fichier main du dossier Client. Il contient déjà un exemple d'utilisation. 
Pour compiler et exécuter :
g++ -o client client.cpp
./client

Ce projet a été réalisé par Ahmet Kalyoncu.

