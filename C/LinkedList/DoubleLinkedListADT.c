#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *Head=NULL;

void CreateList()
{
    int num;
    printf("\nEnter the number of element you want to add into list: ");
    scanf("%d",&num);
    struct Node *new,*p;
    new=(struct Node*)malloc(sizeof(struct Node));
    new->prev=NULL;
    new->next=NULL;
    printf("\nEnter Data: ");
    scanf("%d",&new->data);
    Head=p=new;
    while(--num)
    {
        new=(struct Node*)malloc(sizeof(struct Node));
        new->prev=p;
        p->next=new;
        new->next=NULL;
        p=new;
        printf("\nEnter Data: ");
        scanf("%d",&new->data);
    }
}

void Display()
{
    struct Node *p;
    p=Head;
    while(p!=NULL)
    {
        printf("%d, ",p->data);
        p=p->next;
    }
}

void InsertAtAnyPosition()
{
    struct Node *new,*p,*q;
    int pos,i;
    printf("\nEnter position at which you want to insert: ");
    scanf("%d",&pos);

    new= (struct Node *)malloc(sizeof(struct Node));
    new->prev=NULL;
    new->next=NULL;
    printf("\nEnter data for the newly created Node.");
    scanf("%d",&new->data);
    p=Head;
    if(pos==1)
    {
        new->next=Head;
        Head=new;
    }else
    {
        i=1;
        while(i!=pos && p->next!=NULL)
        {
            p=p->next;
            i++;
        }
        if(p->next==NULL)
        {
            new->next=NULL;
            new->prev=p;
            p->next=new;
            p->prev=new;
        }else
        {
            new->next=p;
            new->prev=p->prev;
            p->prev->next=new;
            p->prev=new;
        }
    }

}

void DeleteFromAnyPosition()
{
    int pos,i;
    struct Node *p;
    p=Head;
    printf("\nEnter position of node to be deleted.");
    scanf("%d", &pos);

    if(pos==1)
    {
        Head=p->next;
        free(p);
    }else
    {
        i=1;
        while(i!=pos && p->next!=NULL)
        {
            p=p->next;
            i++;
        }
        if(p->next!=NULL)
        {
            p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
        }else
        {
            p->prev->next=NULL;
            free(p);
        }
    }

}

void ReverseList()
{
    /*Here just swap the prev and next pointer, we will get the desired result */
    struct Node *p,*temp, *q;
    p=Head;
    while(p)
    {
        printf("\naaaaaaaaa");
        temp=p->next;
        p->next=p->prev;
        q->prev=temp;
        p=temp;
        if(p)
        {
            if(p->next==NULL)
                Head=p;
        }
    }
}
int main()
{
    int choice=1;

    while(choice>0)
    {
        printf("\nEnter -1 to exit.");
        printf("\nEnter 1 to create List.");
        printf("\nEnter 2 to display the list");
        printf("\nEnter 3 to insert at any position.");
        printf("\nEnter 4 to delete from any position.");
        printf("\nEnter 5 to reverse the linked list.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n***User Asked for Termination.***\n");
                break;
            case 1:
                CreateList();
                break;
            case 2:
                Display();
                break;
            case 3:
                InsertAtAnyPosition();
                break;
            case 4:
                DeleteFromAnyPosition();
                break;
            case 5:
                ReverseList();
                break;
            default:
                printf("\nInvalid Choice.\n");
                break;
        }

    }
    if(Head)
    {
        struct Node *p,*q;
        p=Head;
        q=NULL;
        while(p!=NULL)
        {
            q=p;
            p=p->next;
            free(q);
        }
    }
    
}