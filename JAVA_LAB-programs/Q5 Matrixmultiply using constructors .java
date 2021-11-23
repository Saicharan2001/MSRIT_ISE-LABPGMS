import java.util.*;
class Matrix{
    int a[][],b[][],r1,c1,r2,c2;
    Matrix()
    {
        Scanner s = new Scanner(System.in);
        System.out.println("enter rows of m1");
        r1=s.nextInt();
        System.out.println("enter cols of m1");
        c1=s.nextInt();
        System.out.println("enter rows of m2");
        r2=s.nextInt();
        System.out.println("enter cols of m2");
        c2=s.nextInt();
        a=new int[r1][c1];
        b=new int[r2][c2];
        System.out.println("enter data of m1");
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            {
                int r=s.nextInt();
                a[i][j]=r;
            }
        }
        System.out.println("enter data of m2");
        for(int i=0;i<r2;i++)
        {
            for(int j=0;j<c2;j++)
            {
                int r=s.nextInt();
                b[i][j]=r;
            }
        }
    }
    void mul()
    {
        if(c1!=r2)
        {
            System.out.println("matrix multiplication not possible");
        }
        else{
            int sum=0,c[][]=new int[r1][c2];
            for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c2;j++)
                {
                    sum=0;
                    for(int k=0;k<c1;k++)
                    {
                        sum+=a[i][k]*b[k][j];
                    } c[i][j]=sum;
                }
            }
            System.out.println("matrix after multiplication");
            for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c2;j++)
                {
                    System.out.print(c[i][j]+" ");
                }
                System.out.println();
            }
        }   
    }
}
public class p5 {
        public static void main(String args[]){
        Matrix m = new Matrix();
        m.mul();  
    } 
}
