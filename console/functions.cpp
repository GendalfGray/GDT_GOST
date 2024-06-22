#include <iostream>
#include <sstream>
#include <vector>

#include "tol_fields.hpp"
#include "functions.hpp"

// Slice size from field values
std::vector<std::string> sliceSizeAndField(std::string userInput)
{
    std::string size = "blank";
    std::string field = "blank";

    for (char letter : userInput)
    {
        // ASCII char A...90
        if (letter >= 65 && letter <= 90)
        {
            int letterIndex = userInput.find(letter);

            size = userInput.substr(0, letterIndex);
            field = userInput.substr(letterIndex);
            break;
        }

        // ASCII char a...z
        if (letter >= 97 && letter <= 122)
        {
            int letterIndex = userInput.find(letter);

            size = userInput.substr(0, letterIndex);
            field = userInput.substr(letterIndex);
            break;
        }
    }
    return std::vector<std::string>{size, field};
}

void printResults(std::vector<std::string> results)
{
    if (results[0] == "nullptr")
    {
        std::cout << "-- " << results[0] << results[1] << " -- \n";
    }

    if (results[2] == "blank" || results[3] == "blank")
    {
        std::cout << "-- " << results[0] << results[1] << " -- \n";
        std::cout << "n/a" << '\n';
        std::cout << "n/a" << '\n';

        std::cout << "Ra: n/a" << '\n';
    }

    std::cout << "-- " << results[0] << results[1] << " -- \n";
    std::cout << results[2] << '\n';
    std::cout << results[3] << '\n';
}

std::vector<std::string> getResults(std::string size, std::string userTolField)
{
    std::string min_size, max_size, top_tol, bottom_tol;
    std::string toleranceFieldInFile;

    if (std::stoi(size) > 3150)
    {
        std::cout << "Size value out of range." << '\n';
        return std::vector<std::string>{nullptr};
    }

    for (std::string toleranceValue : TOL_FIELDS)
    {
        // Check first value first.
        // "H7, 18, 30, +0.0210, 0"
        std::stringstream inFileString(toleranceValue);

        getline(inFileString, toleranceFieldInFile, ',');

        // Follow only of first entry is correct.
        if (toleranceFieldInFile == userTolField)
        {
            getline(inFileString, min_size, ',');
            getline(inFileString, max_size, ',');
            getline(inFileString, top_tol, ',');
            getline(inFileString, bottom_tol, ',');

            if (std::stod(min_size) <= std::stod(size) && std::stod(max_size) > std::stod(size))
            {
                return std::vector<std::string>{size, toleranceFieldInFile, top_tol, bottom_tol};
            }
        }
    }
    std::cout << "Tolerance field value wasn't found." << '\n';
    return std::vector<std::string>{"nullptr"};
}


void getFitResults(std::string size, std::string field_1, std::string field_2) {

    std::vector<std::string> fit_1 = getResults(size, field_1);
    std::vector<std::string> fit_2 = getResults(size, field_2);

    // return std::vector<std::string>{size, toleranceFieldInFile, top_tol, bottom_tol};

    // first bottom field value more or equal to top field value of second
    if (std::stof(fit_1[3]) >= std::stof(fit_2[2]))
    {
        std::cout << "Free fit." << "\n";
        return;
    }
    
    if (std::stof(fit_2[2]) >= std::stof(fit_1[3]) && std::stof(fit_2[3]) >= std::stof(fit_1[3])){
        
        std::cout << "Press fit.";
        return;
    }

    std::cout << "In the middle fit.";

};

void printHelp()
{
    std::cout << "For exit press Ctrl + C\n";
    std::cout << "For tolerance field type: 40H7, 20g6 etc.\n";
    std::cout << "For fit type: 40H7/g6, 20K7/m6 etc.\n";
}