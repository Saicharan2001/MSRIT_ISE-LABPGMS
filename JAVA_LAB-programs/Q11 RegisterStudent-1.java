 package StudentPackage;
import ResultPackage.*;
import java.util.*;
interface Student{
    public void getDetails();
}
class CreditLimit extends Exception
{
    CreditLimit(String s)
    {
        super(s);
    }
}
class CreditCheck
{
    CreditCheck(int a) throws CreditLimit{
        if(a>30)
        {
            throw new CreditLimit("cannot exceed 30");
        }
    }
}
public class RegisterStudent implements Student{
    Scanner s = new Scanner(System.in);
    int totalcredits=0,subjects;String name,branch;
   public RegisterStudent()
    {
        System.out.println("enter name");
         name=s.n extLine();
        System.out.println("enter branch");
        branch=s.nextLine();
    }
    public void getDetails()
    {
        System.out.println("enter no of subjects");
        subjects=s.nextInt();
        for(int i=0;i<subjects;i++)
        {
            System.out.println("enter no of credits for subject "+(i+1));
            int c=s.nextInt();
            totalcredits+=c;
        }
        try{
            CreditCheck cr = new CreditCheck(totalcredits);
        }
        catch(CreditLimit e)
        {
            System.out.println("exception: "+e.getMessage());
        }
    }
    public void GradeTotal()
    {
        float cgpa=0;
        for(int i=0;i<4;i++)
        {
            Grade g = new Grade();
        
            System.out.println("sem: "+(i+1));
            g.getGrade();
            g.displayGrade();
            cgpa+=g.getsgpa();
        }
        cgpa/=4;
        System.out.println("cgpa :"+cgpa);  
    }
    public static void main(String args[])
    {
        RegisterStudent r =new RegisterStudent();
        r.getDetails();
        r.GradeTotal();
    }

}
