import java.awt.*;
import java.awt.image.BufferStrategy;

import static java.lang.Thread.sleep;

/**
 * Classe représentant un maillon de la chaîne de responsabilité spécialisé dans l'affichage d'un rond.
 * Étend la classe abstraite AffichageChain.
 */
public class AffichageRond extends AffichageChain
{
    /**
     * Constructeur de la classe AffichageRond.
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     */
    public AffichageRond(AffichageChain suivant) {
        super(suivant);
    }

    /**
     * Méthode implémentant l'affichage d'un rond dans le contexte Graphics.
     * @param graphics Le contexte Graphics où afficher le rond.
     * @param chaine La chaîne de caractères à traiter, contenant les paramètres du rond.
     * @throws InterruptedException En cas d'interruption pendant l'affichage.
     */
    @Override
    public void Afficher(Graphics graphics, String chaine) throws InterruptedException {
        String[] words = chaine.split(",");
        String couleur = words[1];
        if(words[0].equals("rond")){
            System.out.println("YEEEESS affichager rond\n");

            double xC = Double.valueOf(words[2]);
            double yC = Double.valueOf(words[3]);
            double R =  Double.valueOf(words[4]);

            int xCentre = (int) xC;
            int yCentre = (int) yC;
            int diametre = (int) R;


            System.out.println(xCentre);
            System.out.println(yCentre);
            System.out.println(diametre);
            //sleep(10000);
            _COR.getColor(couleur);
            graphics.setColor(this.couleur);
            graphics.drawOval(xCentre, yCentre, diametre*2, diametre*2);

            //sleep(100000);

        }

        else {
            this.AffichageSuivant(graphics, chaine);
        }
    }
}
