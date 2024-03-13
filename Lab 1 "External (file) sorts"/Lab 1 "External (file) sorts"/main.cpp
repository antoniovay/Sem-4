//
//  main.cpp
//  Lab 1 "External (file) sorts"
//
//  Created by Antony Miroshnichenko on 20.02.2024.
//



#include "Funcs.hpp"



int main() {
    
    scanFile("000.txt");
    
    std::cout << "Начальный файл: ";
    printFile ("000.txt");
    

    sort3f("000.txt");
    
    
    std::cout << std::endl << "Отсортированный файл: ";
    printFile ("000.txt");
    
    std::cout << std::endl;
    
}
