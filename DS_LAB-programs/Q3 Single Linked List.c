#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Sem3
{
    int rollno;
    char name[20]; 
    struct Sem3 *next;
}Sem3;
Sem3 *head;
Sem3 *searchptr;

int scount; //to count the number of student-nodes in the Sem3 list.
int srollno; //variable to enter the rollno to be assigned to the new student-node
char sname[20];//variable to enter the name to be assigned to the new student-node

void LLDemoOptions()
{
    printf("\n**** Singly Linked List Program. Having ONLY 'Insert' & 'Search' *** \n");
    printf("0.menu\n");
    printf("1.Search RollNo in Singly Linked List for Sem3\n");
    printf("2.Insert Begining of Singly Linked List for Sem3\n");
    printf("3.Insert End of Singly Linked List for Sem3\n");
    printf("4.Insert At Any Position of Singly Linked List for Sem3\n");
    printf("5.Delete any Student given the rollno\n");
    printf("6.Display Students in Singly Linked List for Sem3\n");
    printf("-1.Quit Singly Linked List Program\n");
    
}//end LLDemoOptions

/*The  point to remember in the 'search' function is to return the pointer to the node which contains the 'rollno' searched. */
Sem3 * searchStudent(Sem3 * head, int srollno)
{
    Sem3 * pointer = head;
    if(head == NULL) return NULL;
    else
    {
        while(pointer != NULL)
        {
            if(pointer->rollno == srollno)
                return pointer;
            
            else
                pointer = pointer->next;
        }
        return NULL;
    }
}//end of searchStudent

void printSem3Details(Sem3 * head)
{
    if(head == NULL)
    {
        printf("\nStudent Linked List is empty");
    }
    else
    {
        Sem3 * pointer = head;
        printf("\n Number of students in Sem3 is %d", scount);
        printf("\n Sem3 Student List head address %d ", head);
        while(pointer != NULL)
        {
            printf("\nRollNo: %d -> ",pointer->rollno);
            printf("  Name: %s-> ",pointer->name);
            pointer = pointer->next;//Helps Understand funda of current node
            printf("Next student node pointer address->%d ", pointer);/*Helps Understand funda of next node */
        }//end while
    }//end else
}//end printSem3Details

/*This is a generic function to create a new node. All four 'insert' functions 
call this very same function. No code-change required to handle these four insert operations.  */
Sem3 * createNewStudent(Sem3 * next)
{
    Sem3 * newStudent = (Sem3 *)malloc(sizeof(Sem3));
    strcpy(newStudent->name,sname);
    newStudent->rollno = srollno;
    newStudent->next = next;
    scount++;
    return newStudent;
}//end createNewStudent

/* In this function 'head' pointer is always reassigned to beginning of the 
linked list whereever 'insertBegin' function is called. Therefore, printing always 
happens from beginning. */
Sem3 * insertBegin(Sem3 * head)
{
    
    if(head == NULL)
        printf("\n Congratulations - Very first student to enroll!");
    
    Sem3 * newStudent = createNewStudent(head);
    head = newStudent; /*Very important. Dont forget this to do this!Otherwise you 
    will never be able to print the new student node created.*/
    return head;
    
}//end insertBegin

/* The logic of this function expects you to traverse till the end of the linked list 
where the last node's next points to NULL. The new node needs to be inserted here. */
Sem3 * insertEnd(Sem3 * head)
{
    if(head != NULL)
    {
        Sem3 * pointer = head;
        while(pointer->next != NULL)
            pointer = pointer->next;
        /*Note the passing of 'NULL' as value of 'next' in 'createNewStudent' function. This is because the new node created will be the new last node in the singly linked list train. */
        Sem3 * newStudent = createNewStudent(NULL);
        
        pointer->next = newStudent;/*Very important. Dont forget this to do this!Otherwise you will never be able to print the new student node created. The linked list chain will be broken*/
        return head;
        
    }
}//end of insertEnd

