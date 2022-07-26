#include<iostream>

using namespace std;
int countBitset(int n)
{
    int temp=32;
    int X=1;
    int count=0;
    
    while(temp--)
    {
        if(n==0)
            break;
        if(X & n)
            count++;
        n=n >> 1;
    }
        return count;

}

int main()
{
    int n;

    cout<<"Enter an integer:";
    cin>>n;
    cout<<"Number of fixed bit="<<countBitset(n)<<endl;

    return 0;
}