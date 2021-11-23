#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ThreeB
{
    int rollno;
    char name[20];
    struct ThreeB *next;
    struct ThreeB *prev;
}ThreeB;
ThreeB *head, *tail;
ThreeB *searchptr;

int scount; //to count the number of student-nodes in the ThreeB list.
int srollno; //variable to enter the rollno to be assigned to the new student-node
char sname[20];//variable to enter the name to be assigned to the new student-node

void LLDemoOptions()
{
    printf("\n**** Circular Linked List Program. Having ONLY 'Insert' & 'Search' *** \n");
    printf("0.menu\n");
    printf("1.Search RollNo in Circular Linked List for ThreeB\n");
    printf("2.Insert At Any Position of Circular Linked List for ThreeB\n");
    printf("3.Display Students in Circular Linked List for ThreeB\n");
    printf("4.Delete any Student given the rollno\n");
    printf("-1.Quit Circular Linked List Program\n");
    
}//end LLDemoOptions

/*The  point to remember in the 'search' function is to return the pointer to the node which contains the 'rollno' searched. */
ThreeB * searchStudent(ThreeB * head, int srollno)
{
    ThreeB * pointer = head;
    if(head == NULL) {printf("\n Empty List"); return NULL;}
    else
    {
        do
        {
            if(pointer->rollno == srollno)
                return pointer;
            
            else
                pointer = pointer->next;
        }while(pointer != head);
        //until you dont reach first node again.
        return NULL;
    }
}//end of searchStudent

void printThreeBDetails(ThreeB * head)
{
    if(head == NULL)
    {
        printf("\nStudent Linked List is empty");
    }
    else
    {
        ThreeB * pointer = head;
        printf("\n Number of students in ThreeB is %d", scount);
        printf("\n ThreeB Student List head address %d ", head);
        do
        {
            printf("\nRollNo: %d -> ",pointer->rollno);
            printf("  Name: %s-> ",pointer->name);
            
            /*Helps Understand funda of next node */
            pointer = pointer->next;//Helps Understand funda of current node
            printf("\nNext student node pointer address->%d ", pointer);
        //until you dont reach first node again.
        }while(pointer != head); //end while
    }//end else
}//end printThreeBDetails


/*This is a generic function to create a new node. All five 'insert' conditions call this very same function. No code-change required to handle these five insert operations.  */
ThreeB * createNewStudent(ThreeB * next, ThreeB * prev)
{
    ThreeB * newStudent = (ThreeB *)malloc(sizeof(ThreeB));
    strcpy(newStudent->name,sname);
    newStudent->rollno = srollno;
    newStudent->next = next;
    newStudent->prev = prev;
    scount++;
    return newStudent;
}//end createNewStudent

ThreeB * insertAny(ThreeB * head)
{
    int position=0; // 0 means before 1 means after
    int rollposition=0;
    if(head == NULL)
    {
        printf("\n Congratulations - Very first student to enroll!");
        
        ThreeB * newStudent = createNewStudent(head,tail);
        head = newStudent; /*Very important. Dont forget this to do this!Otherwise you will never be able to print the new student node created.*/
        tail = head;
        tail->next = head;
        head->prev = tail;
        return head;
    }//end of if list is empty
    
    else if(head != NULL)
    {
        ThreeB * posptr = NULL;
        
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
        
        printf("\n posptr pointer address->%d and rollposition is %d", posptr, rollposition);
        if(posptr != NULL)
        {
            if (position == 1 && posptr->next == head)
            {
                printf("\n In Insert Any : Insert After End Node ");
                ThreeB * newStudent = createNewStudent(head,posptr);
                posptr->next = newStudent;
                tail = newStudent;
                head->prev = newStudent;
            }
            else if(position == 1 && posptr->next !=head)
            {
                printf("\n In Insert Any : Insert After a middle Node ");
                ThreeB * newStudent = createNewStudent(posptr->next,posptr);
                newStudent->next->prev = newStudent;
                posptr->next = newStudent;
                
            }
            else if(position == 0 && posptr == head)
            {
                printf("\n In Insert Any : Insert Before Head Node ");
                ThreeB * newStudent = createNewStudent(head,tail);
                head->prev = newStudent;
                tail->next = newStudent;
                head = newStudent;
            }
            else if(position == 0 && posptr != head)
            {
                printf("\n In Insert Any : Insert Before Middle Node ");
                
                ThreeB * newStudent = createNewStudent(posptr, posptr->prev);
                posptr->prev->next = newStudent;
                posptr->prev = newStudent;
                printf("\nposptr->prev->next address->%d and newStudent->%d", posptr->prev->next, posptr->prev);
                
            }//end of inner else for Insert Any : Insert Before Middle Node
            
        }//end of if node to be inserted before or after exists
        else
            if (position == 0)
                printf("\n Sorry! The roll# you want to insert before does not exist in the list");
            else
                printf("\n Sorry! The roll# you want to insert after does not exist in the list");
        
        
        return head;
    }// end of outermost else if when list is not empty
}//end of insertAny

