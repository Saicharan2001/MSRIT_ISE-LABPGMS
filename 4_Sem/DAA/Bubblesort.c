//BUBBLE SORT
/*Complexity Analysis of Bubble Sort
Hence the time complexity of Bubble Sort is O(n2). The main advantage of Bubble Sort is the simplicity of the algorithm.
The space complexity for Bubble Sort is O(1), because only a single additional memory space is required i.e. for temp variable.
and O(n) in the best case*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
    int a[30000],n,swap;
    printf("enter the no of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    clock_t start=clock();
    for(int c=0;c<(n-1);c++){
        for(int d=0;d<(n-c-1);d++){
            if(a[d]>a[d+1]){
                swap=a[d];
                a[d]=a[d+1];
                a[d+1]=swap;
            }
        }
    }
    clock_t end=clock();
    double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("the sorted elements are\n");
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    printf("the totaltime taken is %f",totaltime);
}