/*
Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

#include<iostream>
#include<vector>


class removeElements
{
    public:
        std::vector<int> populate(std::vector<int> vec);
        int removeElement(std::vector<int>& vec, int val);
};
std::vector<int> removeElements::populate(std::vector<int> vec)
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

int removeElements::removeElement(std::vector<int>& vec, int val)
{
    int i,j;
    j=0;
    while(j<vec.size())
    {
        if(vec[j]==val)
        {
            for(i=j;i<vec.size()-1;i++)
            {
                vec[i]=vec[i+1];
            }
            vec.pop_back();
        } else
            j++;
    }
    j=0;
    std::cout<<"Output vector is : ";
    while(j<vec.size())
    {
        std::cout<<vec[j]<<" ";
        j++;
    }

    return vec.size();
}
int main()
{
    std::vector<int> vec;
    int retval,elem;
    removeElements obj1;
    vec=obj1.populate(vec);
    std::cout<<"Enter element to be removed:";
    std::cin>>elem;
    retval=obj1.removeElement(vec,elem);

    std::cout<<"Returned value is :"<< retval << std::endl;
    return 0;
}