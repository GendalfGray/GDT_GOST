#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string filename){
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::pair<std::string, std::vector<int>>> result;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname;

	std::vector<std::string> data;
	std::string word;
	std::string field_tofind;
	int size_tofind;

	std::cout << "What field to find? " << '\n';
	std::cin >> field_tofind;
	std::cout << "What size? " << '\n';
	std::cin >> size_tofind;

    // Read data, line by line
    while(std::getline(myFile, line))
    {
		data.clear();
		std::stringstream str(line);

		// add each element of line to vector
		while(std::getline(str, word, ',')){
			data.push_back(word);
		}
		
		if (field_tofind == data[0]){
			if(std::stoi(data[1]) <= size_tofind && std::stoi(data[2]) > size_tofind){
				std::cout << "Field: " << data[0] << '\n';
				std::cout << "Size: " << "from" << data[1] << " to" << data[2] << '\n';
				std::cout << "Tolerance: " << data[3] << " - " << data[4] << '\n';
			}	
		}
		
    }

    // Close file
    myFile.close();

    return result;
}

int main() {
    
    std::vector<std::pair<std::string, std::vector<int>>> three_cols = read_csv("hole.csv");
    
    return 0;
}
