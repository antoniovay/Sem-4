//
//  main.cpp
//  Lab 1 "External (file) sorts"
//
//  Created by Antony Miroshnichenko on 20.02.2024.
//



#include "Funcs.hpp"



int main()
{
    
    enum SortType {
        
        DirectMerge,
        NaturalMerge
        
    };
    
    const SortType sortType = SortType::NaturalMerge;
    
    std::string fileName = "A.txt";
    const int numbersCount = 1000;
    const int maxNumberValue = 100000;
    
    switch (sortType ) {
        case SortType::DirectMerge:
            std::cout << "-----// Прямое слияние //-----" << std::endl;
            break;
            
        case SortType::NaturalMerge:
            std::cout << "-----// Естественное слияние //-----" << std::endl;
            break;
            
        default:
            break;
    }

    for (int i = 0; i < 10; i++) {
        
        switch (createAndSortFile(fileName, numbersCount, maxNumberValue, sortType)) {
                
            case 1:
                std::cout << "Тест пройден." << std::endl;
                break;
                
            case -1:
                std::cout << "Тест провален: невозможно открыть файл." << std::endl;
                break;

            case -2:
                std::cout << "Тест провален: массив не отсортирован." << std::endl;
                break;
                
        }
        
    }

    return 0;
    
}
