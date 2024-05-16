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
    
    clear(root->left());
    clear(root->right());
    
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



BinaryTree::Node* BinaryTree::copy(Node* root)
{
    Node* rootNew = nullptr;
    
    if (root) {
        
        rootNew = new Node(root->key());
        rootNew->setLeft(copy(root->left()));
        rootNew->setRight(copy(root->right()));
    }
    
    return rootNew;
}



int BinaryTree::height() const {
    
    if (!m_root)
        
        return 0;
    
    int leftHeight = height(m_root->m_left);
    int rightHeight = height(m_root->m_right);
    
    if (rightHeight > leftHeight)
        
        leftHeight = rightHeight;
    
    return 1 + leftHeight;
    
}



int BinaryTree::height(Node *root) const {
    
    int hei = 0;
    if (root == nullptr)
        return hei;

    std::vector<Node*> currentLevelNodes;
    currentLevelNodes.push_back(root);

    while (currentLevelNodes.size() != 0)
    {
        hei++;
        std::vector<Node*> nextLevelNodes;
        nextLevelNodes.reserve(currentLevelNodes.size() * 2);

        for (Node* node : currentLevelNodes)
        {
            if (node->left())
            {
                nextLevelNodes.push_back(node->left());
            }

            if (node->right()) {
                nextLevelNodes.push_back(node->right());
            }
        }

        currentLevelNodes.swap(nextLevelNodes);
    }

    return hei;
    
}



int BinaryTree::getNodesCount() const {
    
    if (!m_root)
        
        return 0;
    
    int count = 1;
    
    count += getNodesCount(m_root->m_left);
    count += getNodesCount(m_root->m_right);
    
    return count;
    
}



int BinaryTree::getNodesCount(Node *root) const {
    
    if (!root)
        
        return 0;
    
    int count = 1;
    
    count += getNodesCount(root->m_left);
    count += getNodesCount(root->m_right);
    
    return count;
    
}



int BinaryTree::max() const {
    
    if (!m_root)
        
        return {};
    
    int maxLeft = max(m_root->m_left);
    int maxRight = max(m_root->m_right);
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
    
    int minLeft = min(m_root->m_left);
    int minRight = min(m_root->m_right);
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
    
    int maxLeft = max(root->m_left);
    int maxRight = max(root->m_right);
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
    
    int minLeft = min(root->m_left);
    int minRight = min(root->m_right);
    int minRoot = root->m_key;
    
    if (minLeft < minRoot)
        
        minRoot = minLeft;
    
    if (minRight < minRoot)
        
        minRoot = minRight;
    
    
    return minRoot;
    
}



BinaryTree::Node *BinaryTree::add (const int key) {
    
    if (m_root) {
        
        return _addNode(m_root, key);
        
    }
    
    else {
        
        return m_root = new Node(key);
        
    }
    
}


/*
bool BinaryTree::remove(const int key) {
    
    return removeNode(find(key));
    
}



auto BinaryTree::finishRemove(Node *currentNode, Node *parentNode, Node *replacementNode) {
    
    //if(!parentNode) return;
    
    if (parentNode->left() == currentNode) {
        
        parentNode->setLeft(nullptr);
        
        delete currentNode;
        
        if (replacementNode)
            
            parentNode->setLeft(replacementNode);
        
    }
    
    else {
        
        parentNode->setRight(nullptr);
        
        delete currentNode;
        
        if (replacementNode)
            
            parentNode->setRight(replacementNode);
        
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
        
        if (currentNode->left() == nullptr && currentNode->right() == nullptr) {
            
            finishRemove(currentNode, parentNode, replacementNode);
            
        } 
        
        else if (!currentNode->left()) {
            
            replacementNode = currentNode->right();
            finishRemove(currentNode, parentNode, replacementNode);
            
        }
        
        else if (!currentNode->right()) {
            
            replacementNode = currentNode->left();
            finishRemove(currentNode, parentNode, replacementNode);
            
        } 
        
        else {
            
            replacementNode = findParent(currentNode, nullptr);
            Node* leafParent = findParent(currentNode, replacementNode);
            
            if(leafParent->left() == replacementNode) {
                
                leafParent->setLeft(nullptr);
                
            } 
            
            else {
                
                leafParent->setRight(nullptr);
                
            }
            
            replacementNode->setLeft(currentNode->left());
            replacementNode->setRight(currentNode->right());
            
            finishRemove(currentNode, parentNode, replacementNode);
            
        }
        
    }
    
    return false;
    
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
        
        
        if (parent->left() == child)
                
            return parent;
        
        else if (parent->left())
            
            nodes.push(parent->left());
        
        
        if (parent->right() == child)
            
            return parent;
        
        else if(parent->right())
            
            nodes.push(parent->right());
        
        
    }
    
    return nullptr;
    
}
*/




