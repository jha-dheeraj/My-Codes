/*
Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, 
with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k 
(hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, 
with the first five elements of nums being 0, 1, 2, 3, 
and 4 respectively.
It does not matter what you leave beyond the 
returned k (hence they are underscores).
*/

#include<iostream>
#include<vector>


class removeDuplicate
{
    public:
        std::vector<int> populate(std::vector<int> vec);
        int removeDuplicates(std::vector<int> vec);
};
std::vector<int> removeDuplicate::populate(std::vector<int> vec)
{
    int n,temp;
    std::cout<<"Enter number of element to be inserted:";
    std::cin>>n;
    vec.reserve(n);
    while(n--)
    {
        std::cin>>temp;
        vec.push_back(temp);
    }
    return vec;
}

int removeDuplicate::removeDuplicates(std::vector<int> vec)
{
    int i,j,temp;;
    i=0;
    j=1;
    temp=vec[0];
    while(j<vec.size())
    {
        if(vec[j]>temp)
        {
            temp=vec[j];
            vec[++i]=temp;
        }
        j++;
    }
    return i+1;
}
int main()
{
    std::vector<int> vec;
    int retval;
    removeDuplicate obj1;
    vec=obj1.populate(vec);
    retval=obj1.removeDuplicates(vec);

    std::cout<<"Returned value is :"<< retval << std::endl;
    return 0;

}