#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int i,j,n,temp,lsum,rsum;
    vector<int> vec;
    cout<<"Enter number of element to insert:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }

    for(i=0; i<n; i++)
    {
        
        lsum=0;
        for(j=0; j<i; j++)
        {
            lsum+=vec[j];
        }

        rsum=0;
        for(j=i+1; j<n; j++)
        {
            rsum+=vec[j];
        }

        if(lsum==rsum)
            break;
    }
    cout<<"Equilibrium index is:"<<i<<endl;
    return 0;
}