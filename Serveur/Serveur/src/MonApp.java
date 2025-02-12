import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.util.ArrayList;

/**
 * Classe représentant un thread pour gérer la communication avec un client.
 * Chaque instance de cette classe est associée à un client connecté.
 */
public class MonApp extends Thread{
    Socket socket;
    BufferedReader fluxEntrant;
    PrintStream fluxSortant;

    AffichageChain _COR;

    Frame _Fenetre;

    Graphics _graphics;
    BufferStrategy _stratégie;


    int _x;
    int _y;
    int _hauteur;
    int _largeur;

    /**
     * Constructeur de la classe MonApp.
     * Initialise les flux de communication et les éléments graphiques associés à chaque client.
     *
     * @param socket      Le socket associé au client.
     * @param groupe      Le groupe de threads auquel appartient ce thread.
     * @param noConnexion Numéro de la connexion.
     * @throws IOException            En cas d'erreur d'entrée/sortie lors de la création des flux.
     * @throws InterruptedException   En cas d'interruption du thread.
     */
    public MonApp(Socket socket, ThreadGroup groupe, int noConnexion) throws IOException, IOException, InterruptedException {
        super(groupe,"Dessinateur");
        this.socket = socket;

        fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));

        /* à présent fluxEntrant est prêt pour lire du texte provenant du client */

        fluxSortant = new PrintStream(this.socket.getOutputStream());

        String input = null;
        input = fluxEntrant.readLine();
        System.out.println(input);

        String[] words = input.split(",");
        int x = Integer.parseInt(words[0]);
        int y = Integer.parseInt(words[1]);
        int hauteur = Integer.parseInt(words[2]);
        int largeur = Integer.parseInt(words[3]);

        Frame f1AR;
        f1AR = new Frame("Frame");

        f1AR.setBounds(x, y,largeur ,hauteur);

        _Fenetre = f1AR;
        f1AR.setVisible(true);      // rend le frame visible sur l'écran
        f1AR.setIgnoreRepaint(true);

        int numBuffers = 2;
        _Fenetre.createBufferStrategy(numBuffers);  // crée une stratégie de tampon d'image à 1 tampon vidéo
        Thread.sleep(150);                       // au moins 150 ms !!!! pour laisser au système le temps de créer le buffer d'image

        BufferStrategy stratégie = _Fenetre.getBufferStrategy();
        Graphics graphics = stratégie.getDrawGraphics();
        _graphics = graphics;
        _stratégie = stratégie;

        //On trace le repérer orthonormée
        graphics.drawLine(hauteur/2,0,hauteur/2,largeur);
        graphics.drawLine(0,hauteur/2,largeur,hauteur/2);

        AffichageChain p;
        AffichageChain croix = new AffichageCroix(null);
        AffichageChain rond = new AffichageRond(croix);
        AffichageChain polygone = new AffichagePolygone(rond);
        p = polygone;
        _COR = p;
    }

    /**
     * Méthode principale du thread qui gère la réception des données du client et les traite.
     */
    public void run()
    {
        while(true)
        {
            String ligne; // saisit le texte du client
            try {
                ligne = fluxEntrant.readLine();
                System.out.println("ligne = ");
                if(ligne == null)
                {
                    while(true) {
                        System.out.println("bug\n");
                    }
                }
                System.out.println(ligne);
                if(ligne.equals("quitter"))
                {
                    System.out.println("ici ? ");
                    socket.close();
                    break;
                }
                _COR.Afficher(_graphics, ligne);
                _stratégie.show();
                System.out.println(ligne);
                sleep(1000);
            } catch (IOException e) {
                throw new RuntimeException(e);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

        }


    }





}
