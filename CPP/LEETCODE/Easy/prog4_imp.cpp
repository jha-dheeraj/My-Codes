/*
Write a function to find the longest common prefix 
string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include<iostream>
#include<string>
#include<vector>

class commonPrefix
{
    public:
        std::vector<std::string> populateVector(std::vector<std::string> vec);
        std::string longestCommonPrefix(std::vector<std::string>& strs);
};

std::vector<std::string> commonPrefix::populateVector(std::vector<std::string> vec)
{
    int n;
    std::string temp;
    std::cout<<"Enter number of strings to be pushed into the vector:"<<std::endl;
    std::cin>>n;
    std::cout<<"Enter strings:"<<std::endl;
    while(n--)
    {
        std::cin>>temp;
        vec.push_back(temp);
    }
    return vec;
}
std::string commonPrefix::longestCommonPrefix(std::vector<std::string>& strs)
{
    std::string first=strs[0];
    for(int i=1; i<strs.size();i++)
    {
        if(first=="")
            break;
        int minsize=std::min(first.size(), strs[i].size());
        while(first.size()>minsize || first!=strs[i].substr(0, minsize))
        {
            if(first=="")
                break;
            if(first.size()>minsize)
            {
                first.pop_back();
            }else 
            {
                first.pop_back();
                --minsize;
            }
        }

    }
    return first;
}
int main()
{
    std::vector<std::string> vec;
    commonPrefix obj;
    std::string res;
    vec=obj.populateVector(vec);
    res=obj.longestCommonPrefix(vec);
    std::cout<<"Longest Common Sequence is : "<<res<<std::endl;
    return 0;

}