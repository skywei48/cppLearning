
#include <iostream>
#include <vector>
void printArray(std::vector<int> &array,int left, int right)
{
    while(left <=right)
    {
        std::cout<<array[left++] <<" ";
    }
    std::cout<<std::endl;
}
void mergeArray(std::vector<int> & array, int left,int middle, int right) 
{
    std::cout<<"merge array: "<<"left "<<left <<" right "<< right <<" middle "<<middle<<std::endl;
    int temp= 0; 
    int rightPtr=middle+1;
    int leftPtr= left;
    int arraySize= right-left+1;
    int tempArray[right-left+1];
    
    printArray(array,left,right);

    while(rightPtr<=right &&leftPtr<=middle)
    {
        if(array[leftPtr]<array[rightPtr])
        {
            tempArray[temp++]= array[leftPtr++];
        }
        else
        {
            tempArray[temp++]= array[rightPtr++];
        }
    }
    while(rightPtr<=right)
    {
        tempArray[temp++]= array[rightPtr++];
    }
    while(leftPtr<=middle)
    {
        tempArray[temp++]= array[leftPtr++];
    }


    for (int i=0; i<arraySize;i++)
    {
        array[i+left] = tempArray[i];
    }
    printArray(array,left,right);
    std::cout<<"hello "<<std::endl;
}

void mergeSortHelper(std::vector<int> &array, int left, int right)
{
    if(left >=right)
    {
        return ;
    }
    int middle = left+(right-left)/2;
    mergeSortHelper(array,left,middle);
    mergeSortHelper(array,middle+1,right);
    mergeArray(array,left,middle,right);
}

void mergeSort(std::vector<int> &array )
{
    int left =0;
    int right = array.size()-1;
    mergeSortHelper(array,left,right);
}

int main()
{
    std::vector<int> array= {1,10,3,4,15,3};
    mergeSort(array);
    printArray(array,0,array.size()-1);
}




