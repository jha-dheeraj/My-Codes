/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

*/

#include<iostream>
#include<string>
class LengthofLastWord
{
    public:
        int LengthofLastWordfun(std::string s);

};

int LengthofLastWord::LengthofLastWordfun(std::string s)
{
    char* c = const_cast<char*>(s.c_str());
    char *token=std::strtok(c," ");
    char *temp;
    temp=token;
    while(token!=NULL)
    {
        std::cout<<token<<std::endl;
        temp=token;
        token=std::strtok(NULL, " ");
    }
    return std::strlen(temp);
}

int main()
{
    LengthofLastWord obj;
    int res;
    res=obj.LengthofLastWordfun("Hello World");
    std::cout<<res;
    return 0;
}