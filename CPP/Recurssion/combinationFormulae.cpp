#include<iostream>

using namespace std;

int fact(int n)
{
    if(n<=1)
        return 1;
    else
        return n*fact(n-1);

}
// Itterative Version
int combinationResultIter(int n, int r)
{
    int t0, t1, t2, result;

    t0 = fact(n);
    t1 = fact(r);
    t2 = fact(n-r);

    return (t0)/(t1*t2);
}

// Using Pascle's triangle rule
int combinationResultRecurssive(int n, int r)
{
    if(r==0 || n==r)
        return 1;
    else 
        return combinationResultRecurssive(n-1, r-1) + combinationResultRecurssive(n-1,r);
}

int main()
{
    int n, r;

    cout << "Enter value of n and r for n(C)r : ";
    cin>>n>>r;

    cout << "Result Using Itterative version is: " << combinationResultIter(n,r) << endl;
    cout << "Result Using Recurssivre version is: " << combinationResultRecurssive(n,r) << endl;

    return 0;
}