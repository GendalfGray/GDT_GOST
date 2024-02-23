#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <math.h>

double roughness(double, double);

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
        std::cout << "Type field H7, h5, g6 ect.\n";
        std::cin >> tol_field;
        std::cout << "Size in mm:\n";
        std::cin >> size;

        try
        {
            double doub_size = std::stod(size);
            if (doub_size > 3145)
            {
                std::cout << "Size is too big"
                          << "\n\n";
            }
        }
        catch (std::invalid_argument)
        {
            std::cout << "Wrong size!\n\n";
        }

        std::ifstream work_file("../all.csv");
        std::string line;

        while (getline(work_file, line))
        {
            std::stringstream tol_value(line);
            std::string tol_field_in_file, min_size, max_size, top_tol, bottom_tol;
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
                    
                    if (top_tol == "blank" || bottom_tol == "blank")
                    {
                        std::cout << "Roughness: " << "0\n";
                        std::cout << "_____________" << '\n';
                    }
                    else{
                        std::cout << "Roughness: " << roughness(std::stod(top_tol), std::stod(bottom_tol)) << "\n";
                        std::cout << "_____________" << '\n';
                    }
                }
            }
        }

        work_file.close();
    }
}



double roughness(double top_tol, double bot_tol){
    
    if (top_tol > 0 && bot_tol > 0){
        double tol_size = fabs(top_tol - bot_tol) * 1000;
        return tol_size * 0.066;
    }
    else if (top_tol < 0 && bot_tol < 0){
        double tol_size = fabs(fabs(top_tol) - fabs(bot_tol)) * 1000;
        return tol_size * 0.066;
    }

    else if (top_tol < 0 && bot_tol > 0 ||
        top_tol > 0 && bot_tol < 0){
        double tol_size = (fabs(top_tol) + fabs(bot_tol)) * 1000;
        return tol_size * 0.066;
    }
    else{
        double tol_size = fabs(top_tol - bot_tol) * 1000;
        return tol_size * 0.066;
    }
    return -1.0;
}