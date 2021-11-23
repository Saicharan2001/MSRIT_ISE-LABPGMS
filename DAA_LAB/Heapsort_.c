/*Heapsort time complexity is bigo(n logn)*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int temp;
void heapify(int a[30000],int size,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size && a[left]>a[largest])  largest=left;
    if(right<size && a[right]>a[largest]) largest=right;
    if(largest!=i){
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        heapify(a,size,largest);
    }
}
void heapsort(int a[30000],int size){
    for(int i=((size/2)-1);i>-1;i--){
        heapify(a,size,i);   //This is first time heapifying the array
    }
    for(int i=size-1;i>=0;i--){  // This is the repeated process
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0); 
    }
}
void main()  
{  
    int a[30000],size,i;
    double totaltime;
    clock_t start,end;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    printf("Enter array elements\n");
    for(i=0;i<size;i++){
        a[i]=rand();
    }
    printf("the given elements are\n");
    for(i=0;i<size;i++){
        printf("%d\n",a[i]);
    }
    start=clock();
    heapsort(a, size);  
    end=clock();
    printf("printing sorted elements\n");  
    for (i=0; i<size; ++i){
        printf("%d\n",a[i]);  
    }
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The totaltime taken is %f",totaltime);
} 