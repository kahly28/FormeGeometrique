//
// Created by Ahmet on 22/02/2024.
//

#ifndef APP2_FORMEVISITOR_H
#define APP2_FORMEVISITOR_H


#include "../Fenetre.h"
#include "../Forme/Groupe.h"
#include "../Forme/Croix.h"
#include "../Forme/Polygone.h"
#include "../Forme/Rond.h"

#include <pcap/socket.h>
#include <unistd.h>
#include <sys/socket.h>

/**
 * @brief Représente un visiteur abstrait permettant d'établir une connexion avec un serveur graphique.
 *        Il définit des méthodes spécifiques pour chaque type de forme, adaptées à la bibliothèque cible.
 */
class FormeVisitor {

private:
    int _socket;
    int _connexion;
    int _port;
    string _adresse;
    Fenetre * _fenetre;


    /**
     * @brief Détruit l'objet FormeVisitor en fermant la connexion.
     */
    void detruire() {
        // Fermer la connexion lorsque l'objet est détruit
        if (_connexion != -1) {
            close(_socket);
            cout << "Connexion fermée" << endl;
        }
    }


protected:
    /**
     * @brief Envoie un message au serveur.
     * @param message Message à envoyer.
     */
    void sendMessage(string message) const
    {
        message = message+'\n';
        int sendMessage = send(this->_socket,(message).c_str(),message.size(),0);
        if(sendMessage == -1)
        {
            throw Erreur("Message");
        }
        cout << "Message envoyé " << endl;
        //     cout << message << endl;
    }

public:
    /**
     * @brief Constructeur pour FormeVisitor.
     * @param adr Adresse IP du serveur.
     * @param port Port de connexion au serveur.
     * @param f Pointeur vers la fenêtre à visiter.
     */
    FormeVisitor(string adr, int port, Fenetre * f):_adresse(adr),_port(port),_fenetre(f)
    {
        int sock = socket(AF_INET,SOCK_STREAM,0);
        _socket = sock;
        if(sock ==-1)
        {
            throw Erreur("Socket");
        }
        sockaddr_in add;
        add.sin_family = AF_INET;
        add.sin_port = htons(_port);
        inet_pton(AF_INET,_adresse.c_str(), &add.sin_addr);
        //Connexion au serveur avec le socket
        int connex = connect(sock,(sockaddr * )&add,sizeof(sockaddr_in));
        _connexion = connex;
        if(connex == -1)
        {
            throw Erreur("Connexion");
        }


        int x = _fenetre->getX();
        int y = _fenetre->getY();
        int h = _fenetre->getH();
        int l = _fenetre->getL();

        string XtoString = to_string(x);
        string YtoString = to_string(y);
        string HtoString = to_string(h);
        string LtoString = to_string(l);
        string msg = XtoString + "," + YtoString + "," + HtoString + "," + LtoString;
        cout << msg << endl;
        sendMessage(msg);

    }


    /**
     * @brief Accesseur pour l'adresse IP du serveur graphique.
     * @return Adresse IP du serveur graphique.
     */
    string getAdresse() const
    {
        return _adresse;
    }


    /**
      * @brief Accesseur pour le port de connexion au serveur graphique.
      * @return Port de connexion au serveur graphique.
      */
    int getPort() const
    {
        return _port;
    }

    /**
     * @brief Accesseur pour la valeur Epsilon 1 de la fenêtre.
     * @return Valeur Epsilon 1 de la fenêtre.
     */
    int getEps1() const
    {
        return _fenetre->getEps1();
    };


    /**
     * @brief Accesseur pour la valeur Epsilon 2 de la fenêtre.
     * @return Valeur Epsilon 2 de la fenêtre.
     */
    int getEps2() const
    {
        return _fenetre->getEps2();
    };

    /**
     * @brief Accesseur pour la valeur Lambda de la fenêtre.
     * @return Valeur Lambda de la fenêtre.
     */
    double getLambda() const
    {
        return _fenetre->getLambda();
    }

    /**
     * @brief Accesseur pour la valeur 'a' de la fenêtre.
     * @return Valeur 'a' de la fenêtre.
     */
    double aGet() const
    {
        return _fenetre->aGet();
    }

    /**
     * @brief Accesseur pour la valeur 'b' de la fenêtre.
     * @return Valeur 'b' de la fenêtre.
     */
    double bGet() const
    {
        return _fenetre->bGet();
    }

    /**
      * @brief Accesseur pour la liste des formes géométriques de la fenêtre.
      * @return Liste des formes géométriques de la fenêtre.
      */
    vector<Forme*> getListeForme() const
    {
        return _fenetre->getListeForme();
    }


    /**
     * @brief Visite un groupe de formes géométriques.
     * @param G Groupe de formes à visiter.
     */
    virtual void visiterGroupe(const Groupe & G) = 0;

    /**
     * @brief Visite une forme générique.
     * @param forme Forme à visiter.
     */
    void visiterForme( Forme&  forme)
    {
        vector<Forme*> ListeForme = _fenetre->getListeForme();
        for(int i = 0;i< ListeForme.size();i++)
        {
            ListeForme[i]->accepter(this);
        }
    }

    /**
     * @brief Visite un cercle dans le contexte de la bibliothèque graphique cible.
     * @param R Cercle à visiter.
     */
    virtual void visiterRond(const Rond & R) = 0;

    /**
     * @brief Visite un polygone dans le contexte de la bibliothèque graphique cible.
     * @param P Polygone à visiter.
     */
    virtual void visiterPolygone(const Polygone & P) = 0;

    /**
     * @brief Visite une croix dans le contexte de la bibliothèque graphique cible.
     * @param C Croix à visiter.
     */
    virtual void visiterCroix(const Croix & C) = 0;

    /**
     * @brief Destructeur virtuel pour FormeVisitor, responsable de la fermeture de la connexion.
     */
    virtual ~FormeVisitor()
    {
        detruire();
    }

    void quitter()
    {
        sendMessage("quitter");
        close(_socket);
    }

};


#endif //APP2_FORMEVISITOR_H
