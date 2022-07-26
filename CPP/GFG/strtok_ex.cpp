#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.length();
 
        char char_array[n + 1];
 
        strcpy(char_array, S.c_str());
        
        char *token;
        vector<string> vec;
        token=strtok(char_array,".");
        while(token!=NULL)
        {
            vec.push_back(token);
            token=strtok(NULL,".");
        }
        S.clear();
        for(vector<string>::iterator it=vec.end()-1;it>=vec.begin();it--)
        {
            cout<<*it;
            S.append(*it);
            if(it != vec.begin())
            {
                cout<<".";
                S.append(".");
            }

        }
        cout<<"\n";
        cout<<S<<"\n";
        return S;
    } 
};

int main()
{
    Solution obj;
    obj.reverseWords("i.love.you");

    return 0;
}