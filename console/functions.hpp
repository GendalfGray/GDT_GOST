#pragma once

#include <vector>
#include <iostream>
#include <string>

void getFitResults(std::string, std::string, std::string);
void printHelp();
void printResults(std::vector<std::string>);
void findTolerance(std::vector<std::string>, int = 5);

double calcRoughness(double, double);

std::vector<std::string> fetchResults(std::string, std::string);
