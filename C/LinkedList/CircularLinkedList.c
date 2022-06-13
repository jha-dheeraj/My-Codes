#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Head;

void CreateCircularList()
{
    int num;
    printf("\nEnter no of elements to be added into circular linked List: ");
    scanf("%d",&num);
    struct Node *p,*q;
    struct Node *node;
    node = (struct Node *)malloc(sizeof(int));
    printf("\nEnter data: ");
    scanf("%d",&node->data);
    p=Head=node;
    while(--num)
    {
        node = (struct Node *)malloc(sizeof(int));
        printf("\nEnter data: ");
        scanf("%d",&node->data);
        p->next=node;
        p=p->next;
    }
    p->next=Head;
}

void Display()
{
    struct Node *p;
    p=Head;
    printf("\nData are as follow: ");
    do
    {
        printf("%d, ", p->data);
        p=p->next;
    } while(p!=Head);
}

void InsertAtAnyPosition()
{
    int pos,i;
    printf("\nEnter the position at which you want to insert the node: ");
    scanf("%d", &pos);
    struct Node *p, *node,*q;
    p=Head;
    q=NULL;
    node=(struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter value to be inserted: ");
    scanf("%d",&node->data);
    if(pos==1)
    {
        node->next=Head;
        while(p->next!=Head)
            p=p->next;
        p->next=node;
        Head=node;
    }else
    {
        i=1;
        while(i!=pos)
        {
            q=p;
            p=p->next;
            i++;
        }
        node->next=p;
        q->next=node;
    }

}

void DeleteAtAnyPosition()
{
    int pos,i;
    printf("\nEnter the position at which you want to Delete the node: ");
    scanf("%d", &pos);
    struct Node *p,*q;
    p=Head;
    q=p->next;
    if(pos==1)
    {
        while(q->next!=Head)
            q=q->next;
        q->next=p->next;
        Head=p->next;
        free(p);
    } else
    {
        i=1;
        while(i!=pos)
        {
            q=p;
            p=p->next;
            i++;
        }
        q->next=p->next;
        free(p);
    }
}
int main()
{
    int choice=1;

    while(choice>0)
    {
        printf("\nEnter 1 to create a Circular Linked List:");
        printf("\nEnter 2 to Display Circular List:");
        printf("\nEnter 3 to insert at any position.");
        printf("\nEnter 4 to Delete at any position.");
        printf("\nEnter -1 to Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n***User Asked for Termination***\n");
                break;
            case 1:
                CreateCircularList();
                break;
            case 2:
                Display();
                break;
            case 3:
                InsertAtAnyPosition();
                break;
            case 4:
                DeleteAtAnyPosition();
                break;
            default :
                printf("\n***Invalid Input***\n");
                break;
        }
    }
    if(Head)
    {
        printf("\nDone with Nodes, Freeing Heap allocated Memory.\n");
        struct Node *p, *q;
        p=Head->next;
        q=NULL;
        while(p!=Head)
        {
            q=p;
            p=p->next;
            free(q);
        }
        free(p);
    }

    return 0;
}