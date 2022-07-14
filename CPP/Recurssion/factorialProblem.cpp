#include<iostream>

using namespace std;

int findFactorial(int n)
{
    if(n==0)
        return 1;
    if(n>0)
        return n*findFactorial(n-1);
    if(n<0)
    {
        cout << "Invalid Input!!!" << endl;
        return 0;
    }
    return 0;
}

int main(int argc, char **argv)
{
    cout << "You are interested in finding factorial of " << argv[1] << endl;
    // cout << "Here is result : " << findFactorial(atoi(argv[1])) << endl;
    cout << "Here is result : " << findFactorial(stoi(argv[1])) << endl;
    return 0;
}
