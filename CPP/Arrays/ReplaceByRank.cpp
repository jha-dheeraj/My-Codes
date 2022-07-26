#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int array[]={4,6,2,5,9,1,0};
    vector<int> vec;
    cout<<"Array is : {";
    for(int i=0; i<7; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"}\n";
    for(int i=0;i<7;i++)
    {
        vec.push_back(array[i]);
    }
    sort(vec.begin(),vec.end());

    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7;j++)
        {
            if(vec[i]==array[j])
                array[j]=i;
        }
    }
    cout<<"Array with rank : {";
    for(int i=0; i<7; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"}\n";

}