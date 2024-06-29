//
//  AVLTreeTester.cpp
//  Lab 4 "AVL tree"
//
//  Created by Antony Miroshnichenko on 12.06.2024.
//

#include <algorithm>
#include <assert.h>
#include <iostream>

#include "AVLTreeTester.hpp"



AVLTreeTester::AVLTreeTester(const bool useConsoleOutput,
                                   const bool enableAllTests)
    : BinaryTreeTester(useConsoleOutput, enableAllTests)
{}

BinaryTree *AVLTreeTester::allocateTree()
{
    return new AVLTree;
}

void AVLTreeTester::check_addAndCount(const BinaryTree *tree, const int size)
{
    BinaryTreeTester::check_addAndCount(tree, size);
    tree->printHorizontal();
    assert(isSearchTree(tree));
    assert(tree->isBalanced());
}

void AVLTreeTester::check_remove(BinaryTree *tree, const int key,
                                    const bool result, const int size)
{
    BinaryTreeTester::check_remove(tree, key, result, size);
    assert(isSearchTree(tree));
    assert(tree->isBalanced());
}

void AVLTreeTester::check_clear(const BinaryTree *tree, const int size)
{
    BinaryTreeTester::check_clear(tree, size);
    assert(isSearchTree(tree));
    assert(tree->isBalanced());
}

void AVLTreeTester::check_assign(const BinaryTree *first,
                                    const BinaryTree *second)
{
    BinaryTreeTester::check_assign(first, second);
    assert(isSearchTree(first) && first->isBalanced());
    assert(isSearchTree(second) && second->isBalanced());
}


void AVLTreeTester::assign()
{
    if (!assignCheckEnabled()) {
        return;
    }

    AVLTree tree1;

    std::vector<int> nodeKeys = generateKeys();
    for (int i = 0 ; i < m_maxSize; ++i) {
        tree1.add(nodeKeys[i]);
    }

    AVLTree tree2 = tree1; //Конструктор копирования
    check_assign(&tree1, &tree2);

    tree1 = tree1; //Присваивание самому себе
    check_assign(&tree1, &tree2); //Проверяем, что tree1 не сломалось

    tree1 = tree2; //Присваивание одинаковых по размеру деревьев
    check_assign(&tree1, &tree2);

    AVLTree tree3;
    tree1 = tree3; //Присваивание дерева меньшего размера
    check_assign(&tree1, &tree3);

    tree3 = tree2; //Присваивание дерева большего размера
    check_assign(&tree2, &tree3);
}

bool AVLTreeTester::isSearchTree(const BinaryTree *tree)
{
    if (m_useConsoleOutput) {
        tree->printHorizontal();
        std::cout << "======\n";
    }
    std::vector<int> keys;
    treeKeysLnr(tree->getRoot(), keys);
    return std::is_sorted(keys.begin(), keys.end());
}

void AVLTreeTester::treeKeysLnr(BinaryTree::Node *root, std::vector<int> &keys)
{
    if (!root) {
        return;
    }

    treeKeysLnr(root->left(), keys);
    keys.push_back(root->key());
    treeKeysLnr(root->right(), keys);
}
