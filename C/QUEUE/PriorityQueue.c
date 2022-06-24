/*Here we will consider, lower number as heigher priority*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *q;
};

bool isFull(struct Queue *Q)
{
    if(Q->rear==Q->size-1)
        return true;
    else
        return false;
}

bool isEmpty(struct Queue *Q)
{
    if(Q->rear==Q->front)
        return true;
    else 
        return false;
}

void Display(struct Queue *Q)
{
    
}
void Enqueue(struct Queue *Q)
{
    if(isFull(Q))
        printf("\nQueue is full.");
    else
    {
        int data,pos,temp;
        printf("\nEnter data to be inserted: ");
        scanf("%d",&data);
        if(data>=Q->q[Q->front] && data<=Q->q[Q->rear])
        {
            /* insertinbetween */
            pos=Q->rear;
            Q->rear++;
            while(Q->q[pos]>=data)
            {
                Q->q[pos+1]=Q->q[pos];
                pos--;
            }
            Q->q[pos+1]=Q->q[pos];
            Q->q[pos]=data;
            
        } else
        {
            /*insert at end*/
            Q->q[++Q->rear]=data;
        }

    }
}

void Dequeue(struct Queue *Q)
{
    if(isEmpty(Q))
        printf("\nQueue is Empty.");
    else
    {
        int data;
        data=Q->q[++Q->front];
        printf("\nDequeued data = %d",data);
    }
}

int main()
{
    struct Queue Q;
    printf("\nEnter size of Queue you want to create: ");
    scanf("%d",&Q.size);
    Q.q=(int *)malloc(sizeof(int));
    Q.front=-1;
    Q.rear=-1;

    int choice=1;
    while(choice>0)
    {
        printf("\nEnter -1 to Exit.");
        printf("\nEnter 1 to Enqueue into priority Queue.");
        printf("\nEnter 2 to Dequeue from priority Queue.");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\nUser Asked for Termination.\n");
                break;
            case 1:
                Enqueue(&Q);
                break;
            case 2:
                Dequeue(&Q);
                break;
            default:
                printf("\nInvalid Choice.\n");
                break;
        }
    }
    printf("\nDone with Use of priority Queue, Releasing memory.\n");
    free(Q.q);

    return 0;

}