#include<iostream>

using namespace std;

static int memo[20];
void Initialize()
{
    for(int i=1; i<=20; i++)
    {
        memo[i] = -1;
    }
}

int fibonacci(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciUsingMemoization(int n)
{   
    if(n<=1)
    {
        memo[n]=n;
        return n;
    } else
    {
        if(memo[n-2]==-1)
            memo[n-2]=fibonacciUsingMemoization(n-2);
        if(memo[n-1]==-1)
            memo[n-1]=fibonacciUsingMemoization(n-1);
        return memo[n-2]+memo[n-1];
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter number of terms we want to find:";
    cin>>n;
    cout << "Terms using normal method are : " << endl;
    for(int i=1 ; i <= n ; i++ )
        cout << fibonacci(i) <<" ";
    cout<<"\n";
    Initialize();
    cout << "Terms using memoization method are : " << endl;
    for(int i=0 ; i < n ; i++ )
        cout << fibonacciUsingMemoization(i) <<" ";
    cout<<"\n";
    return 0;
}

