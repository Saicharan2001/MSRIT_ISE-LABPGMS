#include<stdio.h>
#define S 30

int binSearch(int a[],int beg,int end,int ele)
{
	int mid;
	if (end>=beg)
	{
		mid = (beg+end)/2;
		if (a[mid] == ele)
		{
			return mid+1;
		}
		else if (a[mid]<ele)
		{
			return binSearch (a, mid+1, end, ele);
		}
		else
		{
			return binSearch (a, beg, mid-1, ele);
		}	
	}
	else
	{
		return -1;
	}
}
void main ()
{
	int a[S];
	int ele, i, n, pos=0;


	printf("\nEnter the Size of the Array : ");
	scanf("%d", &n);
	
	printf("\nEnter the Elements of the Array :\n");
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Sorting the given array\n");
	int temp=0;
	for(int i=n-1;i>0;i--){
	    for(int j=0;j<i;j++){
	        if(a[j]>a[j+1]){
	         temp=a[j];
	         a[j]=a[j+1];
	         a[j+1]=temp;
	        }
	    }
	}
	 for(int k=0;k<n;k++){
	     printf("%d \t",a[k]);
	 }
	

	printf("\nEnter the element to be searched for : ");
	scanf("%d", &ele);

	pos = binSearch (a, 0, n-1, ele);
	

	if (pos ==-1)
	{
		printf("\nElement Not Found\n");
	}
	else
	{
		printf("\nElement Found at %d\n",pos);
	}
}
