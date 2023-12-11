#pragma once
template <typename T> 
class unique_ptr {
    public: 
    //constructor
    unique_ptr( T * ptr): resource(ptr)
    {

    }

    //destructor
    ~unique_ptr()
    {
        delete resource;
    }
    unique_ptr( unique_ptr<T> && );//move constructor.

    unique_ptr(const unique_ptr<T> & ) = delete;//object is not copyable
    unique_ptr<T> & operator= ( unique_ptr<T> &&);//move assignment.

    unique_ptr<T> & operator= (const unique_ptr<T> &)= delete;//object is not copy assignable.

    T & operator *()
    {
        return *resource;
    }
    
    T* operation &()
    {
        return resource;
    }
    private: 
        T * resource;

};