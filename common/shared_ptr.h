

#include <utility>
#include <iostream>
template <typename T>
class shared_ptr{
    public: 
    shared_ptr(T* input): resource(input)
    {
        instanceCount  =new int(0);
    }

    ~shared_ptr() 
    {
       remove();
    }

    //copy constructor

    shared_ptr(shared_ptr<T> & toBeCopied)
    {
        std::cout<<"copy constructor called "<<std::endl;
        if(&toBeCopied==this)
            return;
        resource = toBeCopied.resource;
        instanceCount = toBeCopied.instanceCount;
        *instanceCount =*instanceCount +1;
    }

    void remove()
    {
        *instanceCount = *instanceCount -1;
        if((*instanceCount) == 0)
        {
            delete resource;
            delete instanceCount;
        }
    }
    shared_ptr<T>& operator = (shared_ptr<T>& toBeCopied)
    {
        std::cout<<"copy assignment called "<<std::endl;
        if(&toBeCopied!=this)
        {
            shared_ptr<T> tmp = toBeCopied;
            swap(tmp,toBeCopied);
        }
        
        return *this;
    }
    void swap(shared_ptr<T>& l, shared_ptr<T>& r)
    {
        std::swap(l.resource,r.resource);
        std::swap(r.instanceCount,l.instanceCount);
    }

    T & operator *();

    T* operator &();

    shared_ptr(shared_ptr<T>  &&);

    shared_ptr<T> & operator =(shared_ptr<T> &&);



    private: 
    T * resource; 
    int * instanceCount=nullptr; 
};