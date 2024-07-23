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
        std::cout << "n/a\n";
        std::cout << "n/a\n";

        std::cout << "Ra: n/a\n";
    }

    std::cout << "-- " << results[0] << results[1] << " -- \n";
    std::cout << results[2] << '\n';
    std::cout << results[3] << '\n';
}

void printFitResults(std::string fitType,
                     std::string size,
                     std::string fitOneField,
                     std::vector<std::string> fitOneData,
                     std::string fitTwoField,
                     std::vector<std::string> fitTwoData)
{
    std::cout << '\n';
    std::cout << fitType << '\n';
    std::cout << "----  " << size << fitOneField << "/" << fitTwoField << "  ----\n";
    std::cout << fitOneData[2] << "\t" << fitTwoData[2] << '\n';
    std::cout << fitOneData[3] << "\t" << fitTwoData[3] << '\n';
}

std::vector<std::string> fetchTolData(std::string size, std::string userTolField)
{
    std::string min_size, max_size, top_tol, bottom_tol;
    std::string toleranceFieldInFile;

    if (std::stoi(size) > 3150)
    {
        std::cout << "Size value out of range.\n";
        return std::vector<std::string>{nullptr};
    }

    for (std::string toleranceValue : TOL_FIELDS)
    {
        // Check first value first.
        // "H7, 18, 30, +0.0210, 0"
        std::stringstream stringFromDataFile(toleranceValue);
        getline(stringFromDataFile, toleranceFieldInFile, ',');

        // Follow only of first entry is correct.
        if (toleranceFieldInFile == userTolField)
        {
            getline(stringFromDataFile, min_size, ',');
            getline(stringFromDataFile, max_size, ',');
            getline(stringFromDataFile, top_tol, ',');
            getline(stringFromDataFile, bottom_tol, ',');

            if (std::stod(min_size) <= std::stod(size) && std::stod(max_size) > std::stod(size))
            {
                return std::vector<std::string>{size, toleranceFieldInFile, top_tol, bottom_tol};
            }
        }
    }
    std::cout << "Tolerance field value wasn't found." << '\n';
    return std::vector<std::string>{"nullptr"};
}

void getFitResults(std::string size,
                   std::string fitOneField,
                   std::string fitTwoField)
{
    std::vector<std::string> fitOneData = fetchTolData(size, fitOneField);
    std::vector<std::string> fitTwoData = fetchTolData(size, fitTwoField);

    // return std::vector<std::string>{size, toleranceFieldInFile, top_tol, bottom_tol};

    // "18, 30, +0.0210, 0"
    // first bottom field value more or equal to top field value of second
    if (std::stof(fitOneData[3]) >= std::stof(fitTwoData[2]))
    {
        printFitResults("Free fit.", size, fitOneField, fitOneData, fitTwoField, fitTwoData);
        return;
    }

    if (std::stof(fitTwoData[2]) >= std::stof(fitOneData[3]) && std::stof(fitTwoData[3]) >= std::stof(fitOneData[2]))
    {
        printFitResults("Press fit.", size, fitOneField, fitOneData, fitTwoField, fitTwoData);
        return;
    }

    printFitResults("In the middle fit.", size, fitOneField, fitOneData, fitTwoField, fitTwoData);
};

void printHelp()
{
    std::cout << "For exit press Ctrl + C.\n";
    std::cout << "For tolerance field type: field <size> <field>: field 40 H7, field 20 g6 etc.\n";
    std::cout << "For fit type: fit <size> <field1> <field2>: fit 40 H7 g6, fit 20 K7 m6 etc.\n";
    std::cout << "To find tolerance field type: find <size> <top tolerance field> <bootom tolerance field>: find H7 10, etc.\n";
}

void findTolerance(std::vector<std::string> dataToFind)
{
    int numberOfResults = 10;

    std::vector<char> answers;

    double size = std::stod(dataToFind.at(1));
    double top_tolField = std::stod(dataToFind.at(2));
    double bot_tolField = std::stod(dataToFind.at(3));

    for (int i = 0; i <= numberOfResults; i++)
    {
        for (std::string toleranceValue : TOL_FIELDS)
        {
            std::string toleranceFieldInFile;
            std::string min_size, max_size, top_tol, bottom_tol;
            // "H7, 18, 30, +0.0210, 0"
            std::stringstream stringFromDataFile(toleranceValue);

            getline(stringFromDataFile, toleranceFieldInFile, ',');
            getline(stringFromDataFile, min_size, ',');
            getline(stringFromDataFile, max_size, ',');

            // std::cout << toleranceFieldInFile << '\n';
            if (std::stod(min_size) <= size && std::stod(max_size) > size)
            {
                getline(stringFromDataFile, top_tol, ',');
                getline(stringFromDataFile, bottom_tol, ',');

                if (top_tol == "blank" || bottom_tol == "blank")
                {
                    continue;
                }

                if (top_tolField <= std::stod(top_tol) && bot_tolField >= std::stod(bottom_tol))
                {
                    // if letter of field H, JS etc. in - skip.
                    if (std::find(answers.begin(), answers.end(), toleranceFieldInFile[0]) != answers.end())
                    {
                        continue;
                    }
                    else
                    {
                        answers.push_back(toleranceFieldInFile[0]);
                        std::cout << i + 1 << ". " << toleranceFieldInFile << "\n";
                        std::cout << "   " << top_tol << " - " << bottom_tol << "\n";
                        break;
                    }
                }
            }
        }
    }
}