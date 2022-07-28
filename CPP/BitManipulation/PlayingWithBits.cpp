#include<iostream>

using namespace std;

int main()
{
    int i;
    int temp,X=1,temp1;
    cout<<"\nEnter Number to be tested:";
    cin>>i;
    while(i!=-10)
    {   
        cout<<"Number is :"<<i<<endl;
        temp=32;
        while(temp--)
        {
            temp1= i & X;
            cout<< temp1;
            i=i>>1;
        }
        cout<<"\n";
        cout<<"\nEnter Number to be tested:";
        cin>>i;

    }
}