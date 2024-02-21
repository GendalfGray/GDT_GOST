#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

int main()
{
    int run = 1;
    std::string tol_field;
    std::string size;

    while (run)
    {
        // Info
        std::cout << "For exit press "
                     "Ctrl + C"
                     "\n";
        std::cout << "H7, h5, g6 ect.\n";
        std::cin >> tol_field;
        std::cout << "Size in mm:\n";
        std::cin >> size;

        try
        {
            int int_size = std::stoi(size);
            if (int_size > 3145)
            {
                std::cout << "Size is too big"
                          << "\n\n";
            }
        }
        catch (std::invalid_argument)
        {
            std::cout << "Wrong size!\n\n";
        }

        // std::stringstream request_stream(tol_field);

        std::ifstream work_file("hole.csv");
        std::string line;

        while (getline(work_file, line))
        {
            std::stringstream tol_value(line);
            std::string tol_field_in_file;
            std::string min_size;
            std::string max_size;
            std::string top_tol;
            std::string bottom_tol;
            getline(tol_value, tol_field_in_file, ',');
            getline(tol_value, min_size, ',');
            getline(tol_value, max_size, ',');
            getline(tol_value, top_tol, ',');
            getline(tol_value, bottom_tol, ',');

            if (tol_field_in_file == tol_field)
            {
                if (std::stoi(min_size) <= std::stoi(size) && std::stoi(max_size) > std::stoi(size))
                {
                    std::cout << "Field " << tol_field_in_file << " for size " << size << ":\n";
                    std::cout << top_tol << '\n';
                    std::cout << bottom_tol << '\n';
                    double field_size = abs(std::stod(top_tol) - std::stod(bottom_tol)) * 100;

                    std::cout << "Roughness: " << 0.066 * field_size << "\n";
                    std::cout << "_____________" << '\n';
                }
            }
        }

        work_file.close();
    }
}