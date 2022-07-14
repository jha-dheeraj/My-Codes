#include<iostream>

class String
{
    private:
        char *resrc;
        int length;

    public:
        // Default Const
        String():resrc(nullptr),length(0){}
        //parameterized constructor
        String(const char* input)
        {
            std::cout<<"Parameterisd called for "<<input<<std::endl;
            length=strlen(input);
            resrc = new char[length+1];
            strcpy(resrc,input);
        }

        //copy Constructor
        String(const String& obj)
        {
            if(this!=&obj)
            {
                std::cout<<"Called copy constructor with string"<<obj.resrc<<std::endl;
                length=obj.length;
                resrc=new char[length+1];
                strcpy(resrc,obj.resrc);
            }
        }
        // copy assignment operatore
        String& operator=(const String& obj)
        {
            if(this!=&obj)
            {
                std::cout<<"copy assignment operator called"<<std::endl;
                length=obj.length;
                resrc=new char[length+1];
                strcpy(resrc,obj.resrc);
                return *this;
            }
            return *this;
        }
        // move constructor
        String(String&& obj)
        {
            if(this!=&obj)
            {
                std::cout<<"In Move constructor..."<<std::endl;
                length=obj.length;
                resrc=new char[length+1];
                strcpy(resrc,obj.resrc);
                delete []obj.resrc;
                obj.resrc=nullptr;
                obj.length=0;
            }
        }
        // length function
        int str_length()
        {
            return length;
        }


    friend std::ostream& operator<<(std::ostream& cout, String& obj);
    friend std::istream& operator>>(std::istream& cin, String& obj);

};

std::ostream& operator<<(std::ostream& cout, String& obj)
{
    if(obj.resrc!=nullptr)
        cout<<obj.resrc;
    return cout;
}

std::istream& operator>>(std::istream& cin, String& obj)
{
    cin>>obj.resrc;
    obj.length=strlen(obj.resrc);
    return cin;
}
int main()
{
    String str1;            //default Constructor
    String str3="Dheeraj";  // parameterised Constructor
    String str4("Hello World");// parameterised constructor
    String str5(str3);               // copy constructor
    String str2=str4;       // coppy constructor
    str1=str3;              // Copy Assignment operator
    String str6 = std::move(str3);// Move constructor

    std::cout<<str1<<std::endl;
    std::cout<<str3<<std::endl;
    std::cout<<str4<<std::endl;
    std::cout<<str5<<std::endl;
    std::cout<<str2<<std::endl;
    std::cout<<str1<<std::endl;
    std::cout<<str4.str_length();
    std::cin>>str4;
    std::cout<<str4<<std::endl;
    std::cout<<str4.str_length();

}