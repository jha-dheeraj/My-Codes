/*

Given two non-negative integers num1 and num2 represented as 
strings, return the product of num1 and num2, also represented
 as a string.

Note: You must not use any built-in BigInteger library or 
convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
*/

#include<iostream>
#include<string>

class MString
{

    public:
        std::string multiply(std::string num1, std::string num2);
};


std::string MString::multiply(std::string num1, std::string num2)
{
    unsigned long long int temp;
    long n,m;
    n=m=0;
    for(int i=0;i<num1.size();i++)
    {
        n=n*10 + (num1[i]-48);
    }
    for(int i=0;i<num2.size();i++)
    {
        m=m*10 + (num2[i]-48);
    }
    temp=n*m;

    return std::to_string(temp);
}

int main()
{
    std::string num1,num2;
    MString obj;
    std::cout<<"Enter the numbers:"<<std::endl;
    std::cin>>num1>>num2;
    std::cout<<obj.multiply(num1,num2)<<std::endl;

    return 0;
}