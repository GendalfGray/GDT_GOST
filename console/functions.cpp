#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "tol_fields.hpp"
#include "functions.hpp"

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

std::vector<std::string> fetchResults(std::string size, std::string userTolField)
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

void getFitResults(std::string size, std::string field_1, std::string field_2)
{

    std::vector<std::string> fit_1 = fetchResults(size, field_1);
    std::vector<std::string> fit_2 = fetchResults(size, field_2);

    // return std::vector<std::string>{size, toleranceFieldInFile, top_tol, bottom_tol};

    // first bottom field value more or equal to top field value of second
    if (std::stof(fit_1[3]) >= std::stof(fit_2[2]))
    {
        std::cout << "Free fit." << "\n";
        return;
    }

    if (std::stof(fit_2[2]) >= std::stof(fit_1[3]) && std::stof(fit_2[3]) >= std::stof(fit_1[3]))
    {

        std::cout << "Press fit.";
        return;
    }

    std::cout << "In the middle fit.";
};

void printHelp()
{
    std::cout << "For exit press Ctrl + C\n";
    std::cout << "For tolerance field type: field 40 H7, field 20 g6 etc.\n";
    std::cout << "For fit type: fit 40 H7 g6, fit 20 K7 m6 etc.\n";
}

void findTolerance(std::vector<std::string> fieldToFind, int numberOfResults)
{
    double size, top_tolField, bot_tolField;

    std::vector<char> answers;
    
    try
    {
        size = std::stod(fieldToFind.at(1));
        top_tolField = std::stod(fieldToFind.at(2));
        bot_tolField = std::stod(fieldToFind.at(3));

        for (int i = 1; i <= numberOfResults; i++)
        {
            for (std::string toleranceValue : TOL_FIELDS)
            {
                std::string toleranceFieldInFile;
                std::string min_size, max_size, top_tol, bottom_tol;
                // "H7, 18, 30, +0.0210, 0"
                std::stringstream inFileString(toleranceValue);

                getline(inFileString, toleranceFieldInFile, ',');
                getline(inFileString, min_size, ',');
                getline(inFileString, max_size, ',');

                if (std::stod(min_size) <= size && std::stod(max_size) > size)
                {
                    getline(inFileString, top_tol, ',');
                    getline(inFileString, bottom_tol, ',');

                    if (top_tolField <= std::stod(top_tol) && bot_tolField >= std::stod(bottom_tol))
                    {
                        // if letter of field H, JS etc. in - skip.
                        if (std::find(answers.begin(), answers.end(), toleranceFieldInFile[0]) != answers.end())
                        {
                            continue;
                        }
                        else{
                            answers.push_back(toleranceFieldInFile[0]);
                            std::cout << i << ". " << toleranceFieldInFile << "\n";
                            break;
                        }
                        
                    }
                }
            }
        }
    }
    catch (const std::out_of_range& oor) 
    {
        
    }
    
}