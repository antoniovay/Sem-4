//
//  Binary_Tree.hpp
//  Lab 2 "Binary Tree"
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

//#include "BinaryTreeTester.hpp"




class BinaryTree
{
    
public:
    
    class Node;
    
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
    Node* copy(Node* root);
    
    int height() const;
    int height(Node *root) const;
    
    int getNodesCount() const;
    int getNodesCount(Node *root) const;
    
    int max() const;
    int min() const;
    
    int max(Node *root) const;
    int min(Node *root) const;
    
    Node *addNode(const int key);
    virtual bool add(const int key);
    
//    bool remove(const int key);
//    bool removeD(Node* node);
//    auto finishRemove(Node *currentNode, Node *parentNode, Node *replacementNode);
//    bool removeNode(Node *node);
//    Node *findParent(Node *root, Node *child);
    
    
//    bool remove(const int key);
//    bool removeNode(Node* node, const int key);
//    void finishRemove(Node *currentNode, Node *parentNode, Node *replacementNode);
//    const Node *findParent(const Node* root, const Node* child) const;
//    Node *findParent(Node* root, Node* child);
//    Node *findParent(Node* root) const;
//    Node *findParent(Node* root, const int key);
    
//    bool remove(const int key);
//    bool remove(Node* toDelete, Node* parent);
//    const Node* findParent(const Node* root, const Node* child) const;
//    Node* findParent(Node* root, Node* child);
//    Node* getFree(Node* root);
    
    bool remove(int key);
    bool remove(Node* root, int key);
    Node* findParent(Node* root, int key);
    virtual bool removeNode(Node* toDelete, Node* parent);
    Node* getFree(Node* root);
    
    
    Node *find(const int key) const;
    Node *find(Node *root, const int key) const;
    
    Node *findByIndex(const int index);
    Node *findByIndex(Node* root, int index);
    

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
    
    BinaryTree *operator = (const BinaryTree &other);
    
    void printVertical();
    void printVertical(Node* subTreeRoot);
    
private:
    
    Node *_addNode(Node *root, const int key);
    Node *_clone() const;
    Node *_clone(Node *root) const;

    
protected:
    
    Node *m_root = nullptr;
    
};



class BinaryTree::Node
{
    
    friend class BinaryTree;
    friend class BinarySearchTree;
    
public:
    
    Node(int key = 0, Node* left = nullptr, Node* right = nullptr);
    ~Node() = default;

    int key() const;
    void setKey (const int key);

    Node* left() const;
    Node* right() const;
    
    void setLeft (Node* left);
    void setRight (Node* right);

    
private:
    
    int m_key = 0;
    Node* m_left = nullptr;
    Node* m_right = nullptr;

};




#endif /* Binary_Tree_hpp */
