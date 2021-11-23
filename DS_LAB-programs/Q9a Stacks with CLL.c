// stacks using CLL
#include <stdio.h>
#include<stdlib.h>
int count,element=0;
typedef struct Stack{
    int data;
    struct Stack *next;
}Stack;
Stack*head=NULL;
void push(){
   struct Stack * newStack=(struct Stack *)malloc(sizeof(struct Stack));
   printf("enter the data in the node to be created");
   scanf("%d",&element);
   newStack->data=element;
   if(head==NULL){
       printf("the first node is created\n");
       head=newStack;
       newStack->next=head;
       count++;
       return;
   }
   struct Stack * currptr=head;
   do{
      currptr=currptr->next; 
   }
   while(currptr->next!=head);
   currptr->next=newStack;
   newStack->next=head;
   printf("the node with data %d is added successfully\n",element);
   count++;
   return;
}
void pop(){
	if(head==NULL){
		printf("the stack is empty\n");
		return;
	}
    if(head->next==head){
        printf("ur deleting the one and one only node\n");
        printf("the poppped element is %d\n",head->data);
        free(head);
        head=NULL;
        count--;
        return;
    }
    struct Stack * currptr=head;
    struct Stack * prev=head;
    do{
      currptr=currptr->next; 
    }while(currptr->next!=head);
    while(prev->next!=currptr){
        prev=prev->next;
    }
    printf("the poppped element is %d\n",currptr->data);
    prev->next=currptr->next;
    free(currptr);
    count--;
}
void display(){
    if(head==NULL){
        printf("the list is empty\n");
        return;
    }
    printf("the  no of elemensts in list is %d\n",count);
    struct Stack * currptr=head;
    do{
        printf("the data is:%d\n",currptr->data);
        currptr=currptr->next; 
    }
    while(currptr->next!=head);
    printf("the data is:%d\n",currptr->data);
    return;
}

void main(){
    int choice;
    while(1){
        printf("enter ur choice\n");
        printf("1.push \n 2. pop \n 3. display \n 4.exit \n");
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
