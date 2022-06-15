#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


struct Node
{
    int data;
    struct Node *next;
};

struct Node *Top=NULL;

bool isEmpty()
{
    if(Top==NULL)
        return true;
    else
        return false;
}

void push()
{
    struct Node *new;
    new=(struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data to be pushed: ");
    scanf("%d",&new->data);
    new->next=Top;
    Top=new;
}

void pop()
{
    int data;
    struct Node *temp;
    if(isEmpty())
    {
        printf("\nStack is Empty.");
    }else
    {
        data=Top->data;
        temp=Top;
        Top=Top->next;
        free(temp);
        printf("\nPoped data is : %d",data);
    }
    
}

void stackTop()
{
    printf("\nElement at top of stack : %d\n", Top->data);
}

void peek()
{
    struct Node *p=Top;
    int pos,i;
    printf("Enter the position at which you want to peek: ");
    scanf("%d",&pos);
    i=1;
    while(i!=pos && p!=NULL)
    {
        p=p->next;
        i++;
    }
    printf("Element at given index = %d",p->data);
}

void Display()
{
    struct Node *p=Top;
    printf("\nElements in stack are: ");
    if(p!=NULL)
    {
        while(p)
        {
            printf("%d, ",p->data);
            p=p->next;
        }
    }
}
int main()
{
    int choice=1;
    bool ret;
    while(choice>0)
    {
        printf("\nEnter -1 to exit.");
        printf("\nEnter 1 to push a value into the stack.");
        printf("\nEnter 2 to pop a value from the stack.");
        printf("\nEnter 3 to get the top element of stack.");
        printf("\nEnter 4 to check if stack is Empty.");
        printf("\nEnter 5 to peek into some position in stack.");
        printf("\nEnter 6 to see all elements in stack.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n***User Asked for Termination***\n");
                break;
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                stackTop();
                break;
            case 4:
                ret=isEmpty();
                if(ret)
                    printf("\nStack is Empty.");
                else
                    printf("\nStack is not Empty.");
                break;
            case 5:
                peek();
                break;
            case 6:
                Display();
                break;
            default:
                printf("\nInvalid Choice.\n");
                break;

        }
    }
    printf("\nDone with Stack, releasing memory now...\n");
    struct Node *p,*q;
    p=Top;
    if(p!=NULL)
    {
        while(p)
        {
            q=p;
            p=p->next;
            free(q);
        }
    }
}