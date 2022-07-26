#include<iostream>
#include<vector>

class Sorting
{
    private:
        std::vector<int> vec;

    public:
        void setValue()
        {
            int n;
            std::cout<<"Enter the numbers to be sorted or -1 to exit:"<<std::endl;
            while(1)
            {
                std::cout<<"Enter Value:"<<std::endl;
                std::cin>>n;
                
                if(n<0)
                    break;
                vec.push_back(n);
            }
        }
        void InsertionSort();
        void BubbleSort();
        void QuickSort(int l, int h);
        int Partition(int l, int h);
        void printVector();
        int getVectorSize()
        {
            return vec.size();
        }

};

void Sorting::InsertionSort()
{
    int i,j;

    for(i=1;i<vec.size();i++) //swap
    {
        for(j=i;j>0;j--)
        {
            if(vec.at(j-1)>vec.at(j))
                std::swap(vec.at(j),vec.at(j-1));
        }
    }
}

void Sorting::BubbleSort()
{
    int i,j,flag;
    
    for(i=0;i<vec.size()-1;i++) //swap
    {
        flag=0;
        for(j=0;j<vec.size()-1-i;j++)
        {
            if(vec.at(j)>vec.at(j+1))
            {
                std::swap(vec.at(j),vec.at(j+1));
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int Sorting::Partition(int l, int h)
{
    int i,j,pivot,k,m;
    k=i=l;
    m=j=h;
    pivot=vec[l];

    do
    {
        do
        { i++;}while(vec[i]<=pivot && i<=m);
        do{ j--;}while(vec[j]>pivot && j>=k);
        
        if(i<j)
        {
            std::swap(vec.at(i), vec.at(j));
        }
    }while(i<j);

    std::swap(vec.at(l),vec.at(j));

    return j;
}

void Sorting::QuickSort(int l, int h)
{
    int j;
    if(l<h)
    {
        j=Partition(l,h);
        QuickSort(l,j);
        QuickSort(j+1,h);

    }
}
void Sorting::printVector()
{
    for(std::vector<int>::iterator it=vec.begin();it<vec.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
}

int main()
{
    int n;
    Sorting *obj1=new Sorting();
    obj1->setValue();
    std::cout<<"Enter 1 for Insertion sort."<<std::endl;
    std::cout<<"Enter 2 for Bubble sort"<<std::endl;
    std::cout<<"Enter 3 for Quick Sort"<<std::endl;
    std::cin>>n;
    switch(n)
    {
        case 1:
            std::cout<<"Before sorting, array is:"<<std::endl;
            obj1->printVector();
            obj1->InsertionSort();
            std::cout<<"After sorting, array is:"<<std::endl;
            obj1->printVector();
            break;
        case 2:
            std::cout<<"Before sorting, array is:"<<std::endl;
            obj1->printVector();
            obj1->BubbleSort();
            std::cout<<"After sorting, array is:"<<std::endl;
            obj1->printVector();
            break;
        case 3:
            std::cout<<"Before sorting, array is:"<<std::endl;
            obj1->printVector();
            obj1->QuickSort(0,obj1->getVectorSize()-1);
            std::cout<<"After sorting, array is:"<<std::endl;
            obj1->printVector();
            break;
        default:
            std::cout<<"\nInvalid Choice...!"<<std::endl;
            break;

    }
}