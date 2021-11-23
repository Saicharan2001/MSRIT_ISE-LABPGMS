import java.util.*;
public class Main
{
	public static void main(String[] args) {
		System.out.println("Enter the number of digits");
		Scanner sc=new Scanner(System.in);
		int s=sc.nextInt();;
        int arr[]=new int[s];
        for(int i=0;i<s;i++){
            System.out.println("entr the element");
            arr[i]=sc.nextInt();
        }
	   int temp;
        for(int i=s-1;i>=0;i--){
            for(int j=0;j<i;j++){
                temp=0;
                if(sai[j]>sai[j+1]){
                    temp=sai[j+1];
                    sai[j+1]=sai[j];
                    sai[j]=temp;
                }
            }
        }
        System.out.println("Bubble sort");
        for(int i=0;i<s;i++){
            System.out.println(sai[i]);
        }
        
	}
}
