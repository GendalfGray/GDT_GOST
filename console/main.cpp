#include <iostream>
#include <array>

#include "functions.hpp"

int main()
{
    while (true)
    {
        std::string userInput;
        std::cin >> userInput;

        if (userInput == "-help")
        {
            printHelp();
            continue;
        }
        // if '/' wasn't found
        int slash_idx = userInput.find('/');
        if (slash_idx == std::string::npos)
        {
            std::vector<std::string> sizeAndTolField = sliceSizeAndField(userInput);
            //std::cout << sizeAndTolField[0] << '\n';
            //std::cout << sizeAndTolField[1] << '\n';
            printResults(getResults(sizeAndTolField[0], sizeAndTolField[1]));
        }
        else
        {
            //std::cout << slash_idx << '\n';
            
            std::vector<std::string> sizeAndTolField = sliceSizeAndField(userInput.substr(0, slash_idx));
            std::string size       = sizeAndTolField[0];
            std::string field_1    = sizeAndTolField[1];
            std::string field_2    = userInput.substr(slash_idx + 1);
            
            //std::cout << size << '\n';
            //std::cout << field_1 << '\n';
            //std::cout << field_2 << '\n';
            
            getFitResults(size, field_1, field_2);
        }
    }

    return 1;
}