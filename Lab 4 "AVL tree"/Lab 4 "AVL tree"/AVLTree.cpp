//
//  AVLTree.cpp
//  Lab 4 "AVL tree"
//
//  Created by Antony Miroshnichenko on 25.04.2024.
//



#include "AVLTree.hpp"
#include <iostream>



bool AVLTree::removeNode(Node* toDelete, Node* parent)
{
    bool removed = true;
    removed = SearchTree::removeNode(toDelete, parent);

    balance(m_root, nullptr);

    return removed;
}

void AVLTree::balance(Node* root, Node* parent)
{
    if (root && (root->left() || root->right()))
    {
        balance(root->left(), root);
        balance(root->right(), root);

        int h1 = BinaryTree::height(root->left());
        int h2 = BinaryTree::height(root->right());

        if (h1 - h2 == 2)
        {
            int h1_1 = BinaryTree::height(root->left()->left());
            int h1_2 = BinaryTree::height(root->left()->right());
            if (h1_1 - h1_2 > -1)
            {
                Node* temp = root->left();
                root->setLeft(root->left()->right());
                temp->setRight(root);
                if (parent == nullptr)
                    m_root = temp;
                else
                {
                    if (parent->left() == root)
                        parent->setLeft(temp);
                    else
                        parent->setRight(temp);
                }
            }
            else
            {
                Node* temp = root->left()->right();
                root->left()->setRight(temp->left());
                temp->setLeft(root->left());
                root->setLeft(temp->right());
                temp->setRight(root);
                if (parent == nullptr)
                    m_root = temp;
                else
                {
                    if (parent->left() == root)
                        parent->setLeft(temp);
                    else
                        parent->setRight(temp);
                }
            }
        }

        if (h1 - h2 == -2)
        {
            int h2_1 = BinaryTree::height(root->right()->left());
            int h2_2 = BinaryTree::height(root->right()->right());
            if (h2_1 - h2_2 < 1)
            {
                Node* temp = root->right();
                root->setRight(root->right()->left());
                temp->setLeft(root);
                if (parent == nullptr)
                    m_root = temp;
                else
                {
                    if (parent->left() == root)
                        parent->setLeft(temp);
                    else
                        parent->setRight(temp);
                }
            }
            else
            {
                Node* temp = root->right()->left();
                root->right()->setLeft(temp->right());
                temp->setRight(root->right());
                root->setRight(temp->left());
                temp->setLeft(root);
                if (parent == nullptr)
                    m_root = temp;
                else
                {
                    if (parent->left() == root)
                        parent->setLeft(temp);
                    else
                        parent->setRight(temp);
                }
            }
        }
    }
}

AVLTree::AVLTree() 
    : SearchTree()
{}

AVLTree::AVLTree(const AVLTree& other) 
    : SearchTree(other)
{}

AVLTree::~AVLTree()
{
    clear();
}

AVLTree AVLTree::copyTree(int index)
{
    Node* root = findByIndex(index);
    AVLTree newTree;

    newTree.m_root = BinaryTree::copy(root);
    return newTree;;
}

bool AVLTree::add(int key)
{
    bool added = true;

    added = SearchTree::add(key);

    balance(m_root, nullptr);

    return added;
}
