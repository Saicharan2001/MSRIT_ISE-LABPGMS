#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>
int partition(int a[],int low,int high){
	int i,j,key,k,temp;
	key=a[low];
	i=low+1;
	j=high;
	while(i<=j){
		while(i<=high && a[i]<=key){
			++i;
		}
		while(key<a[j] && j>-1){
			--j;
		}
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else{
			temp=a[j];
			a[j]=a[low];
			a[low]=temp;
		}
	}
	return j;
}
void quicksort(int a[],int low,int high){
	if(low>=high) return;
	int pos;
	pos=partition(a,low,high);
	quicksort(a,low,pos-1);
	quicksort(a,pos+1,high);
}
void main(){
	int n,a[30000];
	clock_t start,end;
	double totaltime;
	printf("Enter total number of elements\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		a[i]=rand();
	}
	start=clock();
	quicksort(a,0,n-1);
	end=clock();
	totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Sorted numbers\n");
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	printf("totaltime taken is %f\n",totaltime);
}