//fibonaaci series with recursion
import java.util.Scanner;
public class Main
{
	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		int a=sc.nextInt();
		for(int i=1;i<=a;i++){
		    System.out.println(","+Fibonaaci.fibo(i));
		}
		
	}
}
class Fibonaaci{
    static int fibo(int n){
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        return (fibo(n-1)+fibo(n-2));
    }
}