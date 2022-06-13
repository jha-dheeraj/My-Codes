#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Array
{
    int *arr;
    int length;
    int size;
};

struct Node *Head = NULL;
void CreateNode()
{
    int n;
    struct Node *p;
    printf("\nEnter number of Element to insert:");
    scanf("%d",&n);
    while(n--)
    {
        struct Node *new;
        p=Head;
        new = (struct Node *)malloc(sizeof(struct Node));
        new->next=NULL;
        printf("\nEnter Data to store: ");
        scanf("%d", &new->data);
        if(p==NULL)
        {
            printf("\nHead is pointing to null.\nSo, Adding first Node...");
            Head=new;
        }
        else
        {
            while(p->next != NULL)
            {
                p=p->next;
            }
            p->next=new;
        }
    }
}

void DisplayNodes(struct Node *Headd)
{
    struct Node *p;
    p=Headd;
    if(p==NULL)
        printf("\nList is Empty.");
    else
    {
        printf("\nData is as follow: ");
        while(p!=NULL)
        {
            printf("%d, ", p->data);
            p=p->next;
        }
    }
}

void RecurssiveDisplay(struct Node *node)
{
    if(node==NULL)
        return;
    else
    {
        printf("%d,",node->data);
        RecurssiveDisplay(node->next);
    }
}
int NodeCount()
{
    int count=0;
    struct Node *p=Head;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    printf("\nNo. of Nodes=%d",count);
    return count;

}

void NodeSumValue()
{
    struct Node *p=Head;
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    printf("Sum of nodes data=%d",sum);
}

