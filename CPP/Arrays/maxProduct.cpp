#include<iostream>

using namespace std;

int maxProduct(int array[], int n)
{
    int i,j,max,prod,k;
    max=INT_MIN;
    prod=1;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            prod=1;
            for(k=i;k<=j;k++)
            {
                prod=prod*array[k];
            }
            if(prod>=max)
                max=prod;
        }
    }
    return max;
}

int max(int i, int j)
{
    if(i>j)
        return i;
    else
        return j;
}
int maxProductM2(int array[], int n)
{
    int maxLeft=array[0];
    int maxRight=array[0];
    int i=0,prod=1;

    bool zeroPresent=false;

    for(i=0;i<n;i++)
    {
        prod*=array[i];
        if(array[i]==0)
        {
            prod=1;
            zeroPresent=true;
        }
        maxLeft=max(prod, maxLeft);

    }
    prod=1;
    for(i=n-1;i>=0;i--)
    {
        prod*=array[i];
        if(array[i]==0)
        {
            zeroPresent=true;
            prod=1;
        }
        maxRight=max(prod,maxRight);
    }

    if(zeroPresent)
    {
        return max(max(maxLeft,maxRight),0);
    } else
    {
        return max(maxLeft, maxRight);
    }
}


// Implement Kadane's method.
int main()
{

    int array[]={2,3,-1,0,5,6,9,2,6};
    int maxp;
    maxp=maxProduct(array,9);
    cout<<"Maximum Product with the given array="<<maxp<<endl;

    maxp=maxProductM2(array,9);
    cout<<"Maximum Product with the given array by Method 2="<<maxp<<endl;

    return 0;

}