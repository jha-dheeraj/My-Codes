#include<iostream>

using namespace std;

int main()
{
    int n;
    int temp=31, temp1;

    cout<<"Enter a number:";
    cin>>n;
    
    if(n>>31==0)
    {
        cout<<n<<" is a positive number."<<endl;
        temp1= n>>31;
        cout<< temp1<<endl;
    }
    else if(n>>31 < 0)
    {
        cout<<n<<" is a negative number."<<endl;
        temp1= n>>31;
        cout<< temp1<<endl;
    }

    return 0;
}