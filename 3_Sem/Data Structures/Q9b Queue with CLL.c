#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node*link;
    }*tail=NULL;
    
    
    void enqueue(int data)
    {
        struct node*nn=(struct node*)malloc (sizeof (struct node));
        nn->data = data;
        nn->link=NULL;
        if (tail==NULL)
        {
            tail=nn;
            tail->link=nn;
        }
         else 
        {
            nn->link=tail->link;
           tail->link=nn;
           tail=nn;
           
        }
    }
    void dequeue()
    {
     struct node*head=tail->link;
     if(tail==NULL)
     {
         printf("list is empty");
     }
     else 
     {
         tail->link=head->link;
         head->link=NULL;
         free(head);
     }
    }
    
        void display()
    {
        struct node *curr;
        curr=tail->link;
        while (curr->link!=tail->link)
        {
            printf("%d",curr->data);
            curr = curr->link;
        }
        printf("%d",curr->data);
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
			dequeue();
			break;

			case 3:
			display();
			break;
			
			default:
			exit(0);
		}
	}	
}

/**************************************************************/

#include <stdio.h>
#include<stdlib.h>
typedef struct queue{
    int data;
    struct queue*next;
}queue;
queue*head=NULL;
int count,element=0;
void push(){
   struct queue * newqueue=(struct queue *)malloc(sizeof(struct queue));
   printf("enter the data in the node to be created");
   scanf("%d",&element);
   newqueue->data=element;
   if(head==NULL){
       printf("the first node is created\n");
       head=newqueue;
       newqueue->next=head;
       count++;
       return;
   }
   struct queue * currptr=head;
   do{
      currptr=currptr->next; 
   }
   while(currptr->next!=head);
   currptr->next=newqueue;
   newqueue->next=head;
   printf("the node with data %d is added successfully\n",element);
   count++;
   return;
}
void pop(){
    if(head==NULL){
        printf("queue is empty\n");
        return;
    }
    if(head->next==head){
        printf("the deleted element is %d\n",head->data);
        free(head);
        head=NULL;
        count--;
        return;
    }
    printf("the deleted element is %d\n",head->data);
    struct queue *currptr=head;
	struct queue *lastptr=head;
	do{
		lastptr=lastptr->next;
	}while(lastptr->next!=head);
    free(head);
	head=currptr->next;
	lastptr->next=head;
    count--;
    return;
}
void display(){
    if(head==NULL){
        printf("the list is empty\n");
        return;
    }
    printf("the  no of elemensts in list is %d\n",count);
    struct queue * currptr=head;
   do{
        printf("the data is:%d\n",currptr->data);
        currptr=currptr->next; 
        if(currptr==head){
            break;
        }
    }
    while(1);
    return;
}
void main()
{
    int choice;
    while(1){
        printf("enter the choice\n 1. push \n 2.pop\n 3. display \n 4.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
        }
    }
}
