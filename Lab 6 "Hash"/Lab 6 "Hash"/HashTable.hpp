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
#include <vector>


class IHashFunction
{
public:
    virtual int hash(const int key, const int size) const = 0;
    virtual IHashFunction* _clone() = 0;
};



class FirstHashFunction : public IHashFunction
{
public:
    int hash(const int key, const int size) const
    {
        int h0 = key % size;
        return ((h0 + d) % size);
    }
    IHashFunction* _clone()
    {
        FirstHashFunction* temp = new FirstHashFunction;
        return temp;
    }
private:
    const int d = 3;
};



class SecondHashFunction : public IHashFunction
{
public:
    int hash(const int key, const int size) const
    {
        return static_cast<int>((key % size) * (-(1 - sqrt(5)) / 2) * size) % size;
    }

    IHashFunction* _clone()
    {
        SecondHashFunction* temp = new SecondHashFunction;
        return temp;
    }
};



//class ThirdHashFunction : public IHashFunction
//{
//public:
//
//    int operator()(int N, int K, int i) override
//    {
//        assert(i >= 0);
//        if (i == 0)
//            return K % N;
//        else if (i > 0)
//            return ((K % N) + i * (1+ K % (N - 2))) % N;
//        else return 0;
//    }
//    
//    IHashFunction* clone() const override {
//            return new ThirdHashFunction(*this);
//    }
//    
//};


//class SimpleHashFunction : public IHashFunction
//{
//public:
//    int operator() (int size, int key, int /*i*/) override {
//        return key % size;
//    }
//    IHashFunction *clone() const override {
//        return new SimpleHashFunction(*this);
//    }
//} ;






class HashTable
{
public:
    struct tableElement;
    
public:
    HashTable();
    HashTable(int size, IHashFunction* function);
    HashTable(const HashTable &other);
    ~HashTable();
    
    HashTable& operator =(const HashTable &other);
    std::string &operator [](const int key);
    
    bool add(const int key, const std::string &data);
    bool remove(int key);
    
    bool inTable(int key);
    void changeFunction(IHashFunction *newFunction);
    void resize(const int size);
    
private:
    int _findIndex(tableElement* tabElem) const;
    tableElement* _findElement(const int key) const;
    
private:
    friend std::ostream &operator <<(std::ostream &stream, const HashTable &object);
    
private:
    std::vector<tableElement*> m_table;
    int m_size = 0;
    IHashFunction* m_function = nullptr;
};


struct HashTable::tableElement
{
    int m_key = 0;
    std::string m_data = "";
    bool m_hasValue = false;
    tableElement* m_next = nullptr;
    tableElement* m_prev = nullptr;
};





