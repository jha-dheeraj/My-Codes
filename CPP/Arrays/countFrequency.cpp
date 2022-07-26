#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    map<int, int>maap;
    vector<int> vec = {1,1,3,9,7,7,7,5,0,5};

    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
    {
        // method 1
        // if(maap.count(*it))
        // {
        //     maap[*it]++;
        // }else
        // {
        //     maap.insert({*it,1});
        // }

        // method 2

        if(maap.find(*it)->second)
        {
            maap[*it]++;
        } else
        {
            maap.insert({*it,1});
        }
    }


    for(map<int, int>::iterator it=maap.begin(); it!=maap.end();it++)
    {
        cout<<"Count for "<<it->first<<" ="<<it->second<<endl;
    }

    return 0;
}