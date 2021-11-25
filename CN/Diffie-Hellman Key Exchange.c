#include<stdio.h>
int compute(int g ,int a,int p){
    int r;
    int y=1;
    while(a>0){
        r=a%2;
        if(r==1){
            y=(y*g)%p;
        }
        g=(g*g)%p;
        a=a/2;
    }
    return(y);
}

void main(){
    int p=23;
    int g=5;
    int A,B,a,b;
    a=6;
    b=15;
    A=compute(g,a,p);
    B=compute(g,b,p);
    printf("%d\n",A);
    printf("%d\n",B);
    int keyA=compute(B,a,p);
    int keyB=compute(A,b,p);
    printf("%d,%d",keyA,keyB);
}