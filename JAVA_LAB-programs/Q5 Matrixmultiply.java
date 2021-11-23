import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("enter rows and cols of first matrix");
        int m1=sc.nextInt();
        int n1=sc.nextInt();
        System.out.println("enter rows and cols of second matrix");
        int m2=sc.nextInt();
        int n2=sc.nextInt();
        int arr1[][]=new int[m1][n1];
        int arr2[][]=new int[m2][n2];
        if(n1!=m2){
            System.out.println("multiply not possible");
            System.exit(0);
        }
	   int arr3[][]=new int[m1][n2];
        for(int i=0;i<m1;i++){
            for(int j=0;j<n1;j++){
                arr1[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<m2;i++){
            for(int j=0;j<n2;j++){
                arr2[i][j]=sc.nextInt();
            }
        }
        int sum;
        for(int i=0;i<m1;i++){
            for(int j=0;j<n2;j++){
                sum=0;
                for(int k=0;k<n1;k++){
                    sum=sum+(arr1[i][k]*arr2[k][j]);
                }
                arr3[i][j]=sum;
            }
        }
        for(int i=0;i<m1;i++){
            for(int j=0;j<n2;j++){
                System.out.println(arr3[i][j]);
            }
        }
    }
}
