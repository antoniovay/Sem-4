//
//  Hash.cpp
//  Lab 6 "Hash"
//
//  Created by Antony Miroshnichenko on 28.05.2024.
//

#include "HashTable.hpp"

HashTable::HashTable()
    : HashTable(10, new FirstHashFunction)
{}

HashTable::HashTable(int size, IHashFunction* function)
    : m_size(size),
      m_function(function),
      m_table(size)
{
    for (int i = 0; i < size; i++)
    {
        m_table[i] = new tableElement;
    }
}

HashTable::HashTable(const HashTable &other)
    : m_size(other.m_size),
      m_table(other.m_size)
{
    
    m_function = other.m_function->_clone();
        HashTable temp(other.m_size, other.m_function->_clone());
        for (int i = 0; i < other.m_size; i++)
        {
            temp.m_table[i]->m_hasValue = other.m_table[i]->m_hasValue;
            temp.m_table[i]->m_key = other.m_table[i]->m_key;
            temp.m_table[i]->m_data = other.m_table[i]->m_data;
            temp.m_table[i]->m_next = other.m_table[i]->m_next ? temp.m_table[other._findIndex(other.m_table[i]->m_next)] : nullptr;
            temp.m_table[i]->m_prev = other.m_table[i]->m_prev ? temp.m_table[other._findIndex(other.m_table[i]->m_prev)] : nullptr;
        }
        std::swap(m_table, temp.m_table);
}

HashTable::~HashTable() {
    if (m_function)
        delete m_function;
    for (int i = 0; i < m_size; i++)
            delete m_table[i];
}

HashTable &HashTable::operator =(const HashTable &other) {
    if (this == &other)
        return *this;
    
    m_function = other.m_function->_clone();
    
    if (m_size != other.m_size)
        m_size = other.m_size;
    
    HashTable temp(other);
    std::swap(m_table, temp.m_table);
    
    return *this;
}

bool HashTable::add(const int key, const std::string &data)
{
    bool isFull = true;
    for (int i = 0; i < m_size; i++)
        if (!m_table[i]->m_hasValue)
            isFull = false;
    
    if (isFull || inTable(key))
        return false;
    
    int index = m_function->hash(key, m_size);
    
    if (!m_table[index]->m_hasValue) {
        m_table[index]->m_key = key;
        m_table[index]->m_hasValue = true;
        m_table[index]->m_data = data;
        return true;
        
    } else {
        if (m_table[index]->m_next) {
            int i = index;
            tableElement *temp = m_table[i];
            while (temp->m_next && i < m_size) {
                temp = temp->m_next;
                i = _findIndex(temp);
            }
            if (i >= 0) {
                for (int j = 0; j < m_size; j++) {
                    if (!m_table[j]->m_hasValue) {
                        m_table[j]->m_key = key;
                        m_table[j]->m_hasValue = true;
                        m_table[j]->m_data = data;
                        m_table[i]->m_next = &(*m_table[j]);
                        m_table[j]->m_prev = &(*m_table[i]);
                        return true;
                    }
                }
            }
        } else {
            for (int j = 0; j < m_size; j++) {
                if (!m_table[j]->m_hasValue) {
                    m_table[j]->m_key = key;
                    m_table[j]->m_hasValue = true;
                    m_table[j]->m_data = data;
                    m_table[index]->m_next = &(*m_table[j]);
                    m_table[j]->m_prev = &(*m_table[index]);
                    return true;
                }
            }
        }
    }
    return false;
}


