#include <condition_variable>
#include <mutex>
#include <iostream>
#include <thread>
#include <string>
/**
 * ...........conditional variable.. .......
 * print event and print odd numbers using two threads and 
*/
// std::mutex lock;
// std::condition_variable cv;
// int number =1; 
// void printEven()
// {
//     while(number<=100)
//     {
//         std::unique_lock<std::mutex> ul(lock);
//         cv.wait(ul, []{ return number%2 ==0 ? true: false;});
//         std::cout<<"even number: " << number<<std::endl;
//         ++number;
//         cv.notify_one();
//     }
// }

// void printOdd()
// {
//     while(number<100)
//     {
//         std::unique_lock<std::mutex> ul(lock);
//         cv.wait(ul, []{ return number%2 ==1 ? true: false;});
//         std::cout<<"odd number: " << number<<std::endl;
//         ++number;
//         cv.notify_one();
//     }
// }
// int main ()
// {
//     std::thread t1(printEven);
//     std::thread t2(printOdd);
//     t1.join();
//     t2.join();
// }

std::condition_variable cv;
std::mutex lock;
int num =1;
int max=100;
void printEven()
{
    std::unique_lock<std::mutex> ul(lock);
    while(num<max)
    {
        cv.wait(ul,[]{
            return num%2==0;
        });
        std::cout<<"even number: " << num++<<std::endl;
        cv.notify_one(); 
    }
}

void printOdd()
{
    std::unique_lock<std::mutex> ul(lock);
    while(num<=max)
    {
        cv.wait(ul,[]{return num%2!=0;});
        std::cout<<"odd number: " << num++<<std::endl;
        cv.notify_one();
    }
}
int main()
{
    std::thread t1(printEven);
    std::thread t2(printOdd);
    t1.join();
    t2.join();
}