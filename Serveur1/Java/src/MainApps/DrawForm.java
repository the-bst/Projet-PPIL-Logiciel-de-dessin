/**
 * @author Viacheslav
 * @version 1.0
 */

package MainApps;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

/**
 * Classe qui dessine la forme geometrique
 * avec les infos recuperee d'un flux
 */
public class DrawForm extends Thread {
	
	/*	Attributs	*/
	private BufferedReader entree;
	private Socket socket;
	private int connexion;
	
	/**
	 * Constructeur
	 * @param s (type : Socket) Socket
	 * @param gr (type : ThreadGroup) groupe de Thread
	 * @param co (type : int) id connexion
	 * @throws IOException BufferdReader peut poser un probleme
	 */
	public DrawForm(Socket s, ThreadGroup gr, int co) throws IOException {
		super(gr, "Dessiner la forme depuis le serveur");
		
		/*	INITIALISER socket et connexion AVANT InputStremReader*/
		socket = s;
		connexion = co;
		
		/*	Lecture de la premiere ligne 
		 * necessaire pour pointer sur la suite des infos
		 * */
		entree = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
		
		/*
		String str = entree.readLine();
		System.out.println("Voici ce que j'ai recupere\n" + str);
		System.out.println("FIN");
		*/
		
	}
	
	/**
	 * Procedure run
	 */
	public void run() {

		String lig = null;	//si readLine echoue
		
		while(!isInterrupted()) {
			try {
				/*	Lecture des lignes	*/
				lig = entree.readLine();
			} catch (IOException e) {
				System.err.println("Lecture Impossible");
			}
			if(lig != null) {
				System.out.println("Recu du client " + this.connexion + "\n" + lig);
				Window_Frame w = new Window_Frame(connexion, lig);
				mainJava.form.draw(lig, w);
				w.getBufferStrategy().show();
				w.getBufferStrategy().getDrawGraphics().dispose();
				
				try {
					sleep(7);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}	
		}
	}
}

