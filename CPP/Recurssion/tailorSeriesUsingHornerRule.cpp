#include<iostream>

using namespace std;

double tailorIterative(double x, double n)
{
    double result=1;
    for(double i=n; i>0 ; i--)
    {
        result=1+(x/i)*result;
    }
    return result;
}

double tailorRecurssive(double x, double n)
{
    static double result=1;
    if(n==0)
        return result;
    else
    {
        result=1+(x/n)*result;
        return tailorRecurssive(x,n-1);
    }
    return 0;
}

int main()
{
    double a, b;
    cout << "Enter the value of x and n for the function exp(x,n):";
    cin >> a >> b;
    cout << "Iterative result of exp(" << a << ", "<< b << " ) is: "<< tailorIterative(a,b) << endl;
    cout << "Recurssive result of exp(" << a << ", "<< b << " ) is: "<< tailorRecurssive(a,b) << endl;

    return 0;
}