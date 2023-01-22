// Divides the Iterations into chunks 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<omp.h>

void main(int argc,char *argv[]){
    int iterns,itern[8];
    scanf("%d",&iterns);
    #pragma omp parallel for schedule(static,2)
    for(int i=1;i<=iterns;i++){
        int t=omp_get_thread_num();
        itern[t]+=1;
        printf("Thread %d and value is %d\n",t,i);
    }
}