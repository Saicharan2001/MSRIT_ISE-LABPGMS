//Checking the equality of strings
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the first string");
		String firstString = scanner.nextLine();
		System.out.println("Enter the second string ");
		String secondString = scanner.nextLine();
		firstString = firstString.toLowerCase();
		secondString = secondString.toLowerCase();
		if (firstString.equals(secondString))
			System.out.println("Both strings are equal ");
		else
			System.out.println("Strings are not equal");
		scanner.close();
	}
}