import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferStrategy;

import static java.lang.Thread.sleep;

/**
 * Classe représentant un maillon de la chaîne de responsabilité spécialisé dans l'affichage d'une croix.
 * Étend la classe abstraite AffichageChain.
 */
public class AffichageCroix extends AffichageChain {

    /**
     * Constructeur de la classe AffichageCroix.
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     */
    public AffichageCroix(AffichageChain suivant) {
        super(suivant);
    }

    /**
     * Méthode implémentant l'affichage d'une croix dans le contexte Graphics.
     * @param graphics Le contexte Graphics où afficher la croix.
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant l'affichage.
     */
    @Override
    public void Afficher(Graphics graphics, String chaine) throws InterruptedException {
        String[] words = chaine.split(",");
        String couleur = words[1];

        if(words[0].equals("croix")){
            System.out.println("YEEEESS affichage croix\n");

            double x1 = Double.valueOf(words[2]);
            double y1 = Double.valueOf(words[3]);
            double x2 =  Double.valueOf(words[4]);
            double y2 =  Double.valueOf(words[5]);
            double x3 = Double.valueOf(words[6]);
            double y3 = Double.valueOf(words[7]);
            double x4 = Double.valueOf(words[8]);
            double y4 = Double.valueOf(words[9]);



            int basGaucheX = (int) x1;
            int basGaucheY = (int) y1;
            int HautGaucheX = (int) x2;
            int HautGaucheY = (int) y2;

            int HautDroiteX = (int) x3;
            int HautDroiteY = (int) y3;
            int BasDroiteX = (int) x4;
            int BasDroiteY = (int) y4;


            System.out.println(HautGaucheX);
            System.out.println(HautGaucheY);
            System.out.println(BasDroiteX);
            System.out.println(BasDroiteY);

            //sleep(100000);
            _COR.getColor(couleur);
            graphics.setColor(this.couleur);
            graphics.drawLine(HautGaucheX,HautGaucheY,BasDroiteX,BasDroiteY);
            graphics.drawLine(basGaucheX,basGaucheY,HautDroiteX,HautDroiteY);

        }

        else {
            this.AffichageSuivant(graphics, chaine);
        }
    }
}
