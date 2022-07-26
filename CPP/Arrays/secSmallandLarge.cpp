// #include<bits/stdc++.h>
#include<iostream>


using namespace std;

int main()
{
    int s1,s2,l1,l2,i,size;
    s1=s2=INT_MAX;
    l1=l2=INT_MIN;
    i=0;

    int array[] = {4,7,2,8,6,0,-1,46,78,21,99}; // s1=-1, s2=0, l1=99, l2=78
    size=11;
    while(i!=size)
    {
        if(array[i]>=l1)
        {
            l2=l1;
            l1=array[i];
        } 
        if(array[i]<=s1)
        {
            s2=s1;
            s1=array[i];
        }
        i++;
    }

    cout<<"Largest= "<<l1 << " "<<"2nd Largest= "<<l2<<endl;
    cout<<"Smallest= "<<s1 << " "<<"2nd smallest= "<<s2<<endl;

    return 0;
}