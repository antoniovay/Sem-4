//
//  AVLTree.hpp
//  Lab 4 "AVL tree"
//
//  Created by Antony Miroshnichenko on 25.04.2024.
//



#pragma once


#include "SearchTree.hpp"

class AVLTree: public SearchTree
{
    
protected:
    bool removeNode(Node* toDelete, Node* parent) override;
    
private:
    void balance(Node* root, Node* parent);

    
public:
    AVLTree();
    AVLTree(const AVLTree& other);
    ~AVLTree();

    AVLTree copyTree(int index);

    bool add(int key) override;

    AVLTree& operator = (const AVLTree& other) = default;

};
