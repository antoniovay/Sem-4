//
//  Binary_Tree.hpp
//  BinTree
//
//  Created by Antony Miroshnichenko on 14.03.2024.
//

#ifndef Binary_Tree_hpp
#define Binary_Tree_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#include "BinaryTreeTester.hpp"




class BinaryTree
{
    
public:
    
    class Node;
    class BinaryTreeTester;
    
public:
    
    BinaryTree() = default;
    BinaryTree(const BinaryTree &other);
    ~BinaryTree() { clear(); };
    
    Node *getRoot() const;

    void clear();
    void clear (Node* root);
    
    bool isEmpty() const;
    
    BinaryTree clone() const;
    BinaryTree clone (Node *root) const;
    
    int getHeight() const;
    int getHeight(Node *root) const;
    
    int getNodesCount() const;
    int getNodesCount(Node *root) const;
    
    int max() const;
    int min() const;
    
    int max(Node *root) const;
    int min(Node *root) const;
    
    Node *addNode(const int key);
    
    bool removeNode(const int key);
    bool removeD(Node* node);
    auto finishRemove(Node *currentNode, Node *parentNode, Node *replacementNode);
    bool removeNode(Node *node);
    Node *findParent(Node *root, Node *child);
    
    Node *find(const int key) const;
    Node *find(Node *root, const int key) const;

    bool isBalanced() const;
    bool isBalanced(Node *root) const;

    int getLevel(const int key) const;
    int getLevel(Node* root, Node* target, int currentLevel) const;
    
    void getKeys(std::vector<int> &vector) const;
    void getKeys(Node* root, std::vector<int> &vector) const;

    void printHorizontal(int levelSpacing = 4) const;
    void printHorizontal(Node *root, int marginLeft, int levelSpacing) const;

    void printLeaves() const;
    void getLeafs(Node* root, std::vector<Node*> &leafs) const;
    
    BinaryTree *operator = (const BinaryTree *other);
    
private:
    
    Node *_addNode(Node *root, const int key);
    Node *_clone() const;
    Node *_clone(Node *root) const;

    
private:
    
    Node *m_root = nullptr;
    
};



class BinaryTree::Node
{
    
    friend BinaryTree;
    
public:
    
    Node(int key = 0, Node* left = nullptr, Node* right = nullptr);
    ~Node() = default;

    int getKey() const;
    void setKey (const int key);

    Node* getLeftChild() const;
    Node* getRightChild() const;
    
    void setLeftChild (Node* left);
    void setRightChild (Node* right);

    
private:
    
    int m_key = 0;
    Node* m_leftChild = nullptr;
    Node* m_rightChild = nullptr;

};




#endif /* Binary_Tree_hpp */
