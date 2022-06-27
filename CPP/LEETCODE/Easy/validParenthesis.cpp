/*
Given a string s containing just the characters 
'(', ')', '{', '}', '[' and ']', determine if the input string
 is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/

#include<iostream>
#include<stack>
#include<string>

class validParethesis
{
    public:
        std::string getStr();
        bool isValid(std::string s);
};

std::string validParethesis::getStr()
{
    std::string input;
    std::cout<<"Enter string to be tested:";
    std::cin>>input;
    return input;
}

bool validParethesis::isValid(std::string s)
{
    std::stack<char> st;
    int i=0;
    while(i<s.size())
    {
        if(st.empty())
        {
            std::cout<<"Pushing "<<s[i]<<std::endl;
            st.push(s[i]);
        } else if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            std::cout<<"Pushing "<<s[i]<<std::endl;
            st.push(s[i]);
        }
        else
        {
            if((st.top()== '[' && s[i]==']') || (st.top()== '{' && s[i]=='}') || (st.top()== '(' && s[i]==')'))
            {
                st.pop();
                std::cout<<"Poping "<<std::endl;
            }
            else
            {
                std::cout<<"Pushing "<<s[i]<<std::endl;
                st.push(s[i]);
            }
        }
        i++;
    }
    if(st.empty())
        return true;
    else
        return false;
}




int main()
{
    validParethesis obj;
    std::string str;

    str=obj.getStr();
    if(obj.isValid(str))
        std::cout<<"Balanced Paranthesis."<<std::endl;
    else
        std::cout<<"Not Balanced."<<std::endl;

    return 0;

}