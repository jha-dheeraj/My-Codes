#include<iostream>

using namespace std;

class Test
{
    public:
        static int a;
        int b;

        Test():b(3){}

        static void Getter()
        {
            // cout<<"a ="<<a<<"b =="<<b<<endl; 
            //error: invalid use of member 'b' in static member function

            cout<<"a ="<<a<<endl;
        }
};
int Test::a=2;
int main()
{
    Test obj;
    Test::Getter();

    return 0;
}