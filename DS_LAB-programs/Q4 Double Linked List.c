#include<stdio.h>
#include<stdlib.h>
typedef struct DLL{
    struct DLL *prev;
    int data;
    struct DLL *next;
}DLL;
struct DLL*head=NULL;
int sdata,scount;
void insert(){
    printf("Enter the data of the node u want to insert\n");
    scanf("%d",&sdata);
    struct DLL * newDLL=(struct DLL*)malloc(sizeof(struct DLL));
    newDLL->data=sdata;
    if(head==NULL){
        printf("ur inserting the first node\n");
        newDLL->next=NULL;
        newDLL->prev=NULL;
        head=newDLL;
        scount++;
        return;
    }
    int pos,rollpos;
    printf("Enter 0 to enter before and 1 to enter after an element\n");
    scanf("%d",&pos);
    printf("enter the element present in the list\n");
    scanf("%d",&rollpos);
    struct DLL*currptr=head;
    while(currptr->data!=rollpos){
        currptr=currptr->next;
        if(currptr==NULL){
            break;
        }
    }
    if(currptr==NULL){
        printf("the element u entered is not present\n");
        return;
    }
    else{
        if(pos==0 && currptr==head){
            printf("Ur inserting before the head node\n");
            newDLL->next=head;
            newDLL->prev=NULL;
            currptr->prev=newDLL;
            head=newDLL;
            scount++;
            return;
        }
        if(pos==0 && currptr!=head){
            printf("ur inserting before a middle node\n");
            newDLL->next=currptr;
            newDLL->prev=currptr->prev;
            currptr->prev->next=newDLL;
            currptr->prev=newDLL;
            scount++;
            return;
        }
        if(pos==1 && currptr->next!=NULL){
            printf("ur inserting after a middle node\n");
            newDLL->next=currptr->next;
            newDLL->prev=currptr;
            currptr->next->prev=newDLL;
            currptr->next=newDLL;
            scount++;
            return;
        }
        if(pos==1&&currptr->next==NULL){
            printf("ur inserting after the last node\n");
            newDLL->next=NULL;
            newDLL->prev=currptr;
            currptr->next=newDLL;
            scount++;
            return;
        }
    }
}
void delete(){
    printf("Enter the element u want to delete\n");
    scanf("%d",&sdata);
    if(head==NULL){
        printf("empty list\n");
        return;
    }
    struct DLL*currptr=head;
    while(currptr->data!=sdata){
        currptr=currptr->next;
        if(currptr==NULL){
            break;
        }
    }
    if(currptr==NULL){
        printf("no such element in list\n");
        return;
    }
    else{
        if(currptr==head){
            printf("ur deleting the head  node\n");
            head=currptr->next;
            currptr->next->prev=NULL;
            free(currptr);
            scount--;
            return;
        }
        if(currptr->next==NULL){
            printf("ur deleting the last node\n");
            currptr->prev->next=NULL;
            free(currptr);
            scount--;
            return;
        }
        if(currptr->next!=NULL){
            printf("deleting the middle node\n");
            currptr->next->prev=currptr->prev;
            currptr->prev->next=currptr->next;
            free(currptr);
            scount--;
            return;
        }
    }
}
void display(){
    if(head==NULL){
        printf("empty list\n");
        return;
    }
    struct DLL *currptr=head;
    while(currptr!=NULL){
        printf("%d\n",currptr->data);
        currptr=currptr->next;
    }
}
void main(){
    int choice;
    while(1){
        printf("enter choice \n 1.insert \n 2.delete \n 3.display \n 4.exit \t");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert();
                    break;
            case 2:delete();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
        }
    }
}
