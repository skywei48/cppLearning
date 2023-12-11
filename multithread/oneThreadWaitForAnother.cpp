#include <condition_variable>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
std::mutex lock;

std::condition_variable cv;

bool dataReady = false; 
void task1()
{
    std::unique_lock<std::mutex> ul(lock);
    cv.wait(ul, []{ 
        std::cout<<"still wait for data"<<std::endl;
        return dataReady;});
    std::cout<<"consume data"<<std::endl;
}

void task2()
{
    std::lock_guard<std::mutex> l(lock);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout<<"data ready "<<std::endl;
    dataReady= true;
    cv.notify_one();
}
int main()
{
    std::thread t1(task1);
    std::thread t2(task2);
    t1.join();
    t2.join();
}