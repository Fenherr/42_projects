#include <iostream>
#include "Array.hpp"

#define MAX_VAL 42
int main()
{
    Array<int> test2(MAX_VAL);
    Array<int> test3(5);
        
    Array<std::string> test4(4);
        
    for (unsigned int  i = 0; i < test2.size(); i++)
        test2[i] = i;
            
    std::cout << "Int array test: " << test2 << std::endl;
        
    test3 = test2;
        
    std::cout << "Int array test 2: " << test3 << std::endl;
        
    try
    {
        std::cout << "Valid index: " << test2[4] << std::endl;
        std::cout << "Invalid index: " << test2[MAX_VAL] << std::endl;
    }
    catch(const Array<int>::OutOfBoundsException& e)
    {
        std::cout << e.what() << std::endl;
    }
        
    for (unsigned int i = 0; i < test4.size(); i++)
        test4[i] = "Bonjour";
        
    std::cout << "String array test: " << test4 << std::endl;
}
