#include <stdio.h>
#include<stdlib.h> //for malloc


typedef struct OrderedSLL
{
    int data;
    struct OrderedSLL *next;
}OrderedSLL;

OrderedSLL *head;

//Creating the Ordered SLL - Descending Order
void createOrderedSLL()
{
    OrderedSLL *ptr, *newnode, *prev;
    ptr = newnode = prev = NULL;
    int datavalue;
    
    
    printf("Enter Data for Ordered Single Linked List\n");
    scanf("%d", &datavalue);
    
    
    newnode = (OrderedSLL *)malloc(sizeof(OrderedSLL));
    
    newnode->data = datavalue;
    
    newnode->next = NULL; //As it is the 'head' node its link must be NULL
    if(head == NULL) //'head' == NULL initially
        head = newnode ; /* If 'head' is NULL, then there is no list, so newnode is the head Node inserted */
    else //If the list has some nodes
    {
        //'head' node always has the term with the HIGHEST value of price of bakery item
        if(newnode->data > head->data)//newnode's price value is larger than head node's price
        {
            newnode->next = head;
            head = newnode; //Newnode becomes head
        }
        else
        {
            ptr = head;
            //Keep traversing until the newnode's price value is less than current node's price
            // This is to insert the newnode in the current descending order of price
            //It is allowed to have duplicate terms for the price value. This is the reason it is
            //checked as 'newnode->price  < ptr->price' and NOT 'newnode->price  <= ptr->price'
            while( (ptr!= NULL) && (newnode->data  < ptr->data) )
            {
                prev = ptr;
                ptr = ptr->next;
            }
            if(ptr == NULL)    //When current last node is reached
            {
                prev->next = newnode;///current lastnode's next value is assigned to newnode address
                newnode->next = ptr; //newnode becomes last node
            }
            else //For newnode has intermediate price values
            {
                prev->next = newnode;//newnode price value is greater than OR equal to current node
                newnode->next = ptr;
            }
        }
    }
    
}//end of createOrderedSLL function

//Display Function
void displayOrderedSLL()
{
    OrderedSLL *ptr;
    if(head == NULL)
    {
        printf("\nEmpty Bakery \n");
        return;
    }
    ptr = head; int count = 0;
    while(ptr!= NULL) //Traversing the single linked list till last node
    {
        printf("\nNode#%d. Data is: %d-->", ++count,ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main()
{
    int choice;
    for(;;)
    {
        printf("\n\n***MENU OPTIONS***\n1.Create Ordered SLL\n2.Display In descending order\n3.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                createOrderedSLL();
                printf("\nUse Option 2 to display the Ordered SLL After Creation");
                break;
            case 2:
                printf("\n Ordered SLL Items in descending order of price are ");
                displayOrderedSLL();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid option\n\n");
                break;
        }
    }
}

/**************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}*head=NULL;

struct Node* SortedInsert(int d)
{ 
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = d; 
   if(head == NULL) {
       newNode->next = NULL;
       newNode->prev = NULL;
       return newNode;
   }
   if(head->data >= newNode->data) {
       newNode->next = head; 
       newNode->prev = NULL;
       head->prev = newNode; 
       head = newNode;
   } else {
       struct Node *current = head;
       while(current->next != NULL && current->next->data < newNode->data) {
           current = current->next;
       }
       newNode->prev = current;
       newNode->next = current->next;
       if(current->next != NULL) {
           current->next->prev = newNode;
       }
       current->next = newNode; 
   } 
   return head;
}

void display()
{
	if(head == NULL)
	{
		printf("\nLinked List is empty\n");
	}
	else
	{
		struct Node *ptr = head;
		while(ptr != NULL)
		{
			printf("\t%d ->",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

int main()
{
	head = NULL;
	int ch,data;
	while(ch!=3)
	{
		printf("\n1.Insert\n2.display\n3.exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
		printf("\nEnter the Element: ");
		scanf("%d",&data);
		head = SortedInsert(data);
		break;

		case 2:
		display();
		break;

		case 3: 
		break;
		}
	}
}


