import java.awt.*;

import static java.lang.Thread.sleep;

/**
 * Classe représentant un maillon de la chaîne de responsabilité pour la gestion de la couleur rouge.
 * Étend la classe abstraite ColorChain.
 */
public class RedChain extends ColorChain{
    /**
     * Constructeur de la classe RedChain.
     *
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     * @param affiche La chaîne de responsabilité pour l'affichage associée à ce maillon.
     */
    public RedChain(ColorChain suivant,AffichageChain affiche) {
        super(suivant,affiche);
    }


    /**
     * Méthode pour obtenir la couleur rouge en fonction d'une chaîne de caractères.
     * Si la chaîne est "red", la couleur est définie sur rouge, sinon la demande est passée au maillon suivant.
     *
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant la récupération de la couleur.
     */
    @Override
    public void getColor(String chaine) throws InterruptedException {
        if(chaine.equals("red"))
        {
            getChaine().couleur = Color.RED;
            //return Color.RED;
        }
        else
        {
            this.getColorSuivant(chaine);
        }
    }
}
