#include<iostream>

using namespace std;

template <typename T>
T Add(T a, T b)
{
    return a+b;
}

int main()
{
    cout<<"Addition of 4 + 6 ="<<Add(4,6)<<endl;
    cout<<"Addition of 4.4 + 6.3 ="<<Add(4.4,6.3)<<endl;

}