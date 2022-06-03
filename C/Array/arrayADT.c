#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct Array
{
    int *arr;
    int length;
    int size;
};

void createArray(struct Array *array1)
{
    printf("\nEnter the size of array to be created:");
    scanf("%d", &(array1->size));
    array1->length=0;
    array1->arr = (int *)malloc(array1->size*sizeof(int));
}
void populateArray(struct Array *array1)
{
    int length,i;
    printf("\nSize of array is : %d \nTell us how many element you want to Add...:",array1->size);
    scanf("%d", &length);
    if(length<=array1->size)
    {
        array1->length=length;
        printf("\nEnter elements:");
        for(i=0; i<length; i++)
            scanf("%d",&array1->arr[i]);

    } else
    {
        printf("\nThis much value will overflow our array...!!!\n");
        return;
    }
    
}

void DisplayArray(struct Array array1)
{
    int i;
    printf("\nHere is your Array...: \n");
    for(i=0; i< array1.length;i++)
        printf("%d\t", array1.arr[i]);

    printf("\n");
}

void AddorAppendValue(struct Array *array1)
{
    int value;
    printf("\nEnter value to be inserted: ");
    scanf("%d", &value);
    if(array1->length<array1->size)
        array1->arr[(array1->length)++]=value;
    else
    {
        printf("\nArray overflow!!!");
        return;
    }
}

void InsertAtPosition(struct Array *array1)
{
    int i, pos, key;
    printf("\nEnter the position and the element  to be inserted:");
    scanf("%d %d", &pos,&key);
    if(pos<=array1->length)
    {
        for(i=array1->length; i>pos; i--)
            array1->arr[i]=array1->arr[i-1];
        array1->arr[pos]=key;
        array1->length++;
    } else
    {
        printf("\nSize of array is %d and you want to put this element in heigher index!!!\n", array1->size);
        return;
    }
    
}

void DeletefromPosition(struct Array *array1)
{
    int pos,i;
    printf("\nEnter the position of array from which you wants to delete element:");
    scanf("%d",&pos);
    if(pos<=array1->length)
    {
        for(i=pos; i<array1->length-1; i++)
            array1->arr[i]=array1->arr[i+1];
        array1->length--;
            
    } else 
    {
        printf("\nInvalid Index!!");
        return;
    }
}

void LinearSerach(struct Array array1)
{
    int i,key, index;
    index=-1;

    printf("\nEnter the key to be searched:");
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
        printf("\nFound key at position:%d\n",index);
    } else
    {
        printf("\nINVALID KEY!!!\n");
    }
}

void BinarySearch(struct Array array1)
{
    int low, high, mid, key,index;
    index=-1;
    low=0;
    high=array1.length-1;
    printf("\nEnter the key to be searched...:");
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
        printf("\nFound key at position:%d\n",index);
    } else
    {
        printf("\nINVALID KEY!!!\n");
    }

}

void GetAtIndex(struct Array array1)
{
    int index;
    printf("\nEnter the Index on which you want to find the value: ");
    scanf("%d", &index);
    printf("\nValue at Array[%d] = %d\n", index, array1.arr[index]);
}

void SetAtIndex(struct Array *array1)
{
    int index,value;
    printf("\nEnter the Index and value on which you want to set the value: ");
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
    printf("\nMaximum value in this array=%d\nMinimum value in this array=%d\n",max,min); 
}

void ArrayReverse(struct Array *arr)
{
    int i=0;
    int temp=0;
    int j=arr->length - 1;
    for(;i!=j;i++,j--)
    {
        temp=arr->arr[i];
        arr->arr[i]=arr->arr[j];
        arr->arr[j]=temp;
    }

}

void LeftShiftArray(struct Array *arr)
{
    int i =0, temp;
    for(i=0;i<arr->length;i++)
    {
        if(i==0)
            temp=arr->arr[i];
        else
            arr->arr[i-1]=arr->arr[i];

    }
    arr->arr[arr->length-1]=temp;
}

void RightShiftArray(struct Array *arr)
{
    int i=0,temp;
    temp=arr->arr[arr->length-1];
    for(i=arr->length-1;i>0;i--)
    {
            arr->arr[i]=arr->arr[i-1];
    } 
    arr->arr[0]=temp;
}

void SumofArrayElement(struct Array arr)
{
    int i,sum=0;
    for(i=0;i<arr.length;i++)
        sum+=arr.arr[i];

    printf("\nSum of Element: %d", sum);
}

