import java.awt.*;

/**
 * Classe représentant un maillon de la chaîne de responsabilité pour la gestion de la couleur bleue.
 * Étend la classe abstraite ColorChain.
 */
public class BlueChain extends ColorChain {

    /**
     * Constructeur de la classe BlueChain.
     *
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     * @param affiche La chaîne de responsabilité pour l'affichage associée à ce maillon.
     */
    public BlueChain(ColorChain suivant,AffichageChain affiche) {
        super(suivant,affiche);
    }

    /**
     * Méthode pour obtenir la couleur bleue en fonction d'une chaîne de caractères.
     * Si la chaîne est "blue", la couleur est définie sur bleu, sinon la demande est passée au maillon suivant.
     *
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant la récupération de la couleur.
     */
    @Override
    public void getColor(String chaine) throws InterruptedException {
        if(chaine.equals("blue"))
        {
            getChaine().couleur = Color.BLUE;
            //return Color.BLUE;
        }
        else
        {
            this.getColorSuivant(chaine);
        }
    }
}
