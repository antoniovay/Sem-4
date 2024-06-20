//
//  SearchTree.hpp
//  Lab 3 "Search Tree"
//
//  Created by Antony Miroshnichenko on 15.04.2024.
//

#pragma once

#include "BinaryTree.hpp"

class SearchTree : public BinaryTree
{
    
protected:
    Node* find_by_key(int key);

    Node* max(Node* root);
    Node* min(Node* root);

    Node* maxParent(Node* root);
    Node* minParent(Node* root);

    bool removeNode(Node* toDelete, Node* parent) override;

    
public:
    
    SearchTree();
    SearchTree(const SearchTree& other);
    ~SearchTree() {clear();}

    SearchTree copy(int index);

    using BinaryTree::min;
    using BinaryTree::max;

    bool add(const int key) override;

    int height(int key);

    SearchTree& operator=(const SearchTree& other);
};
