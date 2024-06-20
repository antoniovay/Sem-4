//
//  main.cpp
//  Lab 3 "Search Tree"
//
//  Created by Antony Miroshnichenko on 15.04.2024.
//

#include <iostream>
#include "SearchTree.hpp"
#include "SearchTreeTester.hpp"


void remove_test(const int A = 0, const int B = 100, const int SIZE = 10) {
    
    srand(time(0));
    
    SearchTree tree;
    
    std::vector<int> nums;
    
    for (int i = 0; i < SIZE; i++) {
        nums.push_back(rand() % B - A);
        tree.add(nums[i]);
    }

    std::cout << "Initialed tree:" << std::endl;
    tree.printVertical();
    
    std::cout << std::endl << std::endl << "-----------Remove test----------" << std::endl<< std::endl << "====================" << std::endl;
    
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Deleting " << nums[i] << ":" << std::endl << "====================" << std::endl << "Tree:" << std::endl;
        tree.remove(nums[i]);
        tree.printVertical();
        std::cout << "====================" << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    
}


int main()
{
    
    remove_test();
    
//    SearchTreeTester tester(false, true);
//    tester.test(100);
    
}