ThreeB * deleteAny(ThreeB * head, int srollno)
{
    
    ThreeB * delptr = searchStudent(head, srollno);
    
    printf("\n delptr address %d->", delptr);
    if(delptr == NULL)
    {
        printf("\n The roll number you want to delete does not exist in the list");
        return head;
    }
    else
    {
        if(delptr == head)
        {
            printf("\n You are deleting the head node");
            if(delptr->next == head && delptr->prev == tail )
            {
               printf("\n You are deleting the only node in list");
               head = NULL;
               tail = NULL;
               free(delptr); scount--;
            }
            else
            {
            head = delptr->next;
            tail->next = head;
            free(delptr); scount--;
            }
        }
        else if(delptr->next == head)
        {
            printf("\n You are deleting the last node");
            delptr->prev->next = head;
            tail = delptr->prev;
            head->prev = tail;
            free(delptr); scount--;
        }
        else
        {
            printf("\n You are deleting a middle node");
            delptr->prev->next = delptr->next;
            delptr->next->prev = delptr->prev;
            free(delptr); scount--;
        }
        
        return head;
    }//end of else
    
}//end of deleteAny function

int main()
{
    head = NULL;
    tail = NULL;
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
                printf("\nPlease enter a number to search:");
                scanf("%d",&srollno);
                searchptr = searchStudent(head, srollno);
                if(searchptr != NULL)
                {
                    printf("\nStudent with RollNo %d found. Name is %s",searchptr->rollno, searchptr->name);
                }
                else
                {
                    printf("\nStudent with RollNo %d not found.",srollno);
                }
                break;
                
            case 2:
                printf("\nEnter the Student RollNo ");scanf("%d",&srollno);
                printf("\nEnter the Student Name "); scanf("%s", sname);
                head = insertAny(head);
                break;
                
            case 3:
                printThreeBDetails(head);
                break;
                
            case 4:
                printf("\nEnter the Student RollNo to delete ");scanf("%d",&srollno);
                head = deleteAny(head,srollno);
                break;
                
        }//end switch
        
    }//end while
    
}//end main

/**************************************************************/

//single circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct SLL{
    int data;
    struct SLL *next;
}SLL;
SLL *head,*tail=NULL;
int scount;
int sdata;
void insert(){
    printf("enter the data u want to insert\n");
    scanf("%d",&sdata);
    struct SLL * newSLL=(struct SLL *)malloc(sizeof( struct SLL));
    newSLL->data=sdata;
    if(head==NULL){
        printf("inserting the first node\n");
        head=newSLL;
        newSLL->next=head;
        tail=head;
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
        if(currptr==head){
		currptr=NULL;
            break;
        }
    }
    if(currptr==NULL){
        printf("the element u entered is not found\n");
        return;
    }
    if(pos==0&&currptr==head){
        printf("u r inserting after head");
        newSLL->next=head;
        head=newSLL;
        tail->next=head;
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
    if(pos==1&&currptr->next!=head){
        printf("u r inserting after a  middle node");
        newSLL->next=currptr->next;
        currptr->next=newSLL;
        scount++;
        return;
    }
    if(pos==1&&currptr->next==head){
        printf("u r inserting last node");
        newSLL->next=head;
        currptr->next=newSLL;
        tail=newSLL;
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
        if(currptr==head){
		currptr=NULL;
            break;
        }
    }
    if(currptr!=NULL){
        if(currptr==head){
            printf("ur deleting the first node\n");
            head=currptr->next;
            tail->next=head;
            free(currptr);
            scount--;
            return;
        }
        else if(currptr->next==head){
            printf("ur deletig the last node\n");
            struct SLL*node=head;
            while(node->next!=currptr){
                node=node->next;
            }
            tail=node;
            node->next=head;
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
    do{
        printf("%d\n",currptr->data);
        currptr=currptr->next;
        if(tail==currptr){
            break;
        }
    }while(1);
    printf("%d\n",currptr->data);
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






