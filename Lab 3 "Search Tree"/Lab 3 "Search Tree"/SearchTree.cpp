//
//  SearchTree.cpp
//  Lab 3 "Search Tree"
//
//  Created by Antony Miroshnichenko on 15.04.2024.
//

#include "SearchTree.hpp"

BinaryTree::Node* SearchTree::find_by_key(int key)
{
    if (m_root == nullptr)
        return nullptr;

    Node* temp = m_root;
    while ((temp->left() && key < temp->key()) || (temp->right() && key > temp->key()))
    {
        if (key < temp->key())
            temp = temp->left();
        else
            temp = temp->right();
    }

    if (key == temp->key())
        return temp;
    else
        return nullptr;
}

BinaryTree::Node* SearchTree::max(Node* root)
{
    if (root == nullptr)
        return nullptr;

    Node* temp = root;
    while (temp->right())
    {
        temp = temp->right();
    }

    return temp;
}

BinaryTree::Node* SearchTree::min(Node* root)
{
    if (root == nullptr)
        return nullptr;

    Node* temp = root;
    while (temp->left())
    {
        temp = temp->left();
    }

    return temp;
}



bool SearchTree::removeNode(Node* toDelete, Node* parent)
{
    if (toDelete == nullptr)
        return false;

    if (toDelete->left() == nullptr && toDelete->right() == nullptr)
    {
        if (parent && parent->left() == toDelete)
            parent->setLeft(nullptr);

        if (parent && parent->right() == toDelete)
            parent->setRight(nullptr);

        if (!parent)
            m_root = nullptr;

        delete toDelete;

        return true;
    }

    if (toDelete->left() == nullptr && toDelete->right() != nullptr)
    {
        if (parent && parent->left() == toDelete)
            parent->setLeft(toDelete->right());

        if (parent && parent->right() == toDelete)
            parent->setRight(toDelete->right());

        if (!parent)
            m_root = toDelete->right();

        delete toDelete;

        return true;
    }

    if (toDelete->left() != nullptr && toDelete->right() == nullptr)
    {
        if (parent && parent->left() == toDelete)
            parent->setLeft(toDelete->left());

        if (parent && parent->right() == toDelete)
            parent->setRight(toDelete->left());

        if (!parent)
            m_root = toDelete->left();

        delete toDelete;

        return true;
    }

    if (toDelete->left() && toDelete->right())
    {
        Node* to_insert = min(toDelete->right());
        Node* parent_insert = minParent(toDelete->right());

        if (parent_insert)
        {
            parent_insert->setLeft(to_insert->right());
            to_insert->setLeft(toDelete->left());
            to_insert->setRight(toDelete->right());
        }
        else
        {
            to_insert->setLeft(toDelete->left());
        }

        if (parent && parent->left() == toDelete)
            parent->setLeft(to_insert);

        if (parent && parent->right() == toDelete)
            parent->setRight(to_insert);

        if (!parent)
            m_root = to_insert;

        delete toDelete;

        return true;
    }
    
    return false;
    
}



BinaryTree::Node* SearchTree::maxParent(Node* root)
{
    if (root == nullptr || root->right() == nullptr)
        return nullptr;

    Node* m = max(root);
    Node* temp = root;
    while (temp->right() && temp->right()->right())
    {
        temp = temp->right();
    }

    if (temp->right() == m)
        return temp;
    else
        return nullptr;
}

BinaryTree::Node* SearchTree::minParent(Node* root)
{
    if (root == nullptr || root->left() == nullptr)
        return nullptr;
    Node* m = min(root);
    Node* temp = root;
    while (temp->left() && temp->left()->left())
    {
        temp = temp->left();
    }

    if (temp->left() == m)
        return temp;
    else
        return nullptr;
}



SearchTree::SearchTree() : BinaryTree()
{}

SearchTree::SearchTree(const SearchTree& other) 
    : BinaryTree(other)
{}

SearchTree SearchTree::copy(int index)
{
    Node* subTreeRoot = findByIndex(index);
    SearchTree newTree;
    
    newTree.m_root = BinaryTree::copy(subTreeRoot);
    return newTree;
}

bool SearchTree::add(int key)
{
    if (m_root == nullptr)
    {
        m_root = new Node(key);
    }
    else
    {
        Node* temp = m_root;
        while ((temp->left() && key < temp->key()) || (temp->right() && key >= temp->key()))
        {
            if (key < temp->key())
                temp = temp->left();
            else
                temp = temp->right();
        }
        if (key < temp->key())
        {
            Node* left = new Node(key);
            temp->setLeft(left);
        }
        else
        {
            Node* right = new Node(key);
            temp->setRight(right);
        }
    }

    return true;
}

int SearchTree::height(int key)
{
    if (m_root == nullptr)
        return -1;

    int h = 0;
    Node* temp = m_root;
    while ((temp->left() && key < temp->key()) || (temp->right() && key > temp->key()))
    {
        if (key < temp->key())
            temp = temp->left();
        else
            temp = temp->right();
        h++;
    }

    if (key == temp->key())
        return h;
    else
        return -1;
}

SearchTree& SearchTree::operator=(const SearchTree& other)
{
    BinaryTree::operator=(other);
    return *this;
}