//bool BinaryTree::remove(const int key) {
//    
//    return removeNode(find(key), key);
//    
//}
//
//
//
//bool BinaryTree::removeNode(Node* node, const int key) {
//    
//    Node *currentNode = node,
//         *parentNode = findParent(m_root, key),
//         *replacementNode = nullptr;
//    
//    if (!currentNode) {
//        
//        return false;
//        
//    }
//    
//    
//    
//    if(currentNode->left() == nullptr && currentNode->right() == nullptr) {
//        
//        finishRemove(currentNode, parentNode, replacementNode);
//        
//    }
//    
//    else if(!currentNode->left()) {
//        
//        replacementNode = currentNode->right();
//        finishRemove(currentNode, parentNode, replacementNode);
//        
//    }
//    
//    else if(!currentNode->right()) {
//        
//        replacementNode = currentNode->left();
//        finishRemove(currentNode, parentNode, replacementNode);
//        
//    }
//    
//    
//    
//    else {
//        
//        replacementNode = findParent(currentNode, nullptr);
//        Node* leafParent = findParent(currentNode, replacementNode);
//        
//        if (leafParent->left() == replacementNode) {
//            
//            leafParent->setLeft(nullptr);
//            
//        }
//        
//        else {
//            
//            leafParent->setRight(nullptr);
//            
//        }
//        
//        replacementNode->setLeft(currentNode->left());
//        replacementNode->setRight(currentNode->right());
//        finishRemove(currentNode, parentNode, replacementNode);
//        
//    }
//    
//    return true;
//    
//}
//
//
//
//void BinaryTree::finishRemove(Node *currentNode, Node *parentNode, Node *replacementNode) {
//    
//    if (!parentNode) {
//        
//        return;
//        
//    }
//    
//    if (parentNode == currentNode) {
//        
//        m_root = replacementNode;
//        delete currentNode;
//        currentNode = nullptr;
//        parentNode = nullptr;
//        
//    } 
//    
//    else if (parentNode->left() == currentNode) {
//        
//        parentNode->setLeft(nullptr);
//        delete currentNode;
//        currentNode = nullptr;
//        
//        if (replacementNode)
//            
//            parentNode->setLeft(replacementNode);
//        
//    }
//    
//    else {
//        
//        parentNode->setRight(nullptr);
//        delete currentNode;
//        currentNode = nullptr;
//        
//        if (replacementNode)
//            
//            parentNode->setRight(replacementNode);
//        
//    }
//    
//}
//
//
//
//BinaryTree::Node *BinaryTree::findParent(Node* root, const int key) {
//    
//    if (m_root && (m_root->key() == key))
//        return nullptr;
//
//    if (root)
//    {
//        if (root->left() || root->right())
//        {
//            if ((root->left() && root->left()->key() == key) || (root->right() && root->right()->key() == key))
//                return root;
//            else
//            {
//                Node* left = findParent(root->left(), key);
//                Node* right = findParent(root->right(), key);
//                if (left)
//                    return left;
//
//                if (right)
//                    return right;
//            }
//        }
//    }
//
//    return nullptr;
//    
//}



