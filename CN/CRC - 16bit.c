//Chandana T
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     int i,j,keylen,msglen,flag=0;
//     char input[100],key[30],temp[100],quot[100],rem[30],key1[30];
   
//     printf("Enter data: ");
//     scanf("%s",input);
//     printf("Enter key(17 bit): ");
//     scanf("%s",key);
//     keylen=strlen(key);
//     msglen=strlen(input);
//     strcpy(key1,key);
//     for(i=0;i<keylen-1;i++)
//         input[msglen+i]='0';
//     for(i=0;i<keylen;i++)
//         temp[i]=input[i];
//     for(i=0;i<msglen;i++){
//         quot[i]=temp[0];
//         if(quot[i]=='0'){
//             for(j=0;j<keylen;j++)
//                 key[j]='0';
//         }
//         else{
//             for(j=0;j<keylen;j++)
//                 key[j]=key1[j];
//         }
//         for(j=keylen-1;j>0;j--){
//             if(temp[j]==key[j])
//                 rem[j-1]='0';
//             else
//                 rem[j-1]='1';
//         }
//         rem[keylen-1]=input[i+keylen];
//         strcpy(temp,rem);
//     }
//     strcpy(rem,temp);
//     printf("\n Quotient is ");
//     for(i=0;i<msglen;i++)
//         printf("%c",quot[i]);
//     printf("\n Remainder is ");
//     for(i=0;i<keylen-1;i++)
//         printf("%c",rem[i]);
//     printf("\n Final data is: ");
//     for(i=0;i<msglen;i++)
//         printf("%c",input[i]);
//     for(i=0;i<keylen-1;i++)
//         printf("%c",rem[i]);
//     printf("\n");
//     char temp1[100];
   
//     printf("Enter recieved data: ");
//     scanf("%s",temp1);
   
//     for(i=0;i<keylen;i++)
//         temp[i]=temp1[i];
//     for(i=0;i<msglen;i++){
//         quot[i]=temp[0];
//         if(quot[i]=='0'){
//             for(j=0;j<keylen;j++)
//                 key[j]='0';
//         }
//         else{
//             for(j=0;j<keylen;j++)
//                 key[j]=key1[j];
//         }
//         for(j=keylen-1;j>0;j--){
//             if(temp[j]==key[j])
//                 rem[j-1]='0';
//             else
//                 rem[j-1]='1';
//         }
//         rem[keylen-1]=temp1[i+keylen];
//         strcpy(temp,rem);
//     }
//     strcpy(rem,temp);
//     printf("\n Quotient is ");
//     for(i=0;i<msglen;i++)
//         printf("%c",quot[i]);
//     printf("\n Remainder is ");
//     for(i=0;i<keylen-1;i++)
//         printf("%c",rem[i]);
       
//     flag=0;
//     for(i=0;i<keylen-1;i++){
//         if(rem[i]=='1'){
//             flag=1;
//             break;
//         }
//         else
//             flag=0;
//     }
//     if(flag==0)
//         printf("\n No error");
//     else
//         printf("\nError is detected");
   
//     return 0;
// }
// Nithin CH
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int crc(char *ip,char *op,char *poly,int mode){
    strcpy(op,ip);
    if(mode){
        for(int i=1;i<strlen(poly);i++){
            strcat(op,"0");
        }
    }
    //Perform XOR on the msg with the selected polynomial
    for(int i=0;i<strlen(ip);i++){
        if(op[i]=='1'){
            for(int j=0;j<strlen(poly);j++){
                if(op[i+j]==poly[j]){
                    op[i+j]='0';
                }
                else{
                    op[i+j]='1';
                }
            }
        }
    }
    //check for errors return 0 if error is detected
    for(int i=0;i<strlen(op);i++){
        if(op[i]=='1'){
            return 0;
        }
    }
    return 1;
}
void main(){
    char ip[50],op[50],recv[50];
    char poly[]="10001000000100001";
    printf("Enter the input message in binary\n");
    scanf("%s",ip);
    crc(ip,op,poly,1);
    // printf("%s\n",op);
    
    // printf("%d\n",strlen(ip));
    // printf("%s",op+strlen(ip));
    printf("The transmitted message is : %s%s\n",ip,op+strlen(ip));
    printf("Enter the received message in binary\n");
    scanf("%s",recv);
    if(crc(recv,op,poly,0)){
        printf("No error");
    }
    else{
        printf("error there");
    }
    
}