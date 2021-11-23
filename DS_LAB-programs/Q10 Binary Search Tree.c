//Here there are two programs for the given question and u can go with ur own choice.............

#include <stdio.h>
#include<stdlib.h> //for malloc
struct BSTree
{
    int marks;
    struct BSTree *right;
    struct BSTree *left;
};

//Prototype / Forward declarion of the functions
struct BSTree *createBSTree(struct BSTree *, int);
void Inorder(struct BSTree *);
void Preorder(struct BSTree *);
void Postorder(struct BSTree *);

int main()
{
    struct BSTree *root = NULL;
    int choice, value, n, i;
    do
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                root = NULL;
                printf("\n\nBST for How Many Nodes ? ");
                scanf("%d",&n);
                for(i = 1; i <= n; i++)
                {
                    printf("\nEnter data for node %d : ", i);
                    scanf("%d",&value);
                    root = createBSTree(root,value);
                }
                printf("\nBST with %d nodes is ready to Use!!\n", n);
                break;
            case 2:
                printf("\nBST Traversal in INORDER \n");
                Inorder(root);
                break;
            case 3:
                printf("\nBST Traversal in PREORDER \n");
                Preorder(root);
                break;
            case 4:
                printf("\nBST Traversal in POSTORDER \n");
                Postorder(root);
                break;
            case 5:
                printf("\n\n Terminating  \n\n");
                exit(0);
                break;
            default:
                printf("\n\nInvalid Option !!! Try Again !! \n\n");
                break;
        }
    } while(choice != 5);
    return 0;
}

struct BSTree *createBSTree(struct BSTree *root, int value)
{
    if(root == NULL)
    {
        root = (struct BSTree *)malloc(sizeof(struct BSTree));
        root->left = root->right = NULL;
        root->marks = value;
        return root;
    }
    else
    {
        //BST hence the new node created must be correctly put to the right or left
        if(value < root->marks )
            root->left = createBSTree(root->left,value);
        else if(value > root->marks )
            root->right = createBSTree(root->right,value);
        else
            //Ensures that duplicate values are not allowed to be entered in the BST
            printf(" Duplicate Element !! Not Allowed !!!");
        
        return(root);
    }
}


void Inorder(struct BSTree *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->marks);
        Inorder(root->right);
    }
}

void Preorder(struct BSTree *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->marks);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct BSTree *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->marks);
    }
}

/**************************************************************/

#include <stdio.h>
#include<stdlib.h>
typedef struct BStree{
    int marks;
    struct BStree *left;
    struct BStree *right;
}BStree;
struct BStree * createBStree(struct BStree *root,int value){
    if(root==NULL){
        root = (struct BStree *)malloc(sizeof(struct BStree));
        root->marks=value;
        root->left=root->right=NULL;
        return root;
    }
    if(value<root->marks){
        root->left=createBStree(root->left,value);
    }
    else if(value>root->marks){
        root->right=createBStree(root->right,value);
    }
    else{
        printf("dupilcate element not allowed\n");
    }
    return root;
}
void Inorder(struct BStree *root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d\t",root->marks);
        Inorder(root->right);
    }
}
void Preorder(struct BStree *root){
    if(root!=NULL){
        printf("%d\t",root->marks);
        Preorder(root->left);
        
        Preorder(root->right);
    }
}
void Postorder(struct BStree *root){
    if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d\t",root->marks);
    }
}
void displayBinTree(BStree * root,int i)
{
    int j;
    
    
    if(root !=NULL)
    {
        displayBinTree(root->right,i+1);
        for(j=1;j<=i;j++) printf("\t"); //DEMO : Only prints tab
        //Donot enclose the two printf in brackets as the actual print happens
        //outside the for loop when loop condition fails
        //Remove the comment in below print to see the values of i,j from stack
        //printf("%d(%d:%d)\n",root->marks,i,j);
        
        printf("%d \n",root->marks);
        displayBinTree(root->left,i+1);
    }
    
}
void main(){
    struct BStree *root=NULL;
    int choice,n,i,value;
    while(1){
        printf("enter the choice \n 1. createBStree \n 2. Inoreder \n 3.Preorder \n 4. Postorder \n 5.display\n 6.exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enetr the no of nodes\n");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("enter the marks for the node %d",(i+1));
                    scanf("%d",&value);
                    root=createBStree(root,value);
                }
                break;
            case 2:printf("inorder traversal is:");
                    Inorder(root);
                    break;
            case 3:printf("Preorder traversal is:");
                    Preorder(root);
                    break;
            case 4:printf("postorder traversal is:");
                    Postorder(root);
                    break;
		  case 5:displayBinTree(root,i);
				break;
            case 6:exit(0);
        }
    }
}
