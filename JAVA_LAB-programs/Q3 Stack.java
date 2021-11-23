import java.util.*;
class Stack{
    int top,max;
    int arr[];
    Stack(int n){
        top=-1;
        max=n;
        arr=new int[max];
    }
    Boolean push(int m){
        if(top==max-1){
            System.out.println("overflow");
            return false;
        }
        arr[++top]=m;;
        return true;
    }
    int pop(){
        if(top==-1){
            System.out.println("underflow");
        }
        else{
            int k=arr[top--];
            System.out.println("popped successsfully");
            return k;
        }
        return -1;
    }
    void display(){
        if(top==-1){
            System.out.println("underflow");
            return;
        }
        for(int i=0;i<=top;i++){
            System.out.println(arr[i]+"");
        }
    }
}
public class Main{
    public static void main(String[] args){
        Scanner sc =new Scanner(System.in);
        System.out.println("enter size of Stack");
        int g=sc.nextInt();
        Stack mystack1=new Stack(g);
        while(true){
            System.out.println("1.Push,2.pop,3.display,4.exit");
            System.out.println("enter choice");
            int choice=sc.nextInt();
            switch(choice){
                case 1:System.out.println("enter element to push\n");
                        int k=sc.nextInt();
                        String result=mystack1.push(k)?"pushed":"not pushed";
                        System.out.println(result);
                        break;
                case 2:int l=mystack1.pop();
				  if(l!=-1){
                        System.out.println("element popped is:"+l);
				  }
                        break;
                case 3:mystack1.display();
                        break;
                case 4:System.exit(0);
                        
            }
        }
    }
}
