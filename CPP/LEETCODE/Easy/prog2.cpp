/*Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.*/


#include<iostream>
#include<vector>

using namespace std;

class palindrome
{
    private:
        int num;
    public:
        void setValue(int& x);
        bool isPalindrome(int x);
};
void palindrome::setValue(int& x)
{
    num=x;
}

bool palindrome::isPalindrome(int x)
{
    int temp=x;
    int rem=0;
    while(temp)
    {
        rem=rem*10 + temp%10;
        temp/=10;
    }
    if(rem==x)
        return true;
    else
        return false;
}
int main()
{
    int n;
    palindrome obj1;
    cout<<"Enter Value to be tested:";
    cin>> n;
    obj1.setValue(n);
    if(obj1.isPalindrome(n))
        cout<<"\nPalindrome Number."<<endl;
    else
        cout<<"\n Non Palindrome number."<<endl;

}