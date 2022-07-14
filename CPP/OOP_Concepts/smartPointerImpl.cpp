#include<iostream>
#include<memory>


class Square
{
    private:
        int side;
    
    public:
        Square():side(0){}
        Square(int x):side(x){}
        void getPerimeter()
        {
            std::cout<<"Perimeter of square with side "<<side<<"= "<<4*side<<std::endl;
        }
        void getArea()
        {
            std::cout<<"Area of square with side "<<side<<"= "<<side*side<<std::endl;
        }
};

int main()
{
    std::unique_ptr<Square> ptr1=(std::unique_ptr<Square>)new Square();
    std::unique_ptr<Square> ptr2(new Square(2));
    std::shared_ptr<Square> ptr3=(std::unique_ptr<Square>)new Square();
    std::shared_ptr<Square> ptr4(new Square(3));

    ptr1->getPerimeter();
    ptr1->getArea();
    ptr2->getPerimeter();
    ptr2->getArea();
    ptr3->getPerimeter();
    ptr3->getArea();
    ptr4->getPerimeter();
    ptr4->getArea();


    return 0;

}