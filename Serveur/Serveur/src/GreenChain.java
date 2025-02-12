import java.awt.*;

/**
 * Classe représentant un maillon de la chaîne de responsabilité pour la gestion de la couleur verte.
 * Étend la classe abstraite ColorChain.
 */
public class GreenChain extends ColorChain{

    /**
     * Constructeur de la classe GreenChain.
     *
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     * @param affiche La chaîne de responsabilité pour l'affichage associée à ce maillon.
     */
    public GreenChain(ColorChain suivant,AffichageChain affiche) {
        super(suivant,affiche);
    }

    /**
     * Méthode pour obtenir la couleur verte en fonction d'une chaîne de caractères.
     * Si la chaîne est "green", la couleur est définie sur verte, sinon la demande est passée au maillon suivant.
     *
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant la récupération de la couleur.
     */
    @Override
    public void getColor(String chaine) throws InterruptedException {
        if(chaine.equals("green"))
        {
            getChaine().couleur = Color.GREEN;
            //return Color.green;
        }
        else
        {
            this.getColorSuivant(chaine);

        }
    }
}
