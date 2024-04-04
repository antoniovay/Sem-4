//
//  Binary_Tree.cpp
//  BinTree
//
//  Created by Antony Miroshnichenko on 14.03.2024.
//

#include "BinaryTree.hpp"



// Методы для BinaryTree



BinaryTree::BinaryTree (const BinaryTree &other) {
    
    m_root = other._clone();
    
}



BinaryTree::Node *BinaryTree::getRoot() const {
    
    return m_root;
    
}



void BinaryTree::clear() {
    
    clear (m_root);
    
    m_root = nullptr;
    
}



void BinaryTree::clear (Node* root) {
    
    if (!root) {
        
        return;
        
    }
    
    clear(root->getLeftChild());
    clear(root->getRightChild());
    
    delete root;
    
}



bool BinaryTree::isEmpty() const {
    
    if (!m_root)
        
        return false;
    
    return true;
    
}



BinaryTree BinaryTree::clone() const {
    
    return clone(m_root);
    
}



BinaryTree BinaryTree::clone (Node *root) const {
    
    BinaryTree tree;
    
    tree.m_root = _clone(root);
    
    return tree;
    
}



int BinaryTree::getHeight() const {
    
    if (!m_root)
        
        return 0;
    
    int leftHeight = getHeight(m_root->m_leftChild);
    int rightHeight = getHeight(m_root->m_rightChild);
    
    if (rightHeight > leftHeight)
        
        leftHeight = rightHeight;
    
    return 1 + leftHeight;
    
}



int BinaryTree::getHeight(Node *root) const {
    
    if (!root)
        
        return 0;
    
    int leftHeight = getHeight(root->m_leftChild);
    int rightHeight = getHeight(root->m_rightChild);
    
    if (rightHeight > leftHeight)
        
        leftHeight = rightHeight;
    
    return 1 + rightHeight;
    
}



int BinaryTree::getNodesCount() const {
    
    if (!m_root)
        
        return 0;
    
    int count = 1;
    
    count += getNodesCount(m_root->m_leftChild);
    count += getNodesCount(m_root->m_rightChild);
    
    return count;
    
}



int BinaryTree::getNodesCount(Node *root) const {
    
    if (!root)
        
        return 0;
    
    int count = 1;
    
    count += getNodesCount(root->m_leftChild);
    count += getNodesCount(root->m_rightChild);
    
    return count;
    
}



int BinaryTree::max() const {
    
    if (!m_root)
        
        return {};
    
    int maxLeft = max(m_root->m_leftChild);
    int maxRight = max(m_root->m_rightChild);
    int maxRoot = m_root->m_key;
    
    if (maxLeft > maxRoot)
        
        maxRoot = maxLeft;
    
    if (maxRight > maxRoot)
        
        maxRoot = maxRight;
    
    return maxRoot;
    
}



int BinaryTree::min() const {
    
    if (!m_root)
        
        return {};
    
    int minLeft = min(m_root->m_leftChild);
    int minRight = min(m_root->m_rightChild);
    int minRoot = m_root->m_key;
    
    if (minLeft < minRoot)
        
        minRoot = minLeft;
    
    if (minRight < minRoot)
        
        minRoot = minRight;
    
    return minRoot;
    
}



int BinaryTree::max(Node *root) const {
    
    if (!root)
        
        return {};
    
    int maxLeft = max(root->m_leftChild);
    int maxRight = max(root->m_rightChild);
    int maxRoot = root->m_key;
    
    if (maxLeft > maxRoot)
        
        maxRoot = maxLeft;
    
    if (maxRight > maxRoot)
        
        maxRoot = maxRight;
    
    return maxRoot;
    
}



int BinaryTree::min(Node *root) const {
    
    if (!root)
        
        return {};
    
    int minLeft = min(root->m_leftChild);
    int minRight = min(root->m_rightChild);
    int minRoot = root->m_key;
    
    if (minLeft < minRoot)
        
        minRoot = minLeft;
    
    if (minRight < minRoot)
        
        minRoot = minRight;
    
    
    return minRoot;
    
}



BinaryTree::Node *BinaryTree::addNode (const int key) {
    
    if (m_root) {
        
        return _addNode(m_root, key);
        
    }
    
    else {
        
        return m_root = new Node(key);
        
    }
    
}



bool BinaryTree::removeNode(const int key) {
    
    return removeNode(find(key));
    
}