bool HashTable::remove(int key) {
    if (!m_function)
        return false;
    
    if (!inTable(key))
        return false;
    
    int index = m_function->hash(key, m_size);
    
    if (m_table[index]->m_key == key) {
        if (!m_table[index]->m_prev && !m_table[index]->m_next) {
            m_table[index]->m_hasValue = false;
            m_table[index]->m_key = 0;
            m_table[index]->m_data = "";
        }
        else if (m_table[index]->m_prev && !m_table[index]->m_next) {
            m_table[index]->m_hasValue = false;
            m_table[index]->m_key = 0;
            m_table[index]->m_data = "";
            m_table[index]->m_prev->m_next = nullptr;
            m_table[index]->m_prev = nullptr;
        }
        else if (m_table[index]->m_next) {
            tableElement* temp = m_table[index];
            while (temp->m_next && temp->m_hasValue) {
                temp->m_key = temp->m_next->m_key;
                temp->m_data = temp->m_next->m_data;
                temp = temp->m_next;
            }
            temp->m_hasValue = false;
            temp->m_key = 0;
            temp->m_data = "";
            temp->m_prev->m_next = nullptr;
            temp->m_prev = nullptr;
        }
    } else {
        tableElement* temp = m_table[index];
        while (temp->m_key != key)
            temp = temp->m_next;
        while (temp->m_next && temp->m_hasValue) {
            temp->m_key = temp->m_next->m_key;
            temp->m_data = temp->m_next->m_data;
            temp = temp->m_next;
        }
        temp->m_hasValue = false;
        temp->m_key = 0;
        temp->m_data = "";
        temp->m_prev->m_next = nullptr;
        temp->m_prev = nullptr;
    }
    return true;
}

bool HashTable::inTable(int key) {
    if (!_findElement(key))
        return false;
    else
        return true;
}

void HashTable::changeFunction(IHashFunction *function) {
    if(function)
        delete m_function;
    
    m_function = function;
    std::vector<tableElement*> oldTable(m_size, nullptr);
    oldTable.swap(m_table);
    for (int i = 0; i < m_size; i++)
    {
        m_table[i] = new tableElement;
    }
    for (int i = 0; i < oldTable.size(); i++)
    {
        if (oldTable[i]->m_hasValue)
        {
            add(oldTable[i]->m_key, oldTable[i]->m_data);
        }
        delete oldTable[i];
    }
}

void HashTable::resize(int size)
{
    if (m_size == size)
    {
        return;
    }
    std::vector<tableElement*> oldTable(m_size, nullptr);
    std::swap(m_table, oldTable);
    m_table.resize(size);
    m_size = size;
    for (int i = 0; i < size; ++i)
    {
        m_table[i] = new tableElement;
    }
    for (int i = 0; i < oldTable.size(); i++)
    {
        if (oldTable[i]->m_hasValue)
        {
            add(oldTable[i]->m_key, oldTable[i]->m_data);
        }
        delete oldTable[i];
    }
}

int HashTable::_findIndex(tableElement* element) const
{
    for (int i = 0; i < m_size; i++)
    {
        if((m_table[i]->m_key == element->m_key) && (m_table[i]->m_next == element->m_next))
        {
            return i;
        }
    }
    return -1;
}

HashTable::tableElement*  HashTable::_findElement(const int key) const
{
    int index = m_function->hash(key, m_size);
    if (m_table[index]->m_hasValue)
    {
        if (m_table[index]->m_key == key)
        {
            return m_table[index];
        }
        else
        {
            if (m_table[index]->m_next)
            {
                tableElement* temp = m_table[index];
                while (temp->m_next)
                {
                    temp = temp->m_next;
                    if (temp->m_key == key)
                    {
                        return temp;
                    }
                }
                return nullptr;
            }
            else
            {
                return nullptr;
            }
        }
    }
    else
    {
        return nullptr;
    }
}

std::ostream &operator <<(std::ostream &stream, const HashTable &object) {
    for (int i = 0; i < object.m_size; i++) {
        if (object.m_table[i]->m_hasValue)
            stream << i << "\t" <<
                    &object.m_table[i] << "\t" <<
                    object.m_table[i]->m_next << "\t" <<
                    object.m_table[i]->m_key << "\t" <<
                    object.m_table[i]->m_data << std::endl;
        else
            stream << i << "\tFree" << std::endl;
    }
    return stream;
}
