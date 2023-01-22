// 6.	Parallel Vector Addition

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void vector_addn_parallel(int n,int *c,int *a,int *b){
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        c[i]=a[i]+b[i];
    }
}
void main(int argc,char *argv[]){
    int *a,*b,*c;
    int n=20;
    a=malloc(n*sizeof(int));
    b=malloc(n*sizeof(int));
    c=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        b[i]=rand()%100;
        printf("%d ",b[i]);
    }
  printf("\n");
    double start = omp_get_wtime();
	vector_addn_parallel(n,c,a,b);
    double end = omp_get_wtime();
    for(int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
    printf("Parallel Time %f\n",end-start);
}