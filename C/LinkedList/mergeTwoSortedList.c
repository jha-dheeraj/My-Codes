/* Note: Use Concept of Dummy List to merge any number of list */

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode* createList(struct ListNode* Head1)
{
    int n;
    struct ListNode *new;
    struct ListNode *temp;
    printf("\nEnter number of nodes to be inserted:");
    scanf("%d",&n);
    if(Head1==NULL)
    {
        new=(struct ListNode*)malloc(sizeof(struct ListNode*));
        printf("\nEnter data for first Node:");
        scanf("%d", &new->data);
        new->next=NULL;
        Head1=new;
        n--;
    }
    temp=Head1;
    while(n--)
    {
        new=(struct ListNode*)malloc(sizeof(struct ListNode*));
        printf("\nEnter data for next Node:");
        scanf("%d", &new->data);
        new->next=NULL;
        temp->next=new;
        temp=temp->next;
    }

    return Head1;
}

struct ListNode* mergeList(struct ListNode* Head1, struct ListNode* Head2)
{
    if(Head1==NULL)
        return Head2;
    if(Head2==NULL)
        return Head1;
    
    struct ListNode *dummy=NULL;
    struct ListNode *Head3=NULL;
    if(Head1->data<Head2->data)
    {
        dummy=Head1;
        Head1=Head1->next;
        Head3=dummy;
    } else
    {
        dummy=Head2;
        Head2=Head2->next;
        Head3=dummy;
    }

    while(Head1!=NULL && Head2!=NULL)
    {
        if(Head1->data<Head2->data)
        {
            dummy->next=Head1;
            Head1=Head1->next;
            dummy=dummy->next;
        } else
        {
            dummy->next=Head2;
            Head2=Head2->next;
            dummy=dummy->next;
        }
    }

    if(Head1==NULL)
    {
        while(Head2!=NULL)
        {
            dummy->next=Head2;
            Head2=Head2->next;
            dummy=dummy->next;
        }
    } else
    {
        while(Head1!=NULL)
        {
            dummy->next=Head1;
            Head1=Head1->next;
            dummy=dummy->next;
        }
    }

    return Head3;
    
}
int main()
{
    struct ListNode *Head1 = NULL;
    struct ListNode *Head2 = NULL;
    struct ListNode *temp1 = NULL;
    Head1=createList(Head1);
    Head2=createList(Head2);
    Head1=mergeList(Head1,Head2);

    temp1=Head1;
    printf("\nHere is merged list:\n");
    while(temp1!=NULL)
    {
        printf("\nData= %d",temp1->data);
        temp1=temp1->next;
    }
    return 0;
}