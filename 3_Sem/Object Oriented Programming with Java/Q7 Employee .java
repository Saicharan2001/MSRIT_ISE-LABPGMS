import java.util.*;
class Personal{
    String name, education;
	int age, experienceYears, numberOfLoans, loanAmount, tax;
	float basic,da,hra,total;
	Personal(String name, int age, String education, int experienceYears, int numberOfLoans, float basic,
	            int loanAmount){
	                this.name=name;
	                this.age=age;
	                this.education=education;
	                this.experienceYears=experienceYears;
	                this.numberOfLoans=numberOfLoans;
	                this.basic=basic;
	                this.loanAmount=loanAmount;
	  }
	  float Salary(float x){
		    hra = (float) (basic * 0.4);
		    da = (float) (basic* 0.6);
		    total = (basic + hra + da);
	        return  total; 
	  }
	void isEligible() {
		if ((loanAmount <= total / 2) && (numberOfLoans < 5))
			System.out.println("Is eligible for loan");
		else
			System.out.println("Not eligible for loan");
	}
	int taxPay() {
		if (total < 250000)
			tax = 0;
		else if ((total > 250000) && (total < 500000))
			tax = (int) (0.1 * total);
		else if ((total > 500000) && (total < 1000000))
			tax = (int) (0.2 * total);
		else if (total > 1000000)
			tax = (int) (0.3 *total);
		return tax;
	}
	void isEligiblePromotion() {
		if (experienceYears > 10)
			System.out.println("Eligible for promotion ");
		else
			System.out.println("Not eligible for promotion");
	}

	void Display() {
		System.out.println("name: " + name);
		System.out.println("age :" + age);
		System.out.println("education :" + education);
		System.out.println("Years of Experience: " + experienceYears);
		System.out.println("Number of Loans: " + numberOfLoans);
		System.out.println("Salary: " + Salary(basic));
		isEligible();
		System.out.println("The tax to be paid is " + taxPay());
		isEligiblePromotion();
		System.out.println("\n\n\n");
	}
}
public class Main
{
	public static void main(String[] args) {
	    Scanner scanner=new Scanner(System.in);
	    System.out.println("Enter number of employees to be created");
	    int n=scanner.nextInt();
	    Personal p[]=new Personal[n];	
	    for (int i = 0; i < n; i++) {
			System.out.println("Enter the information for employee number "+(i+1));
			System.out.println("Enter the name");
			String name = scanner.nextLine();
			System.out.println("Enter the age");
			int age = scanner.nextInt();
			System.out.println("Enter Education");
			String education = scanner.nextLine();
			System.out.println("Enter years of experience");
			int experienceYears = scanner.nextInt();
			System.out.println("Enter number of Loans");
			int numberOfLoans = scanner.nextInt();
			System.out.println("Enter the basic salary");
			int basic = scanner.nextInt();
			System.out.println("Enter the loan amount");
			int loanAmount = scanner.nextInt();
			p[i] = new Personal(name, age, education, experienceYears, numberOfLoans, basic, loanAmount);
	    }
	    for (int j = 0; j < n; j++) {
			System.out.println("This is employee number "+(j+1)+"'s Information");
			p[j].Display();
			System.out.println("\n");
		}
	}
}
