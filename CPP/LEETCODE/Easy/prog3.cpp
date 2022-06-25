/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/


#include<iostream>
#include<string>
#include <unordered_map>

class RomantoInteger
{
    public:
        int romanToInt(std::string s);
};

int RomantoInteger::romanToInt(std::string str)
{
    int ret,i;
    ret=0;
    /*std::unordered_map<char, int> umap;

    umap['M']=1000;
    umap['D']=500;
    umap['C']=100;
    umap['L']=50;
    umap['X']=10;
    umap['V']=5;
    umap['I']=1;*/

    i=0;
    while(i<str.size())
    {
        if(str[i]=='M')
        {
            ret+=1000;
        } else if(str[i]=='D')
        {
            ret+=500;
        } else if(str[i]=='C')
        {
            if(str[i+1]=='M' && i+1!=str.size())
            {
                ret+=900;
                i++;
            } else if(str[i+1]=='D' && i+1!=str.size())
            {
                ret+=400;
                i++;
            }else
                ret+=100;
        } else if(str[i]=='L')
        {
            ret+=50;
        }else if(str[i]=='X')
        {
            if(str[i+1]=='C' && i+1!=str.size())
            {
                ret+=90;
                i++;
            }else if(str[i+1]=='L' && i+1!=str.size())
            {
                ret+=40;
                i++;
            }else
            {
                ret+=10;
            }
        }else if(str[i]=='V')
        {
            ret+=5;
        } else
        {
            if(str[i+1]=='X' && i+1!=str.size())
            {
                ret+=9;
                i++;
            }else if(str[i+1]=='V' && i+1!=str.size())
            {
                ret+=4;
                i++;
            }else
            {
                ret++;
            }
        }
        i++;
    }
    return ret;
}
int main()
{
    std::string str;
    int retVal;
    std::cout<<"Enter Number in roman numeral:"<<std::endl;  
    std::cin>>str;
    RomantoInteger obj;
    retVal=obj.romanToInt(str);
    std::cout<<"Result = "<<retVal;
    return 0;
}
