/**
 * @author Viacheslav
 * @version 1.0
 */


package MainApps;


/**
 * Classe Point qui est la base de tout les formes geometriques
 */
public class Point {
	
	/*	Atributs	*/
	private double x,y;
	
	/**
	 * Constructeur 1
	 * @param x (type : double) coordonnee horizontal
	 * @param y (type : double) coordonnee vertical
	 */
	public Point(double x, double y ) {
		this.x = x;
		this.y = y;
	}
	
	/**
	 * Constructeur 2
	 * @param form (type : String) un point geometrique
	 */
	public Point(String form) {
		
		if(form.matches("\\(-?[0-9]+\\.?[0-9]+,-?[0-9]+\\.?[0-9]+\\)$")) {
			
			/*	Recupere x et y	*/
			form= form.substring(form.indexOf("(") + 1, form.indexOf(")"));
			String[] t = form.split(",");
			
			x = Double.parseDouble(t[0]);
			y = -Double.parseDouble(t[1]);	// "-" : Ordonnee, sens vers le bas
		}
	}
	
	/**
	 * Getter
	 * @return (type : double ) x (sur l'axe horizontal)
	 */
	public double getX() {	return x;	}
	
	/**
	 * Getter
	 * @return (type : double ) x (sur l'axe vertical)
	 */
	public double getY() {	return y;	}
}
