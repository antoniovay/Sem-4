//
//  HashTable.hpp
//  HashTableVector
//
//  Created by Antony Miroshnichenko on 28.06.2024.
//

#ifndef IS_TEMPLATE_HASH_TABLE_DECLARED
#define IS_TEMPLATE_HASH_TABLE_DECLARED

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <list>

class IHashFunction 
{
public:
    virtual ~IHashFunction() = default;
    virtual IHashFunction *clone() const = 0;
    virtual int hash(const int key, const int m_size) const = 0;
};


class FirstHashFunction : public IHashFunction
{
public:
    ~FirstHashFunction() override = default;

    int hash(const int key, const int m_size) const override {
        int H = key % m_size;
        return (H + c + d) % m_size;
    }

    IHashFunction* clone() const override {
        return new FirstHashFunction(*this);
    }

private:
    static constexpr int c = 5;
    static constexpr int d = 7;
};

class SecondHashFunction : public IHashFunction 
{
public:
    ~SecondHashFunction() override = default;

    int hash(const int key, const int m_size) const override {
        static double a = (1 - std::sqrt(5)) / 2;
        
        return static_cast<int>(std::abs(key * a)) % m_size;
    }

    IHashFunction* clone() const override {
        return new SecondHashFunction(*this);
    }
};

class ThirdHashFunction : public IHashFunction {
public:
    ~ThirdHashFunction() override = default;

    int hash(const int key, const int m_size) const override {
        int H = key % m_size;
        return (H + i * (1 + key % (m_size - 2))) % m_size;
    }

    IHashFunction* clone() const override {
        return new ThirdHashFunction(*this);
    }

private:
    const int i = 1;
};


template <typename Type>
struct tableElement
{
    int m_key;
    Type m_data;
   
    tableElement(int key, const Type &data)
        : m_key(key),
          m_data(data)
    {}
};


template <typename Type>
class HashTable
{
public:
    struct tableElement;

public:

    HashTable();
    HashTable(const int size, IHashFunction* function);
    HashTable(const HashTable &other);
    ~HashTable();
    
    HashTable& operator =(const HashTable& other);

    void add(const int key, const Type& value);
    bool remove(const int key);
    
    bool inTable(const int key) const;
    void changeFunction(IHashFunction* newHashFunction);

    int size() const;
    void resize(const int size);
    void clear();
    
    friend std::ostream &operator <<(std::ostream &stream, const HashTable &object);
    

    Type &operator [](const int key);
    
    friend class HashTableWidget;
    
private:
    std::vector<std::list<tableElement>> m_table;
    int m_size;
    IHashFunction *m_function;
    
};

#include "HashTable.cpp"

#endif
