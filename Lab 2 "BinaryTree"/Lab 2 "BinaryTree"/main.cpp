//
//  main.cpp
//  BinTree
//
//  Created by Antony Miroshnichenko on 14.03.2024.
//



#include "BinaryTree.hpp"



int main() {
    srand((unsigned)time(NULL));
    BinaryTree tree;
    
    tree.addNode(10);
    tree.addNode(50);
    tree.addNode(20);
    tree.addNode(5);
    tree.addNode(100);
    
    
    tree.printHorizontal();
    
//    std::cout << tree.max() << " " << tree.min() << std::endl;
//    
//    std::cout << tree.getNodesCount() << std::endl;
//    
//    tree.printLeaves();
//    
//    std::cout << tree.getLevel(5) << std::endl;
//
//    std::vector<int> nums;
//
//    tree.getKeys(nums);
//
//    for (auto it = nums.begin(); it != nums.end(); ++it) {
//
//        std::cout << *it << ((it + 1) == nums.end() ? "":", ");
//
//    }
//
//    std::cout << std::endl;
    
    
    
    tree.removeNode(20);
    tree.removeNode(100);
    
    std::cout << std::endl << std::endl;

    tree.printHorizontal();
    
}


