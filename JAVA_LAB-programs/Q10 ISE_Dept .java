10. Define an interface ‘Department’ with methods to readdata() and printdata(), 
print_number_designations(), number_research_consultancy_projs(). Define a ‘Faculty’ 
class with members name, designation, age, years of experience, joining_date and 
subjects_handled.
a. In package ISE define the ‘ISE_department’ class that implements the 
‘Department’ interface, accepts n faculty details and define all the methods. 
Raise a user defined exception ‘AgeException’ if the age of the faculty is > 58.
b. In the default package define a ‘MainClass’ which uses the methods of the 
above classes and also displays those faculty details whose years of experience 
is greater than or equal to 20


package ISE;
import java.util.*;
interface Department{
    public void readData();
    public void putData();
    public void print_number_designations();
    public void number_of_reasearch_projs();
}
class Faculty{
    String name,designations,joining_date,subjects,research_projs;int age,exp;
} 
class AgeException extends Exception{
    AgeException(String m)
    {
        super(m);
    } 
}
class AgeCheck{
    AgeCheck(int age) throws AgeException{
        if(age>58)
        {
            throw new AgeException("age limit exceeded");
        }
    }
}
public class ISE_Dept implements Department{
    int n;
    List<Faculty> facultylist= new ArrayList<Faculty>();
    Scanner s=new Scanner(System.in);
   public ISE_Dept()
    {
        System.out.println("enter no of faculty");
        n=s.nextInt();
        String v=s.nextLine();
    }
    public void readData() {
        
        for(int i=0;i<n;i++)
        {
            int flag=0;
            Faculty f = new Faculty();   
            System.out.println("enter details of faculty"+(i+1));
            System.out.println("enter name");
            f.name=s.nextLine();
            System.out.println("enter age");
            f.age=s.nextInt();
            String buffer=s.nextLine();
            try{
                AgeCheck a = new AgeCheck(f.age);
            }
            catch(AgeException e)
            {
                flag=1;
                System.out.println("exception: "+e.getMessage());
                i--;
            }
            if(flag==0)
            {
                System.out.println("enter designations");
                f.designations=s.nextLine();
                System.out.println("enter joining data");
            f.joining_date=s.nextLine();
            System.out.println("enter subjects");
            f.subjects=s.nextLine();
            System.out.println("enter exp");
            f.exp=s.nextInt();
            String st=s.nextLine();
            System.out.println("enter research projects");
            f.research_projs=s.nextLine();
            facultylist.add(f);
            }   
        }
    }
    public void number_of_reasearch_projs()
    {
        System.out.println("number of research projects of faculty");
        for(int i=0;i<facultylist.size();i++)
        {
            String arr[]=facultylist.get(i).research_projs.split(" ");
            System.out.println("number of  research projects of faculty "+(i+1)+" is: "+arr.length);
        }
    }
    public void print_number_designations()
    {
        System.out.println("number of designations of faculty");
          for(int i=0;i<facultylist.size();i++)
        {
            String arr[]=facultylist.get(i).designations.split(" ");
            System.out.println("number of designations of faculty "+(i+1)+" is: "+arr.length);
        }
    }
    public void putData()
    {
        System.out.println("faculty details");
        for(int i=0;i<facultylist.size();i++)
        {
            System.out.println("faculty "+(i+1)+" details");
            System.out.println("name : "+facultylist.get(i).name);
            System.out.println("age : "+facultylist.get(i).age);
            System.out.println("exp : "+facultylist.get(i).exp);
            System.out.println("designations: "+facultylist.get(i).designations);
            System.out.println("subjects handeled : "+facultylist.get(i).subjects);
            System.out.println("joining_date : "+facultylist.get(i).joining_date);
            System.out.println("research_projs :"+facultylist.get(i).research_projs);
        }
    }
    public void exp_greater_20(){
        System.out.println("faculty details with exp greater than 20");
        for(int i=0;i<facultylist.size();i++)
        {
            if(facultylist.get(i).exp>20)
            {
            System.out.println("faculty "+(i+1)+" details");
            System.out.println("name : "+facultylist.get(i).name);
            System.out.println("age : "+facultylist.get(i).age);
            System.out.println("exp : "+facultylist.get(i).exp);
            System.out.println("designations: "+facultylist.get(i).designations);
            System.out.println("subjects handeled : "+facultylist.get(i).subjects);
            System.out.println("joining_date : "+facultylist.get(i).joining_date);
            System.out.println("research_projs :"+facultylist.get(i).research_projs);
            }
        }
    }
}