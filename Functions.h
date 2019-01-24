#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Functions.h"

void readList(std::vector<int> &list, std::string fileName);
void bubbleSort(std::vector<int> &list);

void merge(std::vector<int> &list, int upperBound, int middleBound, int lowerBound, int &comparisons, int &assignments);
void mergeSort(std::vector<int> &list, int upperBound, int lowerBound, int &comparisons, int &assignments);

void indexSort(std::vector<int> &list);

#endif