auto BinaryTree::finishRemove(Node *currentNode, Node *parentNode, Node *replacementNode) {
    
    //if(!parentNode) return;
    
    if (parentNode->getLeftChild() == currentNode) {
        
        parentNode->setLeftChild(nullptr);
        
        delete currentNode;
        
        if (replacementNode)
            
            parentNode->setLeftChild(replacementNode);
        
    }
    
    else {
        
        parentNode->setRightChild(nullptr);
        
        delete currentNode;
        
        if (replacementNode)
            
            parentNode->setRightChild(replacementNode);
        
    }
    
}



bool BinaryTree::removeNode(Node *node) {
    
    if (!node)
        
        return false;
    
    
    Node *currentNode = node,
         *parentNode = findParent(m_root, node),
         *replacementNode = nullptr;
    
    
    if (parentNode == currentNode)
        
        clear();
       
    else {
        
        if (currentNode->getLeftChild() == nullptr && currentNode->getRightChild() == nullptr) {
            
            finishRemove(currentNode, parentNode, replacementNode);
            
        } 
        
        else if (!currentNode->getLeftChild()) {
            
            replacementNode = currentNode->getRightChild();
            finishRemove(currentNode, parentNode, replacementNode);
            
        }
        
        else if (!currentNode->getRightChild()) {
            
            replacementNode = currentNode->getLeftChild();
            finishRemove(currentNode, parentNode, replacementNode);
            
        } 
        
        else {
            
            replacementNode = findParent(currentNode, nullptr);
            Node* leafParent = findParent(currentNode, replacementNode);
            
            if(leafParent->getLeftChild() == replacementNode) {
                
                leafParent->setLeftChild(nullptr);
                
            } 
            
            else {
                
                leafParent->setRightChild(nullptr);
                
            }
            
            replacementNode->setLeftChild(currentNode->getLeftChild());
            replacementNode->setRightChild(currentNode->getRightChild());
            
            finishRemove(currentNode, parentNode, replacementNode);
            
        }
        
    }
    
    return true;
    
}



BinaryTree::Node *BinaryTree::findParent(Node *root, Node *child) {
    
    if (!root || !child)
        
        return nullptr;
    
    
    std::stack<BinaryTree::Node*> nodes;
    
    nodes.push(root);
    
    Node *parent = nullptr;
    
    
    while(!nodes.empty()) {
        
        parent = nodes.top();
        
        nodes.pop();
        
        
        if (parent == child)
            
            return parent;
        
        
        if (parent->getLeftChild() == child)
                
            return parent;
        
        else if (parent->getLeftChild())
            
            nodes.push(parent->getLeftChild());
        
        
        if (parent->getRightChild() == child)
            
            return parent;
        
        else if(parent->getRightChild())
            
            nodes.push(parent->getRightChild());
        
        
    }
    
    return nullptr;
    
}



BinaryTree::Node *BinaryTree::find(const int key) const {
    
    return find(m_root, key);
    
}



BinaryTree::Node *BinaryTree::find(Node *root, const int key) const {
    
    if (!root)
        
        return root;
    
    if (root->m_key == key)
        
        return root;
    
    
    if (find(root->m_leftChild, key))
        
        return find(root->m_leftChild, key);
        
    if (find(root->m_rightChild, key))
        
        return find(root->m_rightChild, key);
    
    return nullptr;
    
}



bool BinaryTree::isBalanced() const {
    
    return isBalanced(m_root);
    
}



bool BinaryTree::isBalanced(Node *root) const {
    
    if (!root)
        
        return true;
    
    int leftHeight = getHeight(root->getLeftChild());
    int rightHeight = getHeight(root->getRightChild());
    int difference = leftHeight - rightHeight;
    
    bool balanced = (difference == 0 || difference == 1 || difference == -1);
    
    return ( balanced && isBalanced(root->getLeftChild()) && isBalanced(root->getRightChild()) );
    
}



int BinaryTree::getLevel (const int key) const {
    
    Node* node = find(key);
    if(!node) {
        return -1;
    }
    
    return getLevel(m_root, node, 0);
    
}



int BinaryTree::getLevel(Node* root, Node* node, int currentLevel) const {
    
    if (!root) {
        
        return -1;
        
    }
    
    ++currentLevel;
    
    if (root == node) {
        
        return currentLevel;
        
    }
    
    int leftTree = getLevel(root->getLeftChild(), node, currentLevel);
    int rightTree = getLevel(root->getRightChild(), node, currentLevel);
    
    if (leftTree == -1)
        
        return rightTree;
    
    return leftTree;
    
}



