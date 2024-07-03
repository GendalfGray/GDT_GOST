#include <iostream>
#include <array>
#include <sstream>

#include "functions.hpp"

int main()
{
    while (true)
    {
        std::string userInput;
        std::getline(std::cin, userInput);

        std::stringstream userInputStream(userInput);
        std::string word;

        std::vector<std::string> slicedUserInput;

        while (getline(userInputStream, word, ' '))
        {
            slicedUserInput.push_back(word);
        }

        if (slicedUserInput[0] == "help")
        {
            printHelp();
            continue;
        }

        if (slicedUserInput[0] == "find")
        {
            findTolerance(slicedUserInput);   
            continue;
        }

        if (slicedUserInput[0] == "field")
        {
            if (slicedUserInput.size() <= 2)
            {
                std::cout << "Not enough arguments. Type: field <size> <tolerance field>." << "\n";
                continue;
            }
            printResults(fetchResults(slicedUserInput[1], slicedUserInput[2]));
        }

        if (slicedUserInput[0] == "fit")
        {

            if (slicedUserInput.size() <= 3)
            {
                std::cout << "Not enough arguments. Type: field <size> <hole tolerance field> <shaft tolerance field>." << "\n";
                continue;
            }

            std::string size = slicedUserInput[1];
            std::string field_1 = slicedUserInput[2];
            std::string field_2 = slicedUserInput[3];

            getFitResults(size, field_1, field_2);
        }
    }

    return 1;
}