#include <iostream>
#include <array>

#include "func.cpp"

int main()
{

    std::string userInput;
    std::cin >> userInput;

    std::array<std::string, 2> n;

    n = sliceSizeAndField(userInput);

    printResults(n[0], n[1]);

    return 1;
}