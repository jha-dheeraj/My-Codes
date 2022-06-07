#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Head;

int main()
{
    int choice=1;

    while(choice>0)
    {
        printf("\nEnter 1 to create a Circular Linked List:");
        printf("\nEnter 2 to Display Circular List:");
        printf("\nEnter -1 to Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n***User Asked for Termination***");
                break;
            default :
                printf("\n***Invalid Input***\n");
                break;
        }
    }

    return 0;
}