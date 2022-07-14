#include<iostream>

using namespace std;

int findPower(int base, int exp)
{
    if(base==0)
        return 0;
    if(exp==0)
        return 1;
    if(exp>0)
        return base*findPower(base,exp-1);
    return 0;
}

int main(int argc, char *argv[])
{
    cout << "You are interested in finding power of base : " << argv[1] <<" and exponent: "<<argv[2]<<endl;
    cout << "Here is result:"<< findPower(stoi(argv[1]), stoi(argv[2])) << endl;
    return 0;
}
