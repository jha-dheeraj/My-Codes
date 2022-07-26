#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    int array1[]={2,4,6,9,1,22};
    int array2[]={0,1,1,2,3,4,5,5,6,7,8,0,9,11};
    unordered_map<int, bool>mp;
    int i;
    int flag=0;

    //insert into unordered map
    for(i=0; i < 14; i++)
    {
        mp.insert(pair<int, bool>(array2[i],true));
    }
    for(i=0; i<6; i++)
    {
        if(mp.count(array1[i])<1)
        {
            flag=1;
            break;
        }

    }
    if(flag==0)
        cout<<"Array1 is subset of array2."<<endl;
    else
        cout<<"Array1 is not subset of array2."<<endl;


    return 0;
}