//const BinaryTree::Node* BinaryTree::findParent(const Node* root, const Node* child) const {
//    
//    if (!root) {
//        
//        return nullptr;
//        
//    }
//    
//    std::stack<const Node*> unprocessedNodes;
//    unprocessedNodes.push(root);
//    const Node* parent = nullptr;
//    
//    while (!unprocessedNodes.empty()) {
//        
//        parent = unprocessedNodes.top();
//        unprocessedNodes.pop();
//        
//        if (parent == child) {
//            
//            return parent;
//            
//        }
//        
//        if (parent->left() == child) {
//            
//            if (child)
//                
//                return parent;
//            
//        } 
//        
//        else if (parent->left()) {
//            
//            unprocessedNodes.push(parent->left());
//            
//        }
//        
//        if (parent->right() == child) {
//            
//            return parent;
//            
//        } 
//        
//        else if (parent->right()) {
//            
//            unprocessedNodes.push(parent->right());
//            
//        }
//        
//    }
//    
//    return nullptr;
//    
//}
//
//
//
//BinaryTree::Node* BinaryTree::findParent(Node* root, Node* child) {
//    
//    return const_cast<Node*>(findParent(const_cast<const Node*>(root), const_cast<const Node*>(child)));
//    
//}
//
//
//
//BinaryTree::Node* BinaryTree::findParent(Node* root) const
//{
//    std::vector<Node*> unprocessedNodes;
//    unprocessedNodes.push_back(m_root);
//    while (!unprocessedNodes.empty())
//    {
//        Node* node = unprocessedNodes.front();
//        if (node == nullptr) return nullptr;
//        if (node->left())
//        {
//            if (node->left() == root)
//            {
//                return node;
//            }
//            unprocessedNodes.push_back(node->left());
//        }
//        if (node->right())
//        {
//            if (node->right() == root)
//            {
//                return node;
//            }
//            unprocessedNodes.push_back(node->right());
//        }
//        unprocessedNodes.pop_front();
//    }
//    return nullptr;
//}



/*
bool BinaryTree::remove(const int key) {
    
    return remove(find(key), findParent(m_root, find(key)));
    
}



bool BinaryTree::remove(Node* deleteNode, Node* parentNode)
{
    if (deleteNode == nullptr)
        
        return false;

    if (deleteNode->left() == nullptr && deleteNode->right() == nullptr) {
        
        if (parentNode && parentNode->left() == deleteNode)
            
            parentNode->setLeft(nullptr);

        if (parentNode && parentNode->right() == deleteNode)
            
            parentNode->setRight(nullptr);

        if (!parentNode)
            
            m_root = nullptr;

        delete deleteNode;

        return true;
        
    }

    if (deleteNode->left() == nullptr && deleteNode->right() != nullptr) {
        
        if (parentNode && parentNode->left() == deleteNode)
            
            parentNode->setLeft(deleteNode->right());

        if (parentNode && parentNode->right() == deleteNode)
            
            parentNode->setRight(deleteNode->right());

        if (!parentNode)
            
            m_root = deleteNode->right();

        delete deleteNode;

        return true;
        
    }

    if (deleteNode->left() != nullptr && deleteNode->right() == nullptr) {
        
        if (parentNode && parentNode->left() == deleteNode)
            
            parentNode->setLeft(deleteNode->left());

        if (parentNode && parentNode->right() == deleteNode)
            
            parentNode->setRight(deleteNode->left());

        if (!parentNode)
            
            m_root = deleteNode->left();

        delete deleteNode;

        return true;
        
    }

    if (deleteNode->left() && deleteNode->right()) {
        
        if (parentNode) {
            
            if (parentNode->left() == deleteNode) {
                
                parentNode->setLeft(deleteNode->left());
                
                Node* toAdd = getFree(parentNode);
                
                if (toAdd->right() == nullptr)
                    
                    toAdd->setRight(deleteNode->right());
                
                else
                    
                    toAdd->setLeft(deleteNode->right());
                
            }

            if (parentNode->right() == deleteNode) {
                
                parentNode->setRight(deleteNode->right());
                
                Node* toAdd = getFree(parentNode);
                
                if (toAdd->left() == nullptr)
                    
                    toAdd->setLeft(deleteNode->left());
                
                else
                    
                    toAdd->setRight(deleteNode->left());
                
            }
            
        }
        
        else {
            
            m_root = deleteNode->left();
            
            Node* toAdd = getFree(m_root);
            
            if (toAdd->right() == nullptr)
                
                toAdd->setRight(deleteNode->right());
            
            else
                
                toAdd->setLeft(deleteNode->right());
            
        }

        delete deleteNode;

        return true;
        
    }
    
    return true;
    
}



const BinaryTree::Node* BinaryTree::findParent(const Node* root, const Node* child) const {
    
    if (!root) {
        
        return nullptr;
        
    }
    
    std::stack<const Node*> unprocessedNodes;
    unprocessedNodes.push(root);
    const Node* parent = nullptr;
    
    while (!unprocessedNodes.empty()) {
        
        parent = unprocessedNodes.top();
        unprocessedNodes.pop();
        
        if (parent == child) {
            
            return parent;
            
        }
        
        if (parent->left() == child) {
            
            if (child)
                
                return parent;
            
        }
        
        else if (parent->left()) {
            
            unprocessedNodes.push(parent->left());
            
        }
        
        if (parent->right() == child) {
            
            return parent;
            
        }
        
        else if (parent->right()) {
            
            unprocessedNodes.push(parent->right());
            
        }
        
    }
    
    return nullptr;
    
}



BinaryTree::Node* BinaryTree::findParent(Node* root, Node* child) {
    
    return const_cast<Node*>(findParent(const_cast<const Node*>(root), const_cast<const Node*>(child)));
    
}



BinaryTree::Node* BinaryTree::getFree(Node* root)
{
    if (root == nullptr)
        throw "getFree: tree is empty";

    if (root->left() == nullptr || root->right() == nullptr)
        return root;
    else
    {
        int h1 = height(root->left());
        int h2 = height(root->right());
        if (h1 < h2)
            return getFree(root->left());
        else if(h1 > h2)
            return getFree(root->right());
        else
        {
            int c1 = getNodesCount(root->left());
            int c2 = getNodesCount(root->right());
            if(c1 < c2)
                return getFree(root->left());
            else
                return getFree(root->right());
        }
    }
}
*/





