#include<iostream>

using namespace std;

int func1(int n)
{
    if(n>0)
    {
        printf("%d ", n);
        func1(n-1);
    }
    return 0;
}

int main()
{
    int n = 3;
    func1(n);
    return 0;
}