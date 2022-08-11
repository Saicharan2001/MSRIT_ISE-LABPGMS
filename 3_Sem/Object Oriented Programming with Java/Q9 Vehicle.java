import java.util.*;
 abstract class Vehicle {
	public int year_of_manufacture;

	Vehicle() {
	}

	public abstract int getData();

	public abstract void putData(int year);
}

class TwoWheeler extends Vehicle {

	@Override
	public int getData() {

		return year_of_manufacture;
	}

	@Override
	public void putData(int year) {
		year_of_manufacture = year;

	}

	TwoWheeler(int year) {
		year_of_manufacture = year;

	}

}

final class FourWheeler extends Vehicle {

	@Override
	public int getData() {

		return year_of_manufacture;

	}

	@Override
	public void putData(int year) {
		year_of_manufacture = year;

	}
	FourWheeler(int year){
		year_of_manufacture=year;
	}

}

class MyTwoWheeler extends TwoWheeler {
	MyTwoWheeler(int year) {
		super(year);
	}

}
public class Main {

	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
	    System.out.println("Enter the year");
	    int year=sc.nextInt();
		MyTwoWheeler myTwoWheeler=new MyTwoWheeler(2023);
		System.out.println("Year of manufacture is:"+myTwoWheeler.getData());
	}

}
