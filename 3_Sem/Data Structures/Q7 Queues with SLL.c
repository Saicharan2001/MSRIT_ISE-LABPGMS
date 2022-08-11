#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head=NULL;

void ine(int data)
{
    struct node* nn=(struct node*)malloc (sizeof(struct node));
    nn->data=data; 
    nn->link=NULL;
    
    struct node* curr;
    curr=head;
    if (head==NULL)
    {
        head=nn;
    }
    else
    {
        while(curr->link!=NULL)
        {
            curr=curr->link;
        }
        curr->link=nn;
    }
}

void delb(){
    struct node *nn;
    if(head==NULL){
        printf("list iis empty,nothing to delete\n");
    }else{
        nn=head;
        head=nn->link;
        nn->link=NULL;
        free(nn);
    }
}
void display()
{
     struct node* curr=head;
     while(curr->link!=NULL)
     {
         printf("%d", curr->data);
         curr=curr->link;
     }
      printf("%d", curr->data);
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
                ine(data);
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
typedef struct queue{
    int data;
    struct queue*link;
}queue;
queue*head=NULL;
int element,count=0;
void push(){
    struct queue * newqueue=(struct queue*)malloc(sizeof(struct queue)); 
    printf("enter the data");
    scanf("%d",&element);
    newqueue->data=element;
    if(head==NULL){
        printf("The first node is created\n");
        head=newqueue;
        newqueue->link=NULL;
        count++;
        return;
    }
    queue*currptr=head;
    while(currptr->link!=NULL){
        currptr=currptr->link;
    }
    currptr->link=newqueue;
    newqueue->link=NULL;
    count++;
}
void pop(){
    if(head==NULL){
        printf("queue is empty\n");
        return;
    }
    queue*newhead=head;
    printf("the popped element is :%d\n",head->data);
    free(head);
    head=newhead->link;
    count--;
}
void display(){
    if(head==NULL){
        printf("queue is empty\n");
        return;
    }
    queue*currptr=head;
    while(currptr->link!=NULL){
        printf("%d\n",currptr->data);
        currptr=currptr->link;
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
