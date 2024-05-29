//
//  Hash.hpp
//  Lab 6 "Hash"
//
//  Created by Antony Miroshnichenko on 28.05.2024.
//

#pragma once

#include <iostream>
#include <string>

class Hash
{
public:
    class tableElement;
    
public:
    Hash();
    Hash(int n);
    Hash(const Hash& other);
    ~Hash();
    
    Hash operator = (const Hash& other);
    
    bool add(int key, std::string string);
    bool remove(int key);
    
    bool inTable(int key);
    
private:
    tableElement* m_table = nullptr;
    int m_size;
};


struct Hash::tableElement
{
    int key = 0;
    std::string data = "";
    bool hasValue = false;
    tableElement* next = nullptr;
};
