#include <fstream>
#include <string> 
#include <vector>
std::vector<std::string> parseCsv(std::string fileName){
    std::ifstream fileToRead;
    std::vector<std::string> output;
    fileToRead.open(fileName);
    if(fileToRead.is_open())
    {

        std::string line;
        while(std::getline(fileToRead,line,','))
        {
            output.push_back(line);
        }
        fileToRead.close();
    }
    return output;
}
int main()
{
    
}