Sem3 * insertAny(Sem3 * head)
{
    int position; // 0 means before 1 means after
    int rollposition;
    if(head == NULL)
    {
        head = insertBegin(head); //Using the exisitng insertBegin function
        return head; /*very important to write this statement.In some 'C' runtimes 'head'
                       is getting overwritten with some junk*/
    }//end of if list is empty
    
    else if(head != NULL)
    {
        Sem3 * posptr = NULL;
        
        printf("\nDo you want to insert after or before a roll number : Enter 0 for before, 1 for after? ");
        scanf("%d",&position);
        
        if(position == 0)
        {
            printf("\nEnter the Student RollNo you want to insert before ");
            scanf("%d",&rollposition);
        }
        else if(position == 1)
        {
            printf("\nEnter the Student RollNo you want to insert after ");
            scanf("%d",&rollposition);
        }
        else printf("\n Wrong value for position - enter 0 for before, 1 for after");
        
        posptr = searchStudent(head, rollposition);
        
        printf("posptr pointer address->%d and rollposition is %d", posptr, rollposition);
        if(posptr != NULL)
        {
            if (position == 1 && posptr->next ==NULL)
            {
                printf("\n In Insert Any : Insert After End Node ");
                posptr=insertEnd(head); //Using the exisitng insertEnd function
            }
            else if(position == 1 && posptr->next !=NULL)
            {
                printf("\n In Insert Any : Insert After a middle Node ");
                Sem3 * newStudent = createNewStudent(posptr->next);
                posptr->next = newStudent;
            }
            else if(position == 0 && posptr == head)
            {
                printf("\n In Insert Any : Insert Before Head Node ");
                Sem3 * newStudent = createNewStudent(head);
                head = newStudent;
            }
            else if(position == 0 && posptr != head)
            {
                printf("\n In Insert Any : Insert Before Middle Node ");
                Sem3 * beforeStudent = head;
                if(beforeStudent->next == posptr)
                {
                    Sem3 * newStudent = createNewStudent(posptr);
                    beforeStudent->next = newStudent;
                    printf("\nbeforeStudent address->%d and newStudent->%d", beforeStudent, newStudent);
                }
                else
                {
                    while(beforeStudent->next != posptr)
                    {
                        beforeStudent = beforeStudent->next;
                        printf("\nbeforeStudent address->%d and posptr->%d", beforeStudent, posptr);
                    }
                    Sem3 * newStudent = createNewStudent(posptr);
                    beforeStudent->next = newStudent;
                    printf("\nbeforeStudent address->%d and newStudent->%d", beforeStudent, newStudent);
                }//end of innermost else for Insert Any : Insert Before Middle Node
                
            }//end of inner else for Insert Any : Insert Before Middle Node
            
        }//end of if node to be inserted before or after exists
        else
            if (position == 0)
                printf("\n Sorry! The roll# you want to insert before does not exist in the list");
            else
                printf("\n Sorry! The roll# you want to insert after does not exist in the list");
        
        
        return head;
    }// end of outermost else when list is not empty
}//end of insertAny

Sem3 * deleteAny(Sem3 * head, int srollno)
{
    Sem3 * delptr = searchStudent(head, srollno);
    
    if(delptr == NULL)
    {
        printf("\n The roll number you want to delete does not exist in the list");
        return head; //try commeting this. Run code with a roll no that does not exist. List will be shown as empty!!
        /*very important to write this statement.In some 'C' runtimes 'head' is getting overwritten with some junk*/
    }
    else
    {
        if(delptr == head)
        {
            printf("\n You are deleting the head node");
            head = delptr->next;
            free(delptr); scount--;
        }
        else if(delptr->next == NULL)
        {
            printf("\n You are deleting the last node");
            Sem3 * beforeptr = head;
            
            while(beforeptr->next != delptr)
                beforeptr = beforeptr->next;
            
            beforeptr->next = NULL;
            free(delptr); scount--;
        }
        else
        {
            printf("\n You are deleting a middle node");
            Sem3 * beforeptr = head;
            
            while(beforeptr->next != delptr)
                beforeptr = beforeptr->next;
            
            beforeptr->next = delptr->next;
            free(delptr); scount--;
        }
        
        return head;
    }//end of else
    
}//end of deleteAny function

