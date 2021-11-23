//concatenation
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the first string");
		String one = scan.nextLine();
		System.out.println("Enter the second string");
		String two = scan.nextLine();
		String three = one.concat(two);
		System.out.println("Concatenated two strings \nThe string is now " + three);
		scan.close();
	}

}
