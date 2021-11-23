import java.util.*;
class Complex{    
    double a,b;
    Complex(double a,double b){
        this.a=a;
        this.b=b;
    }
    void add(Complex k){
        double temp1=k.a+a;
        double temp2=k.b+b;
        System.out.println("The sum of c1 and c2 is:"+temp1+"+i"+temp2);
    }
    void subtract(Complex k){
        double temp1=a-k.a;
        double temp2=b-k.b;
        System.out.println("The subtract of c2 from c1 is:"+temp1+"+i"+temp2);
    }
    void multiply(Complex k){
        double temp1=a*(k.a)-b*(k.b);
        double temp2=a*(k.b)+b*(k.a);
        System.out.println("The result of multiplication is:"+temp1+"+i"+temp2);
    }
}
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the first two real numbers for first complex num");
		double m1=sc.nextDouble();
		double n1=sc.nextDouble();
		System.out.println("enter the first two real numbers for second complex num");
		double m2=sc.nextDouble();
		double n2=sc.nextDouble();

		Complex c1=new Complex(m1,n1);
		Complex c2=new Complex(m2,n2);
		c1.add(c2);
		c1.subtract(c2);
		c1.multiply(c2);
	}
}