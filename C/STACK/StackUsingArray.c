#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Stack
{
    int size;
    int top;
    int *s;
};

bool isEmpty(struct Stack *st)
{
    if(st->top==-1)
        return true;
    else
        return false;
}
bool isFull(struct Stack *st)
{
    if(st->top==st->size-1)
        return true;
    else
        return false;
}

void push(struct Stack *st)
{
    if(isFull(st))
    {
        printf("\nStack Overflow.");
    }else
    {
        printf("\nEnter element to be pushed into the stack: ");
        scanf("%d",&st->s[++st->top]);
    }
}

void pop(struct Stack *st)
{
    int temp;
    if(isEmpty(st))
    {
        printf("\nStack is Empty.");
    }else
    {
        temp=st->s[st->top--];
        printf("\nPoped Element= %d",temp);
    }
    
}

void peek(struct Stack st)
{
    int index;
    printf("\nEnter the index at which you want to peek into the stack.");
    scanf("%d",&index);
    if(index>st.top)
        printf("\nInvalid Index.");
    else
        printf("Element at given Index = %d",st.s[index]);
}

void stackTop(struct Stack st)
{
    if(!isEmpty(&st))
        printf("\nTop Element at Stack= %d", st.s[st.top]);
    else
        printf("\nStack is Empty.");
}

void Display(struct Stack st)
{
    int index=0;
    printf("\nElements in stack are as follow: ");
    while(index<=st.top)
    {
        printf("%d, ",st.s[index++]);
    }
}
int main()
{
    struct Stack st;
    int choice=1,ret;
    printf("\nEnter the size of Stack you want to create: ");
    scanf("%d",&st.size);
    st.s=(int *)malloc(st.size*sizeof(int));
    st.top=-1;

    while(choice>0)
    {
        printf("\nEnter -1 to exit.");
        printf("\nEnter 1 to push a value into the stack.");
        printf("\nEnter 2 to pop a value from the stack.");
        printf("\nEnter 3 to get the top element of stack.");
        printf("\nEnter 4 to check if stack is Empty.");
        printf("\nEnter 5 to check if stack is full.");
        printf("\nEnter 6 to peek into some position in stack.");
        printf("\nEnter 7 to see all elements in stack.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\n***User Asked for Termination***\n");
                break;
            case 1:
                push(&st);
                break;
            case 2:
                pop(&st);
                break;
            case 3:
                stackTop(st);
                break;
            case 4:
                ret=isEmpty(&st);
                if(ret)
                    printf("\nStack is Empty.");
                else
                    printf("\nStack is not Empty.");
                break;
            case 5:
                ret=isFull(&st);
                if(ret)
                    printf("\nStack is full.");
                else
                    printf("\nStack is not full.");
                break;
            case 6:
                peek(st);
                break;
            case 7:
                Display(st);
                break;
            default:
                printf("\nInvalid Choice.\n");
                break;

        }


    }

    printf("\nDone with Stack Use, releasing memory now.\n\n");
    free(st.s);
    

}