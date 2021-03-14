/**
 * @author Viacheslav
 * @version 1.0
 */

package MainApps;

import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;


/**
 * Classe qui s'occupe de l'ecran
 */
@SuppressWarnings("serial")
public class Window_Frame extends Frame {
	
	/**
	 * Constructeur 
	 * @param noClient (type : int) numero du client
	 * @param form (type : String) la forme geometrique a dessiner
	 */
	public Window_Frame(int noClient, String form) {
		
		super("Dessin de " + form + "du client numero " + noClient);
		
		/*	Amelioration de defintion de la fenetre	*/
		/*	Recup de dimension d'ecran	*/
		Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
		
		/*	Definition de la largeur	*/
		double w = d.getWidth();
		
		/*	Definition de la fenetre	(top(0),left(0),largeur,hauteur)	*/
		this.setBounds(0,0,(int)w-800,(int)w-1000);
		
		/*	Placer ecran a un endroit "aleatoire"	*/
		this.setLocationRelativeTo(null);

		/*	Precaution	anti-plaintage, interdire de redimensionner la fenetre	*/
		this.setResizable(false);
		
		/*	Activer la fenetre	*/
		this.setVisible(true);
		
		
		
		/* Fermer la fenetre avec CROIX ROUGE */
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent windowEvent) {
				System.exit(0);	//liberer la memoire
			}
		});
		
		/*	desactiver repaint	*/
		setIgnoreRepaint(true);
		
		
		this.createBufferStrategy(2);
		
		try {	/*	Peut avoir une interruption de systeme	*/
			Thread.sleep(150);
		} catch (InterruptedException e) {
			
			e.printStackTrace();
		}
		
		/*	Tracer un repere orthonorme (axes des abscisses et ordonnees)	*/
		BufferStrategy strategie = this.getBufferStrategy();
		
		Graphics graphics = strategie.getDrawGraphics(); 

		graphics.drawLine(0, getHeight()/2, getWidth(), getHeight()/2);
		graphics.drawLine(getWidth()/2, 0, getWidth()/2, getHeight());
		
	}
	/**
	 * @return (type : Point) nouveau point (x,y)
	 * */
	public Point getCenter() {	return new Point(getWidth()/2, getHeight()/2);	}
	
	/**
	 * @return (type : Graphics2D) graphics2D de buffer de la frame
	 */
	public Graphics2D getGraph2D() {
		/*	Recup du buffer	*/
		return (Graphics2D) this.getBufferStrategy().getDrawGraphics();
	}
}