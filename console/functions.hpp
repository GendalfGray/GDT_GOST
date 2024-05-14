#pragma once

#include <vector>
#include <iostream>
#include <string>

void getFitResults(std::string, std::string);
void printHelp();
void printResults(std::vector<std::string>);

double calcRoughness(double, double);

std::vector<std::string> sliceSizeAndField(std::string);
std::vector<std::string> getResults(std::string, std::string);
