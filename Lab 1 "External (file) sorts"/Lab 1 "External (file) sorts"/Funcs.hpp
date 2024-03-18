//
//  Funcs.hpp
//  Lab 1 "External (file) sorts"
//
//  Created by Antony Miroshnichenko on 20.02.2024.
//



#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>



bool createFileWithRandomNumbers (const std::string& fileName, const int numbersCount, const int maxNumberValue);

bool isFileContainsSortedArray (const std::string& fileName);

void mergeDirect (const std::string filenameIn1, const std::string filenameIn2, const std::string filenameOut1, const std::string filenameOut2, int size);

void split (const std::string& filenameIn, const std::string& filenameOut1, const std::string& filenameOut2);

bool check (const std::string& filenameIn1, const std::string& filenameIn2, const std::string& filenameIn3, const std::string& filenameIn4);

void print (const std::string& filename);

std::string sorted (const std::string& filename1, const std::string& filename2, const std::string& filename3, const std::string& filename4);

void sortFile (const std::string& fileName);

int createAndSortFile (const std::string& fileName, const int  numbersCount, const int maxNumberValue);
