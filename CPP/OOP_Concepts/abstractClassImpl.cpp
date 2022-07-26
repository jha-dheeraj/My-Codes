#include<iostream>


class Vehicle // Abstract Class
{
    public:
        virtual void CreateCar()=0; //pure virtual function
};

class car : public Vehicle
{
    public:
        void CreateCar()
        {
            std::cout<<"Creating car..."<<std::endl;
        }

};

int main()
{
    Vehicle *a1=new car;
    a1->CreateCar();
    return 0;
}







class String 
{
    private:
        char res[10];
        int len;

    public:
        String(const String& obj)
        {
            if(this!=obj)
            {
                int i=0;
                while(obj.res[i] != '\0')
                    i++;
                len=i;
                strcpy(res,obj.res);
                res[i+1]='\0';
            }
        }
};


int main()
{

    int days=365;
    int week, day;

    week=days/7;
    day=days%7;

    printf("week=%d, Day=%d",week, day);

    return 0;
    


}

private x
public y
protected z

class Base
{
    private:
        int x;
    public:
        int y;
    protected:
        int z;

};

class Derived : public Base
{
    y // public
    x // not accessible
    z // not accessible
};

class Derived1 : private Base
{
    x // not accessible
    y // private
    z // not accessible 
};