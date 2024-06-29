//
//  main.cpp
//  Lab 4 "AVL tree"
//
//  Created by Antony Miroshnichenko on 25.04.2024.
//

#include <assert.h>
#include <iostream>

#include "AVLTree.hpp"
#include "AVLTreeTester.hpp"


bool test_balance_etnt(int maxSize = 20, bool useConsole = true, bool printTree = false) {
    
    AVLTree tree;
    
    for (int size = 1; size < maxSize+1; size++) {
        for (int i = 1; i<size+1; i++)
            tree.add((rand()%100));
        if (!tree.isBalanced())
            return false;
        if (useConsole) {
            if (printTree) {
                std::cout << "=========================(SIZE=" << size << ")=========================" << std::endl;
                tree.printVertical();
            }
            else
                std::cout << "Size = " << size << std::endl;
        }
        tree.clear();
    }
    
    return true;
    
}

bool test_balance_po(int maxSize = 20, bool useConsole = true, bool printTree = false) {
    
    AVLTree tree;
    
    for (int size = 1; size < maxSize+1; size++) {
        tree.add((rand()%100));
        if (!tree.isBalanced())
            return false;
        if (useConsole) {
            if (printTree) {
                std::cout << "=========================(SIZE=" << size << ")=========================" << std::endl;
                tree.printVertical();
            }
            else
                std::cout << "Size = " << size << std::endl;
        }
    }
    
    return true;
    
}


int main() {
    
//    std::cout << "Every time new tree TEST:" << std::endl;
//    if(test_balance_etnt(100, true, false))
//        std::cout << "SUCCESS";
//    else
//        std::cout << "FAILED";
//    std::cout << std::endl << std::endl;
//    
//    
//    std::cout << "Plus one TEST:" << std::endl;
//    if(test_balance_po(100, true, false))
//        std::cout << "SUCCESS";
//    else
//        std::cout << "FAILED";
//    std::cout << std::endl << std::endl;
    
    
    
    AVLTreeTester tester(true);
    tester.setRemoveCheckEnabled(true);
    tester.test(10);
    
}
