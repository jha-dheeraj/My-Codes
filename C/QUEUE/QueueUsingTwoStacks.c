#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Stack
{
    int size;
    int top;
    int *s;
};
bool isFull(struct Stack *st1)
{
    if(st1->top==st1->size-1)
        return true;
    else
        return false;
}

bool isEmpty(struct Stack *st1, struct Stack *st2)
{
    if(st1->top==-1 && st2->top==-1)
        return true;
    else
        return false;
}

void Display(struct Stack *st)
{
    int i=0;
    printf("\n");
    while(i<=st->top)
        printf("%d, ",st->s[i++]);
}
void Enqueue(struct Stack *st1)
{
    if(isFull(st1))
        printf("\nQueue is Full.");
    else
    {
        printf("\nEnter data to be inserted.");
        scanf("%d",&st1->s[++st1->top]);
        Display(st1);
    }

}

void Dequeue(struct Stack *st1, struct Stack *st2)
{
    if(isEmpty(st1, st2))
        printf("\nQueue is Empty.");
    else
    {
        int data;
        if(st2->top==-1)
        {
            while(st1->top!=-1)
            {
                st2->s[++st2->top]=st1->s[st1->top--];
            }
        }
        data=st2->s[st2->top--];
        printf("\nDequeued element = %d", data);
    }
}

int main()
{
    struct Stack st1, st2;
    st1.top=-1;
    st2.top=-1;
    printf("\nEnter size of Queue: ");
    scanf("%d",&st1.size);
    st2.size=st1.size;
    st1.s=(int *)malloc(sizeof(int));
    st2.s=(int *)malloc(sizeof(int));

    int choice=1;
    while(choice>0)
    {
        printf("\nEnter -1 to exit.");
        printf("\nEnter 1 to push data into Queue.");
        printf("\nEnter 2 to pop data from Queue.");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n***User Asked for Termination***");
                break;
            case 1:
                Enqueue(&st1);
                break;
            case 2:
                Dequeue(&st1, &st2);
                break;
            default:
                printf("\nInvalid Choice.\n");
                break;
        }
    }
    printf("\nDone with use of Queue, releasing memory.\n");
    free(st1.s);
    free(st2.s);

}