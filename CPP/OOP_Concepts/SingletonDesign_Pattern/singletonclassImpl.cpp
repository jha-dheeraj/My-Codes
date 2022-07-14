#include<iostream>

class singletoncls
{
    public:
        void printHello()
        {
            std::cout<<"Hello Worlld..."<<std::endl;
            std::cout<<"Data = "<<data<<std::endl;
        }
        static singletoncls *getObject()
        {
            if(!sinletonobj)
            {
                sinletonobj=new singletoncls;
            }
            return sinletonobj;
        }
        void setValue(int x)
        {
            this->data=x;
        }

    private:
        int data;
        static singletoncls *sinletonobj;

        singletoncls():data(0){}

};

singletoncls *singletoncls::sinletonobj = nullptr;
int main()
{
    singletoncls *s=singletoncls::getObject();
    s->printHello();
    s->setValue(5);
    s->printHello();

    return 0;
}