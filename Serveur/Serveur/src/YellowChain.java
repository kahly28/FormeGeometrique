import java.awt.*;

/**
 * Classe représentant un maillon de la chaîne de responsabilité pour la gestion de la couleur jaune.
 * Étend la classe abstraite ColorChain.
 */
public class YellowChain extends ColorChain {

    /**
     * Constructeur de la classe YellowChain.
     *
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     * @param affiche La chaîne de responsabilité pour l'affichage associée à ce maillon.
     */
    public YellowChain(ColorChain suivant,AffichageChain affiche) {
        super(suivant,affiche);
    }

    /**
     * Méthode pour obtenir la couleur jaune en fonction d'une chaîne de caractères.
     * Si la chaîne est "yellow", la couleur est définie sur jaune, sinon la demande est passée au maillon suivant.
     *
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant la récupération de la couleur.
     */
    @Override
    public void getColor(String chaine) throws InterruptedException {
        if(chaine.equals("yellow"))
        {
            getChaine().couleur = Color.YELLOW;
            //return Color.YELLOW;
        }
        else
        {
            this.getColorSuivant(chaine);

        }
    }
}
