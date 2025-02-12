import java.awt.*;

import static java.lang.Thread.sleep;

/**
 * Classe représentant un maillon de la chaîne de responsabilité spécialisé dans l'affichage d'un polygone.
 * Étend la classe abstraite AffichageChain.
 */
public class AffichagePolygone extends AffichageChain{

    /**
     * Constructeur de la classe AffichagePolygone.
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     */
    public AffichagePolygone(AffichageChain suivant) {
        super(suivant);
    }


    /**
     * Méthode implémentant l'affichage d'un polygone dans le contexte Graphics.
     * @param graphics Le contexte Graphics où afficher le polygone.
     * @param chaine La chaîne de caractères à traiter, contenant les paramètres du polygone.
     * @throws InterruptedException En cas d'interruption pendant l'affichage.
     */
    @Override
    public void Afficher(Graphics graphics, String chaine) throws InterruptedException {
        String[] words = chaine.split(",");
        String couleur = words[1];
        int xPoints[] = new int[(words.length - 2) / 2];
        int yPoints[] = new int[(words.length - 2) / 2];
        if(words[0].equals("polygone"))
        {
            if(words.length %2 == 0)
            {
                for (int i = 2; i < words.length; i++)
                {
                    int valeur = Integer.parseInt(words[i]);
                    if(i % 2 == 0)
                    {
                        xPoints[(i - 2) / 2] = valeur;
                    }
                    else
                    {
                        yPoints[(i - 2) / 2] = valeur;

                    }
                }
            }

            _COR.getColor(couleur);
            graphics.setColor(this.couleur);

            graphics.drawPolygon(xPoints,yPoints,xPoints.length);
           // sleep(10000);


        }
        else {
            this.AffichageSuivant(graphics, chaine);
        }
    }
}
