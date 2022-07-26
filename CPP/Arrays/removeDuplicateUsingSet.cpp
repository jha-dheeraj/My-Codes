#include<iostream>
#include<vector>
#include<set>


using namespace std;

int main()
{
    set<int> st;
    vector<int> vec = {1,1,1,2,3,4,4,4,5,5,6,7,7,8,8,9,9};

    // copy vector to set
    for(int x : vec)
    {
        st.insert(x);
    }

    vec.clear();
    // copy set to vector
    for(int x : st)
    {
        vec.push_back(x);
    }

    for(int x : vec)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}