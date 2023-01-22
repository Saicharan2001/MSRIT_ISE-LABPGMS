// Fibonacci numbers using Parallel Directive. Demonstrate elimination of the race condition using Schedule directive.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<omp.h>

int fib(int n){
    int a=0;
    int b=1;
    int t;
    #pragma omp parallel for schedule(static,2)
    for(int i=0;i<n;i++){
        #pragma omp critical
        {
            t=a+b;
            a=b;
            b=t;
        }
    }
    return a;
}
void main(int argc,char *argv[]){
    int n=15;
    double start=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        printf("thread %d and value %d\n",omp_get_thread_num(),fib(i));
    }
    double end = omp_get_wtime();
    printf("using schedule time is : %f\n",end-start);
}