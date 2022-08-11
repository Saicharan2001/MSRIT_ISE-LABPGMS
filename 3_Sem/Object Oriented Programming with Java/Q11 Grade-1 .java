11. Write a Java Program that does the following related to Packages and Interfaces , Exception 
Handling:
a. Create an interface Student which gets the name and branch of a student.
b. Create a package called ‘StudentPackage’ which has a user-defined class 
RegisterStudent.
c. If a student registers above 30 credits for the semester, the method should throw 
a user-defined exception called ‘CreditLimit’ and display an appropriate 
message.
d. Create another package called ‘ResultPackage’ which displays the grade for the 
subject registered for particular semester and the SGPA . If SGPA is above 10 
then throws an InvalidSGPA user-defined exception.
e. In the StudentPackage , collect the marks of all the subjects in 4 semesters and 
calculate SGPA and CGPA.


package ResultPackage;
import java.util.*;
class SGPALimit extends Exception{
    SGPALimit(String m)
    {
        super(m);
    }
}
class SGPACheck{
    SGPACheck(float sgpa) throws SGPALimit{
        if(sgpa>10)
        {
            throw new SGPALimit("cannot be more than 10");
        }
        if(sgpa<0)
        {
            throw new SGPALimit("cannot be less than 0"); 
        }
    }
}
public class Grade {
    Scanner s = new Scanner(System.in);
    int n,arr_grades[];float sgpa_arr;public float sgpa=0;
    public void getGrade(){
    System.out.println("enter no of subjects");
    n=s.nextInt();
    arr_grades=new int[n];
    for(int i=0;i<n;i++)
    {
        System.out.println("enter grade of subject"+(i+1));
        int g=s.nextInt();
        arr_grades[i]=g;
        sgpa+=g;
    }
    sgpa=sgpa/n;
    sgpa_arr=sgpa;
    try{
        SGPACheck sg =new SGPACheck(sgpa);
    }
    catch(SGPALimit e)
    {
        System.out.println("exception :"+e.getMessage());
    }
    } 
    public void displayGrade()
    {
        System.out.println("SGPA: ");
        for(int i=0;i<arr_grades.length;i++){
            System.out.println("grade of subject"+(i+1)+" is: "+arr_grades[i]);
        }
        System.out.println("sgpa for the sem: "+sgpa_arr);
        
    }
    public float getsgpa()
    {
        return sgpa_arr;
    }

}
