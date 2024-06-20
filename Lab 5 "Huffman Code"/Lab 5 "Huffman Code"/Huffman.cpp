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


void Huffman::build(std::string fnameIn)
{
    _delete(m_root);
    
    char c;
    unsigned char symbols[256];
    std::ifstream fin;
    fin.open(fnameIn);
    
    if (!fin.is_open())
        return;
    
    for (int i = 0; i < 256; i++)
        symbols[i] = 0;

    while (fin.get(c))
        symbols[(unsigned char)c]++;

    fin.close();
    
    std::vector<Node*> nodes;
    
    for (int i = 0; i < 256; i++)
        if (symbols[i]) {
            Node* temp = new Node((unsigned char)i, symbols[i]);
            nodes.push_back(temp);
        }
    
    std::sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        return a->frequency() < b->frequency();
    });

    while (nodes.size() > 1) {
        Node* temp = new Node(nodes[0], nodes[1]);
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());
        nodes.push_back(temp);
        std::sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
            return a->frequency() < b->frequency();
        });
    }

    m_root = nodes[0];
    
}

float Huffman::encode(std::string fnameIn, std::string fnameOut)
{
    build(fnameIn);
    
    if (!m_root)
        return 0.0f;

    std::ifstream fin;
    fin.open(fnameIn);
    if (!fin.is_open())
        return 0.0f;

    std::ofstream fout;
    fout.open(fnameOut);
    if (!fout.is_open())
        return 0.0f;

    int rezultOfBitsCounting = 0;
    int inputOfBitsCounting = 0;

    char c;
    while (fin.get(c)) {
        Node* temp = m_root;
        while (temp->left() != nullptr && temp->right() != nullptr) {
            if (temp->left()->data().inSet(c)) {
                temp = temp->left();
                fout << '0';
            } else {
                temp = temp->right();
                fout << '1';
            }
            rezultOfBitsCounting++;
        }
        inputOfBitsCounting++;
    }

    if (m_root->left() == nullptr && m_root->right() == nullptr) {
        for (int i = 0; i < inputOfBitsCounting; i++)
            fout << '1';
        rezultOfBitsCounting = inputOfBitsCounting;
    }

    fin.close();
    fout.close();

    inputOfBitsCounting *= 8;

    return ((float)rezultOfBitsCounting / (double) inputOfBitsCounting);
    
    
}

bool Huffman::decode(std::string fnameIn, std::string fnameOut)
{
    if (!m_root)
        return false;

    std::ifstream fin;
    fin.open(fnameIn);
    if (!fin.is_open())
        return 0.0f;

    std::ofstream fout;
    fout.open(fnameOut);
    if (!fout.is_open())
        return 0.0f;

    char c;
    Node* temp = m_root;
    while (fin.get(c)) {
        switch (c) {
            case '0':
                if (temp->left() != nullptr)
                    temp = temp->left();
                break;
            case '1':
                if (temp->right() != nullptr)
                    temp = temp->right();
                break;
            default:
                return false;
        }

        if (temp->left() == nullptr && temp->right() == nullptr) {
            fout << temp->data();
            temp = m_root;
        }
    }

    fin.close();
    fout.close();

    return false;
}

void Huffman::_delete(Node* root)
{
    if (root) {
        _delete(root->left());
        _delete(root->right());
        delete root;
    }
}


Huffman::Node::Node()
{
    m_data = Set();
    m_frequency = 0;
    m_left = nullptr;
    m_right = nullptr;
}

Huffman::Node::Node(unsigned char symbol, int frequency)
{
    m_data = Set(symbol);
    m_frequency = frequency;
    m_left = nullptr;
    m_right = nullptr;
}

Huffman::Node::Node(Node* left, Node* right)
{
    m_data = left->m_data | right->m_data;
    m_frequency = left->m_frequency + right->m_frequency;
    m_left = left;
    m_right = right;
}

Set Huffman::Node::data()
{
    return m_data;
}

int Huffman::Node::frequency()
{
    return m_frequency;
}

Huffman::Node* Huffman::Node::left() const
{
    return m_left;
}

Huffman::Node* Huffman::Node::right() const
{
    return m_right;
}