void Merge()
{
    struct Array array1,array2,array3;
    int i,j,K;
    
    printf("\nEnter size of array 1 and array2 respectively:");
    scanf("%d %d",&array1.size, &array2.size);
    array1.arr=(int *)malloc((array1.size)*sizeof(int));
    array2.arr=(int *)malloc((array2.size)*sizeof(int));

    printf("\nEnter number of elements in array1 and array2 you wish to add:");
    scanf("%d %d",&array1.length, &array2.length);
    printf("\nEnter Elements of array1:");
    for(i=0;i<array1.length;i++)
        scanf("%d",&array1.arr[i]);
    printf("\nEnter Elements of array2:");
    for(i=0;i<array2.length;i++)
        scanf("%d",&array2.arr[i]);

    array3.size=array1.length + array2.length + 5;
    array3.arr=(int *)malloc(array3.size*(sizeof(int)));


    i=j=K=0;
    while(i!=array1.length && j!=array2.length)
    {
        if(array1.arr[i]<array2.arr[j])
            array3.arr[K++]=array1.arr[i++];
        else if (array1.arr[i]>array2.arr[j])
            array3.arr[K++]=array2.arr[j++];
        else
        {
            array3.arr[K++]=array2.arr[j++];
            i++;
        }
    }
    if(i==array1.length)
    {
        while(j!=array2.length)
           array3.arr[K++]=array2.arr[j++];
    } else
    {
        while(i!=array1.length)
           array3.arr[K++]=array1.arr[i++];
    }
    array3.length=K;

    printf("\nArray1 was like this:\n");
    for(i=0;i<array1.length;i++)
        printf("%d\t",array1.arr[i]);
    printf("\nArray2 was like this:\n");
    for(i=0;i<array2.length;i++)
        printf("%d\t",array2.arr[i]);
    printf("\nFinally after merging:\n");
    for(i=0;i<array3.length;i++)
        printf("%d\t",array3.arr[i]);  

}
bool isDuplicate(int key, struct Array array)
{
    int i,flag;
    flag=1;
    for(i=0;i<array.length;i++)
    {
        if(array.arr[i]==key)
            flag++;
    }
    if(flag>1)
        return true;
    else 
        return false;
}
void ArrayUnion()
{
    struct Array array1,array2,array3;
    int i,j,k;
    
    printf("\nEnter size of array 1 and array2 respectively:");
    scanf("%d %d",&array1.size, &array2.size);
    array1.arr=(int *)malloc((array1.size)*sizeof(int));
    array2.arr=(int *)malloc((array2.size)*sizeof(int));

    printf("\nEnter number of elements in array1 and array2 you wish to add:");
    scanf("%d %d",&array1.length, &array2.length);
    printf("\nEnter Elements of array1:");
    for(i=0;i<array1.length;i++)
        scanf("%d",&array1.arr[i]);
    printf("\nEnter Elements of array2:");
    for(i=0;i<array2.length;i++)
        scanf("%d",&array2.arr[i]);

    array3.size=array1.length + array2.length + 5;
    array3.arr=(int *)malloc(array3.size*(sizeof(int)));
    array3.length=array1.length + array2.length;


    i=j=k=0;
    while(i!=array1.length )
    {
        if(!isDuplicate(array1.arr[i],array3))
        {
            array3.arr[k++]=array1.arr[i++];
        } else
              i++;   
    }
    while(j!=array2.length )
    {
        if(!isDuplicate(array2.arr[j],array3))
        {
            array3.arr[k++]=array2.arr[j++];
        } else
        {
            j++;   
        }
    }
    array3.length=k;

    printf("\nArray1 was like this:\n");
    for(i=0;i<array1.length;i++)
        printf("%d\t",array1.arr[i]);
    printf("\nArray2 was like this:\n");
    for(i=0;i<array2.length;i++)
        printf("%d\t",array2.arr[i]);
    printf("\nFinally after merging:\n");
    for(i=0;i<array3.length;i++)
        printf("%d\t",array3.arr[i]);  

}

