import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) throws IOException{
		final Socket socket = new Socket("192.168.0.103", 6789);
		final PrintWriter out = new PrintWriter(socket.getOutputStream());
//		out.print("Hello");
//		out.flush();
		final BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		
		new Thread(new Runnable(){
			@Override
			public void run() {
				String line = null;
				do{
					try {
						line = in.readLine();
					} catch (IOException e) {
						System.out.println("IOException :: "+e.getMessage());
					}
					if(line != null){
						System.out.println("Got: "+line);
					}
				}while(line != null);
			}
		}).start();
		
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextLine()){
			String line = sc.nextLine();
			if(line != null){
				out.print(line);
				out.flush();
				if(line.equalsIgnoreCase("close")){
					break;
				}
			}
		}
		sc.close();
		in.close();
		out.close();
		socket.close();
	}
	
}
