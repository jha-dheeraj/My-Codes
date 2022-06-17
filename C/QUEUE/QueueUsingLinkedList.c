#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;

bool isEmpty()
{
    if(front==rear && front==NULL)
        return true;
    else
        return false;
}

void Enqueue()
{
    struct Node *new;
    
    if(rear==NULL)
    {
        new=(struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data to be inserted: ");
        scanf("%d",&new->data);
        new->next=NULL;
        rear=new;
        front=new;
    }else
    {
        new=(struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data to be inserted: ");
        scanf("%d",&new->data);
        rear->next=new;
        new->next=NULL;
        rear=new;
    }
}

void Dequeue()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty.");
    }else
    {
        struct Node *p;
        p=front;
        if(rear==p)
            rear=NULL;
        front=front->next;
        printf("\nPoped data is = %d",p->data);
        free(p);
    }
}

void QueueFront()
{
    printf("\nData at front of Queue = %d",front->data);
}

void Display()
{
    struct Node *p;
    p=front;
    printf("\nData in Queue are: ");
    while(p)
    {
        printf("%d, ",p->data);
        p=p->next;
    }
}
int main()
{
    int choice=1,ret;
    while(choice>0)
    {
        printf("\nEnter -1 to exit.");
        printf("\nEnter 1 to push a value into the Queue.");
        printf("\nEnter 2 to pop a value from the Queue.");
        printf("\nEnter 3 to get the element at front of Queue.");
        printf("\nEnter 4 to check if Queue is Empty.");
        printf("\nEnter 5 to see all elements in Queue.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n***User Asked for Termination***\n");
                break;
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                QueueFront();
                break;
            case 4:
                ret=isEmpty();
                if(ret)
                    printf("\nQueue is Empty.");
                else
                    printf("\nQueue is not Empty.");
                break;
            case 5:
                Display();
                break;
            default:
                printf("\nInvalid Choice.\n");
                break;

        }


    }

    printf("\nDone with Stack Use, releasing memory now.\n\n");
    if(!isEmpty())
    {
        struct Node *p;
        while(front)
        {
            p=front;
            front=front->next;
            free(p);
        }
    }
}