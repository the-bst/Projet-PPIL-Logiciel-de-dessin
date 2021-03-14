/**
 * @author Viacheslav
 * @version 1.0
 */

package Forms;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;

import MainApps.Point;
import MainApps.Window_Frame;

/**
 * Classe d'un segment heritant de la classe Form
 */
public class Segment extends Form {
	
	/**
	 * Constructeur
	 * @param next (type : Forme) la forme geometrique suivante 
	 */
	public Segment(Form next) {
		super(next);
	}
	
	/**
	 * Getter
	 * @return (type : String ) le type de la forme geometrique
	 */
	@Override
	public String getTypeForm() {
		return "Segment";
	}
	
	/**
	 * Dessine un cercle suivant les parametres passees
	 * @param form (type : Form) le type de la forme geometrique
	 * @param w (type : Window_Frame) Ecran
	 */
	@Override
	public void drawing(String form, Window_Frame w) {
		//Verification de la chaine form
		if(form.matches("^Segment couleur [0-9]+ \\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\);\\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\)$")) {
			
			/*	Recuperation de la couleur et de points	*/
			String[] t = form.split(" ");
			String co = t[2];
			String[] t2 = t[3].split(";");
			
			Point P1 = new Point(t2[0]);
			Point P2 = new Point(t2[1]);
			
			/*	Recup de graphics2D	*/
			Graphics2D graph = w.getGraph2D();
			
			/*	Application de la couleur	*/
			graph.setColor(new Color(Integer.parseInt(co)));
			
			graph.draw(new Line2D.Double(P1.getX() + w.getCenter().getX(),
					   					 P1.getY() + w.getCenter().getY(),
					   					 P2.getX() + w.getCenter().getX(),
					   					 P2.getY() + w.getCenter().getY()));
			
		}
		
	}



}
