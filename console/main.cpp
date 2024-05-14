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
        }
        // if '/' wasn't found
        if (userInput.find('/') == std::string::npos)
        {
            std::vector<std::string> sizeAndTolField = sliceSizeAndField(userInput);
            std::cout << sizeAndTolField[0] << '\n';
            std::cout << sizeAndTolField[1] << '\n';
            printResults(getResults(sizeAndTolField[0], sizeAndTolField[1]));
        }
        else
        {
            std::vector<std::string> sizeAndFit = sliceSizeAndField(userInput);
            getFitResults(sizeAndFit[0], sizeAndFit[1]);
        }
    }

    return 1;
}