import java.awt.*;

/**
 * Cette classe abstraite représente une chaîne de responsabilité permettant de traiter une chaîne de caractères
 * et de dessiner la forme correspondante dans un contexte Graphics.
 * Elle inclut également une chaîne de responsabilité pour gérer la couleur.
 */
public abstract class AffichageChain {
    private AffichageChain next;
    ColorChain _COR;
    Color couleur;

    /**
     * Constructeur de la classe AffichageChain.
     * @param suivant Le maillon suivant dans la chaîne de responsabilité.
     */
    public AffichageChain(AffichageChain suivant)
    {

        next = suivant;
        ColorChain c;
        ColorChain red = new RedChain(null,this);
        ColorChain black = new BlackChain(red,this);
        ColorChain blue = new BlueChain(black,this);
        ColorChain green = new GreenChain(blue,this);
        ColorChain yellow = new YellowChain(green,this);
        ColorChain cyan = new CyanChain(yellow,this);
        c = cyan;
        _COR = c;

    }

    /**
     * @return Retourne la couleur associée à la chaîne de responsabilité.
     */
    public Color getC() {
        return couleur;
    }

    /**
     * Méthode abstraite permettant d'afficher la forme correspondante à la chaîne de caractères dans un contexte Graphics.
     * @param graphics Le contexte Graphics où afficher la forme.
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant l'affichage.
     */
    public abstract void Afficher(Graphics graphics, String chaine) throws InterruptedException;

    /**
     * Méthode permettant de passer la chaîne de responsabilité au maillon suivant pour un traitement ultérieur.
     * @param graphics Le contexte Graphics où afficher la forme.
     * @param chaine La chaîne de caractères à traiter.
     * @throws InterruptedException En cas d'interruption pendant l'affichage.
     */
    public void AffichageSuivant(Graphics graphics, String chaine) throws InterruptedException {
        next.Afficher(graphics, chaine);
    }
}
