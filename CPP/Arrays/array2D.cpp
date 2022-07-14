// This program is written to understand the 1D and 2D array declaration on Heap.

#include<iostream>

using namespace std;

int main()
{
    int arr[10] = {-1};
    for(int i =0; i<10; i++)
        cout << arr[i] << endl;

    cout << "\n";
    // Dynamic 1D Array Allocation
    int *p = new int[10];
    for(int i =0; i<10; i++)
        cout << p[i] << endl;
    delete []p;
    p=NULL;
    
    // Dynamic 2D array allocation(partial on Heap)
    int *a[3];

    a[0]= new int[3];
    a[1]= new int[3];
    a[2]= new int[3];

    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                a[i][j]=0;
            else
                a[i][j]=3;
        }
    }
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    delete []a[0];
    delete []a[1];
    delete []a[2];
    // Dynamic 2D array allocation(Fully on Heap)

    int **s;

    s = new int*[3];

    s[0] = new int[3];
    s[1] = new int[3];
    s[2] = new int[3];
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                s[i][j]=0;
            else
                s[i][j]=3;
        }
    }
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }

    delete []s[0];
    delete []s[1];
    delete []s[2];
    delete []s;
    return 0;
}