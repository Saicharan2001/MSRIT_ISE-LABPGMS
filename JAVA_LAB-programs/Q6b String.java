//Checking number of occurences of a word
import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("enter a string");
		String str=sc.nextLine();
		System.out.println("enter a word u want to find no:of concurrences");
		String word=sc.next();
		String a[]=str.split(" ");
		int count=0;
		for(int i=0;i<a.length;i++){
			if(word.equals(a[i]))
				count++;
		}
		System.out.println("no of occurences:"+count);
	}	
}
