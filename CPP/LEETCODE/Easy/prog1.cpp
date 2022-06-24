/*Problem Description*/

/*
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/


#include<iostream>
#include<vector>

using namespace std;

class TwoSum
{
    private:
        int a,b;

    public:
        TwoSum();
        TwoSum(int temp1, int temp2, vector<int>& nums);
        vector<int> setValue(int c, int d, vector<int> nums);
        void getValue(vector<int> nums);
        vector<int> twoSum(vector<int> nums, int target);
};

TwoSum::TwoSum()
{
    cout<<"\nIn default constructor."<<endl;
}

TwoSum::TwoSum(int temp1, int temp2, vector<int>& nums)
{
    cout<<"\nIn parameterised constructor."<<endl;
    a=temp1;
    b=temp2;
}

vector<int> TwoSum::setValue(int c, int d, vector<int> nums)
{
    int n,temp;
    a=c;
    b=d;
    cout<<"\nEnter number of element to be pushed into vector:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        nums.push_back(temp);
    }
    return nums;
}

void TwoSum::getValue(vector<int> nums)
{
    cout << "a="<<a<<"\tb="<<b<<endl;
    if(nums.empty())
        cout<<"Vector is Empty."<<endl;
    cout<<"Values are: ";
    for(vector<int>::iterator itr=nums.begin();itr!=nums.end();++itr)
    {
        cout<<*itr<<" ";
    }
    cout<<"\n";
}

vector<int> TwoSum::twoSum(vector<int> nums, int target)
{
    vector<int> vec2;
    int i,j;
    for(i=0;i<nums.size();i++)
    {
        for(j=i+1;j<nums.size();j++)
        {
            if(nums.at(i)+nums.at(j)==target)
            {
                vec2.push_back(i);
                vec2.push_back(j);
                break;
            }
        }
    }
    return vec2;
}

int main()
{
    vector<int> vec;
    vector<int> res;
    TwoSum object1;
    vec=object1.setValue(5,6,vec);
    object1.getValue(vec);
    res=object1.twoSum(vec,3);
    for(int i=0; i<res.size();i++)
    {
        cout<< res[i] << " ";
    }
    return 0;
}