void BinaryTree::getKeys(std::vector<int> &vector) const {
    
    if (!m_root)
        
        return;
        
    vector.push_back(m_root->getKey());
    getKeys(m_root->getLeftChild(), vector);
    getKeys(m_root->getRightChild(), vector);
    
    for (int i = vector.size() - 1; i > 0; i--)
        
        for (int j = 0; j < i; j++)
            
            if (vector[j] > vector[j+1])
                
                std::swap(vector[j], vector[j+1]);
    
}



void BinaryTree::getKeys(Node* root, std::vector<int> &vector) const {
    
    if(!root)
        
        return;
        
    vector.push_back(root->getKey());
    getKeys(root->getLeftChild(), vector);
    getKeys(root->getRightChild(), vector);
    
}



void BinaryTree::printHorizontal(int levelSpacing) const {
    
    printHorizontal(m_root, 0, levelSpacing);
    
}



void BinaryTree::printHorizontal(Node *root, int marginLeft, int levelSpacing) const {
    
    if (root == nullptr) {
        
        return;
        
    }
    
    printHorizontal(root->getRightChild(), marginLeft + levelSpacing, levelSpacing);
    
    std::cout << std::string(marginLeft, ' ') << root->getKey() << std::endl;
    
    printHorizontal(root->getLeftChild(), marginLeft + levelSpacing, levelSpacing);
    
}



void BinaryTree::printLeaves() const {
    
    if (!m_root) {
        
        return;
        
    }
    
    std::vector<Node* > leafsList;
    
    getLeafs(m_root, leafsList);
    
    std::cout << '[';
    
    for (auto it = leafsList.begin(); it != leafsList.end(); ++it) {
        
        std::cout << (*it)->getKey() << ((it + 1) == leafsList.end() ? "":", ");
        
    }
    
    std::cout << ']' << std::endl;
    
}



void BinaryTree::getLeafs(Node* root, std::vector<Node*> &leafsList) const {
    
    if (!root)
        
        return;
    
    if (!root->getLeftChild() && !root->getRightChild())
        
        leafsList.push_back(root);
    
    else {
        
        getLeafs(root->getLeftChild(), leafsList);
        getLeafs(root->getRightChild(), leafsList);
        
    }
    
}



BinaryTree *BinaryTree::operator = (const BinaryTree *other) {
    
    if (m_root != other->m_root) {
        
        clear();
        
        auto obj = other->m_root;
        
        std::swap(m_root, obj);
        
    }
    
        return this;
    
}



BinaryTree::Node *BinaryTree::_addNode (Node *root, const int key) {
    
    if (!root) {
        
        root = new Node(key);
        
    }
    
    else if (rand() % 2) {
        
        root->setLeftChild(_addNode(root->getLeftChild(), key));
        
    }
    
    else {
        
        root->setRightChild(_addNode(root->getRightChild(), key));
        
    }
    
    return root;
    
}



BinaryTree::Node *BinaryTree::_clone() const {
    
    return _clone(m_root);
    
}



BinaryTree::Node *BinaryTree::_clone(Node *root) const {
    
    Node *cloneRoot = nullptr;
    
    if (root == nullptr) {
        
        return cloneRoot;
        
    }
    
    cloneRoot = new Node(root->getKey());
    
    cloneRoot->setLeftChild(_clone(root->getLeftChild()));
    cloneRoot->setRightChild(_clone(root->getRightChild()));
    
    return cloneRoot;
    
}





// Методы для Node



BinaryTree::Node::Node(int key, Node* left, Node* right)

    : m_key(key)
    , m_leftChild(left)
    , m_rightChild(right)

{}



int BinaryTree::Node::getKey() const {
    
    return m_key;
    
}



void BinaryTree::Node::setKey(const int key) {
    
    m_key = key;
    
}



BinaryTree::Node* BinaryTree::Node::getLeftChild() const {
    
    return m_leftChild;
    
}



BinaryTree::Node* BinaryTree::Node::getRightChild() const {
    
    return m_rightChild;
    
}



void BinaryTree::Node::setLeftChild(Node* left) {
    
    m_leftChild = left;
    
}



void BinaryTree::Node::setRightChild(Node* right) {
    
    m_rightChild = right;
    
}