bool BinaryTree::remove(int key) {
    
    return remove(m_root, key);
}



bool BinaryTree::remove(Node* root, int key) {
    
    Node* to_delete = find(root, key);
    Node* parent = findParent(root, key);
    return removeNode(to_delete, parent);
    
}



BinaryTree::Node* BinaryTree::findParent(Node* root, int key) {
    
    if (m_root && (m_root->key() == key))
        
        return nullptr;

    if (root) {
        
        if (root->left() || root->right()) {
            
            if ((root->left() && root->left()->key() == key) || (root->right() && root->right()->key() == key))
                
                return root;
            
            else {
                
                Node* left = findParent(root->left(), key);
                Node* right = findParent(root->right(), key);
                
                if (left)
                    
                    return left;

                if (right)
                    
                    return right;
                
            }
            
        }
    }

    return nullptr;
    
}



bool BinaryTree::removeNode(Node* deleteNode, Node* parentNode) {
    
    if (deleteNode == nullptr)
        
        return false;

    if (deleteNode->left() == nullptr && deleteNode->right() == nullptr) {
        
        if (parentNode && parentNode->left() == deleteNode)
            
            parentNode->setLeft(nullptr);

        if (parentNode && parentNode->right() == deleteNode)
            
            parentNode->setRight(nullptr);

        if (!parentNode)
            
            m_root = nullptr;

        delete deleteNode;

        return true;
        
    } else if (deleteNode->left() == nullptr && deleteNode->right() != nullptr) {
        
        if (parentNode && parentNode->left() == deleteNode)
            
            parentNode->setLeft(deleteNode->right());

        if (parentNode && parentNode->right() == deleteNode)
            
            parentNode->setRight(deleteNode->right());

        if (!parentNode)
            
            m_root = deleteNode->right();

        delete deleteNode;

        return true;
        
    } else if (deleteNode->left() != nullptr && deleteNode->right() == nullptr) {
        
        if (parentNode && parentNode->left() == deleteNode)
            
            parentNode->setLeft(deleteNode->left());

        if (parentNode && parentNode->right() == deleteNode)
            
            parentNode->setRight(deleteNode->left());

        if (!parentNode)
            
            m_root = deleteNode->left();

        delete deleteNode;

        return true;
        
    } else if (deleteNode->left() && deleteNode->right()) {
        
        if (parentNode) {
            
            if (parentNode->left() == deleteNode) {
                
                parentNode->setLeft(deleteNode->left());
                
                Node* toAdd = getFree(parentNode); //getLeaf
                
                if (toAdd->right() == nullptr)
                    
                    toAdd->setRight(deleteNode->right());
                
                else
                    
                    toAdd->setLeft(deleteNode->right());
                
            }

            if (parentNode->right() == deleteNode) {
                
                parentNode->setRight(deleteNode->right());
                
                Node* toAdd = getFree(parentNode);
                
                if (toAdd->left() == nullptr)
                    
                    toAdd->setLeft(deleteNode->left());
                
                else
                    
                    toAdd->setRight(deleteNode->left());
                
            }
            
        }
        
        else {
            
            m_root = deleteNode->left();
            
            Node* toAdd = getFree(m_root);
            
            if (toAdd->right() == nullptr)
                
                toAdd->setRight(deleteNode->right());
            
            else
                
                toAdd->setLeft(deleteNode->right());
            
        }

        delete deleteNode;

        return true;
        
    }
    
    return true;
    
}



