/**
 * @author Viacheslav
 * @version 1.0
 */

package Forms;

import MainApps.Window_Frame;
import MainApps.mainJava;

/**
 * Classe FormeComplexe heritant de la classe Form
 */
public class ComplexShape extends Form {
	
	/**
	 * Constructeur
	 * @param next (type : Forme) la forme geometrique suivante 
	 */
	public ComplexShape(Form next) {
		super(next);
	}
	
	/**
	 * Getter
	 * @return (type : String ) le type de la forme geometrique
	 */
	@Override
	public String getTypeForm() {
		return "FormeComplexe";
	}
	
	/**
	 * Dessine une forme complexe suivant les parametres passees
	 * @param form (type : Form) le type de la forme geometrique
	 * @param w (type : Window_Frame) Ecran
	 */
	@Override
	public void drawing(String form, Window_Frame w) {
		///Verification de la chaine forme
		if (form.matches("^FormeComplexe couleur [0-9]+ .*")) {
			//Recup des infos
			form = form.substring(form.indexOf("[") + 1, form.lastIndexOf("]"));
			
			/*	indexOf recherche	premiere forme	dans la ligne	*/
			if (form.indexOf("|") != -1) {
				String[] tab = form.split("\\|");	//recuperer les formes(avec les parametres) et stocker dans tableau
				/*	Pour chaque formes simples, dessiner	*/
				for (String forme : tab) {
					mainJava.form.draw(forme, w);
				}
			} else {	// Si la forme est simple
				mainJava.form.draw(form, w);
			}
		}	

	}

}
