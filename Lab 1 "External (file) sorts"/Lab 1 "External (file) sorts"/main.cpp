//
//  main.cpp
//  Lab 1 "External (file) sorts"
//
//  Created by Antony Miroshnichenko on 20.02.2024.
//



#include "Funcs.hpp"



int main()
{
    
    const int P = 1;     // Параметр, отвечающий за выбор алгоритма выбора отрезков (0 - прямое слияние, 1 - естественное слияние)
    
    std::string fileName = "A.txt";
    const int numbersCount = 10;
    const int maxNumberValue = 100;
    
    switch (P) {
        case 0:
            std::cout << "-----// Прямое слияние //-----" << std::endl;
            break;
            
        case 1:
            std::cout << "-----// Естественное слияние //-----" << std::endl;
            break;
            
        default:
            break;
    }

    for (int i = 0; i < 10; i++) {
        
        switch (createAndSortFile(fileName, numbersCount, maxNumberValue, P)) {
                
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
