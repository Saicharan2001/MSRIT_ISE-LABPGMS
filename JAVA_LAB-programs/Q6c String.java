//Replacing a substring within a string
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		System.out.println("Hello World");
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a string");
		String str=sc.nextLine();
		System.out.println("Enter the string u wonna replace");
		String str1=sc.nextLine();
		System.out.println("Enter the new string to replace with old one");
		String str2=sc.nextLine();
		sc.close();
		String replaced=str.replace(str1,str2);
		System.out.println("replaced string is:"+replaced);
	
	}
}
