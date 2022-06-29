/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
*/


#include<iostream>
#include<vector>


class solution
{
    public:
        std::vector<int> setValue(std::vector<int> vec);
        int searchInsert(std::vector<int>& nums, int target);
};

std::vector<int> solution::setValue(std::vector<int> vec)
{
    int n,temp;
    std::cout<<"Enter number of value to be inserted:";
    std::cin>>n;
    vec.reserve(n);
    while(n--)
    {
        std::cin>>temp;
        vec.push_back(temp);
    }
    return vec;
}

int solution::searchInsert(std::vector<int>& nums, int target)
{
    int i=0;
    while(i<nums.size())
    {
        if(nums.at(i)>=target)
            break;
        i++;
    }
    return i;
}

int main()
{
    std::vector<int> nums;
    solution obj;
    int res;
    nums=obj.setValue(nums);
    std::cout<<"\nEnter the target to be searched:";
    std::cin>>res;
    res=obj.searchInsert(nums,res);
    std::cout<<"\nSearch index= "<< res << std::endl;

    return 0;
}