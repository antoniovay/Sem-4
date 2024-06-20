//
//  main.cpp
//  Lab 6 "Hash"
//
//  Created by Antony Miroshnichenko on 28.05.2024.
//

#include <iostream>

#include "Hash.hpp"

int main()
{
    Hash table(5);

    table.add(88, "raz");
    table.add(72, "dva");
    table.add(22, "tri");
    table.add(59, "chetyire");
    table.add(61, "pyat");
    //table.add(22, "qwerty");
    
    std::cout << table << std::endl;
    
    table.remove(59);
    
    std::cout << table << std::endl;
    
    table.changeFunction(new SecondHashFunction);
    
    table.add(59, "desyat");
    
    std::cout << table << std::endl;
    
    return 0;
}
