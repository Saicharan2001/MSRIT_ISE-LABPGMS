// 7.	Write a program   calculate the sum of first 100 Numbers. (Using critical directive)

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc,char *argv[]){
    int n=100;
    int sum=0;
    #pragma omp parallel for
    for(int i=1;i<=n;i++){
        #pragma omp critical
        sum=sum+i;
    }
    printf("Sum is %d",sum);
}