#pragma once
#include <memory>
#include <string>
class Foo
{
    public: 
    //constructor
    Foo( int bufferSize ){

    }

    ~Foo()
    {

    }

    uint8_t * buffer()
    {
        return m_buffer;
    }

    void setBufferSize(unsigned int size)
    { 
        m_bufferSize= size;
    }
  

    unsigned int bufferSize()
    {
        return m_bufferSize;
    }
    
    //copy constructor
    Foo(const Foo & foo)
    {
        delete [] m_buffer; 
        std::memcpy(m_buffer, foo.m_buffer,foo.m_bufferSize);
    }
    //copy assignment 
    Foo & operator=(const Foo & foo)
    {
        if(&foo == this)
            return *this;
        delete [] m_buffer; 
        m_buffer= foo.m_buffer;
        m_bufferSize=foo.m_bufferSize;
        return *this;
    }

    //move constructor
    Foo( Foo &&foo)
    {

        m_buffer= foo.m_buffer;
        m_bufferSize=foo.m_bufferSize;
        foo.m_buffer = nullptr;
        foo.m_bufferSize=0;
        
    }

    Foo& operator=( Foo &&foo)
    {
        if(&foo ==this)
            return *this;
        
        delete [] m_buffer;
        m_bufferSize= foo.m_bufferSize;
        m_buffer = foo.m_buffer;
        foo.m_buffer = nullptr;
        foo.m_bufferSize=0;
        return *this;
    }

    private: 

    uint8_t * m_buffer;
    unsigned int m_bufferSize; 
};

