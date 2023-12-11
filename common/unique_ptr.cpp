#include "unique_ptr.h"
#include <iostream>
#include <utility>

template <typename T>
unique_ptr<T>::unique_ptr(  unique_ptr<T> && move)
{
    std::cout<<"move constructor called. "<<std::endl;
    resource= move.resource;
    move.resource= nullptr;
}

template <typename T> 
unique_ptr<T> &unique_ptr<T>::operator=(  unique_ptr<T>&& input)
{
    std::cout<<"move assignment operator called. "<<std::endl;
    delete resource ;
    resource= input.resource;
    input.resource= nullptr;
    return *this;
}

int main()
{
    int *tmp = new int(5);
    int *tmp2 = new int(5);

    unique_ptr<int> uPtr(tmp);
    unique_ptr<int> uPtr2(tmp2);

    unique_ptr<int> uPtr3 = std::move(uPtr);
    uPtr2 = std::move(uPtr3);
}