//Reconsider logic for intersectio...
void ArrayIntersection()
{
    struct Array array1,array2,array3;
    int i,j,k,flag;
    
    printf("\nEnter size of array 1 and array2 respectively:");
    scanf("%d %d",&array1.size, &array2.size);
    array1.arr=(int *)malloc((array1.size)*sizeof(int));
    array2.arr=(int *)malloc((array2.size)*sizeof(int));

    printf("\nEnter number of elements in array1 and array2 you wish to add:");
    scanf("%d %d",&array1.length, &array2.length);
    printf("\nEnter Elements of array1:");
    for(i=0;i<array1.length;i++)
        scanf("%d",&array1.arr[i]);
    printf("\nEnter Elements of array2:");
    for(i=0;i<array2.length;i++)
        scanf("%d",&array2.arr[i]);

    array3.size=array1.length + array2.length + 5;
    array3.arr=(int *)malloc(array3.size*(sizeof(int)));
    array3.length=array1.length + array2.length;
    i=j=k=0;
    while(i!=array1.length)
    {
        if(!isDuplicate(array1.arr[i],array3))
        {
            array3.arr[k++]=array1.arr[i++];
        } else
            i++; 

    }
    while(j!=array2.length)
    {
        flag=0;
        if(!isDuplicate(array1.arr[j],array3) && !isDuplicate(array2.arr[j],array2))
        {
            for(i=0; i<array1.length; i++)
            {
                if(array1.arr[i]==array2.arr[j])
                {
                    array3.arr[k++]=array2.arr[j++];
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                j++;
        } else
            j++;
        
    }
    array3.length=k;

    printf("\nArray1 was like this:\n");
    for(i=0;i<array1.length;i++)
        printf("%d\t",array1.arr[i]);
    printf("\nArray2 was like this:\n");
    for(i=0;i<array2.length;i++)
        printf("%d\t",array2.arr[i]);
    printf("\nFinally after merging:\n");
    for(i=0;i<array3.length;i++)
        printf("%d\t",array3.arr[i]);  

}

void ResizeArray(struct Array *array)
{
    int i, *temp;
    printf("\nSpecify the size:");
    scanf("%d", &array->size);
    temp=(int *)malloc(array->size*sizeof(int));
    for(i=0;i<array->length;i++)
    {
        temp[i]=array->arr[i];
    }
    free(array->arr);
    array->arr=temp;
    printf("Successfully resized the array...");
}


int main()
{
    int sz;
    int choice=1;
    struct Array array1;
    while(choice>0)
    {
        printf("\nEnter Choice:");
        printf("\nEnter 1 for create Array:");
        printf("\nEnter 2 to populate Array:");
        printf("\nEnter 3 for Displaying Elements in array:");
        printf("\nEnter 4 for Add or Append Element:");
        printf("\nEnter 5 for Insert at some position:");
        printf("\nEnter 6 for Delete from some position:");
        printf("\nEnter 7 for Linear Search:");
        printf("\nEnter 8 for Binary Search:");
        printf("\nEnter 9 for Get value at particular Index:");
        printf("\nEnter 10 for setting some value at particular Index:");
        printf("\nEnter 11 to Get Maximum and minimum element:");
        printf("\nEnter 12 for reversing Array:");
        printf("\nEnter 13 for shifting array left:");
        printf("\nEnter 14 for shifting array right:");
        printf("\nEnter 15 to find some of elements of array:");
        printf("\nEnter 16 to merge two array in sorted Order:");
        printf("\nEnter 17 to find union operation between two arrays:");
        printf("\nEnter 18 to find intersection operation between two arrays:");
        printf("\nEnter 19 to resize current array:");
        printf("\nEnter -1 to terminate!!!:");
        printf("\n\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case -1:
                printf("\n\n****USER ASKED FOR TERMINATION****\n\n");
                break;
            case 1:
                printf("\n\nRedirecting to Array Creation:");
                createArray(&array1);
                break;
            case 2:
                printf("\n\nRedirecting to array population part\n\n");
                populateArray(&array1);
                break;
            case 3:
                printf("\n\nRedirecting to array Display part\n\n");
                DisplayArray(array1);
                break;
            case 4:
                printf("\n\nRedirecting to Add or Append Part\n\n");
                AddorAppendValue(&array1);
                break;
            case 5:
                printf("\n\nRedirecting...\n\n");
                InsertAtPosition(&array1);
                break;
            case 6:
                printf("\n\nRedirecting...\n\n");
                DeletefromPosition(&array1);
                break;
            case 7:
                printf("\n\nRedirecting...\n\n");
                LinearSerach(array1);
                break;
            case 8:
                printf("\n\nRedirecting...\n\n");
                BinarySearch(array1);
                break;
            case 9:
                printf("\n\nRedirecting...\n\n");
                GetAtIndex(array1);
                break;
            case 10:
                printf("\n\nRedirecting...\n\n");
                SetAtIndex(&array1);
                break;
            case 11:
                printf("\n\nRedirecting...\n\n");
                GetMaxAndMinElement(array1);
                break;
            case 12:
                printf("\n\nRedirecting...\n\n");
                ArrayReverse(&array1);
                break;
            case 13:
                printf("\n\nRedirecting...\n\n");
                LeftShiftArray(&array1);
                break;
            case 14:
                printf("\n\nRedirecting...\n\n");
                RightShiftArray(&array1);
                break;
            case 15:
                printf("\n\nRedirecting...\n\n");
                SumofArrayElement(array1);
                break;
            case 16:
                printf("\n\nRedirecting...\n\n");
                Merge();
                break;
            case 17:
                printf("\n\nRedirecting...\n\n");
                ArrayUnion();
                break;
            case 18:
                printf("\n\nRedirecting...\n\n");
                ArrayIntersection();
                break;
            case 19:
                printf("\n\nRedirecting...\n\n");
                ResizeArray(&array1);
                break;
            default :
                printf("\n\n****Invalid Choice****\n\n");
                break;

        }
    }

    printf("Done with use of Array, releasing memory now...\n");
    if(array1.size>0)
        free(array1.arr);

    return 0;

}