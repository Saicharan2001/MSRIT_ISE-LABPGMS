#include<stdio.h>
#include<string.h>

int checksum(int fl)
{
    char in[100];
    //int buf[25];
    int i,sum=0,n,temp,temp1;
    scanf(" %[^\n]s",in); // SPACE REQUIRED BEFORE % TO TAKE IN A STRING INSTEAD OF ONE WORD
    //fgets(in,100,stdin);
    
    if(strlen(in)%2!=0)
        n=(strlen(in)+1)/2;
    else
        n=(strlen(in))/2;
    //printf("%ld is length\n , %d",strlen(in),n);
    for(i=0;i<n;i++)
    {
        //printf("%d\n",i);
        temp=in[i*2];
        //printf("%d ", temp);
        temp=(temp*256)+in[(i*2)+1];
        //printf(" %d",temp);

        sum=sum+temp;
    	//printf("%d",sum);
    }
    
    if(fl==1)
    {
        printf("Enter the checksum value \n");
        scanf ("%x", &temp1);
        sum+=temp1;
    }
    
    if(sum%65536!=0)
    {
        n=sum%65536;
        sum=(sum/65536) + n;
    }
    sum=65535-sum;
    //printf("%x\n",sum);
    return sum;
}


void main()
{
    //char st[100];
    int ch,sum;
    do{
        printf("1.Encode \n2.Decode \n3.Exit \n");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {

            case 1: printf("Enter the string \n");
                    //scanf(" %[^\n]s",st);
                    sum=checksum(0);
                    printf("Checksum to append is:%x \n",sum);
                    break;

            case 2: printf("Enter the string \n");
                    sum=checksum(1);
                    if(sum!=0)
                        printf("The data has been tampered with or invalid checksum\n");
                    else
                        printf("The checksum is valid \n");
                    break;
            case 3: break;
            default: printf("Invalid option, try again \n");
        }
    }while(ch!=3);
}
 
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// int checksum(int f1){
//     char in[100];
//     int i,n,temp,temp1,sum=0;
//     scanf(" %[^\n]s",in);
//     if(strlen(in)%2!=0){
//         n=(strlen(in)+1)/2;
//     }
//     else{
//         n=strlen(in)/2;
//     }
//     for(int i=0;i<n;i++){
//         temp=in[i*2];
//         temp=temp*256+in[i*2+1];
//         sum+=temp;
//     }
//     if(f1==1){
//         printf("Enter the checksum value\n");
//         scanf("%x",&temp1);
//         sum+=temp1;
//     }
//     if(sum%65536!=0){
//         sum=(sum/65536)+(sum%65536);
//     }
//     sum=65535-sum;
//     return sum;
    
// }
// void main(){
//     int ch,sum;
//     do{
//         printf("Enter any 1.Encode , 2.Decode , 3.Exit\n");
//         scanf("%d",&ch);
//         printf("\n");
//         switch(ch){
//             case 1:printf("Enter the string\n");
//                    sum=checksum(0);
//                    printf("checksum to be appended is %x\n",sum);
//                    break;
//             case 2:printf("Enter the string\n");
//                    sum=checksum(1);
//                    if(sum==0){
//                        printf("The data is valid\n");
//                    }
//                    else{
//                        printf("The data is tampered\n");
//                    }
//                    break;
//             case 3:break;
//         }
//     }while(ch!=3);
// }