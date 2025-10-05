#pragma once

#include <vector>
#include <iostream>
#include <string>

void getFitResults(std::string, std::string, std::string);
void printHelp();
void printResults(std::vector<std::string>);
void findTolerance(std::vector<std::string>);
void getFitResults(std::string, std::string, std::string);

double calcRoughness(double, double);

std::vector<std::string> fetchTolData(std::string, std::string);
