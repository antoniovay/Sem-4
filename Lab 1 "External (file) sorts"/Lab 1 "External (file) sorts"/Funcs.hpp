//
//  Funcs.hpp
//  Lab 1 "External (file) sorts"
//
//  Created by Antony Miroshnichenko on 20.02.2024.
//



#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <assert.h>



bool isFileContainsSortedArray (const std::string &fileName);

void scanFile(const char *name);

void printFile (const char *name);

void split (const char *name, const char *name1, const char *name2);

void merger (const char *name, const char *name1, const char *name2);

void sort3f(const char *name);