BinaryTree::Node* BinaryTree::getFree(Node* root) {
    
    if (root == nullptr) {
        
        std::cerr << "getFree: tree is empty";
        
        return nullptr;
        
    }
        

    if (root->left() == nullptr || root->right() == nullptr)
        
        return root;
    
    else {
        
        int h1 = height(root->left());
        int h2 = height(root->right());
        
        if (h1 < h2)
            
            return getFree(root->left());
        
        else if(h1 > h2)
            
            return getFree(root->right());
        
        else {
            
            int c1 = getNodesCount(root->left());
            int c2 = getNodesCount(root->right());
            
            if(c1 < c2)
                
                return getFree(root->left());
            
            else
                
                return getFree(root->right());
            
        }
        
    }
}












BinaryTree::Node *BinaryTree::find(const int key) const {
    
    return find(m_root, key);
    
}



BinaryTree::Node *BinaryTree::find(Node *root, const int key) const {
    
    if (!root)
        
        return root;
    
    if (root->m_key == key)
        
        return root;
    
    
    if (find(root->m_left, key))
        
        return find(root->m_left, key);
        
    if (find(root->m_right, key))
        
        return find(root->m_right, key);
    
    return nullptr;
    
}



BinaryTree::Node* BinaryTree::findByIndex(int index) {
    
    return findByIndex(m_root, index);
    
}



BinaryTree::Node* BinaryTree::findByIndex(Node* root, int index) {
    
    if (index == 0) {
        
        return root;
        
    }
    
    else if (root == nullptr) {
        
        return nullptr;
        
    }

    std::vector<Node*> currentLevelNodes;
    currentLevelNodes.push_back(root);

    while (currentLevelNodes.size() != 0 && index >= currentLevelNodes.size()) {
        
        std::vector<Node*> nextLevelNodes;
        
        nextLevelNodes.reserve(currentLevelNodes.size() * 2);

        for (Node* node : currentLevelNodes) {
            
            if (node->left()) {
                
                nextLevelNodes.push_back(node->left());
                
            }

            if (node->right()) {
                
                nextLevelNodes.push_back(node->right());
                
            }
            
        }

        index -= currentLevelNodes.size();
        
        currentLevelNodes.swap(nextLevelNodes);
        
    }

    if (currentLevelNodes.size() == 0) {
        
        return nullptr;
        
    }
    
    else {
        
        return currentLevelNodes[index];
        
    }
    
}



bool BinaryTree::isBalanced() const {
    
    return isBalanced(m_root);
    
}



bool BinaryTree::isBalanced(Node *root) const {
    
    if (!root)
        
        return true;
    
    int leftHeight = height(root->left());
    int rightHeight = height(root->right());
    int difference = leftHeight - rightHeight;
    
    bool balanced = (difference == 0 || difference == 1 || difference == -1);
    
    return ( balanced && isBalanced(root->left()) && isBalanced(root->right()) );
    
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
    
    int leftTree = getLevel(root->left(), node, currentLevel);
    int rightTree = getLevel(root->right(), node, currentLevel);
    
    if (leftTree == -1)
        
        return rightTree;
    
    return leftTree;
    
}



void BinaryTree::getKeys(std::vector<int> &vector) const {
    
    if (!m_root)
        
        return;
        
    vector.push_back(m_root->key());
    getKeys(m_root->left(), vector);
    getKeys(m_root->right(), vector);
    
    for (int i = vector.size() - 1; i > 0; i--)
        
        for (int j = 0; j < i; j++)
            
            if (vector[j] > vector[j+1])
                
                std::swap(vector[j], vector[j+1]);
    
}



void BinaryTree::getKeys(Node* root, std::vector<int> &vector) const {
    
    if(!root)
        
        return;
        
    vector.push_back(root->key());
    getKeys(root->left(), vector);
    getKeys(root->right(), vector);
    
}



void BinaryTree::printHorizontal(int levelSpacing) const {
    
    printHorizontal(m_root, 0, levelSpacing);
    
}



