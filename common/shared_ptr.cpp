#include "shared_ptr.h"


template <typename T>
T & shared_ptr<T>::operator * ()
{
    return *resource;
}
template <typename T>
T* shared_ptr<T>::operator&()
{
    return resource;
}


template <typename T> 
shared_ptr<T>::shared_ptr(shared_ptr<T> &&toBeMoved)
{
    std::cout<<"moved constructor called."<<std::endl;
    if(&toBeMoved!= this)
    {
        swap(*this,toBeMoved);
        toBeMoved.instanceCount= nullptr;
        toBeMoved.resource=nullptr;
    }
}

template <typename T> 
shared_ptr<T> & 
shared_ptr<T>::operator=(shared_ptr<T>&& toBeMoved)
{
    std::cout<<"moved assignment called."<<std::endl;
    if(&toBeMoved!=this)
    {
        auto tmp = toBeMoved;
        swap(this,tmp);   
    }
    return *this;
}

