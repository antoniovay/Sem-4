//
//  main.cpp
//  Lab 5 "Huffman Code"
//
//  Created by Antony Miroshnichenko on 23.05.2024.
//

#include <iostream>

#include "Huffman.hpp"

int main() {
    
    Huffman code;

    std::cout << code.encode("input.txt", "output.txt") << std::endl;

    code.decode("output.txt", "decode.txt");
    
}
