/**
 * @author Viacheslav
 * @version 1.0
 */

package Forms;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

import MainApps.Point;
import MainApps.Window_Frame;

/**
 * Classe Cercle heritant de la classe Form
 */
public class Circle extends Form {
	
	/**
	 * Constructeur
	 * @param next (type : Forme) la forme geometrique suivante 
	 */
	public Circle(Form next) {	super(next);	}
	
	/**
	 * Getter
	 * @return (type : String ) le type de la forme geometrique
	 */
	@Override
	public String getTypeForm() {	return "Cercle";	}
	
	/**
	 * Dessine un cercle suivant les parametres passees
	 * @param form (type : Form) le type de la forme geometrique
	 * @param w (type : Window_Frame) Ecran
	 */
	@Override
	public void drawing(String form, Window_Frame w) {
		/*	Verification de la chaine form	*/
		if(form.matches("^Cercle de couleur [0-9]+ [0-9]+\\.?[0-9]+  \\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\)$")) {
			
			/*	Recuperation de rayon(r), couleur(co), centre(ce)	*/
			String[] t = form.split(" ");
			double r = Double.parseDouble(t[2]);
			String co = t[4];
			
			/*	creation d'un nouveau Point */
			Point ce = new Point(t[5]);
			
			/*	Recup de graphics2D	*/
			Graphics2D graph = w.getGraph2D();
			
			/*	Application de la couleur	*/
			graph.setColor(new Color(Integer.parseInt(co)));
			
			/*	Dessin	*/
			graph.draw(new Ellipse2D.Double(ce.getX() + w.getCenter().getX() - r*0.5, ce.getY() + w.getCenter().getY() - r*0.5, r, r));
			
		}
	}
}
