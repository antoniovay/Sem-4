//
//  SearchTreeTester.hpp
//  Lab 3 "Search Tree"
//
//  Created by Antony Miroshnichenko on 16.05.2024.
//



#pragma once

#include "SearchTree.hpp"

#include "BinaryTreeTester.hpp"

class SearchTreeTester : public BinaryTreeTester
{
    
public:
    SearchTreeTester(const bool useConsoleOutput, const bool enableAllTests = true);
    ~SearchTreeTester() override = default;

protected:
    BinaryTree *allocateTree() override;
    void check_addAndCount(const BinaryTree *tree, const int size) override;
    void check_remove(BinaryTree *tree, const int key,
                      const bool result, const int size) override;
    void check_clear(const BinaryTree *tree, const int size) override;
    void check_assign(const BinaryTree *first,
                      const BinaryTree *second) override;

    void assign() override;
private:
    bool isSearchTree(const BinaryTree *tree);
    void treeKeysLnr(BinaryTree::Node *root, std::vector<int> &keys);
};
