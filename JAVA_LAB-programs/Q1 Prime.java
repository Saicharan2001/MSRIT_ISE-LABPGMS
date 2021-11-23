import java.util.*;
public class Main
{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		String result=Prime.number(a)?"Its a prime number":"Its not a prime";
		System.out.println(result);
	}
}
class Prime{
    public static Boolean number(int n){
		int i;
		for(i=2;i<=(n/2);i++){
			if(n%i==0){
				return false;
			}
		}
	    return true;
    }
}