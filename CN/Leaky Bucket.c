// #include<iostream.h>
// #include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#define bucketSize 512
void bktInput(int a,int b) {
 if(a>bucketSize)
printf("Bucket overflow\n");
 else {
 while(a>b){
// cout<<"\n\t\t"<<b<<" bytes outputted.";
    printf("Bytes outputted are %d",b);
    a-=b;
 }
//  if (a>0) cout<<"\n\t\tLast "<<a<<" bytes sent\t";
if(a>0){
    printf("Bytes sent are %d",a);
}
    printf("Bucket output successful\n");
 }
}
void main() {
    int op, pktSize;
    //  randomize();
    //  cout<<"Enter output rate : "; cin>>op;
    printf("Enter the output rate\n");
    scanf("%d",&op);
    for(int i=1;i<=5;i++){
         scanf("%d",&pktSize);
        //  cout<<"\nPacket no "<<i<<"\tPacket size = "<<pktSize;
        printf("Packet number is %d and Packet size is %d",i,pktSize);
         bktInput(pktSize,op);
    }
}



// #include<stdio.h>
// #include<stdlib.h>
// #define bktsize 512
// void butsize(int a,int b){
//     if(bktsize<a){
//         printf("overflow\n");
//         return;
//     }
//     else{
//         while(a>b){
//             printf("%d bytes are outputted\n",b);
//             a=a-b;
//         }
//     }
//     if(a>0){
//         printf("%d bytes are outputted\n",a);
//     }
//     printf("Transaction successful\n");
// }
// void main(){
//     int pktsize,oprate;
//     printf("Enter oprate\n");
//     scanf("%d",&oprate);
//     for(int i=0;i<3;i++){
//         printf("Enter pktsize\n");
//         scanf("%d",&pktsize);
//         butsize(pktsize,oprate);
//     }
//     // }https://www.onlinegdb.com/#tab-stdin
// }