void BinaryTree::printHorizontal(Node *root, int marginLeft, int levelSpacing) const {
    
    if (root == nullptr) {
        
        return;
        
    }
    
    printHorizontal(root->right(), marginLeft + levelSpacing, levelSpacing);
    
    std::cout << std::string(marginLeft, ' ') << root->key() << std::endl;
    
    printHorizontal(root->left(), marginLeft + levelSpacing, levelSpacing);
    
}



void BinaryTree::printLeaves() const {
    
    if (!m_root) {
        
        return;
        
    }
    
    std::vector<Node* > leafsList;
    
    getLeafs(m_root, leafsList);
    
    std::cout << '[';
    
    for (auto it = leafsList.begin(); it != leafsList.end(); ++it) {
        
        std::cout << (*it)->key() << ((it + 1) == leafsList.end() ? "":", ");
        
    }
    
    std::cout << ']' << std::endl;
    
}



void BinaryTree::getLeafs(Node* root, std::vector<Node*> &leafsList) const {
    
    if (!root)
        
        return;
    
    if (!root->left() && !root->right())
        
        leafsList.push_back(root);
    
    else {
        
        getLeafs(root->left(), leafsList);
        getLeafs(root->right(), leafsList);
        
    }
    
}



void BinaryTree::printVertical() {
    
    printVertical(m_root);
    
}



void BinaryTree::printVertical(Node* root) {
    
    if (root == nullptr) {
        
        std::cout << "Tree is empty" << std::endl;
        
        return;
        
    }

    std::vector<Node*> currentLevelNodes;
    currentLevelNodes.push_back(root);
    
    int significant = 1;
    int level = 1;
    int h = height(root);

    while (significant) {
        
        for (int i = 0; i < currentLevelNodes.size(); i++) {
            
            if (i == 0)
                
                for (int j = 0; j < pow(2, h - level); j++)
                    
                    std::cout << " ";
            else
                
                for (int j = 0; j < pow(2, h - level) + pow(2, h - level) - 1; j++)
                    
                    std::cout << " ";

            if (currentLevelNodes[i])
                
                std::cout << currentLevelNodes[i]->key();
            
            else
                
                std::cout << "X";
            
        }
        
        std::cout << std::endl;

        significant = 0;
        std::vector<Node*> nextLevelNodes;
        nextLevelNodes.reserve(currentLevelNodes.size() * 2);

        for (Node* node : currentLevelNodes) {
            
            if (node) {
                
                if (node->left())
                    
                    significant++;
                
                if (node->right())
                    
                    significant++;

                nextLevelNodes.push_back(node->left());
                nextLevelNodes.push_back(node->right());
                
            }
            
            else {
                
                nextLevelNodes.push_back(nullptr);
                nextLevelNodes.push_back(nullptr);
                
            }
            
        }

        currentLevelNodes.swap(nextLevelNodes);
        level++;
        
    }
    
}





BinaryTree *BinaryTree::operator = (const BinaryTree &other) {
    
    if (m_root != other.m_root) {
        
        clear();
        
        auto obj = clone(other.m_root);
        
        std::swap(m_root, obj.m_root);
        
    }
    
        return this;
    
}



BinaryTree::Node *BinaryTree::_addNode (Node *root, const int key) {
    
    if (!root) {
        
        root = new Node(key);
        
    }
    
    else if (rand() % 2) {
        
        root->setLeft(_addNode(root->left(), key));
        
    }
    
    else {
        
        root->setRight(_addNode(root->right(), key));
        
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
    
    cloneRoot = new Node(root->key());
    
    cloneRoot->setLeft(_clone(root->left()));
    cloneRoot->setRight(_clone(root->right()));
    
    return cloneRoot;
    
}









// Методы для Node



BinaryTree::Node::Node(int key, Node* left, Node* right)

    : m_key(key)
    , m_left(left)
    , m_right(right)

{}



int BinaryTree::Node::key() const {
    
    return m_key;
    
}



void BinaryTree::Node::setKey(const int key) {
    
    m_key = key;
    
}



BinaryTree::Node* BinaryTree::Node::left() const {
    
    return m_left;
    
}



BinaryTree::Node* BinaryTree::Node::right() const {
    
    return m_right;
    
}



void BinaryTree::Node::setLeft(Node* left) {
    
    m_left = left;
    
}



void BinaryTree::Node::setRight(Node* right) {
    
    m_right = right;
    
}
