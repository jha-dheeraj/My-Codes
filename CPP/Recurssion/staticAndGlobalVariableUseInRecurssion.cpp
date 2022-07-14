#include<iostream>

int x =0;

/* Recurssion using static variable */
int f1(int n)
{
    static int y = 0;
    if(n>0)
    {
        y++;
        return f1(n-1)+y;
    }
    return 0;
}

/* Recurssion using global variable */
int f2(int n)
{
    if(n>0)
    {
        x++;
        return f2(n-1) + x;
    }
    return 0;
}

/* Recurssion using local variable */
int f3(int n)
{
    if(n>0)
    {
        return f3(n-1)+n;
    }
    return 0;
}

int main()
{
    int a = 5;

    std::cout << "Output of f1(5) = " << f1(a) << std::endl;
    std::cout << "Output of f2(5) = " << f2(a) << std::endl;
    std::cout << "Output of f3(5) = " << f3(a) << std::endl;
    return 0;
}