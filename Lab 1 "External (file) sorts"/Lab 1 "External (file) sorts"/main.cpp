//
//  main.cpp
//  Lab 1 "External (file) sorts"
//
//  Created by Antony Miroshnichenko on 20.02.2024.
//



#include "Funcs.hpp"



int main()
{
    std::string fileName = "A.txt";
    const int numbersCount = 1000000;
    const int maxNumberValue = 100000;

    for (int i = 0; i < 10; i++) {
        
        switch (createAndSortFile(fileName, numbersCount, maxNumberValue)) {
                
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
