//
//  main.cpp
//  BinTree
//
//  Created by Antony Miroshnichenko on 14.03.2024.
//



#include "BinaryTree.hpp"
#include "BinaryTreeTester.hpp"


int main() {
    
    //srand((unsigned)time(NULL));
    BinaryTree tree;
    std::vector<int> nums;
    
    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
        tree.add(i);
    }
    
    
    std::cout << "Tree:" << std::endl;
    tree.printVertical();
    std::cout << "Nodes: " << tree.getNodesCount() << std::endl << std::endl;
    
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
    
    

//    for (int i = 0; i < 10; i++) {
//        
//        tree.remove(i);
//        std::cout << "Tree:" << std::endl;
//        tree.printVertical();
//        std::cout << "Nodes: " << tree.getNodesCount() << std::endl << std::endl;
//        
//    }

    
    
    BinaryTreeTester tester(true, false);
    tester.setRemoveCheckEnabled(true);
    tester.test(10);
    
}