void MaxAndMininList()
{
    int min=INT_MAX;
    int max=INT_MIN;
    struct Node *p=Head;
    while(p!=NULL)
    {
        if(p->data<min)
            min=p->data;
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    printf("\nMaximum value=%d\nMinimum value=%d",max,min);
}

void SearchingInList()
{
    int key;
    struct Node *p=Head;
    printf("\nEnter the value of key to be searched: ");
    scanf("%d",&key);
    while(p!=NULL)
    {
        if(p->data==key)
        {
            printf("\nKey found...");
            return;
        }
        p=p->next;
    }
    printf("\nKey not Found...");
}

/* In improved searching, we are using Move to Head mechanism,
i.e, moving all the key nodes towards Head
Note: Transposition is not suggested here */
void ImprovedSearching()
{
    int key;
    struct Node *p,*q;
    p=Head;
    q=NULL;
    printf("\nEnter the value of key to be searched: ");
    scanf("%d",&key);
    while(p!=NULL)
    {
        if(p->data==key)
        {
            printf("\nKey found...");
            q->next=p->next;
            p->next=Head;
            Head=p;
            return;
        }
        q=p;
        p=p->next;
    }
    printf("\nKey not Found...");
}

void InsertAtAnyPosition()
{
    int pos,i;
    struct Node *p,*q;
    struct Node *new;
    printf("\nEnter position at which key is to be inserted: ");
    scanf("%d",&pos);
    new=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter data for this new NODE:");
    scanf("%d",&new->data);
    p=Head;
    q=NULL;
    
    if(pos==1)
    {
        new->next=Head;
        Head=new;
    }else
    {
        while(i!=pos && p!=NULL)
        {
            q=p;
            p=p->next;
            i++;
        }
        new->next=p;
        q->next=new;
    }
}

void InsertInSortedList()
{
    struct Node *new,*p,*q;
    new=(struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Data to be inserted in the node: ");
    scanf("%d",&new->data);
    p=Head;
    q=NULL;
    while(p->data<=new->data && p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    if(p->next==NULL)
    {
        new->next=NULL;
        p->next=new;

    }else if(p!=NULL && q==NULL) /*Insert at begining */
    {
        new->next=p;
        Head=new;
    }
    else
    {
        new->next=p;
        q->next=new;
    }
}

void DeleteAtAnyPosition()
{
    struct Node *p,*q;
    int pos;
    int i=1;
    p=Head;
    q=NULL;
    printf("\nEnter the position of node to Delete: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        Head=p->next;
        free(p);
    }else
    {
        while(i!=pos && p!=NULL)
        {
            q=p;
            p=p->next;
            i++;
        }
        q->next=p->next;
        free(p);
    }

}

void CheckSortedList()
{
    struct Node *p;
    p=Head;
    while(p->next!=NULL)
    {
        if(p->data > p->next->data)
        {
            printf("\nList is not sorted...");
            return;
        }
        p=p->next;
    }
    printf("\nList is Sorted...");

}
void RemoveDuplicateFromSortedList()
{
    struct Node *p,*q;
    p=Head;
    q=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        if(p!=NULL && q!=NULL)
        {
            if(p->data==q->data)
            {
                q->next=p->next;
                free(p);
                p=q->next;
            }
        }
    }


}

void AppendNode()
{
    struct Node *new,*p;
    new=(struct Node*)malloc(sizeof(struct Node));
    p=Head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    printf("\nEnter data for this node: ");
    scanf("%d",&new->data);
    new->next=NULL;
    p->next=new;
}

void ConcatTwoList()
{
    int n;
    struct Node *new,*p;
    new=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter Number of node required in 2nd list: ");
    scanf("%d",&n);
    printf("Enter data for Node 1:");
    scanf("%d",&new->data);
    p=Head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=new;
    p=p->next;
    n--;
    while(n--)
    {
        new=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for next Node:");
        scanf("%d",&new->data);
        p->next=new;
        p=p->next;
    }
}

void RemoveDuplicateNode()
{
    struct Node *p,*q,*r;
    p=q=Head;
    r=NULL;
    while(p!=NULL)
    {
        q=Head;
        r=NULL;
        while(q!=NULL)
        {
            if(p->data==q->data && p!=q)
            {
                r->next=q->next;
                free(q);
                q=r->next;
            }else
            {
                r=q;
                q=q->next;
            }
            
            
        }
        p=p->next;
    }
}

/* Recurssive call will deal later */
void ReverseList()
{
    int choice;
    printf("\nReverse can be done in 2 possible ways:\n");
    printf("\nPress 1 to reverse list by reversing it's data.");
    printf("\nPress 2 to reverse the list by reverssing the links.\n");
    scanf("%d", &choice);
    if(choice==1)
    {
        struct Array array1;
        struct Node *p;
        int i=0;
        p=Head;
        array1.size=NodeCount()+10;
        array1.length=NodeCount();
        array1.arr=(int *)malloc(array1.size*sizeof(int));
        while(p)
        {
            array1.arr[i++]=p->data;
            p=p->next;
        }
        p=Head;
        i=array1.length-1;
        while(p)
        {
            p->data=array1.arr[i--];
            p=p->next;
        }
        free(array1.arr);
    } else if(choice==2)
    {
        struct Node *p,*q,*r;
        p=Head;
        q=r=NULL;
        while(p)
        {
            /*Order is very important*/
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        Head=q;
    } else
    {
        printf("Invalid Choice.");
    }
}

void CheckLoopinList()
{
    struct Node *p, *q;
    p=q=Head;
    q=q->next->next;
    while(p!=NULL && q->next!=NULL)
    {
        if(p==q)
            break;
        p=p->next;
        q=q->next->next;
    }
    if(p==q && p!=NULL)
        printf("\nThere is loop in list.");
    else
        printf("\nThere is no loop in list");
}

void mergeList()
{
    int num;
    struct Node *Head1,*p;
    struct Node *node;
    printf("\nEnter number of nodes you want to add in newly created list: ");
    scanf("%d", &num);
    node = (struct Node *)malloc(sizeof(struct Node));
    Head1=p=node;
    printf("\nEnter data for node: ");
    scanf("%d", &node->data);
    node->next=NULL;
    while(--num)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data for node: ");
        scanf("%d", &node->data);
        node->next=NULL;
        p->next=node;
        p=p->next;
    }
    DisplayNodes(Head);
    DisplayNodes(Head1);

    /* TODO : Code for Merge */

}

int main()
{
    struct Node ll;
    int choice=1;
    while(choice>0)
    {
        printf("\nEnter 1 to create a linked list.");
        printf("\nEnter 2 to display the list.");
        printf("\nEnter 3 to Recurssive display of the list.");
        printf("\nEnter 4 to count the nodes of the list.");
        printf("\nEnter 5 to find sum of all the nodes of the list.");
        printf("\nEnter 6 to find the maximum and minimum elements of the list.");
        printf("\nEnter 7 to search a key in the list.");
        printf("\nEnter 8 for improved search in the list.");
        printf("\nEnter 9 insert at any position in the list.");
        printf("\nEnter 10 insert in a sorted list.");
        printf("\nEnter 11 Delete at any position in the list.");
        printf("\nEnter 12 to check if list is sorted or not.");
        printf("\nEnter 13 to remove duplicate from sorted linked list.");
        printf("\nEnter 14 to remove duplicate from the list.");
        printf("\nEnter 15 to concat 2 linked list.");
        printf("\nEnter 16 to merge 2 linked list.");
        printf("\nEnter 17 to check loop in linked list.");
        printf("\nEnter 18 to append a node in linked list.");
        printf("\nEnter 19 to reverse the linked list.");
        printf("\nEnter -1 to Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n**User Asked for Termination.**\n");
                break;
            case 1:
                CreateNode();
                break;
            case 2:
                DisplayNodes(Head);
                break;
            case 3:
                RecurssiveDisplay(Head);
                break;
            case 4:
                NodeCount();
                break;
            case 5:
                NodeSumValue();
                break;
            case 6:
                MaxAndMininList();
                break;
            case 7:
                SearchingInList();
                break;
            case 8:
                ImprovedSearching();
                break;
            case 9:
                InsertAtAnyPosition();
                break;
            case 10:
                InsertInSortedList();
                break;
            case 11:
                DeleteAtAnyPosition();
                break;
            case 12:
                CheckSortedList();
                break;
            case 13:
                RemoveDuplicateFromSortedList();
                break;
            case 14:
                RemoveDuplicateNode();
                break;
            case 15:
                ConcatTwoList();
                break;
            case 16:
                mergeList();
                break;
            case 17:
                CheckLoopinList();
                break;
            case 18:
                AppendNode();
                break;
            case 19:
                ReverseList();
                break;
            default:
                printf("\nInvalid Input.\n");
                break;
        }
    }
    if(Head)
    {
        printf("\nDone with Nodes, Freeing Heap allocated Memory.");
        struct Node *p, *q;
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