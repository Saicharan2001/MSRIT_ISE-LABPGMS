#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define S 20

int a[S];
int t=-1;


void push(int ele)
{
a[++t]=ele;
}

int pop()
{
	return a[t--];
}


int main ()
{
	char pf[S], ch;
	int i=0, op1, op2;
	printf("Enter the postfix expression : ");
	scanf("%s", pf);

	while ((ch=pf[i++]) != '\0')
	{
		if (isdigit(ch))
		{
			push(ch-'0');
		}

		else
		{
			op1 = pop();
			op2 = pop();

			switch (ch)
			{

				case '+':
				push(op2+op1);
				break;

				case '-':
				push(op2-op1);
				break;

				case '*':
				push(op2*op1);
				break;

				case '/':
				if (op1!=0)
				{
				push(op2/op1);
				}
				else
				{
				printf("\nDivision by 0 not possible\n");
				return 0;
				}
				break;

				default:

				break;
			}
		}
									
	}

printf("\nThe postfix expression given is : %s\n",pf);
printf("\nThe Calculated Value is %d\n", a[t]);
}  


/**************************************************************/

#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define s 30
int a[s];
int top=-1;
void push(int t){
    a[++top]=t;
}
int pop(){
    return a[top--];
}
void main(){
    printf("enter the valid postfix expression");
    char pe[s];
    scanf("%s",pe);
    int ch,op1,op2,i=0;
    while((ch=pe[i++])!='\0'){
        if(isdigit(ch)){
            push(ch-'0');
        }
        else{
            op1=pop();
            op2=pop();
            switch(ch){
                 case'+':push(op2+op1);
                        break;
                case'-':push(op2-op1);
                        break;
                case'*':push(op2*op1);
                        break;
                case'/':push(op2/op1);
                        break;
                case'^':push(pow(op2,op1));
                        break;
            }
        }
    }
    printf("the postfix expression:%s",pe);
    printf("the result is:%d",a[top]);
}
