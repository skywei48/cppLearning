#include <iostream>

class A
{
    public: 
    A()
    {
        std::cout<<"A constructed. "<<std::endl;
    }
    virtual void func()
    {
        std::cout<<"A funct. "<<std::endl;
    }
    virtual ~A()
    {
        std::cout<<"A destroyed. "<<std::endl;
    }

};

class B : public A
{
    public: 
    B()
    {
        std::cout<<"B constructed. "<<std::endl;
    }
    void func()
    {
        std::cout<<"B funct. "<<std::endl;
    }
     ~B()
    {
        std::cout<<"B destroyed. "<<std::endl;
    }
};

int main()
{

    B b;
    A& a= b;
    a.func();
}