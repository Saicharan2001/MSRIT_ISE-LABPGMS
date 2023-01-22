// 2.	Estimate the value of pi 

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<math.h>

#define num_steps 1000000 
void main(int argc,char*argv[]){
    float pi=0;
    double start = omp_get_wtime();
    for(int k=0;k<num_steps;k++){
        pi+= pow(-1,k)/(2*k+1);
    }
    pi=4*pi;
    double end=omp_get_wtime();
    printf("Pi is %f and time is %f",pi,(end-start));

    pi=0;
    start = omp_get_wtime();
    double threads[8];

    #pragma omp parallel for num_threads(8)
    for(int k=0;k<num_steps;k++){
        int t=omp_get_thread_num();
        threads[t]+= pow(-1,k)/((2*k)+1);
    }
  
    for(int i=0;i<8;i++){
        pi+=threads[i];
    }
    pi=4*pi;
    end=omp_get_wtime();
    printf("Pi is %f and time is %f",pi,(end-start));

}