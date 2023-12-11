#include <iostream>   // std::cout
#include <functional> // std::ref
#include <thread>     // std::thread
#include <future>
#include <iostream>
#include <chrono>
// void function(std::promise<std::string> & promise)
// {
//     promise.set_value("hello");
// }

// void function2(int & a )
// {

// }
// int main()
// {
//     std::promise<std::string> p;
//     auto f = p.get_future();
//     std::thread t(function,std::ref(p));
//     std::cout<<"string value " << f.get()<<std::endl;
//     int a =2;
//     std::thread t2(function2,std::ref(a));
//     t.join();
//     t2.join();
// }

void function(std::promise<int> &dataToFill)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "fill data with " << 10 << std::endl;
    dataToFill.set_value(10);
}
void function2(std::future<int> &&data)
{
    int filledData = data.get();
    std::cout << "filled data " << filledData << std::endl;
}
int main()
{
    std::promise<int> dataToBeFilled;
    std::future<int> futureData = dataToBeFilled.get_future();
    std::thread t1(function, std::ref(dataToBeFilled));
    std::thread t2(function2, std::move(futureData));
    t1.join();
    t2.join();
}

