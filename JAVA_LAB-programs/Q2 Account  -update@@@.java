import java.util.*;
class Account{
     int Accno;
    String name;
     int Phone_No;
     float balance_amt;
     Scanner sc=new Scanner(System.in);
    Account(int Accno,String name,int Phone_No,float balance_amt){
        this.Accno=Accno;
        this.name=name;;
        this.Phone_No=Phone_No;
        this.balance_amt=balance_amt;
        System.out.println("Account with ur submitted  details is created successfully");
    }
    void getinput(){
        System.out.println("please enter the below mentiioned details");
        System.out.println("Enter ur name");
        name=sc.nextLine();
        System.out.println("Enter ur phone number");
        Phone_No=sc.nextInt();
        System.out.println("enter ur accno");
        Accno=sc.nextInt();
        System.out.println("enter the balance amt");
        balance_amt=sc.nextFloat();
    }
    void deposit(float amount){
        System.out.println("Amount to be deposited is:"+amount);
        System.out.println("initial balance :"+balance_amt);
        balance_amt=balance_amt+amount;
        System.out.println("Amount deposited and ur final Account balance :"+balance_amt);
    }
    void withdraw(int withdraw_amt){
        if(withdraw_amt<=0){
            System.out.println("invalid Amount");
            return;
        }
        else if(withdraw_amt<=balance_amt){
            System.out.println("Amount to be withdrawn:"+withdraw_amt);
            balance_amt=balance_amt-withdraw_amt;
            System.out.println("Amount withdrawn and ur final Account balance :"+balance_amt);
        }
        else{
            System.out.println("Low balance and request access denied");
            return;
        }
    }
    
}
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Account acc;
        acc.getinput();
        acc=new Account(accno,name,Phone_No,balance_amt);
        while(true){
             System.out.println("pick ur choice");
             System.out.println("1.withdraw\n,2.deposit\n,3.exit\n");
             int choice=sc.nextInt();
             if(choice==1){
                  System.out.println("Enter the amount to be withdrawn");
                  int withdrawal=sc.nextInt();
                  acc.withdraw(withdrawal);
             }
             else if(choice==2){
                System.out.println("Enter the amount to be deposited");
                float deposital=sc.nextFloat();
                acc.deposit(deposital);
             }
             else if(choice==3){
                 System.out.println("Exit point");
                 System.exit(0);
             }
             else{
                 System.out.println("Enter a valid choice");
             }
        }
    }
}