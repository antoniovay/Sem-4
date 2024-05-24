//
//  Huffman.hpp
//  Lab 5 "Huffman Code"
//
//  Created by Antony Miroshnichenko on 23.05.2024.
//

#pragma once

#include <string>

#include "Set.hpp"


class Huffman
{
    
public:
    
    class Node;
    
public:
    
    Huffman() { m_root = nullptr; }
    ~Huffman() { _delete(m_root); }

    void build(std::string filenameIn);
    float encode(std::string filenameIn, std::string filenameOut);
    bool decode(std::string filenameIn, std::string filenameOut);

private:

    void _delete(Node* root);
    
    Node* m_root;
    
};



class Node
{
public:
    
    Node();
    Node(unsigned char symbol, int frequency);
    Node(Node* left, Node* right);
    ~Node() = default;

    Set data();
    int frequency();

    Node* left() const;
    Node* right() const;

private:
    
    Set m_data;
    int m_frequency;

    Node* m_left;
    Node* m_right;
};
