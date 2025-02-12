import java.awt.*;

/**
 * Classe abstraite représentant un maillon de la chaîne de responsabilité pour la gestion des couleurs.
 */
public abstract class ColorChain {
    /**
     * Maillon suivant dans la chaîne de responsabilité.
     */
    private ColorChain next;


    /**
     * Chaîne de responsabilité pour l'affichage associée à ce maillon.
     */
    private AffichageChain chaine;

    /**
     * Constructeur de la classe ColorChain.
     *
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     * @param affiche La chaîne de responsabilité pour l'affichage associée à ce maillon.
     */
    public ColorChain(ColorChain suivant,AffichageChain affiche)
    {
        next = suivant;
        chaine = affiche;

    }

    /**
     * Getter pour la chaîne de responsabilité pour l'affichage associée à ce maillon.
     *
     * @return La chaîne de responsabilité pour l'affichage.
     */
    public AffichageChain getChaine()
    {
        return chaine;
    }


    /**
     * Méthode abstraite pour obtenir la couleur en fonction d'une chaîne de caractères.
     *
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant la récupération de la couleur.
     */
    public abstract void getColor(String chaine) throws InterruptedException;

    /**
     * Méthode pour passer la demande de récupération de couleur au maillon suivant dans la chaîne.
     *
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant la récupération de la couleur.
     */
    public void getColorSuivant(String chaine) throws InterruptedException {
        next.getColor(chaine);
    }
}
