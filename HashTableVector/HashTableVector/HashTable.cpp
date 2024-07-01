//
//  HashTable.cpp
//  HashTableVector
//
//  Created by Antony Miroshnichenko on 28.06.2024.
//

#ifndef ARE_TEMPLATE_HASH_TABLE_METHODS_DEFINED
#define ARE_TEMPLATE_HASH_TABLE_METHODS_DEFINED

#include "HashTable.hpp"


template <typename Type>
HashTable<Type>::HashTable()
    : m_size(10),
      m_table(10),
      m_function(new FirstHashFunction())
{}

template <typename Type>
HashTable<Type>::HashTable(const int size, IHashFunction *function)
    : m_size(size),
      m_table(size),
      m_function(function->clone()) 
{}

template <typename Type>
HashTable<Type>::HashTable(const HashTable &other)
    : m_size(other.m_size),
      m_table(other.m_table),
      m_function(other.m_function->clone()) 
{}

template <typename Type>
HashTable<Type>::~HashTable() {
    delete m_function;
}

template <typename Type>
HashTable<Type> &HashTable<Type>::operator =(const HashTable &other) {
    if (this != &other) {
        delete m_function;
        m_size = other.m_size;
        m_table = other.m_table;
        m_function = other.m_function->clone();
    }
    return *this;
}

template <typename Type>
void HashTable<Type>::add(const int key, const Type &data) {
    if (inTable(key))
        return;

    int index = m_function->hash(key, m_size);
    m_table[index].push_back(tableElement(key, data));
}

template <typename Type>
bool HashTable<Type>::remove(const int key) {
    int index = m_function->hash(key, m_size);

    for (auto it = m_table[index].begin(); it != m_table[index].end(); it++) {
        if (it->m_key == key) {
            m_table[index].erase(it);
            return true;
        }
    }
    return false;
}

template <typename Type>
bool HashTable<Type>::inTable(const int key) const {
    int index = m_function->hash(key, m_size);
    for (const auto& tabElem : m_table[index]) {
        if (tabElem.m_key == key) {
            return true;
        }
    }
    return false;
}

template <typename Type>
void HashTable<Type>::changeFunction(IHashFunction *function) {
    if (!function || m_function == function) {
        return;
    }

    delete m_function;
    m_function = function->clone();
    resize(m_size);
}

template <typename Type>
void HashTable<Type>::print() const {
    for (int i = 0; i < m_size; i++) {
        std::cout << i << ": ";
        for (const auto &tabElem : m_table[i])
            std::cout << "(" <<
                    tabElem.m_key << ", " <<
                    tabElem.m_data << ") ";
        std::cout << std::endl;
    }
}

template <typename Type>
void HashTable<Type>::resize(const int size) {
    std::vector<std::list<tableElement>> newTable(size);
    for (const auto &list : m_table) {
        for (const auto& tabElem : list) {
            int index = m_function->hash(tabElem.m_key, size);
            newTable[index].push_back(tabElem);
        }
    }
    m_table.swap(newTable);
    m_size = size;
}

template <typename Type>
void HashTable<Type>::clear() {
    for (auto &list : m_table) {
        list.clear();
    }
}

template <typename Type>
Type &HashTable<Type>::operator [](const int key) {
    int index = m_function->hash(key, m_size);

    for (auto &tabElem : m_table[index]) {
        if (tabElem.m_key == key) {
            return tabElem.m_data;
        }
    }
    
    return m_table[index].back().m_data;
}



#endif
