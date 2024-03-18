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


void split4d (const std::string& fnameIn, const std::string& fnameOut1, const std::string& fnameOut2);

void merge4d (const std::string fnameIn1, const std::string fnameIn2, const std::string fnameOut1, const std::string fnameOut2, int size);


void split4n (const std::string& fnameIn, const std::string& fnameOut1, const std::string& fnameOut2);

void merge4n (const std::string fnameIn1, const std::string fnameIn2, const std::string fnameOut1, const std::string fnameOut2, int size);


bool check (const std::string& fnameIn1, const std::string& fnameIn2, const std::string& fnameIn3, const std::string& fnameIn4);

void print (const std::string& fileName);

std::string sorted (const std::string& fname1, const std::string& fname2, const std::string& fname3, const std::string& fname4);

void sortFile (const std::string& fileName, const int p);

int createAndSortFile (const std::string& fileName, const int  numbersCount, const int maxNumberValue, const int p);
