#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void findSymmetricPair(int array[5][2], int n)
{
    int k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(array[i][0]==array[j][1] && array[i][1]==array[j][0])
            {
                cout<<"pair"<<k++<<"= { "<<"{"<<array[i][0]<<", "<<array[i][1]<<"}"<<",{"<<array[j][0]<<", "<<array[j][1]<<"} }"<<endl;
                break;
            }
        }
    }

}

int main()
{
    int array[][2]={{1,2},{2,1},{3,1},{5,1},{1,5}};
    //method 1
    findSymmetricPair(array, 5);

    return 0;

}