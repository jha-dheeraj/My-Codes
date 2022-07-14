#include<iostream>
using namespace std;

int sumOfNaturalNumber(int n)
{
    if(n==1)
        return 1;
    if(n>1)
        return n + sumOfNaturalNumber(n-1);
    return 0;
}

int main()
{
    int a;
    cout << "Enter the number of Natural number to be counted:";
    cin >> a;
    cout << "Sum of " << a << " natural number is: " << sumOfNaturalNumber(a)<< endl;
    return 0;
}
