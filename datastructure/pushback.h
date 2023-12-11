#pragma once
#include <memory>
#include <string>

template <typename T> 
class vector
{
    public:
        vector()
        {
            storage = new T[arraySize];

        }
        ~vector()
        {
            delete [] storage;
        }
        vector( vector<T> & copy)= default;

        vector<T>& operator=(vector<T> & copy) =default;

        void push_back(T& itemToAdd)
        {
            if(currentElementIndex==arraySize)
            {
                //we need to resize
                int newSize= arraySize*2;
                T * newContainer = new T[newSize];
                for(int index=0 ; index < currentElementIndex; ++index)
                {
                    *(newContainer+index) = *(storage+index);
                }
                delete [] storage;
                currentElementIndex= arraySize;
                arraySize= newSize;
                storage = newContainer;
            }
            else
            {
                *storage[currentElementIndex++]= itemToAdd;
            }

        }
    private:
        T * storage=nullptr;
        int currentElementIndex=0;
        int arraySize=1;
        
};