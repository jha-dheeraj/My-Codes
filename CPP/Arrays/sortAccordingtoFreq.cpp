#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
    return a.second < b.second;
}

void sort(map<int, int>& M)
{
  
    // Declare vector of pairs
    vector<pair<int, int> > A;
  
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }
  
    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);
  
    M.clear();
    for(auto& it : A)
    {
        M.insert(it);
    }
}
int main()
{
    map<int, int>mp;
    int array[]={2,2,1,3,5,2,4,3,1};
    int i,k=0;

    for(i=0; i<9;i++)
    {
        if(mp.count(array[i]))
        {
            mp[i]++;
        }else
        {
            mp.insert({array[i],1});
        }
    }
    sort(mp);

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second > 1)
        {
            for(i=0; i < it->second; i++)
            {
                array[k++]=it->first;
            }
        }else
        {
            array[k++]=it->first;
        }
    }

    for(i=0;i<9;i++)
    {
        cout<<array[i]<<" ";
    }

    cout<<"\n";

    return 0;

}
