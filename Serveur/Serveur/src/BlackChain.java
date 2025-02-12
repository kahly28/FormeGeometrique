import java.awt.*;

/**
 * Classe représentant un maillon de la chaîne de responsabilité pour la gestion de la couleur noire.
 * Étend la classe abstraite ColorChain.
 */
public class BlackChain extends ColorChain{

    /**
     * Constructeur de la classe BlackChain.
     *
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     * @param affiche La chaîne de responsabilité pour l'affichage associée à ce maillon.
     */
    public BlackChain(ColorChain suivant,AffichageChain affiche) {
        super(suivant,affiche);
    }

    /**
     * Méthode pour obtenir la couleur noire en fonction d'une chaîne de caractères.
     * Si la chaîne est "black", la couleur est définie sur noir, sinon la demande est passée au maillon suivant.
     *
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant la récupération de la couleur.
     */
    @Override
    public void getColor(String chaine) throws InterruptedException {
        if(chaine.equals("black"))
        {
            //return Color.BLACK;
            getChaine().couleur = Color.BLACK;

        }
        else
        {
            this.getColorSuivant(chaine);
        }

    }
}
