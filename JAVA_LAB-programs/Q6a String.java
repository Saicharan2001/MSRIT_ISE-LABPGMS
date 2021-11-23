// extracting a part of the string
import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("enter as string");
		String str=sc.nextLine();
		char sai[]=str.toCharArray();       //important
		System.out.println("enter the initial position from where u want to extract;start from 0");
		int m=sc.nextInt();
		char saiex[]=new char[50];
		System.out.println("enter how many characters u wonna extract");
		int n=sc.nextInt();
		for(int i=m,j=0;i<m+n;i++,j++){
			saiex[j]=sai[i];
		}
		String strex=new String(saiex);
		System.out.println(strex);
	}
}

