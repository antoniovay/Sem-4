//
//  Hash.cpp
//  Lab 6 "Hash"
//
//  Created by Antony Miroshnichenko on 28.05.2024.
//

#include "HashTable.hpp"

HashTable::HashTable()
: HashTable(1)
{}

HashTable::HashTable(int n) {
    m_size = n;
    m_table = new tableElement[m_size];
    m_function = new FirstHashFunction;
}

HashTable::HashTable(const HashTable &other) {
        
    m_size = other.m_size;
    m_table = new tableElement[m_size];
    
    for (int i = 0; i < m_size; i++)
        add(other.m_table[i].key, other.m_table[i].data);
    m_function = other.m_function->clone();
}

HashTable::~HashTable() {
    if (m_table)
        delete [] m_table;
    if (m_function)
        delete m_function;
}

HashTable &HashTable::operator =(const HashTable &other) {
    
    if (this == &other)
        return *this;
    
    if (m_table)
        delete [] m_table;

    m_size = other.m_size;
    m_table = new tableElement[m_size];
    
    for (int i = 0; i < m_size; i++)
        add(other.m_table[i].key, other.m_table[i].data);
    
    m_function = other.m_function->clone();

    return *this;
}

bool HashTable::add(int key, std::string string) {
    if (!m_function)
        return false;
    
    int index = (*m_function)(key, m_size, 1);
//    std::cout << index << std::endl;
    
    if (!m_table[index].hasValue) {
        m_table[index].key = key;
        m_table[index].data = string;
        m_table[index].hasValue = true;
        
    } else {
        int i = 0;
        while (i < m_size && m_table[i].hasValue)
            i++;

        if (i >= m_size)
            return false;

        m_table[index].next = &m_table[i];
        m_table[i].key = key;
        m_table[i].data = string;
        m_table[i].hasValue = true;
    }
    
    return true;
    
    
    
//    if (inTable(key) || !m_function)
//        return false;
//
//    int index = (*m_function)(key, m_size, 1);
//    m_table[index].key = key;
//    m_table[index].data = string;
//    m_table[index].hasValue = true;
//    m_table[index].next = &m_table[1];
//    
//    return true;
    
    
    
//    if (!m_function)
//    return false;
//
//    int index = (*m_function)(m_size, key, 1);
//    //std::cout « index « std::endl;
//    if (!m_table[index].hasValue) {
//        m_table[index].key = key;
//        m_table[index].data = string;
//        m_table[index].hasValue = true;
//    } else {
//        int newIndex = (*m_function)(m_size, key, 1);
//        if (!m_table[newIndex].hasValue) {
//            m_table[newIndex].key = key;
//            m_table[newIndex].data = string;
//            m_table[newIndex].hasValue = true;
//            m_table[index].next = &m_table[newIndex];
//        } else {
//            return false;
//        }
//    }
//    return true;
}

bool HashTable::remove(int key) {
    if (!m_function)
        return false;
    
    int index = (*m_function)(key, m_size, 1);

    if (!m_table[index].hasValue)
        return false;

    tableElement *temp = &m_table[index];
    while (temp && temp->key != key && temp->hasValue)
        temp = temp->next;

    if (!temp)
        return false;
    
    else if(temp->hasValue && temp->key == key) {
        while (temp->next) {
            temp->key = temp->next->key;
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp->hasValue = false;
        return true;
    }
    
    return false;
    
//    int index = (*m_function)(m_size, key, 1);
//
//    for (int i = 0; i < m_size && m_table[i].hasValue; i++)
//        if (m_table[i].key == key) {
//            m_table[i].key = m_table[i].next->key;
//            m_table[i].data = m_table[i].next->data;
//            m_table[i] = new tableElement(*m_table[i].next);
//            return true;
//        }
//    
//    return false;
}

bool HashTable::inTable(int key) {
    int index = (*m_function)(key, m_size, 1);

    tableElement* temp = &m_table[index];
    while (temp && temp->key != key && temp->hasValue)
        temp = temp->next;

    if (!temp)
        return false;
    else if(temp->hasValue && temp->key == key)
        return true;
    return false;
    
}

void HashTable::changeFunction(IHashFunction *newFunction) {
    m_function = newFunction;

    tableElement *newTable = new tableElement[m_size];

    for (int i = 0; i < m_size; i++) {
        
        if (m_table[i].hasValue) {
            
            int index = (*m_function)(m_table[i].key, m_size, 1);
            if (!newTable[index].hasValue) {
                newTable[index].key = m_table[i].key;
                newTable[index].data = m_table[i].data;
                newTable[index].hasValue = true;
                
            } else {
                int i = 0;
                while (i < m_size && newTable[i].hasValue)
                    i++;

                newTable[index].next = &newTable[i];
                newTable[i].key = m_table[i].key;
                newTable[i].data = m_table[i].data;
                newTable[i].hasValue = true;
            }
        }
    }

    delete [] m_table;
    m_table = newTable;
}

//void Hash::resize(const int size) {
//    std::vector<Pair> oldData(size);
//    std::swap(oldData, data);
//
//    for(int i = 0; i < oldData.size(); i++)
//        if(oldData[i].value() != "")
//            add(oldData[i].key(), oldData[i].value());
//}





//int Hash::Pair::key() const {
//    return m_key;
//}
//
//std::string Hash::Pair::value() const {
//    return m_value;
//}
//
//void Hash::Pair::setKey(const int key) {
//    m_key = key;
//}
//
//void Hash::Pair::setValue(const std::string& value) {
//    m_value = value;
//}
//
//Hash::Pair* Hash::Pair::next() {
//    return m_next;
//}
//
//const Hash::Pair* Hash::Pair::next() const {
//    return m_next;
//}
//
//void Hash::Pair::setNext(Pair* next) {
//    m_next = next;
//}

std::ostream &operator <<(std::ostream &stream, const HashTable &object) {
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
