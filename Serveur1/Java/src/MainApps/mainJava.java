/**
 * @author Viacheslav
 * @version 1.0
 */

package MainApps;


import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import Forms.Circle;
import Forms.Form;
import Forms.Polygon;
import Forms.Segment;
import Forms.ComplexShape;

/**
 * Classe Principal
 */
public class mainJava {
	
	/**
	 * forme geometrique
	 */
	public static Form form;

	/**
	 * methode Principal
	 * @param args (type : String[]) un tableau de parametres que la fonction main peut prendre
	 * @throws IOException si ServerSocket echoue
	 */
	@SuppressWarnings("resource")
	public static void main(String[] args) throws IOException {
		
		/*	Preparation de la connexion	*/
		ServerSocket s = null;
		try {
			s = new ServerSocket(8888);
		} catch (IOException e) {
			e.printStackTrace();
		}
		ThreadGroup gr;
		InetAddress pc = InetAddress.getLocalHost();;
		int portLocal = s.getLocalPort();;
		
		/*	Creation de la chaine de responsabilite	*/
		form = new ComplexShape(null);
		form = new Polygon(form);
		form = new Circle(form);
		form = new Segment(form);
		
		/*	Infos sur la connexion	*/
		System.out.println("Infos sur la connexion :");
		System.out.println("ServerSocket numero " + s + " est en marche");
		System.out.println("[ IP : " + pc.getHostAddress() + " ]" + " | [ Port : " + portLocal + " ]" );
		
		gr = new ThreadGroup("Sockets");
		
		/*	Tant que la connexion n'est pas etablie avec le client, repeter	*/
		int id = 0;
		do {
			Socket socket;
			DrawForm drawForm;
			
			socket = s.accept(); id++;
			
			System.out.println("Connexion n° :" + id + " réussi");
			
			/*	Si connexion est etablie, alors dessine	*/
			drawForm = new DrawForm(socket, gr, id);
			drawForm.start();
			
		}while(true);
		
	}

}
