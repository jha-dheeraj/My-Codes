#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *arr;
    int length;
    int size;
};

void createArray(struct Array *array1)
{
    array1->arr = (int *)malloc(array1->size*sizeof(int));
}
void populateArray(struct Array *array1)
{
    int length,i;
    printf("Size of array is : %d \nTell us how many element you want to Add...:",array1->size);
    scanf("%d", &length);
    if(length<=array1->size)
    {
        array1->length=length;
        printf("Enter elements:");
        for(i=0; i<length; i++)
            scanf("%d",&array1->arr[i]);

    } else
    {
        printf("This much value will overflow our array...!!!\n");
        return;
    }
    
}

void DisplayArray(struct Array array1)
{
    int i;
    printf("Here is your Array...: \n");
    for(i=0; i< array1.length;i++)
        printf("%d\t", array1.arr[i]);

    printf("\n");
}

void AddorAppendValue(struct Array *array1)
{
    int value;
    printf("Enter value to be inserted: ");
    scanf("%d", &value);
    if(array1->length<array1->size)
        array1->arr[(array1->length)++]=value;
    else
    {
        printf("Array overflow!!!");
        return;
    }
}

void InsertAtPosition(struct Array *array1)
{
    int i, pos, key;
    printf("Enter the position and the element  to be inserted:");
    scanf("%d %d", &pos,&key);
    if(pos<=array1->length)
    {
        for(i=array1->length; i>pos; i--)
            array1->arr[i]=array1->arr[i-1];
        array1->arr[pos]=key;
        array1->length++;
    } else
    {
        printf("Size of array is %d and you want to put this element in heigher index!!!\n", array1->size);
        return;
    }
    
}

void DeletefromPosition(struct Array *array1)
{
    int pos,i;
    printf("Enter the position of array from which you wants to delete element:");
    scanf("%d",&pos);
    if(pos<=array1->length)
    {
        for(i=pos; i<array1->length-1; i++)
            array1->arr[i]=array1->arr[i+1];
        array1->length--;
            
    } else 
    {
        printf("Invalid Index!!");
        return;
    }
}

void LinearSerach(struct Array array1)
{
    int i,key, index;
    index=-1;

    printf("Enter the key to be searched:");
    scanf("%d", &key);

    for(i=0;i<array1.length;i++)
    {
        if(array1.arr[i]==key)
        {
            index=i;
            break;
        }
    }
    if(index>=0)
    {
        printf("Found key at position:%d\n",index);
    } else
    {
        printf("INVALID KEY!!!\n");
    }
}

void BinarySearch(struct Array array1)
{
    int low, high, mid, key,index;
    index=-1;
    low=0;
    high=array1.length-1;
    printf("Enter the key to be searched...:");
    scanf("%d",&key);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(array1.arr[mid]==key)
        {
            index=mid;
            break;
        } else if(array1.arr[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    if(index>=0)
    {
        printf("Found key at position:%d\n",index);
    } else
    {
        printf("INVALID KEY!!!\n");
    }

}

void GetAtIndex(struct Array array1)
{
    int index;
    printf("Enter the Index on which you want to find the value: ");
    scanf("%d", &index);
    printf("Value at Array[%d] = %d\n", index, array1.arr[index]);
}

void SetAtIndex(struct Array *array1)
{
    int index,value;
    printf("Enter the Index and value on which you want to set the value: ");
    scanf("%d %d", &index, &value);
    array1->arr[index]=value;
}

void GetMaxAndMinElement(struct Array array1)
{
    int max,min,i;
    max=array1.arr[0];
    min=array1.arr[0];
    for(i=0;i<array1.length;i++)
    {
        if(array1.arr[i]>max)
            max=array1.arr[i];
        if(array1.arr[i]<min)
            min=array1.arr[i];
    }
    printf("Maximum value in this array=%d\nMinimum value in this array=%d\n",max,min); 
}




int main()
{
    int sz;
    struct Array array1;

    printf("Enter the size of array to be created:");
    scanf("%d", &sz);
    array1.size=sz;
    array1.length=0;
    createArray(&array1);
    populateArray(&array1);
    DisplayArray(array1);
    AddorAppendValue(&array1);
    DisplayArray(array1);
    InsertAtPosition(&array1);
    DisplayArray(array1);
    DeletefromPosition(&array1);
    DisplayArray(array1);
    LinearSerach(array1);
    BinarySearch(array1);
    GetAtIndex(array1);
    SetAtIndex(&array1);
    DisplayArray(array1);
    GetMaxAndMinElement(array1);
    ArrayReverse(&array1); //ToDo
    LeftShiftArray(&array1); // To Do
    RightShiftArray(&array1); // To Do
    MergeArray(&array1); // To Do
    printf("Done with use of Array, releasing memory now...\n");
    free(array1.arr);

    return 0;

}