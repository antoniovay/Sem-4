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
    table.add(11, "tri");
    table.add(59, "chetyire");
    table.add(60, "pyat");
    
    table.remove(59);
    
    table.changeFunction(&function2);
    
    table.add(59, "desyat");
}
