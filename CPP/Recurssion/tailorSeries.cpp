#include<iostream>

using namespace std;

double findTailor(int x, int n)
{
    static double p=1, f=1;
    double result;
    if(n==0)
        return 1;
    else
    {
        result=findTailor(x,n-1);
        p=p*x;
        f=f*n;
        return result+p/f;
    }
    return 0;
}

int main()
{
    int x, n;
    cout << "Enter the value of x and the highest power till which we want to find the series for e(x,n):"<<endl;
    cin >> x >> n;
    cout << "Result: " << findTailor(x,n) << endl;
    return 0; 
}