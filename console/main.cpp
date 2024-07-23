#include <iostream>
#include <array>
#include <sstream>

#include "functions.hpp"

int main()
{
    std::cout << "For help print: help\n";

    while (true)
    {
        std::string userInput;
        getline(std::cin, userInput);

        std::stringstream userInputStream(userInput);
        std::string userCommand;
        std::string command;

        std::vector<std::string> slicedUserInput;

        while (getline(userInputStream, userCommand, ' '))
        {
            slicedUserInput.push_back(userCommand);
        }

        if (slicedUserInput.size() == 0)
        {
            continue;
        }
        else
        {
            command = slicedUserInput[0];
        }

        if (command == "help")
        {
            printHelp();
            continue;
        }

        if (command == "find")
        {
            findTolerance(slicedUserInput);
            continue;
        }

        if (command == "field")
        {
            if (slicedUserInput.size() <= 2)
            {
                std::cout << "Not enough arguments. Type: field <size> <tolerance field>.\n";
                continue;
            }
            printResults(fetchTolData(slicedUserInput[1], slicedUserInput[2]));
        }

        if (command == "fit")
        {
            if (slicedUserInput.size() <= 3)
            {
                std::cout << "Not enough arguments. Type: field <size> <hole tolerance field> <shaft tolerance field>.\n";
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