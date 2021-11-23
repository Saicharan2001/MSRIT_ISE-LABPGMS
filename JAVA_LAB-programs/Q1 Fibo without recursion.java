//Fibonaaci series
import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Fibonaaci.fibo(n);
	}
}
class Fibonaaci{
    static void fibo(int s){
        int a,b,c;
        a=0;
        b=1;
        System.out.println(a+","+b);
        for(int i=1;i<=s-2;i++){
            c=a+b;
            System.out.print(c+",");
            a=b;
            b=c;
        }
    }
}