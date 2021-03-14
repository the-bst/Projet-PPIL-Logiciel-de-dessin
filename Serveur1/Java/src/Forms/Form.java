/**
 * @author Viacheslav
 * @version 1.0
 */

package Forms;

import MainApps.Window_Frame;

/**
 * Classe de la forme geometrique
 */
public abstract class Form{
	
	
	private Form next; //forme suivante dans la chaine
	
	/**
	 * Constructeur
	 * @param next (type : Forme) la forme geometrique suivante 
	 */
	protected Form(Form next) {
		this.next = next;
	}
	
	/**
	 * Getter
	 * @return (type : Form ) la forme suivante
	 */
	public Form getNext() {	return next; }
	
	
	/**
	 * Verifie si la classe actuel peut dessiner
	 * @param forme (type : String) forme geometrique
	 * @return (type : boolean) true si egal, sinon false
	 */
	public boolean canDraw(String forme) {
		return getTypeForm().equals(forme.split(" ")[0]);
	}
	
	/**
	 * Dessine une forme complexe suivant les parametres passees
	 * @param form (type : Form) le type de la forme geometrique
	 * @param w (type : Window_Frame) Ecran
	 */
	public void draw(String form, Window_Frame w) {
		//si la classe actuel == form, alors elle dessine
		if(canDraw(form)){
			drawing(form, w);
		}else {	//Sinon passe la tache a la classe suivante
			if(next != null) {
				next.draw(form, w);
			}
		}
	}
	
	/*	Abstract Methodes	*/
	
	/**
	 * Indique de quel type est la forme qui herite
	 * @return (type : String ) le type de la forme geometrique
	 */
	public abstract String getTypeForm();
	
	/**
	 * Dessine un cercle suivant les parametres passees
	 * @param form (type : Form) le type de la forme geometrique
	 * @param w (type : Window_Frame) Ecran
	 */
	public abstract void drawing(String form, Window_Frame w);
	
}
