//SELECTION SORT
/*One thing which distinguishes selection sort from other sorting algorithms is that it makes the minimum possible number of swaps, n − 1 in the worst case.
Worst-case performance: О(n2) comparisons, ...
Best-case performance: О(n2) comparisons, O..*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
    clock_t start,end;
    double totaltime;
    int n,a[30000],swap,pos;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    start=clock();
    for(int i=0;i<(n-1);i++){
        pos=i;
        for(int j=i+1;j<n;j++){
            if(a[pos]>a[j]){
                pos=j;
            }
        }
        if(pos!=i){
            swap=a[pos];
            a[pos]=a[i];
            a[i]=swap;
        }
    }
    end=clock();
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Sorted elements\n");
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    printf("the totaltime is %f",totaltime);
}