#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

bool isEmpty(struct Queue *q)
{
    if(q->front==q->rear)
        return true;
    else
        return false;

}

bool isFull(struct Queue *q)
{
    if((q->rear+1)%q->size==q->front)
        return true;
    else
        return false;
}
void Enqueue(struct Queue *q)
{
    if(isFull(q))
    {
        printf("\nQueue is full.");
    }else
    {
        int data;
        printf("\nEnter the data to be insterted : ");
        scanf("%d",&data);
        q->Q[(q->rear+1)%q->size]=data;
        q->rear++;
    }
}

void Dequeue(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("\nQueue is Empty.");
    }else
    {
        int data;
        data=q->Q[(q->front+1)%q->size];
        q->front++;
        printf("\nDequeued data = %d",data);
    }
}

void QueueFront(struct Queue *q)
{
    if(!isEmpty(q))
        printf("\nElement at front = %d",q->Q[q->front+1]);
    else
        printf("\nQueue is Empty.");
}

void Display(struct Queue *q)
{
    int i;
    i=q->front+1;
    printf("\nData are : ");
    while(i<=q->rear)
    {
        printf("%d,",q->Q[i++]);
    }
}
int main()
{
    struct Queue q;
    int choice=1,ret;
    printf("\nEnter the size of Queue you want to create: ");
    scanf("%d",&q.size);
    q.Q=(int *)malloc(q.size*sizeof(int));
    q.front=0;
    q.rear=0;

    while(choice>0)
    {
        printf("\nEnter -1 to exit.");
        printf("\nEnter 1 to push a value into the Queue.");
        printf("\nEnter 2 to pop a value from the Queue.");
        printf("\nEnter 3 to get the element at front of Queue.");
        printf("\nEnter 4 to check if Queue is Empty.");
        printf("\nEnter 5 to check if queue is full.");
        printf("\nEnter 6 to see all elements in Queue.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n***User Asked for Termination***\n");
                break;
            case 1:
                Enqueue(&q);
                break;
            case 2:
                Dequeue(&q);
                break;
            case 3:
                QueueFront(&q);
                break;
            case 4:
                ret=isEmpty(&q);
                if(ret)
                    printf("\nQueue is Empty.");
                else
                    printf("\nQueue is not Empty.");
                break;
            case 5:
                ret=isFull(&q);
                if(ret)
                    printf("\nQueue is full.");
                else
                    printf("\nQueue is not full.");
                break;
            case 6:
                Display(&q);
                break;
            default:
                printf("\nInvalid Choice.\n");
                break;

        }


    }

    printf("\nDone with Stack Use, releasing memory now.\n\n");
    free(q.Q);
}