int main()
{
    head = NULL;
    searchptr = NULL;
    
    int choice = 0;
    LLDemoOptions();
    
    while(1)
    {
        printf("\nEnter your choice(0-10,-1 to quit):");
        scanf("%d",&choice);
        
        if(choice == -1)
            break;
        //Caution: DONOT forget to write 'break' for every case!
        switch(choice)
        {
            case 0:
                LLDemoOptions();
                break;
                
            case 1:
                printf("Please enter a number to search:");
                scanf("%d",&srollno);
                searchptr = searchStudent(head, srollno);
                if(searchptr != NULL)
                {
                    printf("Student with RollNo %d found. Name is %s",searchptr->rollno, searchptr->name);
                }
                else
                {
                    printf("Student with RollNo %d not found.",srollno);
                }
                break;
                
            case 2:
                printf("\nEnter the Student RollNo ");scanf("%d",&srollno);
                printf("\nEnter the Student Name "); scanf("%s", sname);
                head = insertBegin(head);
                //printSem3Details(head);
                break;
                
            case 3:
                printf("\nEnter the Student RollNo ");scanf("%d",&srollno);
                printf("\nEnter the Student Name "); scanf("%s", sname);
                head = insertEnd(head);
                //printSem3Details(head);
                break;
            
            case 4:
                printf("\nEnter the Student RollNo ");scanf("%d",&srollno);
                printf("\nEnter the Student Name "); scanf("%s", sname);
                head = insertAny(head);
                //printSem3Details(head);
                break;
                
            case 5:
                printf("\nEnter the Student RollNo you want to remove ");scanf("%d",&srollno);
                head = deleteAny(head,srollno);
                //printSem3Details(head);
                break;
                
            case 6: printSem3Details(head);break;
                
                
        }//end switch
        
    }//end while
    
}//end main

/**************************************************************/

//Single linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct SLL{
    int data;
    struct SLL *next;
}SLL;
SLL *head=NULL;
int scount;
int sdata;
void insert(){
    printf("enter the data u want to insert\n");
    scanf("%d",&sdata);
    struct SLL * newSLL=(struct SLL *)malloc(sizeof( struct SLL));
    newSLL->data=sdata;
    if(head==NULL){
        printf("inserting the first node\n");
        newSLL->next=NULL;
        head=newSLL;
        scount++;
        return;
    }
    int pos,rollpos;
    printf("enter the position 0 to enter before and 1 to enter after an element");
    scanf("%d",&pos);
    printf("Enter the dataof the element  present in list\n");
    scanf("%d",&rollpos);
    struct SLL*currptr=head;
    while(currptr->data!=rollpos){
        currptr=currptr->next;
    }
    if(currptr==NULL){
        printf("the element u entered is not found\n");
        return;
    }
    if(pos==0&&currptr==head){
        printf("u r inserting after head");
        newSLL->next=head;
        head=newSLL;
        scount++;
        return;
    }
    if(pos==0&&currptr!=head){
        printf("u r inserting before middle node");
        struct SLL * node=head;
        while(node->next!=currptr){
            node=node->next;
        }
        newSLL->next=currptr;
        node->next=newSLL;
        scount++;
        return;
    }
    if(pos==1&&currptr->next!=NULL){
        printf("u r inserting after a  middle node");
        newSLL->next=currptr->next;
        currptr->next=newSLL;
        scount++;
        return;
    }
    if(pos==1&&currptr->next==NULL){
        printf("u r inserting last node");
        newSLL->next=NULL;
        currptr->next=newSLL;
        scount++;
        return;
    }
}
void delete(){
    printf("Enter the data to delete\n");
    scanf("%d",&sdata);
    struct SLL*currptr=head;
    while(currptr->data!=sdata){
        currptr=currptr->next;
    }
    if(currptr!=NULL){
        if(currptr==head){
            printf("ur deleting the first node\n");
            head=head->next;
            free(currptr);
            scount--;
            return;
        }
        else if(currptr->next==NULL){
            printf("ur deletig the last node\n");
            struct SLL*node=head;
            while(node->next!=currptr){
                node=node->next;
            }
            node->next=NULL;
            free(currptr);
            scount--;
            return;
        }
        else{
            printf("ur deletig the middle node\n");
            struct SLL*node=head;
            while(node->next!=currptr){
                node=node->next;
            }
            node->next=currptr->next;
            free(currptr);
            scount--;
            return;
        }
    }
}
void display(){
    if(head==NULL){
        printf("ll is empty\n");
        return;
    }
    struct SLL*currptr=head;
    while(currptr!=NULL){
        printf("%d\n",currptr->data);
        currptr=currptr->next;
    }
}
void main(){
    int choice;
    while(1){
        printf("Enter ur choice \n 1.insert \n 2.delete \n 3.display \n 4.exit \n");
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




