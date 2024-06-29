//
//  HashTable.cpp
//  HashTableVector
//
//  Created by Antony Miroshnichenko on 28.06.2024.
//

#include "HashTable.hpp"


HashTable::HashTable() 
    : m_size(10),
      m_table(10),
      m_function(new FirstHashFunction())
{}


HashTable::HashTable(const int size, IHashFunction *function)
    : m_size(size),
      m_table(size),
      m_function(function->clone()) 
{}


HashTable::HashTable(const HashTable &other)
    : m_size(other.m_size),
      m_table(other.m_table),
      m_function(other.m_function->clone()) 
{}

HashTable::~HashTable() {
    delete m_function;
}


HashTable& HashTable::operator =(const HashTable &other) {
    if (this != &other) {
        delete m_function;
        m_size = other.m_size;
        m_table = other.m_table;
        m_function = other.m_function->clone();
    }
    return *this;
}

void HashTable::add(const int key, const std::string &data) {
    if (inTable(key))
        return;

    int index = m_function->hash(key, m_size);
    m_table[index].push_back(tableElement(key, data));
}

bool HashTable::remove(const int key) {
    int index = m_function->hash(key, m_size);

    for (auto it = m_table[index].begin(); it != m_table[index].end(); ++it) {
        if (it->m_key == key) {
            m_table[index].erase(it);
            return true;
        }
    }
    return false;
}

bool HashTable::inTable(const int key) const {
    int index = m_function->hash(key, m_size);
    for (const auto& tabElem : m_table[index]) {
        if (tabElem.m_key == key) {
            return true;
        }
    }
    return false;
}

void HashTable::changeFunction(IHashFunction *newHashFunction) {
    if (!newHashFunction || m_function == newHashFunction) {
        return;
    }

    delete m_function;
    m_function = newHashFunction->clone();
    resize(m_size);
}

void HashTable::resize(int size) {
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

void HashTable::clear() {
    for (auto &list : m_table) {
        list.clear();
    }
}

std::string &HashTable::operator [](const int key) {
    int index = m_function->hash(key, m_size);

    for (auto &tabElem : m_table[index]) {
        if (tabElem.m_key == key) {
            return tabElem.m_data;
        }
    }
    
    return m_table[index].back().m_data;
}


std::ostream &operator <<(std::ostream &stream, const HashTable &object) {
    for (int i = 0; i < object.m_size; i++) {
        stream << i << "\t" <<
                &object.m_table[i] << "\t" <<
                object.m_table[i].m_key << "\t" <<
                object.m_table[i].m_data << std::endl;
    }
}
