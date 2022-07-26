#include<iostream>
#include<vector>

using namespace std;

bool binarySearch(int array[], int key, int low, int high)
{
    int mid;
    static int flag=0;
    if(low<high)
    {
        mid=(low+high)/2;

        if(key==array[mid])
        {
            flag=1;
            return true;
        }
        else if(key>array[mid])
            binarySearch(array,key,mid+1,high);
        else
            binarySearch(array,key,low,mid);
    }
    if(flag==1)
        return true;
    else
        return false;
}

int main()
{
    int array[]={1,4,5,7,8,9,11,17,21};
    if(binarySearch(array, 15, 0, 8))
    {
        cout<<"Key found in list."<<endl;
    }else
    {
        cout<<"Key not found in list."<<endl;
    }
    return 0;
}

