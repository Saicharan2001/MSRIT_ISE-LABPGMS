#include<stdio.h>
#include<stdlib.h>
#define S 5

int r=-1;
int f=0;
int a[S];

int isempty()
{
	return (f>r||r==-1)?1:0;
}


int isfull()
{
	return (r==S-1)?1:0;
}


void enqueue(int ele)
{
    int j;
	 if(isfull()){
        printf("queue overflow\n");
		return;
    }
    j=r;
    while(j>=0 && ele<a[j]){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=ele;
	r=r+1;
}


int dequeue()
{
	if(isempty()){
		printf("Oueue empty\n");
		return;
	}
	int ele = a[f++];
	return ele;
}


void display()
{
	int i=0;
	if (isempty())
	{
		printf("\nQueue Underflow\n");
	}
	else
	{
		printf("\nThe elements are : ");
		for (i=f; i<=r; i++)
		{
			printf("%d ", a[i]);
		}
	}
}


int main ()
{
	int x,ch;
	while(1)
	{
		printf("\n1. Enqueue");
		printf("\n2. Dequeue");
		printf("\n3. Display");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be inserted : ");
				scanf("%d",&x);
				enqueue(x);
			
			break;

			case 2:
			if (isempty())
			{
				printf("\nStack Unerflow\n");
				f=0;
				r=-1;
			}
			else
			{
				printf("\nThe element being deleted is : %d\n",dequeue());
			}
			break;

			case 3:
			display();
			break;
			
			default:
			exit(0);
		}
	}	
}