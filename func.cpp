#include <iostream>
#include <array>
#include <sstream>

#include "data.hpp"

// Slice size from field values
std::array<std::string, 2> sliceSizeAndField(std::string userInput)
{
    std::string size = "none";
    std::string field = "none";

    for (char letter : userInput)
    {
        // ASCII char A 65 ... Z 90
        if (letter >= 65 && letter <= 90)
        {
            int letterIndex = userInput.find(letter);

            size = userInput.substr(0, letterIndex);
            field = userInput.substr(letterIndex);
            break;
        }

        if (letter >= 97 && letter <= 122)
        {
            int letterIndex = userInput.find(letter);

            size = userInput.substr(0, letterIndex);
            field = userInput.substr(letterIndex);
            break;
        }
    }
    return std::array<std::string, 2>{size, field};
}

// Print field values and Ra for size
void printResults(std::string size, std::string field)
{

    for (std::string toleranceValue : tol_fields)
    {
        // Check first value first.
        // "H7, 18, 30, +0.0210, 0"
        std::stringstream inFileString(toleranceValue);
        std::string toleranceFieldInFile;
        getline(inFileString, toleranceFieldInFile, ',');

        // Follow only of first entry is correct.
        if (toleranceFieldInFile == field)
        {
            std::string min_size, max_size, top_tol, bottom_tol;
            getline(inFileString, min_size, ',');
            getline(inFileString, max_size, ',');
            getline(inFileString, top_tol, ',');
            getline(inFileString, bottom_tol, ',');

            if (std::stod(min_size) <= std::stod(size) && std::stod(max_size) > std::stod(size))
            {
                std::cout << "-- " << size << toleranceFieldInFile << " -- \n";
                std::cout << top_tol << '\n';
                std::cout << bottom_tol << '\n';

                if (top_tol == "blank" || bottom_tol == "blank")
                {
                    std::cout << "Ra: "
                              << "0\n";
                    std::cout << "_____________" << '\n';
                    break;
                }
                else
                {
                    // std::cout << "Ra: " << roughness(std::stod(top_tol), std::stod(bottom_tol)) << "\n";
                    std::cout << "Ra here_____________" << '\n';
                    break;
                }
            }
        }
    }
}
