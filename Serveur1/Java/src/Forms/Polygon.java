/**
 * @author Viacheslav
 * @version 1.0
 */

package Forms;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.util.ArrayList;

import MainApps.Point;
import MainApps.Window_Frame;

/**
 * Classe Polygone heritant de la classe Form
 */
public class Polygon extends Form {
	
	/**
	 * Constructeur
	 * @param next (type : Forme) la forme geometrique suivante 
	 */
	public Polygon(Form next) {
		super(next);
	}
	
	/**
	 * Getter
	 * @return (type : String ) le type de la forme geometrique
	 */
	@Override
	public String getTypeForm() {
		return "Polygone";
	}
	
	/**
	 * Dessine un cercle suivant les parametres passees
	 * @param form (type : Form) le type de la forme geometrique
	 * @param w (type : Window_Frame) Ecran
	 */
	@Override
	public void drawing(String form, Window_Frame w) {
		///Verification de la chaine forme
		if (form.matches("^Polygone couleur [0-9]+ \\{(\\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\);*){1,}\\}$")) {

			// Récup couleur
			String co = form.split(" ")[2];

			// Récupération points
			ArrayList<Double> listX = new ArrayList<Double>();
			ArrayList<Double> listY = new ArrayList<Double>();
			
			form = form.substring(form.indexOf("{") + 1, form.indexOf("}"));

			String[] tabPoints = form.split(";");

			// Creation de points
			for (String i : tabPoints) {
				Point p = new Point(i);
				listX.add(p.getX());
				listY.add(p.getY());
			}

			//Ajout du point dans la liste des points
			listX.add(listX.get(0));
			listY.add(listY.get(0));
			int taille = listX.size();

			// Récupération du graph
			Graphics2D graph = w.getGraph2D();

			// Modification la couleur du pinceau
			graph.setColor(new Color(Integer.parseInt(co)));

			//Dessin de polygone
			for (int i = 0; i < taille - 1; i++) {
				graph.draw(new Line2D.Double(listX.get(i) + w.getCenter().getX(),
										   listY.get(i) + w.getCenter().getY(),
										   listX.get(i + 1) + w.getCenter().getX(),
										   listY.get(i + 1) + w.getCenter().getY()));
			}

		}

	}

}
