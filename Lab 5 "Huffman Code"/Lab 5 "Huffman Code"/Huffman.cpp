//
//  Huffman.cpp
//  Lab 5 "Huffman Code"
//
//  Created by Antony Miroshnichenko on 23.05.2024.
//

#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>

#include "Huffman.hpp"


void Huffman::build(std::string filenameIn)
{
    _delete(m_root);
    
    char c;
    unsigned char symbols[256];
    std::ifstream fin;
    fin.open(filenameIn);
    
    if (!fin.is_open())
        return;
    
    for (int i = 0; i < 256; i++)
        symbols[i] = 0;

    while (fin.get(c))
        symbols[c]++;

    fin.close();
    
    std::vector<Node*> nodes;
    
    for (int i = 0; i < 256; i++)
        if (symbols[i]) {
            Node* temp = new Node(i, symbols[i]);
            nodes.push_back(temp);
        }
    
    
    
    
}

float Huffman::encode(std::string filenameIn, std::string filenameOut)
{
    
}

bool Huffman::decode(std::string filenameIn, std::string filenameOut)
{
    
}

void Huffman::_delete(Node* root)
{
    if (root) {
        _delete(root->left());
        _delete(root->right());
        delete root;
    }
}


Node::Node()
{
    m_data = Set();
    m_frequency = 0;
    m_left = nullptr;
    m_right = nullptr;
}

Node::Node(unsigned char symbol, int frequency)
{
    m_data = Set(symbol);
    m_frequency = frequency;
    m_left = nullptr;
    m_right = nullptr;
}

Node::Node(Node* left, Node* right)
{
    m_data = left->m_data | right->m_data;
    m_frequency = left->m_frequency + right->m_frequency;
    m_left = left;
    m_right = right;
}

Set Node::data()
{
    return m_data;
}

int Node::frequency()
{
    return m_frequency;
}

Node* Node::left() const
{
    return m_left;
}

Node* Node::right() const
{
    return m_right;
}


