import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.Buffer;

/**
 * Classe représentant le serveur de l'application.
 * Le serveur écoute les connexions des clients et crée des threads pour chaque client connecté.
 */
public class MonServeur {

    /**
     * Méthode principale qui lance le serveur et accepte les connexions des clients.
     *
     * @param args Arguments de la ligne de commande (non utilisés ici).
     * @throws Exception En cas d'erreur pendant l'exécution du serveur.
     */
    public static void main(String[] args)throws Exception {
        ServerSocket serveur = new ServerSocket(9111);

        System.out.println("serveur de majuscule démarré : " + serveur);

        InetAddress cetteMachine;
        int portLocal;
        ThreadGroup groupe;


        portLocal = serveur.getLocalPort();

        cetteMachine = InetAddress.getLocalHost();

        System.out.println("adresse IP du serveur de majuscule : " + cetteMachine.getHostAddress());
        System.out.println("port du serveur : " + portLocal);

        groupe = new ThreadGroup("ClientApp");
        int noConnexion = 0;
        while (true)
        {
            Socket nouveauClientSocket;
            MonApp nouveauClientThread;

            nouveauClientSocket = serveur.accept();
            ++noConnexion; // la connexion a eu lieu et un socket a été créé : nouveauClientSocket
            System.out.println("Connexion réussie n° : "+noConnexion);

            nouveauClientThread = new MonApp(nouveauClientSocket, groupe, noConnexion);
            nouveauClientThread.start();

        }
    }
}
