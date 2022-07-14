#include<iostream>
#include<array>

void swap(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}
void swap_p(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    std::array<int, 4> a = {1, 2, 3, 4};
    // array<int, 5> ar2 = {1, 2, 3, 4, 5};
    for(int i=0;i<a.size();i++)
    {
        std::cout<<a.at(i)<<" ";
    }
    swap(a[0],a[1]);
    swap_p(&a[0],&a[1]);
    std::swap(a[2],a[3]);
    std::cout<<"After Swap:"<<std::endl;
    for(int i=0;i<a.size();i++)
    {
        std::cout<<a.at(i)<<" ";
    }
    std::cout<<"\n";

    return 0;

}