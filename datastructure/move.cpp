#include <future>
#include <string>
#include <thread>
#include <iostream>
#include <memory>
void function(std::promise<std::string> & promise)
{
    promise.set_value("hello");
}
class Object
{
    public:
    Object()
    {

    }
    Object( const Object & toCopy)
    {
        std::cout<<"Object copied"<<std::endl;
    }
    ~Object()
    {
        std::cout<<"Object destructor"<<std::endl;
    }
    int count =0;
};

void function2(Object && obj)
{
    std::cout<<"calling function 2"<<std::endl;
    return;
}


int main()
{
    // std::promise<std::string> p;

    // auto f = p.get_future();

    // std::thread t(function,p);
    //std::cout<<"string value " << f.get()<<std::endl;
    //t.join();

    Object obj;
    function2(std::move(obj));
    std::cout<<"end of function two. "<<std::endl;
    std::shared_ptr<Object> ptr= std::shared_ptr<Object>(new Object());
    ptr->count=2;
    auto ptr2 = ptr;
    ptr->count=3;
    auto ptr4= ptr;
    auto ptr3 = std::move(ptr2);
    std::cout<<"use count2 "<<ptr2.use_count() <<std::endl;
    std::cout<<"use count1 "<<ptr.use_count() <<std::endl;
    std::cout<<"use count3 "<<ptr3.use_count() <<std::endl;

    Object *objPtr= new Object();

    Object obj2 = std::move(*objPtr);
}