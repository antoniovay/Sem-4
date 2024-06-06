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
    }

private:
    const int c = 5;
    const int d = 3;
} function1;



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

private:
    const double a = 0.6180339887498948;
} function2;



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
    
} function3;



class Hash
{
public:
    class tableElement;
    class Pair;
    
public:
    Hash();
    Hash(int n);
    Hash(const Hash &other);
    ~Hash();
    
    Hash operator =(const Hash &other);
    std::string &operator [](const int key);
    
    bool add(int key, std::string string);
    bool remove(int key);
    
    bool inTable(int key);
    void changeFunction(IHashFunction *newFunction);
    
    friend std::ostream &operator <<(std::ostream &stream, const Hash &object);
    
private:
    tableElement* m_table = nullptr;
    int m_size;
    IHashFunction* m_function;
};


struct Hash::tableElement
{
    int key = 0;
    std::string data = "";
    bool hasValue = false;
    tableElement* next = nullptr;
};



class Hash::Pair
{
    friend class Hash;
    
public:
    Pair(const int key = {}, const std::string& value = {}, Pair* next = nullptr)
        : m_key(key), m_value(value), m_next(next)
    {}

    ~Pair() = default;

    int key() const;
    std::string value() const;

    void setKey(const int key);
    void setValue(const std::string& value);

    Pair* next();
    const Pair* next() const;
    void setNext(Pair* next);

private:
    int m_key = 0;
    std::string m_value = "";

    Pair* m_next = nullptr;
};



std::ostream &operator <<(std::ostream &stream, const Hash &object) {
    for (int i = 0; i < object.m_size; i++) {
        if (object.m_table[i].hasValue)
            stream << i << "\t" << 
            &object.m_table[i] << "\t" <<
            object.m_table[i].next << "\t" <<
            object.m_table[i].key << "\t" <<
            object.m_table[i].data << std::endl;
        else
            stream << i << "\tFree" << std::endl;
    }
    return stream;
}
