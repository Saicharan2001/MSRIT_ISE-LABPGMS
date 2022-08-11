public class InputThreads {
public static void main(String[] args) throws InterruptedException { 
	GetStringThread getStringThread; 
	GetNumberThread getNumberThread; 
	getNumberThread = new GetNumberThread(); 
	getStringThread = new GetStringThread(); 
	getNumberThread.start(); 
	Thread.sleep(100);
	getStringThread.start(); 
//	getStringThread.start(); 
//	getNumberThread.start();
}
}