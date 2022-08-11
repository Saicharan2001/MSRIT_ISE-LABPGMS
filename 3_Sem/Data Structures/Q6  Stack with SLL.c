#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head=NULL;

void inb(int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
    }else{
        temp->link=head;
        head=temp;
    }
}
void delb(){
    struct node *temp;
    if(head==NULL){
        printf("list is empty,nothing to delete.");
    }else{
    temp=head;
    head=temp->link;
    temp->link=NULL;
    free(temp);
    }
}
void display()
{
     struct node* temp=head;
     while(temp->link!=NULL)
     {
         printf("%d", temp->data);
         temp=temp->link;
     }
      printf("%d", temp->data);
}

void main(){
    int ch,data;
    while(ch!=4){
    printf("\n1.push\n2.pop\n3.display\n4.exit\n");
    printf("enter ur choice: ");
    scanf("%d", &ch);
    switch(ch){
        case 1: printf("enter the element to be pushed: ");
                scanf("%d", &data);
                inb(data);
                break;
        case 2: delb();
                break;
        case 3: display();
                break;
    }
    }
}

/**************************************************************/

#include <stdio.h>
#include<stdlib.h>
int element;
typedef struct Stack{
    int data;
    struct Stack*next;
}Stack;
Stack *head=NULL;
int count=0;
void push(){
    struct Stack *newStack=(struct Stack*)malloc(sizeof(struct Stack));
    printf("enter the data");
    scanf("%d",&element);
    newStack->data=element;
    if(head==NULL){
        printf("the very first element created\n");
        head=newStack;
        newStack->next=NULL;
        count++;
        return;
    }
    Stack*currptr=head;
    while(currptr->next!=NULL){
        currptr=currptr->next;
    }
    currptr->next=newStack;
    newStack->next=NULL;
    printf("the element %d is inserted successfully\n",element);
    count++;
}
void pop(){
    if(head==NULL){
        printf("stack is empty\n");
        return;
    }
    Stack*currptr=head;
    Stack*beforeptr=head;
    while(currptr->next!=NULL){
        currptr=currptr->next;
    }
    while(beforeptr->next!=currptr){
        beforeptr=beforeptr->next;
    }
    printf("the poppped element is %d",currptr->data);
    beforeptr->next=NULL;
    free(currptr);
    count--;
}
void display(){
    if(head==NULL){
        printf("stack is empty");
        return;
    }
    printf("the total no of nodes:%d\n",count);
    Stack*currptr=head;
    while(currptr->next!=NULL){
        printf("%d\n",currptr->data);
        currptr=currptr->next;
    }
    printf("%d\n",currptr->data);
}
void main(){
    int choice;
    while(1){
        printf("enter the choice");
        printf("1.push ,2. pop , 3. display ,4.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
            default:printf("enetr valid");
        }
    }
}
