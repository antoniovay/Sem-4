//
//  Hash.hpp
//  Lab 6 "Hash"
//
//  Created by Antony Miroshnichenko on 28.05.2024.
//

#pragma once

#include <iostream>
#include <string>
#include <assert.h>


class IHashFunction
{
public:
    virtual int operator()(int, int, int) = 0;
    virtual IHashFunction *clone() const {return nullptr;}
};



class FirstHashFunction : public IHashFunction
{
public:

    int operator()(int N, int K, int i) override
    {
        assert(i >= 0);
        if (i == 0)
            return K % N;
        else
            return (operator()(N, K, i - 1) + c * i + d * i * i) % N;
            //return ((K % N) + 25 % 5 + 25 % 7) % N;
    }
    
    IHashFunction* clone() const override {
            return new FirstHashFunction(*this);
    }

private:
    const int c = 5;
    const int d = 7;
};



class SecondHashFunction : public IHashFunction
{
public:

    int operator()(int N, int K, int i) override
    {
        assert(i >= 0);
        if (i == 0)
            return K % N;
        else
            return static_cast<int>(operator()(N, K, i - 1) * a * N) % N;
    }
    
    IHashFunction* clone() const override {
            return new SecondHashFunction(*this);
    }

private:
    const double a = 0.6180339887498948;
};



class ThirdHashFunction : public IHashFunction
{
public:

    int operator()(int N, int K, int i) override
    {
        assert(i >= 0);
        if (i == 0)
            return K % N;
        else if (i > 0)
            return ((K % N) + i * (1+ K % (N - 2))) % N;
        else return 0;
    }
    
    IHashFunction* clone() const override {
            return new ThirdHashFunction(*this);
    }
    
};







class HashTable
{
public:
    struct tableElement;
//    class Pair;
    
public:
    HashTable();
    HashTable(int n);
    HashTable(const HashTable &other);
    ~HashTable();
    
    HashTable& operator =(const HashTable &other);
    
    bool add(int key, std::string string);
    bool remove(int key);
    
    bool inTable(int key);
    void changeFunction(IHashFunction *newFunction);
    
    void resize(const int size);
    
    friend std::ostream &operator <<(std::ostream &stream, const HashTable &object);
    
private:
    tableElement* m_table = nullptr;
    int m_size;
    IHashFunction* m_function;
};


struct HashTable::tableElement
{
    int key = 0;
    std::string data = "";
    bool hasValue = false;
    tableElement* next = nullptr;
};





