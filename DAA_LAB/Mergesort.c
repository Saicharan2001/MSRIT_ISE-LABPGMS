/*Time complexity of Merge Sort is O(n*Log n) in all the 3 cases (worst, average and best) as merge sort always divides the array 
in two halves and takes linear time to merge two halves.*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void merge(int a[],int low,int mid,int high){
    int i,j,k,b[30000];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(j<=high){
        b[k++]=a[j++];
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    for(k=low;k<=high;k++){
        a[k]=b[k];
    }
}
void mergesort(int a[],int low,int high){
    if(low>=high) return;
    int mid=floor((low+high)/2);
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
void main(){
	int a[30000],n,k,r;
	clock_t start,end;
	double totaltime;
	printf("Enter total no:of numbers\n");
	scanf("%d",&n);
	for(k=0;k<n;k++){
		a[k]=rand();
	}
	start=clock();
	mergesort(a,0,n-1);
	end=clock();
	totaltime = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Sorted numbers\n");
	for(k=0;k<n;k++){
		printf("%d\n",a[k]);
	}
	printf("time taken is %f",totaltime);
}